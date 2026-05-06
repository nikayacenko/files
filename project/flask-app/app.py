from flask import Flask, request, jsonify, render_template, redirect, session
import hashlib, os, psycopg2, datetime
from functools import wraps

app = Flask(__name__, static_folder='static', template_folder='templates')
app.secret_key = os.environ.get('JWT_SECRET', 'secret')

import os

# Чтение из ConfigMap
AUTH_TITLE = os.environ.get('AUTH_TITLE', 'F1 Management System')
AUTH_WELCOME = os.environ.get('AUTH_WELCOME', 'Welcome')
PROFILE_SERVICE_URL = os.environ.get('PROFILE_SERVICE_URL', 'http://profile-service:8000')
NOTIFICATION_SERVICE_URL = os.environ.get('NOTIFICATION_SERVICE_URL', 'http://notification-service:8000')

# Чтение из Secret
JWT_SECRET = os.environ.get('JWT_SECRET', 'secret')
API_KEY = os.environ.get('API_KEY', 'dev-key')

# ========== БАЗА ДАННЫХ ==========
def get_db():
    return psycopg2.connect(
        host=os.environ.get('POSTGRES_HOST', 'postgres-db'),
        user=os.environ.get('POSTGRES_USER', 'app_user'),
        password=os.environ.get('POSTGRES_PASSWORD', 'SecurePass123'),
        database=os.environ.get('POSTGRES_DB', 'userdb')
    )

# ========== УВЕДОМЛЕНИЯ ==========
notifications = [
    {'id': 1, 'title': 'Гран-при Монако', 'message': 'Следующая гонка: 26 мая 2024, 15:00', 'date': '2024-05-20'},
    {'id': 2, 'title': 'Обновление системы', 'message': 'Доступна новая версия F1 Management', 'date': '2024-05-19'},
]

def login_required(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        if 'user_id' not in session:
            return redirect('/')
        return f(*args, **kwargs)
    return decorated

def admin_required(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        if not session.get('is_admin'):
            return redirect('/home')
        return f(*args, **kwargs)
    return decorated

@app.route('/', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form.get('username')
        password = request.form.get('password')
        password_hash = hashlib.sha256(password.encode()).hexdigest()
        
        conn = get_db()
        cur = conn.cursor()
        cur.execute('SELECT id, username FROM users WHERE username=%s AND password_hash=%s', (username, password_hash))
        user = cur.fetchone()
        cur.close()
        conn.close()
        
        if user:
            session['user_id'] = user[0]
            session['username'] = user[1]
            session['is_admin'] = (username == 'admin')
            return redirect('/home')
        return render_template('login.html', error='Неверный логин или пароль')
    return render_template('login.html', error=None)

@app.route('/home')
@login_required
def home():
    return render_template('index.html', username=session.get('username'), is_admin=session.get('is_admin', False))

@app.route('/profile')
@login_required
def profile():
    return render_template('profile.html', username=session.get('username'), is_admin=session.get('is_admin', False))

@app.route('/notifications')
@login_required
def notifications_page():
    return render_template('notifications.html', notifications=notifications, is_admin=session.get('is_admin', False))

@app.route('/admin')
@login_required
@admin_required
def admin_panel():
    return render_template('admin.html', notifications=notifications)

@app.route('/admin/create', methods=['POST'])
@login_required
@admin_required
def create_notification():
    new_id = max([n['id'] for n in notifications]) + 1 if notifications else 1
    notifications.append({
        'id': new_id,
        'title': request.form.get('title'),
        'message': request.form.get('message'),
        'date': datetime.datetime.now().strftime('%Y-%m-%d %H:%M')
    })
    return redirect('/admin')

@app.route('/admin/delete/<int:id>')
@login_required
@admin_required
def delete_notification(id):
    global notifications
    notifications = [n for n in notifications if n['id'] != id]
    return redirect('/admin')

@app.route('/logout')
def logout():
    session.clear()
    return redirect('/')

@app.route('/health')
def health():
    return jsonify({'status': 'ok'})

@app.route('/')
def index():
    return redirect('/home')

@app.route('/debug')
def debug():
    return {
        'AUTH_TITLE': os.environ.get('AUTH_TITLE'),
        'AUTH_WELCOME': os.environ.get('AUTH_WELCOME'),
        'PROFILE_SERVICE_URL': os.environ.get('PROFILE_SERVICE_URL'),
        'JWT_SECRET': os.environ.get('JWT_SECRET')[:10] + '...',
        'API_KEY': os.environ.get('API_KEY')[:10] + '...',
    }

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
#include <string>
#include <random>
#include <algorithm>
#include <deque>
using namespace std;
string generateRandomId(int length) {
    const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(0, characters.size() - 1);

    string random_id;
    for (int i = 0; i < length; ++i) {
        random_id += characters[distribution(generator)];
    }
    return random_id;
}
long long sizeOf(const string& filename) {
    std::ifstream file(filename, ios::binary | ios::ate);

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return -1; // Ошибка: не удалось открыть файл
    }

    return file.tellg();
}
int main()
{
    setlocale(LC_ALL, "Ru");
    //ofstream fout("fileM.txt", ios::app);
    ifstream fin;
    bool fl = 1;

    do{
        string s;
        string id = generateRandomId(4);
        id += " ";
        //fout.open("fileM.txt");
        //fout << generateRandomId(4) << " ";
        //cout << "введите количество оценок: ";
        int n = 4;
        //cin >> n;
        cout << "введите оценки: ";
        ofstream fout("../../компсети2/x64/Debug/fileM2.bin", ios::binary);
        //fout << generateRandomId(4) << " ";
        char buff[9];
        for (int i = 0; i < 5; i++) {
            buff[i] = id.at(i);
        }
        char marks;
        if (fout.is_open()) {
            for (int i = 0, p=5; i < n; i++,p++) {

                cin >> marks;
                //fout << marks << " ";
                buff[p] = marks;

            }
        }
        fout.write(buff, sizeof(buff));
        //fout << endl;
        fout.close();
        long s1 = sizeOf("../../компсети3/x64/Debug/result2.bin");
        long s2 = s1;
        while (s2 == s1) {
            s2 = s1;
            s1 = sizeOf("../../компсети3/x64/Debug/result2.bin");
        }
        fin.open("../../компсети3/x64/Debug/result2.bin", ios::binary);
        char buff2[13];
        fin.read(buff2, sizeof(buff2));
        string result = "";
        for (int i = 0; i < sizeof(buff2); i++)
            result += buff2[i];
        cout << "стипендия равна: " << result.substr(5) << endl;
        //if (fin.is_open()) {
        //    //cout <<  endl;
        //    while (getline(fin, s)) {
        //        cout << "стипендия равна: " <<s.substr(5) << endl;

        //    }
        //}
        fin.close();
        cout << "Для ввода оценок нажмите на любую клавишу, для выхода из программы нажмите esc" << endl;

    } while (_kbhit() || _getch() != 27);
    //fout.close();

}




//#include<iostream>
//#include<fstream>
//#include<conio.h>
//using namespace std;
//#include <string>
//#include <random>
//#include <algorithm>
//#include <deque>
//
//long long sizef(const string& filename) {
//    std::ifstream file(filename, std::ios::binary | std::ios::ate);
//
//    if (!file.is_open()) {
//        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
//        return -1; // Или другое значение, указывающее на ошибку
//    }
//
//    std::streamsize size = file.tellg();
//    file.close();
//
//    if (size == std::streamsize(-1)) { // Проверка на ошибку
//        std::cerr << "Ошибка при получении размера файла (ifstream)" << std::endl;
//        return -1;
//    }
//
//    return size;
//}
//
//string generateRandomId(int length) {
//    const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//    random_device random_device;
//    mt19937 generator(random_device());
//    uniform_int_distribution<> distribution(0, characters.size() - 1);
//
//    string random_id;
//    for (int i = 0; i < length; ++i) {
//        random_id += characters[distribution(generator)];
//    }
//    return random_id;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    ofstream in;
//    ifstream out;
//    string id = generateRandomId(4);
//    id += " ";
//    do {
//
//
//        cout << "Введите кол-во оценок, которое хотите ввести:" << endl;
//        in.open("C:/Users/yacen/source/repos/компсети2/x64/Debug/fileM.txt", ios::app);
//        int mark;
//        int n;
//        cin >> n;
//        int k = 0;
//        cout << "Введите оценки" << endl;
//        string s = "";
//        while (k < n)
//        {
//            cin >> mark;
//            s += to_string(mark) + " ";//чтобы программы не мешали друг другу
//            k++;
//        }
//        in << id << " " << s << endl;
//        in.close();
//
//        long s1 = sizef("C:/Users/yacen/source/repos/компсети3/x64/Debug/result.txt");
//        long s2 = s1;
//        while (s2 == s1)
//        {
//            s2 = s1;
//            s1 = sizef("C:/Users/yacen/source/repos/компсети3/x64/Debug/result.txt");
//        }
//        out.open("C:/Users/yacen/source/repos/компсети3/x64/Debug/result.txt");
//        s = "";
//        string res = "";
//        while (!out.eof() && getline(out, s))
//        {
//            if (s.find(id) != string::npos)
//            {
//                res = s;
//            }
//        }
//        out.close();
//        cout << "Стипендия равна:" << res.substr(5) << endl;
//        cout << "Для ввода оценок нажмите на любую клавишу, для выхода из программы нажмите esc" << endl;
//    } while (_kbhit() || _getch() != 27);
//    cout << "Exiting...";
//
//}

//
//#include <iostream>
//#include <fstream>
//#include <string>
//
//int main() {
//    std::string filename;
//    std::string read_string;
//
//    std::ifstream infile("../../компсети2/x64/Debug/fileM2.bin", std::ios::binary);
//
//    if (!infile.is_open()) {
//        std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
//        return 1;
//    }
//
//    // Читаем длину строки
//    size_t length;
//    infile.read(reinterpret_cast<char*>(&length), 9);
//
//    // Выделяем память для строки
//    read_string.resize(length);
//
//    // Читаем строку
//    infile.read(&read_string[0], 9); // Важно использовать &read_string[0] для получения указателя на буфер
//
//    infile.close();
//
//    std::cout << "Прочитанная строка: " << read_string << std::endl;
//
//    return 0;
//}

//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//using namespace std;
//int main()
//{
//    setlocale(LC_ALL, "Ru");
//    int k = 0;
//    string Prev;
//    ofstream fout("result.txt", ios::trunc);
//    while (1) {
//        ifstream fin("C:/Users/yacen/source/repos/компсети2/компсети2/fileM.txt");
//        string next;
//        string s;
//        double sum = 0;
//        if (fin.is_open()) {
//            while (getline(fin, s)) {
//                int numb;
//                next = s;
//                int i = 0;
//                stringstream ss(s);
//                while (ss >> numb)
//                    sum += numb;
//                cout << sum << endl;
//                //sum /= 5;
//                /*if (sum == 25)
//                    fout << "повышенная стипендия" << "\n";
//                if (sum <= 25 && sum >= 16)
//                    fout << "обычная стипендия" <<"\n";
//                if (sum < 16)
//                    fout << "стипендии нет(" << "\n";
//                fout << sum << endl;*/
//                /*for (int i = 0; i < 5; i++) {
//                    sum += s.at(i);
//                }*/
//                /*while (i < 5) {
//                    sum += next.at(i);
//                    i++;
//                }
//                fout << sum << endl;
//                break;*/
//
//            }
//            if (next != Prev) {
//                cout << next << endl;
//                //fout << next << endl;
//                Prev = next;
//                
//            }
//
//
//        }fin.close();
//
//
//        
//    }
//}


//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <filesystem>
//using namespace std;
//long long sizeOf(const string& filename) {
//    std::ifstream file(filename, ios::binary | ios::ate);
//
//    if (!file.is_open()) {
//        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
//        return -1; // Ошибка: не удалось открыть файл
//    }
//
//    return file.tellg();
//}
//struct Student {
//    string surname[4];
//    int marks[4];
//};
//int a;
//int main()
//{
//    setlocale(LC_ALL, "Ru");
//    //ofstream fout("result.txt", ios::trunc)
//    //ifstream fin;
//    Student student;
//    while (1) {
//        string s;
//        ifstream fin;
//        fin.open("../../компсети2/x64/Debug/fileM2.bin", ios::binary);
//        //fin.open("C:/Users/yacen/source/repos/компсети2/компсети2/fileM.txt");
//        long s1 = sizeOf("../../компсети2/x64/Debug/fileM2.bin");
//        long s2 = s1;
//        if (!fin.is_open()) {
//            cerr << "Error: Could not open file " << endl;
//            break; // Выходим, если не удалось открыть файл
//        }
//        while (s2 == s1) {
//            s2 = s1;
//            s2 = sizeOf("../../компсети2/x64/Debug/fileM2.bin");
//
//        }
//        fin.read((char*)&student, sizeof(student));
//        //fin.close();
//        ofstream fout("../../компсети3/x64/Debug/result2.bin", ios::binary);
//        a = 0;
//        for (int i = 0; i < 4; i++) {
//            if (student.marks[i] == 4) a = 1;
//            if (student.marks[i] == 3) {
//                a = 2;
//                break;
//            }
//
//        }
//        //if (student.marks == 5) a = 0;
//        //if (student.marks == 4) a = 1;
//        //if (student.marks == 3) a = 2;
//        fout.open("../../компсети3/x64/Debug/result2.bin");
//        fout.write((char*)&a, sizeof(a));
//        fout.close();
//        /*string str = "";
//        string id;
//        string result = "";
//        char buffer[9] = { '0','0','0','0','0','0','0','0','0' };
//        fin.read(buffer, sizeof(buffer));
//        char resultM[13] = { '0','0','0','0','0','0','0','0','0','0', '0','0','0'};
//        for (int i = 0; i < 5; i++)
//            id += buffer[i];
//        result = id + " 3126,82";
//        for (int i = 5; i < sizeof(buffer); i++) {
//            if (buffer[i] == '3') {
//                result = id + " 0";
//                break;
//            }
//            if (buffer[i] == '4') {
//                result = id + " 2046,32";
//            }
//        }
//        for (int i = 0; i < result.size(); i++)
//            resultM[i] = result.at(i);
//        ofstream fout("../../компсети3/x64/Debug/result2.bin", ios::binary);
//        fout.write(resultM, sizeof(resultM));*/
//        //while (getline(fin, s)) {
//        //    int numb;
//        //    int sum = 0;
//        //    //fout << s << endl
//        //    fout << s.substr(0, 4) << " ";
//        //    stringstream ss(s);
//        //    while (ss >> numb)
//        //        sum += numb;
//        //    //fout << sum << endl;
//        //    if (s.find("3") == -1 && s.find("4") == -1) {
//        //        fout << 3126.82 << endl;
//        //        continue;
//        //    }
//        //    if (s.find("3") == -1 ) {
//        //        fout << 2046.32 << endl;
//        //        continue;
//        //    }
//        //    if (s.find("3")>=0) {
//        //        fout << 0 << endl;
//        //        continue;
//        //    }
//        //}
//        //cout << "success" << endl;
//        //fout.close();
//        //fin.close();
//        ofstream ofs;
//        ofs.open("../../компсети2/x64/Debug/fileM2.bin", ios::out | ios::trunc);
//        ofs.close();
//    }
//}

//#include <iostream>
//#include <fstream>
//#include <string>
//#include<conio.h>
//using namespace std;
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
//int main()
//{
//    ifstream in;
//
//    while (true)
//    {
//        in.open("C:/Users/yacen/source/repos/компсети2/x64/Debug/fileM.txt");
//        long s1 = sizef("C:/Users/yacen/source/repos/компсети2/x64/Debug/fileM.txt");
//        long s2 = s1;
//        int fl = 0;
//
//        if (!in.is_open()) {
//            cerr << "Error: Could not open file " << endl;
//            break; // Выходим, если не удалось открыть файл
//        }
//        while (s2 == s1)
//        {
//            s2 = s1;
//            s1 = sizef("C:/Users/yacen/source/repos/компсети2/x64/Debug/fileM.txt");
//        }
//        string s = "";
//        string id;
//        string res = "";
//
//        while (!in.eof() && getline(in, s))
//        {
//            id = s.substr(0, 4);
//            res = id + " 3126.82";
//            for (int i = 5; i < s.size(); i++)
//            {
//                if (s.at(i) == '3')
//                {
//                    res = id + " 0";
//                    break;
//                }
//                if (s.at(i) == '4')
//                {
//                    res = id + " 2046.32";
//                }
//            }
//        }
//        ofstream out("C:/Users/yacen/source/repos/компсети3/x64/Debug/result.txt", ios::app);
//        out << res << endl;
//        out.close();
//        in.close();
//    }
//}


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <thread>
using namespace std;
long long sizeOf(const string& filename) {
    std::ifstream file(filename, ios::binary | ios::ate);

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return -1; // Ошибка: не удалось открыть файл
    }

    return file.tellg();
}
struct Student {
    string surname;
    int marks[4];
};
int a;
int main() {
    setlocale(LC_ALL, "Ru");
    Student student;
    ifstream fin;

    while (true) {
        bool  fl = 1;
        fin.open("../../компсети2/x64/Debug/fileM2.bin", ios::binary);
        if (!fin.is_open()) {
            cerr << "Error: Could not open file " << endl;
            break;
        }
        long s1 = sizeOf("../../компсети2/x64/Debug/fileM2.bin");
        long s2 = s1;
        while (s2 == s1) {
            s2 = s1;
            s2 = sizeOf("../../компсети2/x64/Debug/fileM2.bin");
            
        }
        fin.read((char*)&student, sizeof(student));
        if (fin.gcount() != sizeof(student)) {
            //cerr << "Ошибка: Не удалось прочитать структуру Student из файла." << endl;
            fl = 0;
            fin.close();
            continue; // Переходим к следующей итерации
        }
        fin.close();

        int a = 0; // Локальная переменная
        for (int i = 0; i < 4; i++) {
            if (student.marks[i] == 4) a = 1;
            if (student.marks[i] == 3) {
                a = 2;
                break;
            }
        }

        ofstream fout("../../компсети3/x64/Debug/result2.bin", ios::binary | ios::out);
        fout.write((char*)&a, sizeof(a));
        fout.close();
        if(fl)
            cout << "сервер успешно обработал данные ученика с id=" <<student.surname << endl;
    }

    return 0;
}
//int main()
//{
//    setlocale(LC_ALL, "Ru");
//    Student student;
//    ifstream fin;
//
//    while (1) {
//
//        fin.open("../../компсети2/x64/Debug/fileM2.bin", ios::binary);
//        //fin.read((char*)&student, sizeof(student));
//        long s1 = sizeOf("../../компсети2/x64/Debug/fileM2.bin");
//        long s2 = s1;
//        if (!fin.is_open()) {
//            cerr << "Error: Could not open file " << endl;
//            break; // Выходим, если не удалось открыть файл
//        }
//        fin.read((char*)&student, sizeof(student));
//        while (s2 == s1) {
//            s2 = s1;
//            s2 = sizeOf("../../компсети2/x64/Debug/fileM2.bin");
//
//        }
//        cout << fin.gcount() << " " << sizeof(student) << endl;
//        if (fin.gcount() != sizeof(student)) {
//            cerr << "Ошибка: Не удалось прочитать структуру Student из файла." << endl;
//            fin.close(); // Обязательно закрываем файл в случае ошибки
//            continue;      // Переходим к следующей итерации цикла (или выходим из цикла)
//        }
//        cout << 1 << endl;
//        fin.close();
//        ofstream fout("../../компсети3/x64/Debug/result2.bin", ios::binary | ios::out);
//        a = 0;
//        for (int i = 0; i < 4; i++) {
//            if (student.marks[i] == 4) a = 1;
//            if (student.marks[i] == 3) {
//                a = 2;
//                break;
//            }
//
//        }
//        fout.write((char*)&a, sizeof(a));
//        fout.close();
//        ofstream ofs;
//        ofs.open("../../компсети2/x64/Debug/fileM2.bin", ios::out | ios::trunc);
//        ofs.close();
//    }
//}
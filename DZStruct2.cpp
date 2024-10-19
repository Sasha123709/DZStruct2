//#include <iostream>
//#include <vector>
//#include <Windows.h>
//using namespace std;
//struct Student {
//    string surname;
//    string group;
//    int ocinka[5];
//};
//
//vector<Student> students;
//void goodstudents() {
//    for (auto& student : students) {
//        int goodcount = 0;
//        for (int i = 0; i < 5; i++) {
//            if (student.ocinka[i] >= 4) {
//                goodcount++;
//            }
//        }
//        if (goodcount > 3) {
//            cout << student.surname << ' ' << student.group << endl;
//        }
//    }
//}
//void badstudents() {
//    
//    for (auto& student : students) {
//        int badcount = 0;
//        for (int i = 0; i < 5; i++) {
//            if (student.ocinka[i] <= 4) {
//                badcount++;
//            }
//        }
//        if (badcount > 2) {
//            cout << student.surname << ' ' << student.group << endl;
//        }
//        
//    }
//
//}
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    students.push_back({ "Петров", "П31-31", {1, 2, 1, 5} });
//    students.push_back({ "Стефанюк", "З12-31", {8, 7, 11, 9} });
//    students.push_back({ "Кирилюк", "Р21-41", {10, 9, 9, 10} });
//    students.push_back({ "Ревозан", "З23-31", {3, 1, 5, 3}});
//    students.push_back({ "Кагилюк", "Р21-21", {10, 9, 9, 10} });
//    cout << "Відмінники" << endl;
//    goodstudents();
//    cout << "Двієчники" << endl;
//    badstudents();
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <Windows.h>;
using namespace std;

struct Man {
    string surname;
    string name;
    int age;
    string birth;
};

vector<Man> people;

void sortman(bool sortbysur) {
    if (sortbysur) {
        sort(people.begin(), people.end(), [](const Man& a, const Man& b) {return a.surname < b.surname; });
    }
    else {
        sort(people.begin(), people.end(), [](const Man& a, const Man& b) {return a.name < b.name; });
    }

    for (auto& one : people) {
        cout << one.surname << ' ' << one.name << ' ' << one.age << ' ' << one.birth;
    }
}
void imennunnuku(int mon) {
    cout << "Іменинники:" << endl;
    
    for (auto& one : people) {
        int bithmon = stoi(one.birth.substr(3, 2));
        if (bithmon == mon) {
            cout << one.surname << ' ' << one.name << ' ' << one.age << ' ' << one.birth;
        }
       
    }
}
void search(string &sercht) {
    for (auto& one : people) {
        if (one.surname==sercht||one.name==sercht) {
            cout << one.surname << ' ' << one.name << ' ' << one.age << ' ' << one.birth;
            return;
        }
    }
    cout << "НЕ найдено" << endl;
}
void edit(string& surname, Man& update) {
    for (auto& one : people) {
        if (one.surname == surname) {
            one = update;
            return;
        }
    }
    cout << "НЕ найдено" << endl;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    people.push_back({ "Іванов", "Іван", 30 , "12.05.1992" });
    people.push_back({ "Петров", "Петро", 25, "15.03.1997" });
    people.push_back({ "Сидоров", "Адор", 35, "20.11.1987" });

    while (true) {  // Нескінченний цикл
        cout << "Виберіть дію:" << endl
            << "0) Вихід" << endl
            << "1) Сортувати через прізвище" << endl
            << "2) Сортувати через ім'я" << endl
            << "3) Іменинники за місяцем" << endl
            << "4) Пошук за прізвищем" << endl
            << "5) Редагування запису" << endl;

        int chosse = 0;
        cin >> chosse;

        if (chosse == 0) {
            cout << "Вихід з програми." << endl;
            break;  
        }

        switch (chosse)
        {
        case 1:
            sortman(true);
            break;
        case 2:
            sortman(false);
            break;
        case 3:
        {
            int month;
            cout << "Введіть місяць: ";
            cin >> month;
            imennunnuku(month);
            break;
        }
        case 4:
        {
            string name;
            cout << "Введіть прізвище або ім'я: ";
            cin >> name;
            search(name);
            break;
        }
        case 5:
        {
            string sur;
            cout << "Введіть прізвище для редагування: ";
            cin >> sur;

            
            string new_name, new_birth;
            int new_age;

            cout << "Введіть нове ім'я: ";
            cin >> new_name;

            cout << "Введіть новий вік: ";
            cin >> new_age;

            cout << "Введіть нову дату народження (dd.mm.yyyy): ";
            cin >> new_birth;

            
            Man updated_person = { sur, new_name, new_age, new_birth };

            
            edit(sur, updated_person);
            break;
        }
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            break;
        }

        cout << endl;  
    }

    return 0;
}

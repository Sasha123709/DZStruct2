#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
struct Student {
    string surname;
    string group;
    int ocinka[5];
};

vector<Student> students;
void goodstudents() {
    for (auto& student : students) {
        int goodcount = 0;
        for (int i = 0; i < 5; i++) {
            if (student.ocinka[i] >= 4) {
                goodcount++;
            }
        }
        if (goodcount > 3) {
            cout << student.surname << ' ' << student.group << endl;
        }
    }
}
void badstudents() {
    
    for (auto& student : students) {
        int badcount = 0;
        for (int i = 0; i < 5; i++) {
            if (student.ocinka[i] <= 4) {
                badcount++;
            }
        }
        if (badcount > 2) {
            cout << student.surname << ' ' << student.group << endl;
        }
        
    }

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    students.push_back({ "Петров", "П31-31", {1, 2, 1, 5} });
    students.push_back({ "Стефанюк", "З12-31", {8, 7, 11, 9} });
    students.push_back({ "Кирилюк", "Р21-41", {10, 9, 9, 10} });
    students.push_back({ "Ревозан", "З23-31", {3, 1, 5, 3}});
    students.push_back({ "Кагилюк", "Р21-21", {10, 9, 9, 10} });
    cout << "Відмінники" << endl;
    goodstudents();
    cout << "Двієчники" << endl;
    badstudents();
}
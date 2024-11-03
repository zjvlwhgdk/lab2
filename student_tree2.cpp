#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int midterm;
    int final;
};

int main() {
    int numStudents;
    cout << "학생 수를 입력하세요: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << (i + 1) << "번째 학생의 이름을 입력하세요: ";
        cin >> students[i].name;
        cout << students[i].name << "의 중간 점수를 입력하세요: ";
        cin >> students[i].midterm;
        cout << students[i].name << "의 기말 점수를 입력하세요: ";
        cin >> students[i].final;
    }

    cout << "\n학생들의 평균 점수:\n";
    for (int i = 0; i < numStudents; i++) {
        double average = (students[i].midterm + students[i].final) / 2.0;
        cout << "이름: " << students[i].name << ", 평균 점수: " << average << endl;
    }

    delete[] students;
    return 0;
}

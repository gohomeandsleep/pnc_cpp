#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;

class Student {
public:
    char* name;
    int age;
    char* city;
    Student() {}
    Student(const char* name, int age, const char* city);
    void swap(Student* b);
    void showStudent();
    ~Student(); // Destructor 추가
    int compareStudents(const Student* b);
    void updateStudentCity(const char* city);
};

void showStudents(string message, Student* students[], int numStudents) {
    //void showStudent();를 사용한 객체 출력
    cout << message << endl;
    for (int i = 0; i < numStudents; i++) {
        students[i]->showStudent();
    }
}

void Student::showStudent() {
    //printf("%s      |%d     |%s", name, age, city);
    printf("[%s, %d, %s]\n", name, age, city);
}


// Constructor 구현 - 오류 수정
Student::Student(const char* name, int age, const char* city) {
    this->name = _strdup(name);
    this->age = age;
    this->city = _strdup(city);

}

// Destructor 구현

Student::~Student() {
    delete[] name;
    delete[] city;
}

void Student::updateStudentCity(const char* newcity) {
    delete[] city;
    city = _strdup(newcity);
}
/*
int Student::compareStudents(const Student* b) {


}
void Student::swap(Student* b) {

}



void selectionSortStudents(Student* students[], int numStudents) {
    // int compareStudents(const Student* b);를 사용한 정렬

}
*/
int main() {
    // 학생 객체 초기화
    int numStudents = 5;

    Student* students[5] = {
    new Student("Hong", 11, "Pusan"),
    new Student("Song", 22, "Seoul"),
    new Student("Kong", 41, "Ulsan"),
    new Student("Jong", 97, "Gwangju"),
    new Student("Pong", 11, "Paju")
    };
    // 각 학생 정보 출력
    showStudents("Before Sort:", students, numStudents);

    students[0]->updateStudentCity("busan");
    students[0]->showStudent();
    /*
    selectionSortStudents(students, numStudents);
    showStudents("after sort", students, numStudents);
    */
    system("pause");
    return 0;
}
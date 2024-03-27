#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;

class Student {
public:
	//멤버 변수 
    const char* name;
    int age;
    const char* city;
    //생성자 
    Student() {}
    Student(const char* name, int age, const char* city);
    //소멸자
    ~Student(); // Destructor 추가
    //멤버 함수
    void swap(Student* b);
    void showStudent();
    int compareStudents(const Student* b);
    void updateStudentCity(const char* city);
};

void showStudents(string message, Student* students[], int numStudents) {
    //void showStudent();를 사용한 객체 출력
	cout << message << endl;
    for (int i = 0; i < numStudents; ++i) {
        students[i]->showStudent();
    }
}

void Student::showStudent() {
	printf("[%s, %d, %s]\n", name, age, city);
}

// Constructor 구현 - 오류 수정

Student::Student(const char* name, int age, const char* city) {
	this->name = _strdup(name);
    this->age = age;
    this->city = _strdup(city);
}

void Student::updateStudentCity(const char* newcity) {
	delete[] city;
	city = _strdup(newcity);
}

// Destructor 구현

Student::~Student() {
	delete[] name;
	delete[] city;
}

int Student::compareStudents(const Student* b) {
    return strcmp(this->name, b->name);
}


void selectionSortStudents(Student* students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numStudents; ++j) {
            if (students[j]->compareStudents(students[minIndex]) < 0) {
                minIndex = j;
            }
        }
        students[i]->swap(students[minIndex]);
    }
    // int compareStudents(const Student* b);를 사용한 정렬
}

void Student::swap(Student* b) {
    std::swap(name, b->name);
    std::swap(age, b->age);
    std::swap(city, b->city);
}

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
    
    students[0]->updateStudentCity("Busan");
    students[0]->showStudent();
    
    selectionSortStudents(students, numStudents);
    showStudents("After Sort", students, numStudents);
    
    system("pause");
    return 0;
}

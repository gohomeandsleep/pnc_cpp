#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;

class Student {
public:
	//��� ���� 
    const char* name;
    int age;
    const char* city;
    //������ 
    Student() {}
    Student(const char* name, int age, const char* city);
    //�Ҹ���
    ~Student(); // Destructor �߰�
    //��� �Լ�
    void swap(Student* b);
    void showStudent();
    int compareStudents(const Student* b);
    void updateStudentCity(const char* city);
};

void showStudents(string message, Student* students[], int numStudents) {
    //void showStudent();�� ����� ��ü ���
	cout << message << endl;
    for (int i = 0; i < numStudents; ++i) {
        students[i]->showStudent();
    }
}

void Student::showStudent() {
	printf("[%s, %d, %s]\n", name, age, city);
}

// Constructor ���� - ���� ����

Student::Student(const char* name, int age, const char* city) {
	this->name = _strdup(name);
    this->age = age;
    this->city = _strdup(city);
}

void Student::updateStudentCity(const char* newcity) {
	delete[] city;
	city = _strdup(newcity);
}

// Destructor ����

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
    // int compareStudents(const Student* b);�� ����� ����
}

void Student::swap(Student* b) {
    std::swap(name, b->name);
    std::swap(age, b->age);
    std::swap(city, b->city);
}

int main() {
    // �л� ��ü �ʱ�ȭ
    int numStudents = 5;

    Student* students[5] = {
		new Student("Hong", 11, "Pusan"),
		new Student("Song", 22, "Seoul"),
		new Student("Kong", 41, "Ulsan"),
		new Student("Jong", 97, "Gwangju"),
		new Student("Pong", 11, "Paju")
	};

    // �� �л� ���� ���
    showStudents("Before Sort:", students, numStudents);
    
    students[0]->updateStudentCity("Busan");
    students[0]->showStudent();
    
    selectionSortStudents(students, numStudents);
    showStudents("After Sort", students, numStudents);
    
    system("pause");
    return 0;
}

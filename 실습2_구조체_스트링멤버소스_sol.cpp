#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct Rectangle {
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;
    const char* name;
};

void showRectangle(struct Rectangle r) {
    printf("[%d, %d, %d, %d, %s]\n", r.leftBottomX, r.leftBottomY, r.width, r.height, r.name);
}

void showRectangles(string message, Rectangle* rectangles[], int numRectangles) {
	cout << message << endl;
    for (int i = 0; i < numRectangles; ++i) {
    	showRectangle(*rectangles[i]);
    }
}

void changeRectangle(Rectangle* r, const char* newName) {
    cout << "r1 name is changed" << endl;
    //r.name = newName;
    //strcpy(r.name, newName); //������ ���� ->����� r1�� �ٲ� �� ���� -> runtime error  
    //chatGPT:
	//name ��� ������ ���ڿ� ����� ����Ű�� �����ͷ� ����-> �� �����Ϳ� ���ο� ���ڿ��� ������ �� ����.
    r->name = _strdup(newName); //heap ������ �޸𸮸� �Ҵ��Ͽ� ������
}

int compareRectangles(const Rectangle* a, const Rectangle* b) {
    return (a->leftBottomX - b->leftBottomX);
}
/*
* �̸� ������ �����ϰ��� �ϸ�
int compareRectangles(const Rectangle* a, const Rectangle* b) {
    return strcmp(a->name, b->name);
}
*/


void swap(Rectangle* rect[], int i, int j) {
    Rectangle* temp = rect[i];
    rect[i] = rect[j];
    rect[j] = temp;
}

void selectionSortRectangles(Rectangle* rectangles[], int numRectangles) {
    for (int i = 0; i < numRectangles - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numRectangles; ++j) {
            if (compareRectangles(rectangles[j], rectangles[minIndex]) < 0) {
                minIndex = j;
            }
        }
        swap(rectangles, i, minIndex);
    }
}


int main(void) {
    const int numRectangles = 5;
    struct Rectangle r1 = { 3, 5, 10, 15,"e1" };
    struct Rectangle r2 = { 1, 2, 8, 12 ,"c2" };
    struct Rectangle r3 = { 7, 9, 6, 10,"a3" };
    struct Rectangle r4 = { 4, 6, 7, 8 ,"b4" };
    struct Rectangle r5 = { 2, 3, 9, 14,"5" };
    Rectangle* rectangles[numRectangles] = { &r1,&r2,&r3,&r4,&r5 };

    showRectangles("Before:", rectangles, numRectangles);
    changeRectangle(&r1, "square");
    printf("address of r1= %p, %p\n", &r1, rectangles[0]);
    showRectangle(r1);
    showRectangles("After changing:", rectangles, numRectangles);
    
    selectionSortRectangles(rectangles, numRectangles);

    showRectangles("After sorting:", rectangles, numRectangles);
	
    system("pause");
    return 0;
}

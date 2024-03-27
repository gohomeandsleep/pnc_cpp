#include <iostream>
#include <algorithm>
#include <string>
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

void changeRectangle(Rectangle* r, const char* newName) {
    cout << "r1 name is changed" << endl;
    // r.name = newName;
    // strcpy(r.name, newName);
    r->name = _strdup(newName);
}

void showRectangles(string message, Rectangle* rectangles[], int numRectangles) {
    //void showRectangle(struct Rectangle r) 사용
    cout << message << endl;
    for (int i = 0; i < numRectangles; i++) {
        showRectangle(*rectangles[i]);
    }
}
void swap(Rectangle* rect[], int i, int j) {
    Rectangle *temp = rect[i];
    rect[i] = rect[j];
    rect[j] = temp;

}
int compareRectangles(const Rectangle* a, const Rectangle* b) {
    //return strcmp(a->name, b->name); //문자로 비교할때 strcmp
    return (a->leftBottomX - b->leftBottomX); //숫자로 비교할때 단순 뺄셈
}

void selectionSortRectangles(Rectangle* rectangles[], int numRectangles) {
    // int compareRectangles(const Student* b);를 사용한 정렬
    // void swap(Rectangle * rect[], int i, int j) 사용
    for (int i = 0; i < numRectangles; i++) {
        int minindex = i;
        for (int j = i; j < numRectangles; j++) {
            if (compareRectangles(rectangles[j], rectangles[minindex]) < 0) {
                minindex = j;
            }
        }
        swap(rectangles[minindex], rectangles[i]);
    }
}



int main(void) {
    const int numRectangles = 5;
    struct Rectangle r1 = { 3, 5, 10, 15,"r1" };
    struct Rectangle r2 = { 1, 2, 8, 12 ,"r2" };
    struct Rectangle r3 = { 7, 9, 6, 10,"r3" };
    struct Rectangle r4 = { 4, 6, 7, 8 ,"r4" };
    struct Rectangle r5 = { 2, 3, 9, 14,"r5" };
    Rectangle* rectangles[numRectangles] = { &r1,&r2,&r3,&r4,&r5 };

    showRectangles("Before:", rectangles, numRectangles);
    changeRectangle(&r1, "square");
    printf("\naddress of r1= %p, %p\n", &r1, rectangles[0]);
    showRectangle(r1);
    showRectangles("After changing:", rectangles, numRectangles);
    selectionSortRectangles(rectangles, numRectangles);

    showRectangles("After sorting:", rectangles, numRectangles);
    

    system("pause");
    return 0;
}
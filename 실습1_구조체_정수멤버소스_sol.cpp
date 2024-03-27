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
};

void showRectangle(struct Rectangle r) {
    printf("[%d, %d, %d, %d]\n", r.leftBottomX, r.leftBottomY, r.width, r.height);
}

void showRectangles(string message, Rectangle* rectangles[], int numRectangles) {
 cout << message << endl;
    for (int i = 0; i < numRectangles; ++i) {
    	showRectangle(*rectangles[i]);
    }
}

int compareRectangles(const Rectangle* a, const Rectangle* b) {
    return (a->leftBottomX - b->leftBottomX);
}

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
    struct Rectangle r1 = { 3, 5, 10, 15 };
    struct Rectangle r2 = { 1, 2, 8, 12 };
    struct Rectangle r3 = { 7, 9, 6, 10 };
    struct Rectangle r4 = { 4, 6, 7, 8 };
    struct Rectangle r5 = { 2, 3, 9, 14 };
    Rectangle* rectangles[numRectangles] = { &r1,&r2,&r3,&r4,&r5 };

    showRectangles("Before:", rectangles, numRectangles);
	
    selectionSortRectangles(rectangles, numRectangles);
	
    showRectangles("After:", rectangles, numRectangles);
    
    system("pause");
    return 0;
}

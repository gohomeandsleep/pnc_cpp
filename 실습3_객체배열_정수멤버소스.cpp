#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib> // 

using namespace std;

class Rectangle {
public:
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;

    Rectangle(int x, int y, int w, int h) :
        leftBottomX(x), leftBottomY(y), width(w), height(h) {}
    void showRectangle();
    int compareRectangles(const Rectangle* b);
    void swap(Rectangle* b);
};

void Rectangle::showRectangle() {
    printf("[%d, %d, %d, %d]\n", leftBottomX, leftBottomY, width, height);
}

void showRectangles(string message, Rectangle* rectangles[], int numRectangles) {
    //void showRectangle(); 사용
    cout << message << endl;
    for (int i = 0; i < numRectangles; i++) {
        rectangles[i]->showRectangle();
    }
}

int Rectangle::compareRectangles(const Rectangle* b) {
    return (this->leftBottomX - b->leftBottomX);
}
void Rectangle::swap(Rectangle* b) {
    std::swap(leftBottomX, b->leftBottomX);
    std::swap(leftBottomY, b->leftBottomY);
    std::swap(width , b->width);
    std::swap(height, b->height);
}

void selectionSortRectangles(Rectangle* rectangles[], int numRectangles) {
    // int compareRectangles(const Rectangle* b);를 사용한 정렬
    // void Rectangle::swap(Rectangle* b) 사용 
    for (int i = 0; i < numRectangles; i++) {
        int minindex = i;
        for (int j = i; j < numRectangles; j++) {
            if (rectangles[j]->compareRectangles(rectangles[minindex]) < 0) {
                minindex = j;
            }
            
        }
        if (minindex != i) {
            rectangles[i]->swap(rectangles[minindex]);
        }
    }
}

int main(void) {
    const int numRectangles = 5;
    Rectangle* rectangles[numRectangles] = {
        new Rectangle(3, 5, 10, 15),
        new Rectangle(1, 2, 8, 12),
        new Rectangle(7, 9, 6, 10),
        new Rectangle(4, 6, 7, 8),
        new Rectangle(2, 3, 9, 14)
    };

    showRectangles("Before:", rectangles, numRectangles);
    
    selectionSortRectangles(rectangles, numRectangles);

    showRectangles("After:", rectangles, numRectangles);

    for (int i = 0; i < numRectangles; ++i) {
        delete rectangles[i];
    }
    
    system("pause");
    return 0;
}
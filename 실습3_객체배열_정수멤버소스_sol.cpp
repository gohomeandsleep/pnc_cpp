#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib> 

using namespace std;

class Rectangle {
public:
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;

    Rectangle(int x, int y, int w, int h) :
        leftBottomX(x), leftBottomY(y), width(w), height(h) {}
    /* 아래 표현을 간단히 적은 것 
	Rectangle(int x, int y, int w, int h)
	{
        leftBottomX = x;
		leftBottomY = y;
		width = w;
		height = h;	
	}
	*/
    void showRectangle();
    int compareRectangles(const Rectangle* b);
    void swap(Rectangle* b);
};

void Rectangle::showRectangle() {
    printf("[%d, %d, %d, %d]\n", leftBottomX, leftBottomY, width, height);
}

void showRectangles(string message, Rectangle* rectangles[], int numRectangles) {
    cout << message << endl;
    for (int i = 0; i < numRectangles; ++i) {
        rectangles[i]->showRectangle();
    }
}

void selectionSortRectangles(Rectangle* rectangles[], int numRectangles) {
	for (int i = 0; i < numRectangles - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numRectangles; ++j) {
            if (rectangles[j]->compareRectangles(rectangles[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            rectangles[i]->swap(rectangles[minIndex]);
        }
    }
}

int Rectangle::compareRectangles(const Rectangle* b) {
    return (this->leftBottomX - b->leftBottomX);
}

void Rectangle::swap(Rectangle* b) {
    std::swap(leftBottomX, b->leftBottomX);
    std::swap(leftBottomY, b->leftBottomY);
    std::swap(width, b->width);
    std::swap(height, b->height);
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

#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void boundaryFill(int x, int y, int fillColor, int borderColor) {
    if (getpixel(x, y) != borderColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill(x + 1, y, fillColor, borderColor);
        boundaryFill(x - 1, y, fillColor, borderColor);
        boundaryFill(x, y + 1, fillColor, borderColor);
        boundaryFill(x, y - 1, fillColor, borderColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the rectangle
    rectangle(100, 100, 300, 200);
    floodfill(200, 150, WHITE); // Fill the rectangle with a white border

    // Apply boundary fill to the rectangle
    boundaryFill(150, 150, RED, WHITE); // Fill with red color

    getch();
    closegraph();
    return 0;
}
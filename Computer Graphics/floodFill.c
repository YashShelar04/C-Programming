#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void floodFill(int x, int y, int fillColor, int oldColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, oldColor);
        floodFill(x - 1, y, fillColor, oldColor);
        floodFill(x, y + 1, fillColor, oldColor);
        floodFill(x, y - 1, fillColor, oldColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the triangle
    line(100, 200, 300, 200); // Base
    line(100, 200, 200, 100); // Left side
    line(300, 200, 200, 100); // Right side

    delay(1000); // Delay to visualize the triangle before filling

    // Apply flood fill to the triangle
    floodFill(200, 150, GREEN, BLACK); // Fill with green color

    getch();
    closegraph();
    return 0;
}

#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

const double PI = 3.14159265358979323846;

void drawStar(int x, int y, int size, int color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, size, size);
    
    // Draw glow
    for(int i = 1; i <= 5; i++) {
        setcolor(COLOR(RED_VALUE(color)/i, GREEN_VALUE(color)/i, BLUE_VALUE(color)/i));
        circle(x, y, size + i*2);
    }
}

void drawBackground() {
    // Draw space background
    setfillstyle(SOLID_FILL, BLACK);
    bar(0, 0, getmaxx(), getmaxy());
    
    // Draw some stars
    for(int i = 0; i < 100; i++) {
        putpixel(rand() % getmaxx(), rand() % getmaxy(), WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    int x = getmaxx() / 2, y = getmaxy() / 2;
    int size = 5;
    int color = YELLOW;
    
    // Protostar to Main Sequence
    for (int i = 0; i < 100; i++) {
        drawBackground();
        drawStar(x, y, size, color);
        size += 1;  // Scale transformation
        delay(50);
        if(i == 99) {
            outtextxy(x - 60, y + 60, "Main Sequence Star");
            delay(1000);
        }
    }
    
    // Main Sequence to Red Giant
    for (int i = 0; i < 100; i++) {
        drawBackground();
        color = COLOR(255, 255 - i*2, 0);  // Transition to red
        drawStar(x, y, size, color);
        size += 1;  // Scale transformation
        delay(50);
        if(i == 99) {
            outtextxy(x - 40, y + 100, "Red Giant");
            delay(1000);
        }
    }
    
    // Supernova
    for (int i = 0; i < 50; i++) {
        drawBackground();
        for (int j = 0; j < 20; j++) {
            int explosion_x = x + rand() % 400 - 200;
            int explosion_y = y + rand() % 400 - 200;
            int explosion_size = rand() % 10 + 5;
            drawStar(explosion_x, explosion_y, explosion_size, YELLOW);
        }
        outtextxy(x - 30, y + 150, "Supernova");
        delay(100);
    }
    
    // Neutron Star
    size = 3;
    color = WHITE;
    double angle = 0;
    for (int i = 0; i < 200; i++) {
        drawBackground();
        // Rotate transformation
        int new_x = x + cos(angle) * 20;
        int new_y = y + sin(angle) * 20;
        drawStar(new_x, new_y, size, color);
        angle += 0.1;  // Rotate
        delay(50);
        if(i == 199) {
            outtextxy(x - 40, y + 30, "Neutron Star");
            delay(1000);
        }
    }
    
    getch();
    closegraph();
    return 0;
}

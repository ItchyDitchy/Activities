#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

void gotoxy(short x, short y) {
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) {x, y});
}

void draw(int maxX, int maxY, int delay) {
  int x = 1, y = 1, minX = 1, minY = 1;

  while (minX < maxX && minY < maxY) {
    maxX--; 
    while (x < maxX && minX < maxX && minY < maxY) {
      gotoxy(++x, y);
      printf(".");
      Sleep(delay);
    }

    maxY--;
    while (y < maxY && minX < maxX && minY < maxY) {
      gotoxy(x, ++y);
      printf("-");
      Sleep(delay);
    }

    minX++;
    while (x > minX && minX < maxX && minY < maxY) {
      gotoxy(--x, y);
      printf("+");
      Sleep(delay);
    }

    minY++;
    while (y > minY && minX < maxX && minY < maxY) {
      gotoxy(x, --y);
      printf("#");
      Sleep(delay);
    }
  }
}

int main() {
  system("cls");
  draw(20, 30, 1);
  getch();
  return 0;
}


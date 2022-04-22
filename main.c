#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

int width = 60, height = 30;
int inputX = 0, inputY = 0;
int snakeX = 0, snakeY = 0;
int fruitX = 0, fruitY = 0;
int score = 0, increment = 10;
bool gameOver = false;

void start();
void input();
void update();
void render();

int main()
{
    start();
    while (gameOver == false)
    {
        input();
        if (inputX != 0 || inputY != 0)
        {
            update();
            render();
        }
    }
    return 0;
}

void start()
{
    snakeX = width / 2;
    snakeY = height / 2;
    fruitX = rand() % 60;
    fruitY = rand() % 30;
}

void input()
{
    inputX = 0;
    inputY = 0;
    if (kbhit())
    {
        switch (getch())
        {
            case 'a':
                inputX = -1;
                break;
            case 'd':
                inputX = 1;
                break;
            case 'w':
                inputY = -1;
                break;
            case 's':
                inputY = 1;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void update()
{
    Sleep(16);
    snakeX += inputX;
    snakeY += inputY;
    if (snakeX < 0 || snakeX > width || snakeY < 0 || snakeY > height)
    {
        gameOver = true;
    }
    else if (snakeX == fruitX && snakeY == fruitY)
    {   
        fruitX = rand() % 60;
        fruitY = rand() % 30;
        score += increment;
    }
}

void render()
{
    system("cls");
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if ((y == 0 || y == height - 1) || (x == 0 || x == width - 1))
                printf("#");
            else if (x == snakeX && y == snakeY)
                printf("O");
            else if (x == fruitX && y == fruitY)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

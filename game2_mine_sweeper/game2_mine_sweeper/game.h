#pragma once
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

void game();
void InitBoard(char board[ROWS][COLS], int rows, int cols, char);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void ClearBuffer();
int GetMineCount(char board[ROWS][COLS], int x, int y);

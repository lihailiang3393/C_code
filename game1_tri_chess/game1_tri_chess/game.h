#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

// 展示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

// 判断输赢
char IsWin(char board[ROW][COL], int row, int col);

// 判断满不满
int IsFull(char board[ROW][COL], int row, int col);


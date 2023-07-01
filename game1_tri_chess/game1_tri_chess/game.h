#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

// ��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

// չʾ����
void DisplayBoard(char board[ROW][COL], int row, int col);

// �������
void PlayerMove(char board[ROW][COL], int row, int col);

// ��������
void ComputerMove(char board[ROW][COL], int row, int col);

// �ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);

// �ж�������
int IsFull(char board[ROW][COL], int row, int col);


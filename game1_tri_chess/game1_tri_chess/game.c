#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0, j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
		
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0, j = 0;
	char str[4 * COL + 1] = { '\0' };
	for (i = 0; i < 4 * COL; i++) {
		str[i] = '-';
	}
	for (i = 1; i < col; i++) {
		str[4 * i - 1] = '|';
	}
	str[4 * col - 1] = '\n';
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
			printf("%s", str);
	}	
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家下棋：>\n");
	while (true)
	{
		printf("请输入坐标：>");
		scanf("%d %d", &x, &y);
		getchar();
		if (x >= 1 && x <= row && y >= 1 && y << col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占用，不能下棋，请选择其他位置\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋：>\n");
	int x = 0, y = 0;
	Sleep(2000);
	while (true)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	// 行
	for (i = 0; i < row; i++) {
		for (j = 1; j < col; j++) if (board[i][0] != board[i][j])break;
		if (j == col && board[i][0] != ' ') return board[i][0];
	}
	// 列
	for (j = 0; j < col; j++) {
		for (i = 1; i < row; i++) if (board[0][j] != board[i][j]) break;
		if (i == row && board[0][j] != ' ') return board[0][j];
	}
	// 对角线
	for (i = 1; i < row; i++) if (board[0][0] != board[i][i])break;
	if (i == row && board[0][0] != ' ') return board[0][0];
	for (i = 1; i < row; i++) if (board[row - 1][0] != board[row - i - 1][i])break;
	if (i == row && board[row - 1][0] != ' ') return board[row - 1][0];
	// 没有人赢，就要平局
	if (IsFull(board, ROW, COL)) {
		return 'Q';
	}
	return 'C';
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (board[i][j] == ' ')
				return false;
	return true;
}
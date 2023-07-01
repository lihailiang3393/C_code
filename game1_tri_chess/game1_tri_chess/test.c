#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu() {
	printf("*******************\n");
	printf("***** 1. play *****\n");
	printf("***** 0. exit *****\n");
	printf("*******************\n");
}

void game() {
	char ret = ' ';
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (true)
	{
		PlayerMove(board, ROW, COL);
		system("cls");
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')break;
		DisplayBoard(board, ROW,COL);
		ComputerMove(board, ROW, COL);
		system("cls");
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')break;
		DisplayBoard(board, ROW, COL);
	}
	switch (ret)
	{
	case '*':
		printf("玩家赢\n");
		break;
	case '#':
		printf("电脑赢\n");
		break;
	default:
		printf("平局\n");
		break;
	}
	DisplayBoard(board, ROW, COL);
}

int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
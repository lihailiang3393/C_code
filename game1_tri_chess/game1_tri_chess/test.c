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
		printf("���Ӯ\n");
		break;
	case '#':
		printf("����Ӯ\n");
		break;
	default:
		printf("ƽ��\n");
		break;
	}
	DisplayBoard(board, ROW, COL);
}

int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
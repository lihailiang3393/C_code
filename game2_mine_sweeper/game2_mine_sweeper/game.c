#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game()
{
	printf("����������\n");
	char mine[ROWS][COLS] = { '\0' }; // ��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { '\0' }; // ����Ų�����׵���Ϣ
	// ��ʼ�����������Ϊָ��������
	// mine ������û�в����׵�ʱ�򣬶���'0'
	InitBoard(mine, ROWS, COLS, '0');
	// show ������û���Ų��׵�ʱ�򣬶���'*'
	InitBoard(show, ROWS, COLS, '*');
	// ������
	SetMine(mine, ROW, COL);
	// �Ų���
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char full)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			board[i][j] = full;	
}

void DisplayBoard1(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	char str[4 * COL + 4] = { '|' };
	char str1[4 * COL + 4] = { '-' };
	for (i = 1; i <= 4 * COL + 1; i++) {
		str[i] = '-';
		str1[i] = '-';
	}
	for (i = 1; i <= COL; i++) {
		str[4 * i] = '|';
	}
	str1[4 * COL + 1] = '\n';
	str[4 * COL + 1] = '\n';
	char str2[] = "---------------ɨ����Ϸ---------------\n";
	printf("%s", str2);
	printf("%s", str1);
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		if (i < row) {
			printf("%s", str);
		}

	}
	printf("%s", str1);
	printf("%s", str2);
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	char str2[] = "---------------ɨ����Ϸ---------------\n";
	printf("%s", str2);
	for (i = 0; i <= row; i++) {
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf(" %d ", i);
		for (j = 1; j <= col; j++) {
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("%s", str2);
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1, y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0, win = 0;
	while (true)
	{
		printf("������Ҫ�Ų�����꣺>");
		scanf("%d %d", &x, &y);
		ClearBuffer();
		system("cls");
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (show[x][y] != '*') {
				printf("���λ�ñ��Ų���ˣ��������\n");
				DisplayBoard(show, ROW, COL);
				continue;
			}
			if (mine[x][y] == '1') {
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				win++;
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("���������Ƿ�������������\n");
			DisplayBoard(show, ROW, COL);
		}

		if (win == row * col - EASY_COUNT) {
			printf("��ϲ�㣬���׳ɹ�\n");
			DisplayBoard(mine, ROW, COL);
			break;
		}
	}
}

void ClearBuffer()
{
	char ch=' ';
	while ((ch = getchar()) != '\n');
}

int GetMineCount(char board[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	int sum = 0;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			sum += board[x + i][y + j];
		}
	}
	return sum - 9 * '0';
}


// ����������ʵ��
// 1.��ǹ���
// 2.չ��һƬ����
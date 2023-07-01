#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu() {
	printf("*******************\n");
	printf("***** 1. play *****\n");
	printf("***** 0. exit *****\n");
	printf("*******************\n");
}


int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("ÇëÑ¡Ôñ£º>");
		scanf("%d", &input);
		ClearBuffer();
		system("cls");
		switch (input)
		{
		case 1:
			printf("É¨À×\n");
			game();
			break;
		case 0:
			printf("ÍË³öÓÎÏ·\n");
			break;
		default:
			printf("Ñ¡Ôñ´íÎó\n");
			break;
		}
	} while (input);
	return 0;
}
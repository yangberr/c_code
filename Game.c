#include "game.h"

void InitBorad(char borad[ROW][COL],int row,int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			borad[i][j] = ' ';

		}

	}

}

void DisplayBorad(char borad[ROW][COL], int row, int col) {

	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", borad[i][j]);
			if (j < row -1)
			printf("|");

		}
		printf("\n");
		if (i < row - 1) {
			for (int i = 0; i < row; i++) {
				printf("---");
				if (i < row - 1)
					printf("|");
			}
		
		}
		printf("\n");

	}

}

int IsFull(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (borad[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
void PlayerMove(char borad[ROW][COL], int row, int col) {

	int i = 0;
	int j = 0;
	printf("玩家走>\n");
	printf("请输入坐标>\n");
	while (1) {
		scanf("%d%d", &i, &j);
		if (i > 0 && i <= row && j>0 && j <= col) {

			if (borad[i - 1][j - 1] == ' ') {

				borad[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已有棋子，请重新选择>\n");
			}

		}
		else
		{
			printf("输入坐标非法，请重新输入>\n");
		}

	}
	
}

void ComputerMove(char borad[ROW][COL], int row, int col) {

	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1) {
		_sleep(10);
		x = rand() % row;
		y = rand() % col;
		if (borad[x-1][y-1] == ' ') {
			borad[x - 1][y - 1] = '-';
			break;
		}

	}
	
}
char IsWin(char borad[ROW][COL], int row, int col) {

	int i = 0;
	for (i = 0 ; i < row; i++) 
	{
		if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][1] != ' ')
		{
			return borad[i][1];
		}

	}
	for (i = 0; i < col; i++) 
	{
		if (borad[0][i] == borad[1][i] && borad[1][i] == borad[2][i] && borad[1][i] != ' ')
		{
			return borad[1][i];
		}

	}
	
	if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[0][0] != ' ') 
	{
		return borad[1][1];
	}
	if (borad[0][2] == borad[1][1] && borad[1][1] == borad[2][0] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}

	if (1 == IsFull(borad, ROW, COL)) 
	{
		return 'Q';
	}
	return 'C';
}

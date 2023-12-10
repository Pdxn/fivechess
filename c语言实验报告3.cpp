#include <stdio.h>
#define size 9

char fivechess[size][size];

///棋盘的初始轮廓
void fivechesscontour() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fivechess[i][j] = ' ';
		}
	}
}

///棋盘的列标和行标
void drawfivechess() {
	printf("  ");
	for (int col = 0; col < size; col++) {
		printf("%2d", col + 1);///col表示列
	}
	printf("\n");

	for (int row = 0; row < size; row++) {
		printf("%2d", row + 1);///row表示行
		for (int col = 0; col < size; col++) {
			printf("%2c", fivechess[row][col]);
		}
		printf("\n");
	}
}

void move(char player, int row, int col ) {
	if (row >= 0 && row < size && col >= 0 && col < size && fivechess[row][col] == ' ') {
		fivechess[row][col] = player;
	} else {
		printf("您输入的位置不恰当，请重新输入\n");
	}
}

///检查是否有五个子连在一起

///行
int ifwin(char player, int row, int col) {
	///int num = 0;
	for (int i = 0; i < size; i++) {
		/*if (fivechess[row][i] == player) {
			num += 1;
			if (num == 5) {
				return 1;
			}
		} else {
			num = 0;
		}*/
		if (i + 4 < size) {
			if (fivechess[row][i] == fivechess[row][i + 1]
			        && fivechess[row][i + 1] == fivechess[row][i + 2]
			        && fivechess[row][i + 2] == fivechess[row][i + 3]
			        && fivechess[row][i + 3] == fivechess[row][i + 4]) {
				return 1;
			}
		}
	}
///列
	///num = 0;
	for (int i = 0; i < size; i++) {
		/*if (fivechess[i][col] == player) {
			num += 1;
			if (num == 5) {
				return 1;
			}
		} else {
			num = 0;
		}*/
		if (i + 4 < size) {
			if (fivechess[i][col] == fivechess[i + 1][col]
			        && fivechess[i + 1][col] == fivechess[i + 2][col]
			        && fivechess[i + 2][col] == fivechess[i + 3][col]
			        && fivechess[i + 3][col] == fivechess[i + 4][col]) {
				return 1;
			}
		}
	}
///从左上到右下
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i + 4 < size && j + 4 < size) {
				if (fivechess[i][j] == fivechess[i + 1][j + 1]
				        && fivechess[i + 1][j + 1] == fivechess[i + 2][j + 2]
				        && fivechess[i + 2][j + 2] == fivechess[i + 3][j + 3]
				        && fivechess[i + 3][j + 3] == fivechess[i + 4][j + 4]) {
					return 1;
				}
			}
		}
	}
///从左下到右上
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i - 4 > 0 && j + 4 < size) {
				if (fivechess[i][j] == fivechess[i - 1][j + 1]
				        && fivechess[i - 1][j + 1] == fivechess[i - 2][j + 2]
				        && fivechess[i - 2][j + 2] == fivechess[i - 3][j + 3]
				        && fivechess[i - 3][j + 3] == fivechess[i - 4][j + 4]) {
					return 1;
				}
			}
		}

	}
	return 0;
}


int main() {
	fivechesscontour();
	drawfivechess();
	int player = 'x';
	int row, col;
	while (1) {
		printf("玩家%c,请输入您落子的位置（行 列）:\n", player);
		scanf("%d%d", &row, &col);
		row -= 1;
		col -= 1;
		move(player, row, col);
		if (ifwin(player, row, col)) {
			drawfivechess();
			printf("玩家%c胜利", player);
			break;
		}
		player = (player == 'x') ? 'o' : 'x';
	}
	return 0;
}

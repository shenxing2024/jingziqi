#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
char a[3][3];
void start();
void welcome();
void initialization();
void printcheckerboard();
int ischeckerboardfull();
char winorlose();
void playerplacement();
int pdwzd();
int pdwzt();
void dnlzh();
void dnlze();
void zlzw(int b);
void computermasterplacement(int b);
void pos(int x, int y);
int main() {
	start();
	return 0;
}
void welcome() {
	system("mode con cols=108 lines=32");
	system("cls");
	pos(41, 6);
	printf("welcome come to tic tac toe!\n");
	pos(41, 8);
	printf("****************************\n");
	pos(41, 9);
	printf("********   1.easy   ********\n");
	pos(41, 10);
	printf("********   2.hard   ********\n");
	pos(41, 11);
	printf("********   3.exit   ********\n");
	pos(41, 12);
	printf("****************************\n");
}
void initialization() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			a[i][j] = ' ';
		}
	}
}
void printcheckerboard() {
	for (int i = 0; i <= 2; i++) {
		printf("              +---+---+---+\n");
		printf("              | %c | %c | %c |\n", a[i][0], a[i][1], a[i][2]);
	}
	printf("              +---+---+---+\n");
}
int ischeckerboardfull() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (a[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
char winorlose() {
	if ((a[0][0] == '*' && a[0][1] == '*' && a[0][2] == '*') || (a[1][0] == '*' && a[1][1] == '*' && a[1][2] == '*') || (a[2][0] == '*' && a[2][1] == '*' && a[2][2] == '*') || (a[0][0] == '*' && a[1][0] == '*' && a[2][0] == '*') || (a[0][1] == '*' && a[1][1] == '*' && a[2][1] == '*') || (a[0][2] == '*' && a[1][2] == '*' && a[2][2] == '*') || (a[0][0] == '*' && a[1][1] == '*' && a[2][2] == '*') || (a[0][2] == '*' && a[1][1] == '*' && a[2][0] == '*')) {
		return '*';
	}
	if ((a[0][0] == '#' && a[0][1] == '#' && a[0][2] == '#') || (a[1][0] == '#' && a[1][1] == '#' && a[1][2] == '#') || (a[2][0] == '#' && a[2][1] == '#' && a[2][2] == '#') || (a[0][0] == '#' && a[1][0] == '#' && a[2][0] == '#') || (a[0][1] == '#' && a[1][1] == '#' && a[2][1] == '#') || (a[0][2] == '#' && a[1][2] == '#' && a[2][2] == '#') || (a[0][0] == '#' && a[1][1] == '#' && a[2][2] == '#') || (a[0][2] == '#' && a[1][1] == '#' && a[2][0] == '#')) {
		return '#';
	}
	if (ischeckerboardfull() == 0) {
		return '-';
	} else {
		return '+';
	}
}
void playerplacement() {
	int x, y;
	while (1) {
		scanf("%d%d", &x, &y);
		if (x <= 2 && x >= 0 && y <= 2 && y >= 0) {
			if (a[x][y] == ' ') {
				a[x][y] = '*';
				break;
			} else {
				printf("This position is already occupied!\n");
			}
		} else {
			printf("The position you entered exceeds the limit!\n");
		}
	}
}
int pdwzd() {
	/*
	* 1 2 3
	* 4 5 6
	* 7 8 9
	*/
	int b = 0, d = 0, e = 0;
	//1 2
	if (a[0][0] == '#' && a[0][1] == '#' && a[0][2] == ' ') {
		d = 0;
		e = 2;
		b++;
	}
	//3 2
	if (a[0][2] == '#' && a[0][1] == '#' && a[0][0] == ' ') {
		d = 0;
		e = 0;
		b++;
	}
	//1 3
	if (a[0][0] == '#' && a[0][2] == '#' && a[0][1] == ' ') {
		d = 0;
		e = 1;
		b++;
	}
	//4 5
	if (a[1][0] == '#' && a[1][1] == '#' && a[1][2] == ' ') {
		d = 1;
		e = 2;
		b++;
	}
	//6 5
	if (a[1][2] == '#' && a[1][1] == '#' && a[1][0] == ' ') {
		d = 1;
		e = 0;
		b++;
	}
	//6 4
	if (a[1][2] == '#' && a[1][0] == '#' && a[1][1] == ' ') {
		d = 1;
		e = 1;
		b++;
	}
	//7 8
	if (a[2][0] == '#' && a[2][1] == '#' && a[2][2] == ' ') {
		d = 2;
		e = 2;
		b++;
	}
	//9 8
	if (a[2][2] == '#' && a[2][1] == '#' && a[2][0] == ' ') {
		d = 2;
		e = 0;
		b++;
	}
	//9 7
	if (a[2][2] == '#' && a[2][0] == '#' && a[2][1] == ' ') {
		d = 2;
		e = 1;
		b++;
	}
	//1 4
	if (a[0][0] == '#' && a[1][0] == '#' && a[2][0] == ' ') {
		d = 2;
		e = 0;
		b++;
	}
	//4 7
	if (a[1][0] == '#' && a[2][0] == '#' && a[0][0] == ' ') {
		d = 0;
		e = 0;
		b++;
	}
	//1 7
	if (a[0][0] == '#' && a[2][0] == '#' && a[1][0] == ' ') {
		d = 1;
		e = 0;
		b++;
	}
	//2 5
	if (a[0][1] == '#' && a[1][1] == '#' && a[2][1] == ' ') {
		d = 2;
		e = 1;
		b++;
	}
	//5 8
	if (a[1][1] == '#' && a[2][1] == '#' && a[0][1] == ' ') {
		d = 0;
		e = 1;
		b++;
	}
	//2 8
	if (a[0][1] == '#' && a[2][1] == '#' && a[1][1] == ' ') {
		d = 1;
		e = 1;
		b++;
	}
	//3 6
	if (a[0][2] == '#' && a[1][2] == '#' && a[2][2] == ' ') {
		d = 2;
		e = 2;
		b++;
	}
	//6 9
	if (a[1][2] == '#' && a[2][2] == '#' && a[0][2] == ' ') {
		d = 0;
		e = 2;
		b++;
	}
	//3 9
	if (a[0][2] == '#' && a[2][2] == '#' && a[1][2] == ' ') {
		d = 1;
		e = 2;
		b++;
	}
	//1 5
	if (a[0][0] == '#' && a[1][1] == '#' && a[2][2] == ' ') {
		d = 2;
		e = 2;
		b++;
	}
	//9 5
	if (a[2][2] == '#' && a[1][1] == '#' && a[0][0] == ' ') {
		d = 0;
		e = 0;
		b++;
	}
	//1 9
	if (a[0][0] == '#' && a[2][2] == '#' && a[1][1] == ' ') {
		d = 1;
		e = 1;
		b++;
	}
	//3 5
	if (a[0][2] == '#' && a[1][1] == '#' && a[2][0] == ' ') {
		d = 2;
		e = 0;
		b++;
	}
	//7 5
	if (a[2][0] == '#' && a[1][1] == '#' && a[0][2] == ' ') {
		d = 0;
		e = 2;
		b++;
	}
	//3 7
	if (a[0][2] == '#' && a[2][0] == '#' && a[1][1] == ' ') {
		d = 1;
		e = 1;
		b++;
	}
	if (b != 0) {
		a[d][e] = '#';
		return 1;
	} else {
		return 0;
	}
}
int pdwzt() {
	/*
	* 1 2 3
	* 4 5 6
	* 7 8 9
	*/
	int b = 0, d = 0, e = 0;
	//1 2
	if (a[0][0] == '*' && a[0][1] == '*' && a[0][2] == ' ') {
		d = 0;
		e = 2;
		b++;
	}
	//3 2
	if (a[0][2] == '*' && a[0][1] == '*' && a[0][0] == ' ') {
		d = 0;
		e = 0;
		b++;
	}
	//1 3
	if (a[0][0] == '*' && a[0][2] == '*' && a[0][1] == ' ') {
		d = 0;
		e = 1;
		b++;
	}
	//4 5
	if (a[1][0] == '*' && a[1][1] == '*' && a[1][2] == ' ') {
		d = 1;
		e = 2;
		b++;
	}
	//6 5
	if (a[1][2] == '*' && a[1][1] == '*' && a[1][0] == ' ') {
		d = 1;
		e = 0;
		b++;
	}
	//6 4
	if (a[1][2] == '*' && a[1][0] == '*' && a[1][1] == ' ') {
		d = 1;
		e = 1;
		b++;
	}
	//7 8
	if (a[2][0] == '*' && a[2][1] == '*' && a[2][2] == ' ') {
		d = 2;
		e = 2;
		b++;
	}
	//9 8
	if (a[2][2] == '*' && a[2][1] == '*' && a[2][0] == ' ') {
		d = 2;
		e = 0;
		b++;
	}
	//9 7
	if (a[2][2] == '*' && a[2][0] == '*' && a[2][1] == ' ') {
		d = 2;
		e = 1;
		b++;
	}
	//1 4
	if (a[0][0] == '*' && a[1][0] == '*' && a[2][0] == ' ') {
		d = 2;
		e = 0;
		b++;
	}
	//4 7
	if (a[1][0] == '*' && a[2][0] == '*' && a[0][0] == ' ') {
		d = 0;
		e = 0;
		b++;
	}
	//1 7
	if (a[0][0] == '*' && a[2][0] == '*' && a[1][0] == ' ') {
		d = 1;
		e = 0;
		b++;
	}
	//2 5
	if (a[0][1] == '*' && a[1][1] == '*' && a[2][1] == ' ') {
		d = 2;
		e = 1;
		b++;
	}
	//5 8
	if (a[1][1] == '*' && a[2][1] == '*' && a[0][1] == ' ') {
		d = 0;
		e = 1;
		b++;
	}
	//2 8
	if (a[0][1] == '*' && a[2][1] == '*' && a[1][1] == ' ') {
		d = 1;
		e = 1;
		b++;
	}
	//3 6
	if (a[0][2] == '*' && a[1][2] == '*' && a[2][2] == ' ') {
		d = 2;
		e = 2;
		b++;
	}
	//6 9
	if (a[1][2] == '*' && a[2][2] == '*' && a[0][2] == ' ') {
		d = 0;
		e = 2;
		b++;
	}
	//3 9
	if (a[0][2] == '*' && a[2][2] == '*' && a[1][2] == ' ') {
		d = 1;
		e = 2;
		b++;
	}
	//1 5
	if (a[0][0] == '*' && a[1][1] == '*' && a[2][2] == ' ') {
		d = 2;
		e = 2;
		b++;
	}
	//9 5
	if (a[2][2] == '*' && a[1][1] == '*' && a[0][0] == ' ') {
		d = 0;
		e = 0;
		b++;
	}
	//1 9
	if (a[0][0] == '*' && a[2][2] == '*' && a[1][1] == ' ') {
		d = 1;
		e = 1;
		b++;
	}
	//3 5
	if (a[0][2] == '*' && a[1][1] == '*' && a[2][0] == ' ') {
		d = 2;
		e = 0;
		b++;
	}
	//7 5
	if (a[2][0] == '*' && a[1][1] == '*' && a[0][2] == ' ') {
		d = 0;
		e = 2;
		b++;
	}
	//3 7
	if (a[0][2] == '*' && a[2][0] == '*' && a[1][1] == ' ') {
		d = 1;
		e = 1;
		b++;
	}
	if (b != 0) {
		a[d][e] = '#';
		return 1;
	} else {
		return 0;
	}
}
void dnlzh() {
	int c[3][3], d = 0, e = 0, f = 0;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			c[i][j] = 0;
		}
	}
	if (pdwzd() == 0) {
		if (pdwzt() == 0) {
			if (a[1][1] == ' ') {
				a[1][1] = '#';
			} else {
				if (a[0][0] == ' ') {
					for (int i = 1; i <= 2; i++) {
						if (a[0][i] == ' ' || a[0][i] == '#') {
							c[0][0]++;
						}
					}
					for (int i = 1; i <= 2; i++) {
						if (a[i][0] == ' ' || a[i][0] == '#') {
							c[0][0]++;
						}
					}
					if (a[1][1] == ' ' || a[1][1] == '#') {
						c[0][0]++;
					}
					if (a[2][2] == ' ' || a[2][2] == '#') {
						c[0][0]++;
					}
				}
				if (a[0][1] == ' ') {
					for (int i = 1; i <= 2; i++) {
						if (a[i][1] == ' ' || a[i][1] == '#') {
							c[0][1]++;
						}
					}
					if (a[0][0] == ' ' || a[0][0] == '#') {
						c[0][1]++;
					}
					if (a[0][2] == ' ' || a[0][2] == '#') {
						c[0][1]++;
					}
				}
				if (a[0][2] == ' ') {
					for (int i = 1; i <= 0; i--) {
						if (a[0][i] == ' ' || a[0][i] == '#') {
							c[0][2]++;
						}
					}
					for (int i = 1; i <= 2; i++) {
						if (a[i][2] == ' ' || a[i][2] == '#') {
							c[0][2]++;
						}
					}
					if (a[1][1] == ' ' || a[1][1] == '#') {
						c[0][2]++;
					}
					if (a[2][0] == ' ' || a[2][0] == '#') {
						c[0][2]++;
					}
				}
				if (a[1][0] == ' ') {
					for (int i = 1; i <= 2; i++) {
						if (a[1][i] == ' ' || a[1][i] == '#') {
							c[1][0]++;
						}
					}
					if (a[0][0] == ' ' || a[0][0] == '#') {
						c[1][0]++;
					}
					if (a[2][0] == ' ' || a[2][0] == '#') {
						c[1][0]++;
					}
				}
				if (a[1][2] == ' ') {
					for (int i = 1; i <= 0; i--) {
						if (a[1][i] == ' ' || a[1][i] == '#') {
							c[1][2]++;
						}
					}
					if (a[0][2] == ' ' || a[0][2] == '#') {
						c[1][2]++;
					}
					if (a[2][2] == ' ' || a[2][2] == '#') {
						c[1][2]++;
					}
				}
				if (a[2][0] == ' ') {
					for (int i = 1; i <= 2; i++) {
						if (a[2][i] == ' ' || a[2][i] == '#') {
							c[2][0]++;
						}
					}
					for (int i = 1; i <= 0; i--) {
						if (a[i][0] == ' ' || a[i][0] == '#') {
							c[2][0]++;
						}
					}
					if (a[1][1] == ' ' || a[1][1] == '#') {
						c[2][0]++;
					}
					if (a[0][2] == ' ' || a[0][2] == '#') {
						c[2][0]++;
					}
				}
				if (a[2][1] == ' ') {
					for (int i = 1; i <= 0; i--) {
						if (a[i][1] == ' ' || a[i][1] == '#') {
							c[2][1]++;
						}
					}
					if (a[2][0] == ' ' || a[2][0] == '#') {
						c[2][1]++;
					}
					if (a[2][2] == ' ' || a[2][2] == '#') {
						c[2][1]++;
					}
				}
				if (a[2][2] == ' ') {
					for (int i = 1; i <= 0; i--) {
						if (a[2][i] == ' ' || a[2][i] == '#') {
							c[2][2]++;
						}
					}
					for (int i = 1; i <= 0; i--) {
						if (a[i][2] == ' ' || a[i][2] == '#') {
							c[2][2]++;
						}
					}
					if (a[1][1] == ' ' || a[1][1] == '#') {
						c[2][2]++;
					}
					if (a[0][0] == ' ' || a[0][0] == '#') {
						c[2][2]++;
					}
				}
				for (int i = 0; i <= 2; i++) {
					for (int j = 0; j <= 2; j++) {
						if (c[i][j] > d) {
							d = c[i][j];
							e = i;
							f = j;
						}
					}
				}
				a[e][f] = '#';
			}
		}
	}
}
void dnlze() {
	int x, y;
	while (1) {
		x = rand() % 3;
		y = rand() % 3;
		if (a[x][y] == ' ') {
			a[x][y] = '#';
			break;
		}
	}
}
void zlzw(int b) {
	initialization();
	printcheckerboard();
	while (1) {
		system("cls");
		printf("Player round\n");
		playerplacement();
		printcheckerboard();
		if (winorlose() == '*') {
			printf("Player win\n");
			break;
		}
		if (winorlose() == '+') {
			printf("Draw\n");
			break;
		}
		system("cls");
		printf("Computer round\n");
		if (b == 1) {
			dnlze();
		} else {
			dnlzh();
		}
		printcheckerboard();
		if (winorlose() == '#') {
			printf("Computer win\n");
			break;
		}
		if (winorlose() == '+') {
			printf("Draw\n");
			break;
		}
	}
}
void computermasterplacement(int b) {
	initialization();
	printcheckerboard();
	while (1) {
		system("cls");
		printf("Computer round\n");
		if (b == 1) {
			dnlze();
		} else {
			dnlzh();
		}
		printcheckerboard();
		if (winorlose() == '#') {
			printf("Computer win\n");
			break;
		}
		if (winorlose() == '+') {
			printf("Draw\n");
			break;
		}
		printf("Player round\n");

		playerplacement();
		printcheckerboard();
		if (winorlose() == '*') {
			printf("Player win\n");
			break;
		}
		if (winorlose() == '+') {
			printf("Draw\n");
			break;
		}
	}
}
/*void cs1() {
	char d[3][3], e[3], f = '*';
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			d[i][j] = ' ';
		}
	}
	printcheckerboard(d);
	cin >> e[0] >> e[1];
	d[e[0] - '0'][e[1] - '0'] = f;
	cin >> e[2];
	if (e[2] == 'n' || e[2] == 'y') {
		if (e[2] == 'y') {
			printf("0.continue");
			printf("90.exit");
		} else {
			printf("89.gqz");
			printf("88.gwz");
		}
	} else {
		start();
	}
	cin >> e[2];
	if (e[2] - '0' == 0) {
		printcheckerboard(d);
		cin >> e[0] >> e[1];
		d[e[0] - '0'][e[1] - '0'] = f;
		cin >> e[2];
		if (e[2] == 'n' || e[2] == 'y') {
			if (e[2] == 'y') {
				printf("0.continue");
				printf("90.exit");
			} else {
				printf("89.gqz");
				printf("88.gwz");
			}
		}
	} else {
		start();
	}
	if (e[2] - '0' == 90 || e[2] - '0' == 0 || e[2] - '0' == 89 || e[2] - '0' == 88) {
		if (e[2] - '0' == 90) {
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					a[i][j] = d[i][j];
				}
			}
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					d[i][j] = ' ';
				}
			}
			start();
		}
		if (e[2] - '0' == 89) {
			f = '#';
			d[e[0] - '0'][e[1] - '0'] = f;
			printcheckerboard(d);
			cin >> e[2];
		}
	} else {
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				d[i][j] = ' ';
			}
		}
		start();
	}
}
void cs() {
	string m;
	int c;
	cin >> m;
	if (m == "1234") {
		system("cls");
		printf("111.gp\n");//c=111
		printf("222.glz\n");//c=222
		printf("3.exit\n");//c=3
		scanf("%d", &c);
		if (c == 111) {
			cs1();
		}
	} else {
		int b = 1;
		if (b == 3) {
			start();
		}
		cin >> m;
		b++;
	}
}*/
void start() {
	srand(time(NULL));
	int b, c;
	do {
		welcome();
		c = rand() % 2;
		scanf("%d", &b);
		switch (b) {
			case 1:
			case 2:
				if (c == 0) {
					computermasterplacement(b);
				} else {
					zlzw(b);
				}
				break;
			case 3:
				printf("½áÊø");
				break;
			/*case 4:
				cs();
				break;*/
			default:
				break;
		}
	} while (b != 3);
}
void pos(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handleOutput, pos);
}

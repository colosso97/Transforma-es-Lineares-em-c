#include<stdio.h>
#include<windows.h>

void gotoXY(int X, int Y) {
	COORD p = {X, Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int main() {
	int par = 0, impar = 1, p = 0, i = 0;
	char tecla;
	
	printf("Prescione o numero para comecar\n(1) Iniciar\n(2) Terminar\n");
	while(!(tecla=kbhit()));
	tecla = getch();
	
	if (tecla == '1') {
		while(tecla != '2') {
			while(!(tecla=kbhit())) {
				gotoXY(0, 4);
				printf("Par: %d", par+= 2);
				gotoXY(0, 5);
				printf("Impar: %d", impar += 2);
				Sleep(500);
			}
			if(tecla != '2')tecla = getch();
		}
	}
	else {
		gotoXY(0, 4);
		printf("Tecla invalida! Programa encerrado!");
	}
}

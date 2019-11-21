#include<stdio.h>
#include<windows.h>

void gotoXY(int X, int Y) {
	COORD p = {X, Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int main() {
	int i = 0, p = 0;
	char tecla;
	
	printf("Prescione o numero para comecar\n(1) Iniciar\n(2) Terminar");
	while(!(tecla = kbhit));
	
	tecla = getch();
	
	if(tecla == '1') {
		
		while(tecla != '2') {
			while(!(tecla=kbhit())) {
				gotoXY(0, 4);
				printf("%d", i++);
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

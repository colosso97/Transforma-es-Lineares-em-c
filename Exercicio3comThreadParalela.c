#include<stdio.h>
#include<omp.h>
#include<windows.h>

/* A = entregue para A,
	B = entregue para B,
	C = entregue para C,
	D = entregue para D,
	E = entregue para E,
	F = na fila,
	P = esperar para entrar na fila,
	I = codigo invalido
*/


struct Entregas {
	char codigos[10];
	char status[11];
	int fila[10];
	int atual;
};

void gotoXY(int X, int Y) {
	COORD p = {X, Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int main() {
	struct Entregas pacotes;
	int i, c[10] = {101, 102, 102, 103, 101, 104, 109, 105, 103, 104};
	
	for(i = 0; i < 10; i++) {
		pacotes.codigos[i] = c[i];
		pacotes.status[i] = 'P';
		pacotes.fila[i] = 0;
	}
	pacotes.status[10] = '\0';
	pacotes.atual = 0;
	
	for(int i = 0; i < 10; i++) {
		Sleep(500);

		#pragma omp parallel
		{
			#pragma omp sections
			{
				#pragma omp section
				{
					pacotes.fila[pacotes.atual] = pacotes.codigos[pacotes.atual];
					pacotes.codigos[pacotes.atual] = 0;
					pacotes.status[pacotes.atual] = 'F';
					gotoXY(0, 1);
					printf("%s",pacotes.status);
				}
				#pragma omp section
				{
					switch(pacotes.fila[pacotes.atual]) {
						case 101:
							pacotes.status[pacotes.atual] = 'A';
							break;
						case 102:
							pacotes.status[pacotes.atual] = 'B';
							break;
						case 103:
							pacotes.status[pacotes.atual] = 'C';
							break;
						case 104:
							pacotes.status[pacotes.atual] = 'D';
							break;
						case 105:
							pacotes.status[pacotes.atual] = 'E';
							break;	
						default:
							pacotes.status[pacotes.atual] = 'I';
							break;
					}
					gotoXY(0, 2);
					printf("%s",pacotes.status);
					pacotes.fila[pacotes.atual] = 0;
					pacotes.atual++;
				}
			}
		}
	}
	gotoXY(0, 1);
	printf("%s",pacotes.status);
}

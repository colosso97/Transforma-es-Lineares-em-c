#include<stdio.h>
#include<windows.h>
#include<omp.h>


void gotoXY(int X, int Y) {
	COORD p = {X, Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int main() {
	int par = 0, impar = 1, p = 0, i = 0;
	char tecla;
	
	printf("Prescione a tecla para realizar a tarefa correspondente!\n(1) Iniciar\n(2) Terminar\n");
	while(!(tecla = kbhit()));
	tecla = getch();
	
	if(tecla == '1') {
		while(tecla != '2') {
			while(!(tecla=kbhit())) {
				/*antes de executar siga o seguinte procedimento
				ferramentas -> opções do copilador -> digite -fopenmp na segunda caixa de texto
				caso o dev esteja em ingles o caminho sera
				tools -> compiler options -> digite -fopenmp na segunda caixa de texto*/
				#pragma omp parallel
				{
					//zona paralela
					#pragma omp sections
					{
						//zona onde cada section sera executada em paralelo
						#pragma omp section 
						{
							//zona onde o codigo dentro dela sera executado em sequencia
							gotoXY(0, 4);
							printf("Par: %d", par+= 2);
						}
						#pragma omp section 
						{
							gotoXY(0, 5);
							printf("Impar: %d", impar+= 2);
						}
					}
					
				}
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

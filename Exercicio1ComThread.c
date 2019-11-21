#include<stdio.h>
#include<pthread.h>
#include<windows.h>

//Declara quatidade de threads que serão usadas
pthread_t thread[1];

void gotoXY(int X, int Y) {
	//função responsavel por reposicionar o cursor na tela so funciona com a biblioteca "windows.h"
	COORD p = {X, Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void *thread_contadora(void *i) {
	//função que a thread vai executar
	int *j = (int *)i;
	gotoXY(0, 4);
	printf("%d", *j+=1);
}
int main() {
	int i = 0, p = 0;
	char tecla;
	
	printf("Prescione o numero para comecar\n(1) Iniciar\n(2) Terminar");
	while(!(tecla = kbhit()));//espera ate que alguma tecla seja precionada
	
	tecla = getch();//pega a ultima tecla precionada e salva na variavel tecla
	
	if(tecla == '1') {
		while(tecla != '2') {
			while(!(tecla=kbhit())) {
				//Função que cria a thread
				pthread_create(&(thread[0]),NULL,thread_contadora,&i);
				//Função que inicia a thread
				pthread_join(thread[0],NULL); 
				//Delay de meio segundo
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

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	// Acentos no Prompt de comando windows
	setlocale(LC_ALL, "portuguese");
	
	//variaveis
	int i = 0,j = 0;
	
	//Processamento e Saida
	//coluna
	for(i = 0; i < 6; i++)
	{
		// Linha
		for(j = 0; j < 10;j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

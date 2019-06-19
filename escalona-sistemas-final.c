//programa que escalona, classifica e resolve sistemas lineares
//programa só resolve sistemas possíveis determinados se eles forem quadrados
#include <stdio.h>

int main(){	
	//parte 1: input do sistema
	
	int qtdVar;
	int qtdLinhas;
	
	printf("Digite a qtd de variaveis que o sistema possui em cada linha: ");
	scanf("%d", &qtdVar);
	printf("Digite a qtd de linhas do sistema: ");
	scanf("%d", &qtdLinhas);
	
	double elementos[qtdLinhas][qtdVar+1];
	
	int linha;
	int var;
	
	for(linha = 0; linha < qtdLinhas; linha++){
		for(var = 0; var <= qtdVar; var++){
			if(var == qtdVar){	
				printf("Digite o valor apos a igualdade: ");
			}else{
				printf("Digite a%d%d: ", linha+1, var+1);
			}
			scanf("%lf", &elementos[linha][var]);
		}
	}
	
	//parte 2: escalonando o sistema
			
	//zerando valores abaixo do pivô
	double zeraElemento;
	int linha1, linha2;
	
	for(linha1 = 0; linha1 < qtdLinhas; linha1++){
		for(linha2 = 0; linha2 < qtdLinhas; linha2++){
			if(linha2 > linha1){
				zeraElemento = - (elementos[linha2][linha1] / elementos[linha1][linha1]);
				for(var = 0; var < qtdVar+1; var++){
					elementos[linha2][var] = zeraElemento * elementos[linha1][var] + elementos[linha2][var];
				}
			}
		}
	}
	
	//imprimindo o novo sistema
	printf("\nsistema escalonado:\n");
	
	for(linha = 0; linha < qtdLinhas; linha++){
		for(var = 0; var <= qtdVar; var++){
			if(elementos[linha][var] == -0){
				printf("elementos[%d][%d] = %.5lf\n", linha, var);
			}else{			
				printf("elementos[%d][%d] = %.5lf\n", linha, var, elementos[linha][var]);
			}
		}
	}
	
	//parte 3: transforma o sistema escalonado em sistema escalonado reduzido
	double pivos[qtdLinhas];
	
	//encontrando os pivôs
	printf("\n");
	for(linha = 0; linha < qtdLinhas; linha++){
		for(var = 0; var <= qtdVar; var++){
			if(linha == var){	
				pivos[linha] = elementos[linha][var];
				printf("pivo[%d] = %.5lf\n", linha, pivos[linha]);
			}
		}
	}
	
	//dividindo toda a equação pelo pivo
	for(linha = 0; linha < qtdLinhas; linha++){
		for(var = 0; var <= qtdVar; var++){
			if(pivos[linha] != 0){
				elementos[linha][var] /= pivos[linha];
			}
		}
	}
	
	//imprimindo o novo sistema
	printf("\nsistema escalonado reduzido:\n");
	
	for(linha = 0; linha < qtdLinhas; linha++){
		for(var = 0; var <= qtdVar; var++){
			if(elementos[linha][var] == -0){
				printf("elementos[%d][%d] = %.5lf\n", linha, var);
			}else{
				printf("elementos[%d][%d] = %.5lf\n", linha, var, elementos[linha][var]);
			}			
		}
	}
		
	//parte 4: calculando o determinante
	double determinante = 1;
	
	printf("\n");
	for(linha = 0; linha < qtdLinhas; linha++){
		for(var = 0; var <= qtdVar; var++){
			if(linha == var){	
				determinante *= elementos[linha][var];
			}
		}
	}	
	// printf("determinante = %.5lf\n", determinante);
	
	
	//parte 5: caso seja SPD encontra o valor das variáveis

	if(determinante != 0){ //sistema possível determinante
		if(qtdVar == qtdLinhas){ //algoritmo só resolve sistemas quadrados
			double x[qtdVar];
			double soma = 0;
			int i, j;
			
			x[qtdVar-1] = elementos[qtdLinhas-1][qtdVar] / elementos[qtdLinhas-1][qtdVar-1];
			
			for(i = qtdLinhas-2; i >= 0; i--){
				soma = 0;
				for(j = i + 1; j < qtdVar; j++){
					soma = soma + elementos[i][j] * x[j];
				}
				x[i] = (elementos[i][qtdVar] - soma)/elementos[i][i];
			}
			
			printf("\nSistema possivel determinado!\n");		
			for(i = 0; i < qtdVar; i++){
				if(x[i] == -0){
					printf("x%d = %.5lf\n", i+1);
				}
				else{
					printf("x%d = %.5lf\n", i+1, x[i]);
				}
			}
		}	
	//parte 6: caso seja SPI ou SI imprime qual dos dois é
	}else{
		
		double elementoAntesdaIgualdade = elementos[qtdLinhas-1][qtdVar-1];
		double elementoDepoisdaIgualdade = elementos[qtdLinhas-1][qtdVar];
		
		//printf("%.5lf\n%.5lf\n", elementoAntesdaIgualdade, elementoDepoisdaIgualdade);
		
		if(elementoAntesdaIgualdade != elementoDepoisdaIgualdade){
			printf("Sistema impossivel!\n");
		}else{
			printf("Sistema possivel indeterminado!\n");
		}
	}
		
	system("pause");
	return 0;
}

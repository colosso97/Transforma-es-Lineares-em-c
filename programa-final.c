#include <stdio.h>

int main(){	
	//input
	int qtdPontos;
	
	printf("Digite a qtd de pontos que sua figura possui no plano: ");
	scanf("%d", &qtdPontos);
	
	double vertices[qtdPontos][2];
	
	int ponto;
	int coordenada;
	
	for(ponto = 0; ponto < qtdPontos; ponto++){
		printf("\nPonto %d:", ponto+1);
		for(coordenada = 0; coordenada < 2; coordenada++){
			if((coordenada+1) % 2 != 0){	
				printf("\nDigite o valor de x: ");
			}else{
				printf("Digite o valor de y: ");
			}
			scanf("%lf", &vertices[ponto][coordenada]);
		}
	}
			
	//testando
	//imprimindo
	printf("\n\nCoordenadas no plano\n");
	
	for(ponto = 0; ponto < qtdPontos; ponto++){
		printf("\nPonto %d:", ponto+1);
		for(coordenada = 0; coordenada < 2; coordenada++){
			if((coordenada+1) % 2 != 0){	
				printf("\nx: %lf", vertices[ponto][coordenada]);
			}else{
				printf("\ny: %lf\n", vertices[ponto][coordenada]);
			}
		}
	}
	
	//menu
	int opcao;
	
	do{
		printf("\nMenu\n");
		printf("1. Ampliacao no eixo x de 2 unidades\n");
		printf("2. Rotacao para o angulo de 180 graus\n");
		printf("3. T(x ; y) = (-x ; y)\n");
		printf("4. Cisalhamento de k = 1,5 em relacao ao eixo x\n");
		printf("5. Sair\nOpcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				for(ponto = 0; ponto < qtdPontos; ponto++){
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){//se a coordenada for x	
							vertices[ponto][coordenada] *= 2;
						}
					}
				}
				
				//imprimindo
				printf("\n\nNovas coordenadas\n");
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					printf("\nPonto %d:", ponto+1);
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){	
							printf("\nx: %lf", vertices[ponto][coordenada]);
						}else{
							printf("\ny: %lf\n", vertices[ponto][coordenada]);
						}
					}
				}
				break;
				
			case 2: //sen de 180 = 0; cos de 180 = -1
				for(ponto = 0; ponto < qtdPontos; ponto++){
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){//se a coordenada for x
							vertices[ponto][coordenada] = (vertices[ponto][coordenada] * -1) - (vertices[ponto][coordenada+1] * 0);
						}else{
							vertices[ponto][coordenada] = (vertices[ponto][coordenada-1] * 0) + (vertices[ponto][coordenada] * -1);
						}
					}
				}
				
				//imprimindo
				printf("\n\nNovas coordenadas\n");
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					printf("\nPonto %d:", ponto+1);
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){	
							printf("\nx: %lf", vertices[ponto][coordenada]);
						}else{
							printf("\ny: %lf\n", vertices[ponto][coordenada]);
						}
					}
				}
				break;
				
			case 3: //T(x ; y) = (-x ; y)
				for(ponto = 0; ponto < qtdPontos; ponto++){
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){//se a coordenada for x
							vertices[ponto][coordenada] *= -1;
						}
					}
				}
				
				//imprimindo
				printf("\n\nNovas coordenadas\n");
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					printf("\nPonto %d:", ponto+1);
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){	
							printf("\nx: %lf", vertices[ponto][coordenada]);
						}else{
							printf("\ny: %lf\n", vertices[ponto][coordenada]);
						}
					}
				}
				break;
				
			case 4: //k = 1.5
				for(ponto = 0; ponto < qtdPontos; ponto++){
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){//se a coordenada for x
							vertices[ponto][coordenada] += (vertices[ponto][coordenada+1] * 1.5);
						}
					}
				}
				
				//imprimindo
				printf("\n\nNovas coordenadas\n");
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					printf("\nPonto %d:", ponto+1);
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){	
							printf("\nx: %lf", vertices[ponto][coordenada]);
						}else{
							printf("\ny: %lf\n", vertices[ponto][coordenada]);
						}
					}
				}
				break;
				
			case 5:
				break;
			default:
				printf("\nOpcao nao valida\n");
				break;
		}
	}while(opcao != 5);
		
	system("pause");
	return 0;
}

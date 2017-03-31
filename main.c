#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a[TAMANHO_ARRAY] = 20000;
	ARVORE_B raiz;
	
	//"wt": abertura para grava��o, arquivo texto
	FILE *arq;
	int result;
	char Str[50];
	int i;

	arq = fopen("ArqGrav.txt", "rt");

	if (arq == NULL)
	{
	    printf("Problemas na CRIACAO do arquivo\n");
    return;
	} 
	
	raiz = criaArvore(a, 0, TAMANHO_ARRAY);
	
	int i, result;
   	float x;
   	result = fscanf(arq, "%d%f", &i, &x); 
	
	
	i = 1;
  	while (!feof(arq))
  	{
		// L� uma linha (inclusive com o '\n')
 	    result = fgets(Linha, 100, arq);  // o 'fgets' l� at� 99 caracteres ou at� o '\n'
      	if (result)  // Se foi poss�vel ler
	  	printf("Linha %d : %s",i,Linha);
      	i++;
  	}
  	
	
	
	
	fclose(arq);
	
	
	printf("Imprimindo em pr�-ordem:\n");
	preOrdem(raiz);
	printf("\n\n");

	printf("Imprimindo em ordem:\n");
	emOrdem(raiz);
	printf("\n\n");

	printf("Imprimindo em p�s-ordem:\n");
	posOrdem(raiz);
	printf("\n\n");
	
}

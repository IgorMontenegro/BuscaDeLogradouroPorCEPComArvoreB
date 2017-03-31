#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a[TAMANHO_ARRAY] = 20000;
	ARVORE_B raiz;
	
	//"wt": abertura para gravação, arquivo texto
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
		// Lê uma linha (inclusive com o '\n')
 	    result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      	if (result)  // Se foi possível ler
	  	printf("Linha %d : %s",i,Linha);
      	i++;
  	}
  	
	
	
	
	fclose(arq);
	
	
	printf("Imprimindo em pré-ordem:\n");
	preOrdem(raiz);
	printf("\n\n");

	printf("Imprimindo em ordem:\n");
	emOrdem(raiz);
	printf("\n\n");

	printf("Imprimindo em pós-ordem:\n");
	posOrdem(raiz);
	printf("\n\n");
	
}

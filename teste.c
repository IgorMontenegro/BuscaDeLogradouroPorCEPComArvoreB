#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// ************************************************************
//   Exemplo de uso de arquivo texto
//   Este programa lê um arquivo texto e imprime o seu
//   conteudo na tela.
// ************************************************************


int main(int argc, char* argv[])
{
	//transforma entrada em binário
	int a;
	char b[10];

	printf("Digite um numero: ");
	scanf("%d",&a);

	itoa(a,b,2); //Converte para base 2

	printf("\nO numero %d em binario e: %s",a);

	getch();
	
	//le arquivo
	char url[]="arquivo.txt",
	     nome[20];
	float nota1, nota2, nota3;
	FILE *arq;
	
	arq = fopen(url, "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fscanf(arq,"%s %f %f %f\n", nome, &nota1, &nota2, &nota3))!=EOF )
			printf("%s teve media %.2f\n", nome, (nota1+nota2+nota3)/3);
	
	fclose(arq);
	
	return 0;
}

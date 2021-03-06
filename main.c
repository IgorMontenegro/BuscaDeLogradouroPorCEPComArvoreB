#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <io.h>
#include "stdlib.h"
#include "arvore_binaria.h"
#define TAMANHO_ARRAY 2200

int main(){

    //Cria arvore e adiciona os dados do arquivo.
	//char a[TAMANHO_ARRAY];
    //ARVORE_B raiz;
    char log;//resultado, ;
    //int result;
    int cep, buscaCEP;

	FILE * arq;

	//Inicia tempo de leitura
	clock_t begin = clock();

	arq = fopen("NovaBase.txt", "r");

	if(arq == NULL){
			printf("Erro, nao foi possivel abrir o arquivo.\n");
	}
	else
    {
        system ("Realize sua pesquisa abaixo:");
        printf("### Pesquise algum CEP ###\n");
        printf("Digite o CEP: ");
        scanf("%i", &buscaCEP);

		while( (fscanf(arq,"%i;%s\n", &cep, &log))!=EOF )
        {
            if(buscaCEP == cep){
                printf ("\n Resultado do CEP : %i, %s \n", cep, &log);
                break;
            }
            else{
                printf ("\n N�o achamos CEP correspondente na base.");
                break;
            }
        }
	}

    //Para tempo de leitura e Imprime tempo
    clock_t end = clock();
    printf ("\nO Tempo de leitura dos dados gasto foi: %f\n\n", (double)(end - begin) * 1000 / CLOCKS_PER_SEC);

    //Cria arvore com os dados de cada linha na variavel a
	//raiz = criaArvore(a, 0, TAMANHO_ARRAY);
    fclose(arq);

    //Inicia tempo de busca
    clock_t comeco = clock();

    //converte entrada em binario para char e busca na arvore
    //resultado = arvore_binaria_buscar(raiz,chartobin(entrada));


    //Para tempo de busca e Imprime O tempo
    clock_t fim = clock();
    printf ("\nO Tempo de busca dos dados gasto foi: %f\n\n", (double)(fim - comeco) * 1000 / CLOCKS_PER_SEC);

    //converte resultado binario em string traduzida
    //printf ("\nResultado da busca: %s", bintochar(resultado));

    return 0;
}

//------------------------------------------------------
// Converte uma string em binario para um valor char
//------------------------------------------------------
/*unsigned char bintochar( char* binstr )
{
    // Retorna o valor char que a string passada como argumento
    // representa. Utiliza a funcao strtoul da biblioteca padrao
    return (unsigned char) ( strtoul( binstr, NULL, 2 ) );
}

//----------------------------------------------------------
// Converte um valor do tipo char para uma string binaria
//----------------------------------------------------------
char *chartobin ( unsigned char c ){
    static char bin[CHAR_BIT + 1] = {0};
    int         i;

    for ( i = CHAR_BIT - 1; i >= 0; i-- )
    {
        bin[i] = (c % 2) + '0';
        c /= 2;
    }

    return bin;
}

ARVORE_B novoNo(){
	return ((ARVORE_B)malloc(sizeof(NO)));
}

ARVORE_B iniciaNo(DADO d1, ARVORE_B p1, ARVORE_B p2){
	ARVORE_B t;

	t = novoNo();
	t->d = d1;
	t->esq = p1;
	t->dir = p2;
	return t;
}

ARVORE_B criaArvore(DADO a[], int i, int tamanho){
	if(i >= tamanho){
		return NULL;
	}else{
		return(
			iniciaNo(
				a[i],
				criaArvore(a, 2*i+1, tamanho),
				criaArvore(a, 2*i+2, tamanho)
			)
		);
	}
}

char arvore_binaria_buscar(no, valor){
    if no is None{
        # valor n�o encontrado
        return None;
    }
    else{
        if valor == no.valor
            # valor encontrado
            return no.valor;
        if valor < no.valor
            # busca na sub�rvore esquerda
            return arvore_binaria_buscar(no.filho_esquerdo, valor);
        if valor > no.valor
            # busca na sub�rvore direita
            return arvore_binaria_buscar(no.filho_direito, valor);
    }
}

void preOrdem(ARVORE_B raiz){
	if(raiz != NULL){
		printf("%c ", raiz->d);
		preOrdem(raiz -> esq);
		preOrdem(raiz -> dir);
	}
}

void emOrdem(ARVORE_B raiz){
	if(raiz != NULL){
		emOrdem(raiz -> esq);
		printf("%c ", raiz->d);
		emOrdem(raiz -> dir);
	}
}

void posOrdem(ARVORE_B raiz){
	if(raiz != NULL){
		posOrdem(raiz -> esq);
		posOrdem(raiz -> dir);
		printf("%c ", raiz->d);
	}
}
*/

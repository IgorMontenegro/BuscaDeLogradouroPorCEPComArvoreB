#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"
#include "limits.h"
#include "arvore_binaria.h"
#define TAMANHO_ARRAY 2200

int main(void){

    //Cria arvore e adiciona os dados do arquivo.
	char a[TAMANHO_ARRAY];
    ARVORE_B raiz;
	int i = 0;
    char url[]="BaseDeCepsELogradourosBIN.txt",
         linha,
         resultado;

    char entrada = "";

	FILE *arq;

	arq = fopen(url, "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fscanf(arq,"%s\n", linha))!=EOF )
        {
            a[i] = linha;
            i++;
        }

    //Cria arvore com os dados de cada linha na variavel a
	raiz = criaArvore(a, 0, TAMANHO_ARRAY);

    fclose(arq);

    printf("Digite sua busca: \n");
    scanf("%s",&entrada);

    //converte entrada em binario e busca na arvore
    resultado = arvore_binaria_buscar(raiz,chartobin(entrada));

    //converte resultado binario em string traduzida
    bintochar(resultado);

    //imprime retorno da busca
    printf("Resultado da busca", resultado);
    scanf("%s, pressione qualquer tecla para continuar.",&linha);

    return 0;
}


//------------------------------------------------------
// Converte uma string em binario para um valor char
//------------------------------------------------------
unsigned char bintochar( char* binstr )
{
    // Retorna o valor char que a string passada como argumento
    // representa. Utiliza a funcao strtoul da biblioteca padrao
    return (unsigned char) ( strtoul( binstr, NULL, 2 ) );
}

//----------------------------------------------------------
// Converte um valor do tipo char para uma string binaria
//----------------------------------------------------------
char* chartobin ( unsigned char c ){
    static char bin[CHAR_BIT + 1] = { 0 };
    int i;

    for ( i = CHAR_BIT - 1; i >= 0; i-- ){
        bin[i] = (c % 2) + '0';
        c /= 2;
    }
    // Retorna a string com a representacao binaria do argumento
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
        # valor não encontrado
        return None;
    }
    else{
        if valor == no.valor
            # valor encontrado
            return no.valor;
        if valor < no.valor
            # busca na subárvore esquerda
            return arvore_binaria_buscar(no.filho_esquerdo, valor);
        if valor > no.valor
            # busca na subárvore direita
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

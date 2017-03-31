int main(void)
{
	char url[]="notas.txt",
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

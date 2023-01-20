#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta [TAMANHO_PALAVRA];
char chutes [26];
int chutesdados = 0;

int letraexiste (char letra){
	for (int j = 0; j <strlen (palavrasecreta); j++) {
		if (letra==palavrasecreta [j]) {
			return 1;
		}
	}
}
 
int chuteserrados () {
	int erros=0;
	for (int i=0; i <chutesdados; i++) {
		if (letraexiste (chutes [i])) {
			erros++; 
		}
	}
	return erros;

}

int enforcou () {
	return chuteserrados () >=5;
}
int ganhou () {
	for (int i=0; i<strlen(palavrasecreta); i++){
		if (!jachutou (palavrasecreta [i])) {
			return 0;
		
		}
	}
	return 1; 
}
	
void abertura () {
	printf ("/JOGO DE FORCA/\n");
}
void chuta() {
	char chute;
	printf ("qual letra?");
	scanf ("%c", &chute)) {
		printf ("voce acertou! a palavra tem a letra %c", chute);
		
	}
	else {
		
	printf ("voce errou! a palavra nao tem a letra %c\n\n", chute);
	
}



	chutes [chutesdados] = chute;
	chutesdados++;
}
int jachutou (char letra) {
	int achou = 0;
	for (int j =0; j < chutesdados; j++){
		if (chutes [j] == letra) {
			achou = 1; 
			break;
			
		}
	}
	return achou;
}
		
void desenhaforca (){
	int erros=chuteserrados(); 
	
	for (int i=0; i <strlen (palavrasecreta); i++){
		if (jachutou(palavrasecreta [i])) {
			printf ("%c", palavrasecreta [i]);
		} else { 
		printf ("_");
	
		}
		}
		printf ("\n");
		
	}
	void escolhepalavra () {
		FILE* f;
		f=fopen ("palavras.txt", "r");
		if (f==0){
			printf ("banco de dados de palavras disponivel\n\n");
			exit(1);
			
		}
		int qtdpalavras; 
		fscanf (f, %d, &qtdpalavras);
		srand (time(0));
		int randomico = rand () %qtdpalavras;
		for (int i=0; i<= randomico; i++){
			fscanf (f, "%s", palavrasecreta);
			
		}
		fclose(f);
		
}
    void adicionarpalavra() {
    	char quer; 
    	printf ("voce deseja adicionar uma nova palavra no jogo? (S/N)");
    	scanf ("%c", &quer);
    	if (quer=='S'){
    		char novapalavra [TAMANHO_PALAVRA]; 
    		printf ("digite a nova palavra, em letras minúsculas");
    		scanf ("%s", novapalavra);
    		FILE*f;
    		f=fopen("palavras.txt", "r+");
    		if (f==0){
    			printf ("banco de dados de palavras nao disponivel");
    			exit (1);
    			
			}
			int qtd;
			fscanf (f, "%d", &qtd);
			qtd++; 
			fseek (f,0,SEEK_SET);
			fprintf (f, "%d", qtd);
			fseek (f,0,SEEK_END);
			fprintf(f, "%s", novapalavra);
			fclose (f);
			
		}
	}
	int main () {
		abertura ();
		escolhepalavra (); 
		do { 
		desenhaforca ();
		chuta();
	} while (!ganhou ()&& !enforcou());
	if (ganhou()){
		printf ("parabens, voce ganhou!");
	}
else {
	printf ("puxa, voce foi enforcado!");
	printf ("a palavra era **%s**", palavrasecreta);
}
adicionarpalavra ();
}
	
	
	
	
	
	
	
	
	
	
	
	
	


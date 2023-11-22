#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tirar_espaco(char *texto){ // usado para recolocar o espaço na hora de demonstrar o programa ao usuario 
    int i;
    for(i=0;i<strlen(texto);i++){
		if (texto[i]==' '){ //vê quando tem espaço e coloca " "
			texto[i]='+';
		}
	}
}

void colocar_espaco(char *texto){ //função usada para adicionar um sinal do arquivo texto para não dar erros de leitura
    int i;
    for(i=0;i<strlen(texto);i++){
		if (texto[i]=='+'){//vê quando tem "+" e coloca " "
			texto[i]=' ';	
		}
	}
}

int main(){

    char sla[101];
    
    printf("Escreve algo ai meu chapa: ");
    fgets(sla, sizeof(sla), stdin); //pega a linha inteira
	size_t tamanho = strlen(sla);
    if (tamanho > 0 && sla[tamanho - 1] == '\n'){
    	sla[tamanho - 1] = '\0'; //termina a linha no final da string
    }
    tirar_espaco(sla);
    FILE *arq = fopen("teste.txt", "a+");
    fprintf(arq, "<!DOCTYPE html>\n");
    fprintf(arq, "<html lang='pt-br'>\n");
    fprintf(arq, "<head>\n");
    fprintf(arq, "<meta charset='UTF-8'>\n");
    fprintf(arq, "<meta name='viewport' content='width=device-width', initial-scale='1.0'>\n");
    fprintf(arq, "<title>teste html foda</title>\n");
    fprintf(arq, "</head>\n");
    fprintf(arq, "<body>\n");

    fprintf(arq, "<h1>seu texto:</h1>\n");
    colocar_espaco(sla);
    fprintf(arq, "<p>%s</p>\n", sla);

    fprintf(arq, "</body>\n");
    fprintf(arq, "</html>");

    fclose(arq);
    system("del teste.html");
    system("rename teste.txt teste.html");
    system("del teste.txt");
    system("start teste.html");

    return 0;
}
#include <stdio.h>
#include <string.h>

struct livros{
	char titulo [100];
	char autor[50];
	int ano;
};

int main(){
	struct livros livro1;
	strcpy(livro1.titulo, "Estrutura de Dados");
	strcpy(livro1.autor, "Waldemar Salles");
	livro1.ano=1969;

	printf("Livro: %s\n", livro1.titulo);
	printf("Autor: %s\n", livro1.autor);
}

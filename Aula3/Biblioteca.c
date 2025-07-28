#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura do Livro
typedef struct Livro {
    char titulo[100];
    char autor[50];
    int disponivel; // 1 = disponível, 0 = emprestado
    struct Livro* proximo;
} Livro;

// Protótipos das funções
Livro* criar_livro(const char* titulo, const char* autor);
void adicionar_livro(Livro** cabeca, const char* titulo, const char* autor);
void listar_livros(Livro* cabeca);
void emprestar_livro(Livro* cabeca, const char* titulo);
void devolver_livro(Livro* cabeca, const char* titulo);
void liberar_lista(Livro* cabeca);
void menu();
void limpar_buffer();

// Função principal
int main() {
    Livro* biblioteca = NULL;
    int opcao;
    char titulo[100], autor[50];

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer(); // Limpa o buffer do teclado

        switch(opcao) {
            case 1:
                printf("Titulo do livro: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; // Remove o \n do final

                printf("Autor do livro: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = '\0';

                adicionar_livro(&biblioteca, titulo, autor);
                break;

            case 2:
                listar_livros(biblioteca);
                break;

            case 3:
                printf("Titulo do livro a ser emprestado: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                emprestar_livro(biblioteca, titulo);
                break;

            case 4:
                printf("Titulo do livro a ser devolvido: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                devolver_livro(biblioteca, titulo);
                break;

            case 5:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 5);

    liberar_lista(biblioteca);
    return 0;
}

// Cria um novo nó/livro
Livro* criar_livro(const char* titulo, const char* autor) {
    Livro* novo = (Livro*)malloc(sizeof(Livro));
    if(novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->disponivel = 1; // Por padrão, o livro está disponível
    novo->proximo = NULL;
    return novo;
}

// Adiciona um livro no final da lista
void adicionar_livro(Livro** cabeca, const char* titulo, const char* autor) {
    Livro* novo = criar_livro(titulo, autor);
    if(*cabeca == NULL) {
        *cabeca = novo;
    } else {
        Livro* atual = *cabeca;
        while(atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    printf("Livro '%s' adicionado com sucesso!\n", titulo);
}

// Lista todos os livros da biblioteca
void listar_livros(Livro* cabeca) {
    if(cabeca == NULL) {
        printf("A biblioteca esta vazia!\n");
        return;
    }

    printf("\n=== CATALOGO DA BIBLIOTECA ===\n");
    Livro* atual = cabeca;
    while(atual != NULL) {
        printf("Titulo: %s\n", atual->titulo);
        printf("Autor: %s\n", atual->autor);
        printf("Status: %s\n\n", atual->disponivel ? "Disponivel" : "Emprestado");
        atual = atual->proximo;
    }
}

// Realiza o empréstimo de um livro
void emprestar_livro(Livro* cabeca, const char* titulo) {
    Livro* atual = cabeca;
    int encontrado = 0;

    while(atual != NULL) {
        if(strcasecmp(atual->titulo, titulo) == 0) {
            encontrado = 1;
            if(atual->disponivel) {
                atual->disponivel = 0;
                printf("Livro '%s' emprestado com sucesso!\n", titulo);
            } else {
                printf("O livro '%s' ja esta emprestado!\n", titulo);
            }
            break;
        }
        atual = atual->proximo;
    }

    if(!encontrado) {
        printf("Livro '%s' nao encontrado na biblioteca!\n", titulo);
    }
}

// Realiza a devolução de um livro
void devolver_livro(Livro* cabeca, const char* titulo) {
    Livro* atual = cabeca;
    int encontrado = 0;

    while(atual != NULL) {
        if(strcasecmp(atual->titulo, titulo) == 0) {
            encontrado = 1;
            if(!atual->disponivel) {
                atual->disponivel = 1;
                printf("Livro '%s' devolvido com sucesso!\n", titulo);
            } else {
                printf("O livro '%s' ja esta disponivel!\n", titulo);
            }
            break;
        }
        atual = atual->proximo;
    }

    if(!encontrado) {
        printf("Livro '%s' nao encontrado na biblioteca!\n", titulo);
    }
}

// Libera a memória alocada para a lista
void liberar_lista(Livro* cabeca) {
    Livro* atual = cabeca;
    while(atual != NULL) {
        Livro* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

// Exibe o menu de opções
void menu() {
    printf("\n=== SISTEMA DE BIBLIOTECA ===\n");
    printf("1. Adicionar livro\n");
    printf("2. Listar todos os livros\n");
    printf("3. Emprestar livro\n");
    printf("4. Devolver livro\n");
    printf("5. Sair\n");
}

// Limpa o buffer do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

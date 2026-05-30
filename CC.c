#include <stdio.h>

/* private defines */
#define TAMANHO_NOME 100
#define TOTAL_PESSOAS 5
/* --------------- */

typedef struct
{
    char nome[TAMANHO_NOME];
    unsigned int idade;
}Pessoa_t;

/* cabeçalho das funções */
static void registrar_pessoa(Pessoa_t *pessoa, const char *nome, unsigned int idade);
static void mostrar_registro(const Pessoa_t *pessoa);
/* ------------------- */

static void registrar_pessoa(Pessoa_t *pessoa, const char *nome, unsigned int idade)
{
    size_t index = 0;

/* insere a String na struct até encontrar o delimitador */
    while(nome[index] != '\0' && index < TAMANHO_NOME - 1)
    {
        pessoa -> nome[index] = nome[index];
        index++;
    }

    pessoa -> nome[index] = '\0'; /* insere o delimitador da String no final dela */
    pessoa -> idade = idade;
}

static void mostrar_registro(const Pessoa_t *pessoa)
{
    puts("========================");
    printf("NOME: %s \nIDADE: %u\n", pessoa -> nome, pessoa -> idade);
}

int main(void)
{
    Pessoa_t pessoa[TOTAL_PESSOAS];

    registrar_pessoa(&pessoa[0], "Lucas Oliveira", 25);
    registrar_pessoa(&pessoa[1], "Arthur Menegat", 20);
    registrar_pessoa(&pessoa[2], "Paulo Cesar", 50);
    registrar_pessoa(&pessoa[3], "Joao Victor", 26);
    registrar_pessoa(&pessoa[4], "Jair Mendes", 37);

    for(int index = 0; index < TOTAL_PESSOAS; index++)
    {
        mostrar_registro(&pessoa[index]);
    }

    return 0;
}

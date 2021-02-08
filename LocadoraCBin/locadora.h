
#include <ctype.h>
#include <stdio.h>

/* quantidade m�xima de letras do nome do cliente e do filme */
#define MAX 100

/* defini��o da struct do filme */
typedef struct filme
{
	/* campos da struct filme */
	int id;
	int id_cliente;
	char nome[MAX];
	float preco;
} t_filme;

typedef enum dados_filme{nome, preco} data_filme;

/* defini��o da struct cliente */
typedef struct cliente
{
	/* campos da struct cliente */
	int id;
	char nome[MAX];
} t_cliente;

/* prot�tipos de fun��es */

char *menu(); /* exibe as op��es do programa */
void cadastrar_cliente(); /* cadastra um cliente pelo nome */
void cadastrar_filme(); /* cadastra um filme com o nome e pre�o */
void listar_filmes(); /* exibe todos os filmes cadastrados e as info. de aluguel */
void listar_clientes(); /* exibe todos os clientes cadastrados */
t_filme *obter_filme(FILE *arq_filmes, int id_filme); /* procura um filme pelo id */
t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente); /* procura um cliente pelo id */
char *obter_nome_cliente(FILE *arq_clientes, int id_cliente); /* obtem o nome do cliente pelo id */
void pesquisar_filme(); /* pesquisa por um filme e exibe suas informa��es */
void pesquisar_cliente(); /* pesquisa por um cliente e exibe suas informa��es */
int existe_filme(FILE *arq_filmes, int id_filme); /* procura um filme pelo seu id */
int existe_cliente(FILE *arq_clientes, int id_cliente); /* procura um cliente pelo seu id */
void atualizar_filmes(FILE *arq_filmes, t_filme *filme_alugado); /* atualiza as info. do filme */
void alugar_filme(); /* aluga um filme */
void entregar_filme(); /* entrega um filme */
void entregar_o_filme(int id_filme, FILE *arq_filmes); /* entregar o filme com o id_filme */
void entregar_todos_filmes_cliente(int id_cliente); /* entregar todos os filmes de um cliente */
void excluir_filme(); /* exclui um filme */
void excluir_cliente(); /* exclui um cliente */
int str_somente_numeros(char str[]); /* informa se a string � um n�mero */
void rodar(); /* roda a fun��o principal do programa! */
void limpar_filmes(); /* limpa o conte�do do arquivo de filmes! */
void limpar_clientes(); /* limpa o conte�do do arquivo de clientes! */
void alterar_nome_cliente(); /* altera o nome de um cliente j� cadastrado! */
void alterar_nome_filme(); /* altera o nome de um filme j� cadastrado! */
void alterar_preco_filme(); /* altera o preco de aluguel de um filme j� cadastrado! */
void alterar_dados_filme(data_filme datatype); /* altera um dos dados de um filme j� cadastrado! */
void exibir_nomes_clientes(FILE *arq_clientes); /* exibe a rela��o entre id's e nomes de clientes! */
void exibir_nomes_filmes(FILE *arq_filmes, int alugado, int entregue); /* exibe a rela��o entre id's e nomes de filmes! */
int nao_existe_algum_cliente(); /* n�o existe algum cliente cadastrado? */
int nao_existe_algum_filme(); /* n�o existe algum filme cadastrado? */
int nao_existe_filme_disponivel(FILE *arq_filmes); /* n�o existe filme dispon�vel para aluguel? */
int nao_existe_filme_alugado(FILE *arq_filmes); /* n�o existe filme alugado? */

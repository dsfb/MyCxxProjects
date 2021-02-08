
#include <ctype.h>
#include <stdio.h>

/* quantidade máxima de letras do nome do cliente e do filme */
#define MAX 100

/* definição da struct do filme */
typedef struct filme
{
	/* campos da struct filme */
	int id;
	int id_cliente;
	char nome[MAX];
	float preco;
} t_filme;

typedef enum dados_filme{nome, preco} data_filme;

/* definição da struct cliente */
typedef struct cliente
{
	/* campos da struct cliente */
	int id;
	char nome[MAX];
} t_cliente;

/* protótipos de funções */

char *menu(); /* exibe as opções do programa */
void cadastrar_cliente(); /* cadastra um cliente pelo nome */
void cadastrar_filme(); /* cadastra um filme com o nome e preço */
void listar_filmes(); /* exibe todos os filmes cadastrados e as info. de aluguel */
void listar_clientes(); /* exibe todos os clientes cadastrados */
t_filme *obter_filme(FILE *arq_filmes, int id_filme); /* procura um filme pelo id */
t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente); /* procura um cliente pelo id */
char *obter_nome_cliente(FILE *arq_clientes, int id_cliente); /* obtem o nome do cliente pelo id */
void pesquisar_filme(); /* pesquisa por um filme e exibe suas informações */
void pesquisar_cliente(); /* pesquisa por um cliente e exibe suas informações */
int existe_filme(FILE *arq_filmes, int id_filme); /* procura um filme pelo seu id */
int existe_cliente(FILE *arq_clientes, int id_cliente); /* procura um cliente pelo seu id */
void atualizar_filmes(FILE *arq_filmes, t_filme *filme_alugado); /* atualiza as info. do filme */
void alugar_filme(); /* aluga um filme */
void entregar_filme(); /* entrega um filme */
void entregar_o_filme(int id_filme, FILE *arq_filmes); /* entregar o filme com o id_filme */
void entregar_todos_filmes_cliente(int id_cliente); /* entregar todos os filmes de um cliente */
void excluir_filme(); /* exclui um filme */
void excluir_cliente(); /* exclui um cliente */
int str_somente_numeros(char str[]); /* informa se a string é um número */
void rodar(); /* roda a função principal do programa! */
void limpar_filmes(); /* limpa o conteúdo do arquivo de filmes! */
void limpar_clientes(); /* limpa o conteúdo do arquivo de clientes! */
void alterar_nome_cliente(); /* altera o nome de um cliente já cadastrado! */
void alterar_nome_filme(); /* altera o nome de um filme já cadastrado! */
void alterar_preco_filme(); /* altera o preco de aluguel de um filme já cadastrado! */
void alterar_dados_filme(data_filme datatype); /* altera um dos dados de um filme já cadastrado! */
void exibir_nomes_clientes(FILE *arq_clientes); /* exibe a relação entre id's e nomes de clientes! */
void exibir_nomes_filmes(FILE *arq_filmes, int alugado, int entregue); /* exibe a relação entre id's e nomes de filmes! */
int nao_existe_algum_cliente(); /* não existe algum cliente cadastrado? */
int nao_existe_algum_filme(); /* não existe algum filme cadastrado? */
int nao_existe_filme_disponivel(FILE *arq_filmes); /* não existe filme disponível para aluguel? */
int nao_existe_filme_alugado(FILE *arq_filmes); /* não existe filme alugado? */

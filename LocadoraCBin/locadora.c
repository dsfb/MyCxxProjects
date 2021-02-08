#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif

#include <stdlib.h>
#include <string.h>
#include "locadora.h"
#include "utils.h"

/* rodar a aplicação principal de um programa console */
void rodar() {
    while(1)
	{
	    char resp[3];

        char *choice = menu();

		/* obtém a escolha do usuário */
		strcpy(resp, choice);

        free(choice);

		/* testa o valor de resp */
		if(!strcmp(resp, "1"))
			cadastrar_filme();
		else if(!strcmp(resp, "2"))
			cadastrar_cliente();
		else if(!strcmp(resp, "3"))
			listar_filmes();
		else if(!strcmp(resp, "4"))
			listar_clientes();
		else if(!strcmp(resp, "5"))
			pesquisar_filme();
		else if(!strcmp(resp, "6"))
			pesquisar_cliente();
		else if(!strcmp(resp, "7"))
			alugar_filme();
		else if(!strcmp(resp, "8"))
			entregar_filme();
		else if(!strcmp(resp, "9"))
			excluir_filme();
        else if (!strcmp(resp, "10"))
            excluir_cliente();
        else if (!strcmp(resp, "11"))
            limpar_clientes();
        else if (!strcmp(resp, "12"))
            limpar_filmes();
        else if (!strcmp(resp, "13"))
            alterar_nome_cliente();
        else if (!strcmp(resp, "14"))
            alterar_nome_filme();
        else if (!strcmp(resp, "15"))
            alterar_preco_filme();
		else if(!strcmp(resp, "0"))
			break;
		else
		{
		    printf("Voce digitou %s\n", resp);
			printf("\nOpcao invalida! Pressione <Enter> para continuar...");
			scanf("%*c");

			/* uma forma de limpar o buffer de entrada */
			fseek(stdin, 0, SEEK_END);
		}

		system(limpar_tela);
	}

	printf("\nBye! Curso de Linguagem C para Iniciantes ;-)\n");
}

char *menu()
{
	char *resp = malloc(3);

	printf("------------------------------ Locadora GeeksBR ------------------------------");
	printf("\n\n1  - Cadastrar um filme\n");
	printf("2  - Cadastrar um cliente\n");
	printf("3  - Listar todos os filmes\n");
	printf("4  - Listar todos os clientes\n");
	printf("5  - Pesquisar por filme\n");
	printf("6  - Pesquisar por cliente\n");
	printf("7  - Alugar um filme\n");
	printf("8  - Entregar um filme\n");
	printf("9  - Excluir um filme\n");
	printf("10 - Excluir um cliente\n");
	printf("11 - Limpar o arquivo de clientes\n");
	printf("12 - Limpar o arquivo de filmes\n");
	printf("13 - Alterar o nome de um cliente ja cadastrado\n");
	printf("14 - Alterar o nome de um filme ja cadastrado\n");
	printf("15 - Alterar o preco de um filme ja cadastrado\n");
	printf("0  - Sair\n");
	printf("Digite o numero da opcao: ");
	scanf("%2s%*c", resp);

	fseek(stdin, 0, SEEK_END);

	/* se chegou aqui, é porque a opção é válida */
	return resp;
}

int str_somente_numeros(char str[])
{
	int i = 0;
	int len_str = strlen(str);

	for(i = 0; i < len_str; i++)
	{
		if(str[i] < '0' || str[i] > '9')
			return 0;
	}

	return 1;
}

void cadastrar_cliente()
{
	FILE *arq_clientes = fopen("clientes.bin", "a+b");

    int cont_bytes = 0;

    t_cliente cliente;

	if(arq_clientes == NULL)
	{
		printf("\nFalha ao abrir o arquivo!\n");
		exit(1);
	}

	fseek(arq_clientes, 0, SEEK_END);

	cont_bytes = ftell(arq_clientes);

	if(cont_bytes == 0)
	{
		cliente.id = 1;
	}
	else
	{
		t_cliente ultimo_cliente;

		fseek(arq_clientes, cont_bytes - sizeof(t_cliente), SEEK_SET);

		fread(&ultimo_cliente, sizeof(t_cliente), 1, arq_clientes);

		cliente.id = ultimo_cliente.id + 1;
	}

	printf("\nDigite o nome do cliente: ");
	scanf("%99[^\n]%*c", cliente.nome);

	fseek(stdin, 0, SEEK_END);

	/* se o ponteiro não estiver no final do arquivo, nada é escrito */
	fseek(arq_clientes, 0, SEEK_END);

	/* escreve no arquivo */
	fwrite(&cliente, sizeof(t_cliente), 1, arq_clientes);

	fclose(arq_clientes);

	printf("\nCliente \"%s\" cadastrado com sucesso!", cliente.nome);
	printf("\nID deste cliente: \"%d\"\n", cliente.id);
	pause();
}

void cadastrar_filme()
{
	FILE *arq_filmes = fopen("filmes.bin", "a+b");

	t_filme filme;

	int cont_bytes = 0;

	if(arq_filmes == NULL)
	{
		printf("\nFalha ao abrir o arquivo!\n");
		pause();
		exit(1);
	}

	/* seta o ponteiro do arquivo para o final do arquivo */
	fseek(arq_filmes, 0, SEEK_END);

	/* guarda o número total de bytes */
	cont_bytes = ftell(arq_filmes);

	if(cont_bytes == 0)
	{
		filme.id = 1;
	}
	else
	{
		t_filme ultimo_filme;

		fseek(arq_filmes, cont_bytes - sizeof(t_filme), SEEK_SET);

		/* ler o filme */
		fread(&ultimo_filme, sizeof(t_filme), 1, arq_filmes);

		filme.id = ultimo_filme.id + 1;
	}

	/* obtém o nome do filme */
	printf("\nDigite o nome do filme: ");
	scanf("%99[^\n]%*c", filme.nome);

	fseek(stdin, 0, SEEK_END);

	do
	{
		char str_preco[5];
		int somente_numeros;

		/* obtém o preço do filme */
		printf("Digite o preco do filme: ");
		scanf("%4s%*c", str_preco);

		fseek(stdin, 0, SEEK_END);

		/* verifica se o preço possui somente números */
		somente_numeros = str_somente_numeros(str_preco);

		if(somente_numeros == 1)
		{
		    float float_preco;

			int int_preco;

			/* exemplo: 49,10 deve digitar 4910 */
			sscanf(str_preco, "%d", &int_preco);
			float_preco = int_preco / 100.0;
			filme.preco = float_preco;
			break;
		}
	}
	while(1);

	/* inicializa o id do cliente com -1 para indicar que o filme não está alugado */
	filme.id_cliente = -1;

	fseek(arq_filmes, 0, SEEK_END);

	/* escreve no arquivo */
	fwrite(&filme, sizeof(t_filme), 1, arq_filmes);

	/* fecha o arquivo */
	fclose(arq_filmes);

	printf("\nFilme \"%s\" cadastrado com sucesso!", filme.nome);
	printf("\nID deste filme: \"%d\"\n", filme.id);
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");

	fseek(stdin, 0, SEEK_END);
}

void listar_filmes()
{
	FILE *arq_filmes = fopen("filmes.bin", "rb");
	FILE *arq_clientes = fopen("clientes.bin", "rb");

    int encontrou_filmes = 0;

	t_filme filme;

	if(arq_filmes == NULL)
	{
		printf("\nFalha ao abrir arquivo ou ");
		printf("Nenhum filme cadastrado.\n");
		pause();

		if(arq_clientes != NULL)
            fclose(arq_clientes);

		return;
	}

	printf("\nListando todos os filmes...\n");

	while(1)
	{
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

		if(result == 0)
			break;

		encontrou_filmes = 1;

		printf("\nID do filme: %d\n", filme.id);
		printf("Nome do filme: %s\n", filme.nome);
		printf("Preco: %.2f\n", filme.preco);

		/* se for diferente de -1, então o filme está alugado */
		if(filme.id_cliente != -1)
		{
		    t_cliente *cliente;

			if(arq_clientes == NULL)
			{
				printf("\nFalha ao abrir arquivo!\n");
				fclose(arq_filmes);
				exit(1);
			}

			cliente = obter_cliente(arq_clientes, filme.id_cliente);
			printf("Alugado? Sim.\nCliente: %s\nID do cliente: %d\n", cliente->nome, cliente->id);
			free(cliente);
		}
		else
			printf("Alugado? Nao\n");
	}

	/* verifica se encontrou pelo menos um filme */
	if(encontrou_filmes == 0)
		printf("\nNenhum filme cadastrado.\n");

	if(arq_clientes != NULL)
		fclose(arq_clientes);

	fclose(arq_filmes);

	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");

	fseek(stdin, 0, SEEK_END);
}

t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente)
{
    t_cliente *cliente;

	/* vai para o início do arquivo */
	rewind(arq_clientes);

	cliente = (t_cliente *)malloc(sizeof(t_cliente));

	while(1)
	{
		/* retorna o número de elementos lidos com sucesso */
		size_t result = fread(cliente, sizeof(t_cliente), 1, arq_clientes);

		if(result == 0)
		{
			free(cliente);
			return NULL;
		}

		if(cliente->id == id_cliente)
			break;
	}

	return cliente;
}

char *obter_nome_cliente(FILE *arq_clientes, int id_cliente) {
    t_cliente *cliente = obter_cliente(arq_clientes, id_cliente);

    if (cliente != NULL) {
        return cliente->nome;
    }

    return NULL;
}

void listar_clientes()
{
    int encontrou_clientes = 0;
	t_cliente cliente;

    if(nao_existe_algum_cliente())
	{
		printf("\nFalha ao abrir arquivo(s) ou ");
		printf("Nenhum cliente cadastrado.\n");
		pause();
		return;
	}

    /* abre o arquivo binário para leitura */
	FILE *arq_clientes = fopen("clientes.bin", "rb");

	printf("\nListando todos os clientes...\n");

	while(1)
	{
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);

		if(result == 0)
			break;

		encontrou_clientes = 1;

		printf("\nID do cliente: %d\n", cliente.id);
		printf("Nome do cliente: %s\n", cliente.nome);
	}

	if(encontrou_clientes == 0)
		printf("\nNenhum cliente cadastrado.\n");

	fclose(arq_clientes);

	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");

	fseek(stdin, 0, SEEK_END);
}

int nao_existe_algum_cliente() {
    /* abre o arquivo binário para leitura */
	FILE *arq_clientes = fopen("clientes.bin", "rb");

	int result = arq_clientes == NULL;

	if (arq_clientes)
        fclose(arq_clientes);

    return result;
}

void exibir_nomes_clientes(FILE *arq_clientes) {
    t_cliente cliente;

    while(1)
	{
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);

		if(result == 0)
			break;

		printf("\n(Dados do cliente) ID: %d\tNome: %s", cliente.id, cliente.nome);
	}
}

void exibir_nomes_filmes(FILE *arq_filmes, int alugado, int entregue) {
    t_filme filme;

    while(1) {
        size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

        if(result == 0)
            break;

        if (!entregue) {
            if (alugado && filme.id_cliente != -1)
                continue;

            printf("\n(Dados do filme) ID: %d\tNome: %s", filme.id, filme.nome);
        } else {
            if (filme.id_cliente != -1)
                printf("\n(Dados do filme) ID: %d\tNome: %s", filme.id, filme.nome);
        }
    }
}

void pesquisar_filme()
{
	char nome[MAX];
	int encontrou_filme = 0;

	t_filme filme;

	FILE *arq_filmes = fopen("filmes.bin", "rb");
	FILE *arq_clientes = fopen("clientes.bin", "rb");

	if(arq_filmes == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");

		if(arq_clientes != NULL)
            fclose(arq_clientes);

		return; /* aborta o programa */
	}

	printf("\nDigite o comeco do nome do filme: ");
	scanf("%99[^\n]%*c", nome);

	printf("\nFilmes com o nome comecando com \"%s\":\n\n", nome);

	while(1)
	{
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

		char nome_aux[MAX];

		if(result == 0)
			break;

		strcpy(nome_aux, filme.nome);

		if(starts_with(strupr(nome_aux), strupr(nome)))
		{
			printf("(Dados do Filme) ID: %d\tNome: %s\tPreco: %.2f\n", filme.id, filme.nome, filme.preco);

			if(filme.id_cliente != -1)
			{
			    t_cliente *cliente;

				if(arq_clientes == NULL)
				{
					printf("\nFalha ao abrir arquivo!\n");
					fclose(arq_filmes);
					exit(1);
				}

				cliente = obter_cliente(arq_clientes, filme.id_cliente);

				printf("Alugado? Sim. Cliente: %s\n", cliente->nome);
				free(cliente);
			}
			else
				printf("Alugado? Nao\n");
            printf("--------------------------------------------------------------------------------------\n");
			encontrou_filme = 1;
			printf("\n");
		}
	}

	if(encontrou_filme == 0)
		printf("Nenhum filme encontrado.\n\n");

	fclose(arq_filmes);

    if(arq_clientes != NULL)
		fclose(arq_clientes);

	printf("Pressione <Enter> para continuar...");
	scanf("%*c");

	fseek(stdin, 0, SEEK_END);
}

void pesquisar_cliente()
{
	char nome[MAX];
	int encontrou_cliente = 0;

	t_cliente cliente;

	FILE *arq_clientes = fopen("clientes.bin", "rb");

	if(arq_clientes == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		return; /* aborta o programa */
	}

	printf("\nDigite o comeco do nome do cliente: ");
	scanf("%99[^\n]%*c", nome);

	printf("\nClientes com o nome comecando com \"%s\":\n\n", nome);

	while(1)
	{
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);

		char nome_aux[MAX];

		if(result == 0)
			break;

		strcpy(nome_aux, cliente.nome);

		if(starts_with(strupr(nome_aux), strupr(nome)))
		{
			/* mostra os dados do cliente */
			printf("ID do cliente: %d\tNome do cliente: %s\n", cliente.id, cliente.nome);
			printf("--------------------------------------------------------------------\n");
			encontrou_cliente = 1;
		}
	}

	if(encontrou_cliente == 0)
		printf("Nenhum cliente encontrado.\n\n");

	fclose(arq_clientes);
    pause();
}

int nao_existe_filme_alugado(FILE *arq_filmes) {
    int resultado = 1;
    t_filme filme;

	while(1) {
        size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

        if(result == 0)
			break;

        if (filme.id_cliente != -1) {
            resultado = 0;
            break;
        }
	}

    fclose(arq_filmes);

    return resultado;
}

int nao_existe_filme_disponivel(FILE *arq_filmes) {
    int resultado = 1;
    t_filme filme;

	while(1) {
        size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

        if(result == 0)
			break;

        if (filme.id_cliente == -1) {
            resultado = 0;
            break;
        }
	}

    fclose(arq_filmes);

    return resultado;
}

void alugar_filme()
{
	char str_id_cliente[11];
	int id_cliente;

	FILE *arq_filmes = fopen("filmes.bin", "rb+");
	FILE *arq_clientes = fopen("clientes.bin", "rb+");

	if(arq_filmes == NULL)
	{
		arq_filmes = fopen("filmes.bin", "wb+");
		if(arq_filmes == NULL)
		{
			printf("\nFalha ao criar arquivo(s)!\n");
			if (arq_clientes) {
                fclose(arq_clientes);
			}
			pause();
			return; /* aborta o programa */
		}
	}

	if(nao_existe_filme_disponivel(arq_filmes)) {
        printf("\nNao eh possivel alugar um filme, pois nao existe algum filme disponivel para aluguel!\n");
        if (arq_clientes) {
            fclose(arq_clientes);
        }
        pause();
        return;
	}

	if(arq_clientes == NULL)
	{
		arq_clientes = fopen("clientes.bin", "wb+");
		if(arq_clientes == NULL)
		{
			printf("\nFalha ao criar arquivo(s)!\n");
			pause();
			return;
		}
	}

	exibir_nomes_clientes(arq_clientes);
	printf("\nDigite o ID do cliente: ");
	scanf("%10s%*c", str_id_cliente);

	fseek(stdin, 0, SEEK_END);

	if(str_somente_numeros(str_id_cliente) == 1)
	{
		sscanf(str_id_cliente, "%d", &id_cliente);

		if(existe_cliente(arq_clientes, id_cliente))
		{
			char str_id_filme[11];
			int id_filme;

            exibir_nomes_filmes(arq_filmes, 1, 0);
			printf("\nDigite o ID do filme: ");
			scanf("%10s%*c", str_id_filme);

			fseek(stdin, 0, SEEK_END);

			if(str_somente_numeros(str_id_filme) == 1)
			{
			    t_filme *filme;

				sscanf(str_id_filme, "%d", &id_filme);

				filme = obter_filme(arq_filmes, id_filme);

				/* testa se o filme existe */
				if(filme != NULL)
				{
					/* testa se o filme já está alugado */
					if(filme->id_cliente != -1)
						printf("\nO filme \"%s\" ja esta alugado!\n", filme->nome);
					else
					{
						filme->id_cliente = id_cliente;
						atualizar_filmes(arq_filmes, filme);
						printf("\nFilme \"%s\" foi alugado com sucesso para o cliente: \"%s\"!\n", filme->nome,
                            obter_nome_cliente(arq_clientes, id_cliente));
					}
					free(filme);
				}
				else
					printf("\nNao existe filme com o ID \"%d\".\n", id_filme);
			}
			else
				printf("\nO ID so pode conter numeros!\n");
		}
		else
			printf("\nNao existe cliente com o ID \"%d\".\n", id_cliente);
	}
	else
		printf("\nO ID so pode conter numeros!\n");

	fclose(arq_clientes);
	fclose(arq_filmes);
    pause();
}

int existe_cliente(FILE *arq_clientes, int id_cliente)
{
    t_cliente cliente;

	/* vai para o início do arquivo */
	rewind(arq_clientes);

	while(1)
	{
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);

		if(result == 0)
			break;

		if(cliente.id == id_cliente)
			return 1;
	}

	return 0;
}

t_filme *obter_filme(FILE *arq_filmes, int id_filme)
{
    t_filme *filme;

	rewind(arq_filmes);

	filme = (t_filme *)malloc(sizeof(t_filme));

	while(1)
	{
		size_t result = fread(filme, sizeof(t_filme), 1, arq_filmes);

		if(result == 0)
			break;

		if(filme->id == id_filme)
			return filme;
	}

	free(filme);
	return NULL;
}

void atualizar_filmes(FILE *arq_filmes, t_filme *filme_alugado)
{
    t_filme filme;

	rewind(arq_filmes);

	while(1)
	{
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

		if(result == 0)
			break;

		if(filme.id == filme_alugado->id)
		{
			/* posiciona o arquivo */
			fseek(arq_filmes, - sizeof(t_filme), SEEK_CUR);

			/* atualiza o filme */
			fwrite(filme_alugado, sizeof(t_filme), 1, arq_filmes);

			/* sai do loop */
			break;
		}
	}
}

void atualizar_clientes(FILE *arq_clientes, t_cliente *cliente_atualizado)
{
    t_cliente cliente;

	rewind(arq_clientes);

	while(1)
	{
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);

		if(result == 0)
			break;

		if(cliente.id == cliente_atualizado->id)
		{
			/* posiciona o arquivo */
			fseek(arq_clientes, - sizeof(t_cliente), SEEK_CUR);

			/* atualiza o filme */
			fwrite(cliente_atualizado, sizeof(t_cliente), 1, arq_clientes);

			/* sai do loop */
			break;
		}
	}
}

/* entregar todos os filmes de um cliente */
void entregar_todos_filmes_cliente(int id_cliente) {
    FILE *arq_filmes = fopen("filmes.bin", "rb+");

    t_filme *filme;

    if (arq_filmes == NULL) {
        printf("\nArquivo inexistente! Operacao de entrega de todos os filmes esta cancelada!\n");
        pause();
        return;
    }

    filme = (t_filme *) malloc(sizeof(t_filme));
    if (filme != NULL) {
        int filmes[128], indice = -1;
        while (indice < 127) {
            size_t result = fread(filme, sizeof(t_filme), 1,
                                  arq_filmes);
            if (!result)
                break;

            if (filme->id_cliente == id_cliente) {
                filme->id_cliente = -1;
                atualizar_filmes(arq_filmes, &filme);
            }
        }

        free(filme);
    }

    fclose(arq_filmes);
}

void limpar_filmes() {
    FILE *arq_filmes = fopen("filmes.bin", "wb");

    fclose(arq_filmes);

    printf("\nO arquivo de filmes foi limpo com sucesso!");
    pause();
}

void limpar_clientes() {
    FILE *arq_clientes = fopen("clientes.bin", "wb");

    fclose(arq_clientes);

    printf("\nO arquivo de clientes foi limpo com sucesso!");
    pause();
}

/* entregar o filme com o id_filme */
void entregar_o_filme(int id_filme, FILE *arq_filmes) {
    t_filme *filme;

    filme = obter_filme(arq_filmes, id_filme);

    if(filme != NULL)
    {
        if(filme->id_cliente == -1)
            printf("\nO filme \"%s\" ja esta disponivel!\n", filme->nome);
        else
        {
            filme->id_cliente = -1;
            atualizar_filmes(arq_filmes, filme); /* atualiza o filme no arquivo */
            printf("\nFilme \"%s\" entregue com sucesso!\n", filme->nome);
        }

        free(filme);
    }
    else
        printf("\nNao existe filme com o ID \"%d\".\n", id_filme);

    pause();
}

void entregar_filme()
{
	char str_id_filme[11];
	int id_filme;

	FILE *arq_filmes = fopen("filmes.bin", "rb+");

	if(arq_filmes == NULL)
	{
	    printf("\nArquivo inexistente! Operacao de entrega de filme esta cancelada!\n");
	    pause();
        return;
	}

	if(nao_existe_filme_alugado(arq_filmes)) {
        printf("\nNao eh possivel entregar um filme, pois nao existe algum filme jah alugado!\n");
        pause();
        return;
	}

	exibir_nomes_filmes(arq_filmes, 0, 1);
	printf("\nDigite o ID do filme: ");
	scanf("%10s%*c", str_id_filme);

	fseek(stdin, 0, SEEK_END);

	if(str_somente_numeros(str_id_filme) == 1)
	{
	    sscanf(str_id_filme, "%d", &id_filme);

		entregar_o_filme(id_filme, arq_filmes);
	}
	else
		printf("\nO ID so pode conter numeros!\n");

	fclose(arq_filmes);

	pause();
}

void excluir_filme()
{
	char str_id_filme[11];
	int id_filme;

	printf("\nDigite o ID do filme: ");
	scanf("%10s%*c", str_id_filme);

	fseek(stdin, 0, SEEK_END);

	if(str_somente_numeros(str_id_filme) == 1)
	{
	    FILE *arq_filmes;

		sscanf(str_id_filme, "%d", &id_filme);

		arq_filmes = fopen("filmes.bin", "rb");

		if(arq_filmes == NULL)
		{
			printf("\nFalha ao abrir arquivo(s)!\n");
			pause();
			return;
		}

		if(existe_filme(arq_filmes, id_filme) == 1)
		{
			char nome_filme[MAX];

			FILE *arq_temp = fopen("temp_filmes.bin", "a+b");

			t_filme filme;

			if(arq_temp == NULL)
			{
				printf("\nFalha ao criar arquivo temporario!\n");
				fclose(arq_filmes);
				exit(1); /* aborta o programa */
			}

			rewind(arq_filmes);

			while(1)
			{
				size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

				if(result == 0)
					break;

				if(filme.id != id_filme)
				{
					fwrite(&filme, sizeof(t_filme), 1, arq_temp);
				}
				else
					strcpy(nome_filme, filme.nome);
			}

			fclose(arq_filmes);
			fclose(arq_temp);

			if(remove("filmes.bin") != 0)
				printf("\nErro ao deletar o arquivo \"filmes.bin\"\n");
			else
			{
				/* renomeia o arquivo */
				int r = rename("temp_filmes.bin", "filmes.bin");

				if(r != 0)
				{
					printf("\nPermissao negada para renomear o arquivo!\n");
					printf("Feche esse programa bem como o arquivo \"temp_filmes.bin\" e renomeie manualmente para \"filmes.bin\"\n");
				}
				else
					printf("\nFilme \"%s\" removido com sucesso!\n", nome_filme);
			}
		}
		else
		{
			fclose(arq_filmes);
			printf("\nNao existe filme com o ID \"%d\".\n", id_filme);
		}
	}
	else
		printf("\nO ID so pode conter numeros!\n");

    pause();
}

void excluir_cliente() {
    char str_id_cliente[11];
    int id_cliente;

    printf("\nDigite o ID do cliente: ");
    scanf("%10s%*c", str_id_cliente);

    fseek(stdin, 0, SEEK_END);

    if (str_somente_numeros(str_id_cliente) == 1) {
        FILE *arq_clientes;

        sscanf(str_id_cliente, "%d", &id_cliente);

        arq_clientes = fopen("clientes.bin", "rb");

        if (arq_clientes == NULL) {
            printf("\nFalha ao abrir arquivo(s)!\n");
            pause();
            return;
        }

        if (existe_cliente(arq_clientes, id_cliente) == 1) {
            char nome_cliente[MAX];

            FILE *arq_temp = fopen("temp_clientes.bin", "a+b");

            t_cliente cliente;

            if (arq_temp == NULL) {
                printf("\nFalha ao criar arquivo temporario!\n");
                fclose(arq_clientes);
                exit(1); /* aborta o programa */
            }

            rewind(arq_clientes);

            while (1) {
                size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);

                if (result == 0)
                    break;

                if (cliente.id != id_cliente) {
                    fwrite(&cliente, sizeof(t_cliente), 1, arq_temp);
                } else strcpy(nome_cliente, cliente.nome);
            }

            fclose(arq_clientes);
            fclose(arq_temp);

            if(remove("clientes.bin") != 0)
                printf("\nErro ao deletar o arquivo \"clientes.bin\"\n");
            else {
                /* renomeia o arquivo */
                int r = rename("temp_clientes.bin", "clientes.bin");

                if (r != 0) {
                    printf("\nPermissao negada para renomear o arquivo!\n");
                    printf("Feche este programa bem com o arquivo \"temp_clientes.bin\" e renomeie manualmente para \"clientes.bin\"\n");
                } else {
                    printf("\nCliente \"%s\" removido com sucesso!\n", nome_cliente);
                    entregar_todos_filmes_cliente(id_cliente);
                    printf("\nFilmes entregues do cliente \"%s\" com sucesso!\n", nome_cliente);
                }
            }
        } else {
            fclose(arq_clientes);
            printf("\nNao existe cliente com o ID \"%d\".\n", id_cliente);
        }
    } else printf("\nO ID so pode conter numeros!\n");

    pause();
}

int existe_filme(FILE *arq_filmes, int id_filme)
{
    t_filme filme;

	rewind(arq_filmes);

	while(1)
	{
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

		if(result == 0)
			break;

		if(filme.id == id_filme)
			return 1;
	}

	return 0;
}

/* altera o nome de um cliente já cadastrado! */
void alterar_nome_cliente() {
    FILE *arq_clientes = fopen("clientes.bin", "rb+");
    int id_cliente;
    char str_id_cliente[11];

    if (arq_clientes == NULL) {
        printf("\nOpa! O arquivo de clientes nao existe! Abortando a operacao de alteracao de nome de cliente...!");
        pause();
        return;
    }

    exibir_nomes_clientes(arq_clientes);
    rewind(arq_clientes);

    printf("\nDigite o ID do cliente: ");
	scanf("%10s%*c", str_id_cliente);

	fseek(stdin, 0, SEEK_END);

	if(str_somente_numeros(str_id_cliente) == 1) {
		sscanf(str_id_cliente, "%d", &id_cliente);

		if(existe_cliente(arq_clientes, id_cliente)) {
            char nome[MAX];
            t_cliente *cliente;
            cliente = obter_cliente(arq_clientes, id_cliente);
            printf("\nNome antigo do cliente: \"%s\"\n", cliente->nome);
            printf("Digite o novo nome do cliente: ");
            scanf("%99[^\n]%*c", nome);
            printf("\nVoce digitou a seguinte opcao: \"%s\"\n", nome);
            strcpy(cliente->nome, nome);
            atualizar_clientes(arq_clientes, cliente);
            printf("\nEste cliente teve o nome alterado com sucesso!\n");
            free(cliente);
		} else
			printf("\nNao existe cliente com o ID \"%d\".\n", id_cliente);
	} else
		printf("\nO ID so pode conter numeros!\n");

    fclose(arq_clientes);
    pause();
}

/* altera um dos dados de um filme já cadastrado! */
void alterar_dados_filme(data_filme datatype) {
    FILE *arq_filmes = fopen("filmes.bin", "rb+");
    int id_filme;
    char str_id_filme[11];

    if (arq_filmes == NULL) {
        printf("\nOpa! O arquivo de filmes nao existe! Abortando a operacao de alteracao de nome de filme...!");
        pause();
        return;
    }

    exibir_nomes_filmes(arq_filmes, 0, 0);
    rewind(arq_filmes);

    printf("\nDigite o ID do filme: ");
	scanf("%10s%*c", str_id_filme);

	fseek(stdin, 0, SEEK_END);

	if(str_somente_numeros(str_id_filme) == 1) {
		sscanf(str_id_filme, "%d", &id_filme);

		if(existe_filme(arq_filmes, id_filme)) {
            t_filme *filme;
            filme = obter_filme(arq_filmes, id_filme);
            switch(datatype) {
            case nome:
                {
                    char nome[MAX];
                    printf("\nNome antigo do filme: \"%s\"\n", filme->nome);
                    printf("Digite o novo nome do filme: ");
                    scanf("%99[^\n]%*c", nome);
                    printf("\nVoce digitou a seguinte opcao: \"%s\"\n", nome);
                    strcpy(filme->nome, nome);
                }
                break;
            case preco:
                printf("\nPreco antigo do filme: \"%.2f\"\n", filme->preco);

                do
                {
                    char str_preco[5];
                    int somente_numeros;

                    /* obtém o preço do filme */
                    printf("Digite o novo preco do filme: ");
                    scanf("%4s%*c", str_preco);

                    fseek(stdin, 0, SEEK_END);

                    /* verifica se o preço possui somente números */
                    somente_numeros = str_somente_numeros(str_preco);

                    if(somente_numeros == 1)
                    {
                        printf("\nVoce digitou a seguinte opcao: \"%s\"\n", str_preco);
                        float float_preco;

                        int int_preco;

                        /* exemplo: 49,10 deve digitar 4910 */
                        sscanf(str_preco, "%d", &int_preco);
                        float_preco = int_preco / 100.0;
                        filme->preco = float_preco;
                        break;
                    }
                }
                while(1);
                break;
            default:
                printf("Erro! Tipo de dado invalido para filme!\n");
                break;
            }

            atualizar_filmes(arq_filmes, filme);
            printf("\nEste filme teve o nome alterado com sucesso!\n");
            free(filme);
		} else
			printf("\nNao existe filme com o ID \"%d\".\n", id_filme);
	} else
		printf("\nO ID so pode conter numeros!\n");

    fclose(arq_filmes);
    pause();
}

/* altera o nome de um filme já cadastrado! */
void alterar_nome_filme() {
    alterar_dados_filme(nome);
}

/* altera o preco de aluguel de um filme já cadastrado! */
void alterar_preco_filme() {
    alterar_dados_filme(preco);
}

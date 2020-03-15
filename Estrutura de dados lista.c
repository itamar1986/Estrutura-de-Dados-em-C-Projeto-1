#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Declaração da Estrutura Nodo */
typedef struct sNodo
{
	int info;
	struct sNodo *prox;
} Nodo;

/* Declaração da Estrutura Lista Simplesmente Encadeada */
typedef struct sListaSimplesEnc
{
	Nodo *prim;
} ListaSimplesEnc;

/* Função de criação de Lista Vazia */
void criarLista(ListaSimplesEnc *pList)
{
	pList->prim = NULL;
}

/* Função para Consulta da Lista */
void mostrarLista(ListaSimplesEnc *pList)
{
	Nodo *p;
	printf("Lista: ");
	for (p = pList->prim; p != NULL; p = p->prox)
	{
		printf("%d -> ", p->info);
	}
	printf("NULL\n");
}

/* Função para Inclusão de elemento no início da Lista */
void inserirIni(ListaSimplesEnc *pList, int v)
{
	Nodo *novo;
	novo = (Nodo*)malloc(sizeof(Nodo));
	if (novo != NULL)
	{
	novo->info = v;
		novo->prox = pList->prim;
		pList->prim = novo;
	}	
	else
	{
		printf("Memória Insuficiente\n");
	}
}

/* Função para remover no Inicio da Lista */
void removerIni(ListaSimplesEnc *pList)
{
	Nodo *pAux = pList->prim;
	if (pAux != NULL)
	{
		pList->prim = pList->prim->prox;
		free(pAux);
		printf("Valor Removido\n");
	}
	else
	{
		printf("Lista Vazia\n");
	}
}

/* Função para Inclusão de elemento em ordem (verifique a ordenação) */
void inserirOrd(ListaSimplesEnc *pList, int v)
{
	Nodo *novo;
	novo = (Nodo*)malloc(sizeof(Nodo));
	if (novo != NULL)
	{
		novo->info = v;
		Nodo *pAtu, *pAnt;
		pAnt = NULL;
		pAtu = pList->prim;
		while (pAtu != NULL && pAtu->info < v)
		{
			pAnt = pAtu;
			pAtu = pAtu->prox;
		}
		novo->prox = pAtu;
		if (pAnt != NULL)
		{
			pAnt->prox = novo;
		}
		else
		{
			pList->prim = novo;
		}
	}
	else
	{
		printf("Memória Insuficiente\n");
	}
}

/* Função para Remoção de elemento específico da Lista */
void removerEle(ListaSimplesEnc *pList, int v)
{
	Nodo *pAtu, *pAnt;
	pAnt = NULL;
	pAtu = pList->prim;
	while (pAtu != NULL && pAtu->info != v)
	{
		pAnt = pAtu;
		pAtu = pAtu->prox;
	}
	if (pAnt != NULL)
	{
		if (pAtu != NULL) {
			pAnt->prox = pAtu->prox;
			free(pAtu);
			printf("Valor Removido\n");
		}
		else
		{
			printf("Valor não encontrado\n");
		}
	}
	else
	{
		printf("Lista Vazia\n");
	}
}

/* Função para Remoção de todos os elementos da Lista */
void removerTudo(ListaSimplesEnc *pList)
{
	Nodo *pAux = pList->prim;
	if (pAux != NULL)
	{
		while (pAux != NULL)
		{
			pList->prim = pAux->prox;
			free(pAux);
			pAux = pList->prim;
		}
		printf("Todos os elementos foram removidos!\n");
	}
	else
	{
		printf("Lista Vazia\n");
	}
}

/* Função para Alteração de elemento da Lista */
void alterarEle(ListaSimplesEnc *pList, int v1, int v2)
{
	Nodo *pAtu, *pAnt;
	pAnt = NULL;
	pAtu = pList->prim;
	while (pAtu != NULL && pAtu->info != v1)
	{
		pAnt = pAtu;
		pAtu = pAtu->prox;
	}
	if (pAnt != NULL)
	{
		if (pAtu != NULL)
		{
			pAtu->info = v2;
			printf("Valor alterado\n");
		}
		else
		{
			printf("Valor não encontrado\n");
		}
	}
	else
	{
		printf("Lista Vazia\n");
	}
}

/* Função para verificar Lista Vazia */
int estaVazia(ListaSimplesEnc *pList) {
	return(pList->prim == NULL);
}

/* Programa Principal */
int main()
{
	setlocale(LC_ALL, "portuguese");
	ListaSimplesEnc minhaLista;
	int valor, op, valorAlt;
	criarLista(&minhaLista);
	
	printf("Escolha uma opção:\n");
	while (1) {
		printf("\n(1) Inclusão de elemento no início da Lista\n");
		printf("(2) Inclusão de elemento em ordem (verifique a ordenação)\n");
		printf("(3) Consulta da Lista\n");
		printf("(4) Alteração de elemento da Lista\n");
		printf("(5) Remoção de elemento no início da Lista\n");
		printf("(6) Remoção de elemento específico da Lista\n");
		printf("(7) Remoção de todos os elementos da Lista\n");
		printf("(0) Sair\n");
		printf(" ? ");
		scanf("%d", &op);
		system("cls");
		switch (op) {
		case 1: // Inclusão de elemento no início da Lista
				printf("Valor? ");
				scanf("%d", &valor);
				inserirIni(&minhaLista, valor);
				break;
		case 2: // Inclusão de elemento em ordem (verifique a ordenação)
				printf("Valor? ");
				scanf("%d", &valor);
				inserirOrd(&minhaLista, valor);
				break;
		case 3: // Consulta da Lista
				if (estaVazia(&minhaLista)) {
					printf("Lista vazia\n");
				}
				else {
					mostrarLista(&minhaLista);
				}
				break;
		case 4: // Alteração de elemento da Lista
				printf("Valor a ser alterado? ");
				scanf("%d", &valor);
				printf("Novo valor? ");
				scanf("%d", &valorAlt);
				alterarEle(&minhaLista, valor, valorAlt);
				break;								
		case 5: // Remoção de elemento no início da Lista
				removerIni(&minhaLista);
				break;
		case 6: // Remoção de elemento específico da Lista
				printf("Valor? ");
				scanf("%d", &valor);
				removerEle(&minhaLista, valor);
				break;
		case 7: // Remoção de todos os elementos da Lista
				removerTudo(&minhaLista);
				break;
		case 0: // Sair do programa
				removerTudo(&minhaLista);
				exit(0);
			default:
				printf("Opção inexistente!\n");
		}
	}
}

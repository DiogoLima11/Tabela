//Bibliotecas usadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

//Structs usadas para determinar as regioes e ajustar os ponteiros.
struct regiao
{
    struct regiao *ant;
    struct regiao *prox;
    struct times *times;
    char regiao[13];
};

//Strucuts usadas para determinar os times e ajustar os ponteiros.
struct times
{
    struct times *prox;
    char times[25];
    int titulos;
};
typedef struct
{
    struct regiao *inicio;
    struct regiao *fim;
} lista;


//Fun��es usadas para inserir e mostrar os ponteiros na lista.
int  insere(lista *q, char regiao[13]);
void mostra(lista *q, char regiao[13]);
int insere2(lista *q, char times[25], int titulos, char regiao[13]);


//No main temos as declara��es de variaveis(int e char), os insere(para colocar as regioes e times)
//e o for para transformar a letra MAI�SCULA EM MIN�SCULA.
int main(void)
{
    int i;
    char nome[13];
    setlocale(LC_ALL,"Portuguese");
    lista a;
    a.inicio = NULL;
    a.fim = NULL;
    insere(&a,"CENTRO-OESTE");
    insere(&a,"NORTE");
    insere(&a,"NORDESTE");
    insere(&a,"SUL");
    insere(&a,"SUDESTE");
    insere2(&a,"S�o Paulo",18,"SUDESTE");
    insere2(&a,"Palmeiras",23,"SUDESTE");
    insere2(&a,"Flamengo",23,"SUDESTE");
    insere2(&a,"Brasiliense",1,"CENTRO-OESTE");
    insere2(&a,"Athl�tico Goianiense",2,"CENTRO-OESTE");
    insere2(&a,"Vila Nova",3,"CENTRO-OESTE");
    insere2(&a,"Remo",3,"NORTE");
    insere2(&a,"Rio Branco",4,"NORTE");
    insere2(&a,"Trem",5,"NORTE");
    insere2(&a,"Athl�tico Paranaense",5,"SUL");
    insere2(&a,"Internacional",11,"SUL");
    insere2(&a,"Gremio",13,"SUL");
    insere2(&a,"Fortaleza",9,"NORDESTE");
    insere2(&a,"Sport",10,"NORDESTE");
    insere2(&a,"Bahia",15,"NORDESTE");
    printf("\n ====================================================================================================================== \n");
    printf(" Trabalho LAB AED II\n");
    printf("\n Integrantes: \n\n Diogo Lima;\n\n Luis Otavio;\n\n Wanderlei J�nior; \n ");
   do{ printf("\n ====================================================================================================================== \n");
        printf("\n Caso deseje finalizar o programa digite 'Sair' \n");
    printf("\n Digite uma das seguintes regi�es para ver seus times e a quantidade de titulos.\n\n -> Sul\n\n -> Sudeste\n\n -> Centro-Oeste\n\n -> Norte\n\n -> Nordeste\n\n -> ");
    scanf("%12[^\n]s",&nome);
    printf("\n ====================================================================================================================== \n");
    getchar();
    for(i = 0; i <= strlen(nome); i++)
        nome[i] = toupper(nome[i]);
        if(strcmp("SAIR",nome)!=0)
    mostra(&a,nome);
   }while(strcmp("SAIR",nome)!=0);
}

//Fun��o que insere um n� na lista
int  insere(lista *q, char regiao[13])
{
    struct regiao *aux;
    aux = (struct regiao*) malloc(sizeof(struct regiao));
    if (aux == NULL)
        return 0;
    if (q->inicio == NULL)
    {
        aux->times = NULL;
        strcpy(aux->regiao, regiao);
        q->inicio = aux;
        q->fim = aux;
        aux->prox = q->inicio;
        aux->ant = q->fim;
        return 1;
    }
        aux->times = NULL;
        strcpy(aux->regiao, regiao);
        aux->ant = q->fim;
        q->fim->prox = aux;
        aux->prox = q->inicio;
        q->inicio->ant = aux;
        q->fim = aux;
        return 1;
}

//Fun��o que mostra o n� das regi�es na lista
void mostra(lista *q, char regiao[13])
{
    int achou = 0;
    struct regiao *aux;
    struct times *auxT;
    if (q->inicio == NULL)
        printf("\n ->Lista vazia<- \n");
    else
    {
            aux = q->inicio;
    do{
        if(strcmp(aux->regiao,regiao)== 0)
        {
            achou = 1;
                break;
        }
        aux=aux->prox;
    }while(q->inicio->regiao != aux->regiao);
    if(achou)
    {
    auxT = aux->times;
            do
            {
                printf("\n %s - Titulos: %d\n", auxT->times,auxT->titulos);
                auxT = auxT->prox;
            } while (auxT != NULL);
    }
    else
    printf("\n Regi�o N�o Encontrada \n");
    }
}

//Fun��o que insere um n� dos times na lista
int insere2(lista *q, char times[25], int titulos, char regiao[13])
{
    struct regiao *auxRegiao;
    struct times *auxTimes;
    auxTimes= (struct times*) malloc(sizeof(struct times));
    auxRegiao = q->inicio;
    do{
        if(strcmp(auxRegiao->regiao,regiao)== 0)
            break;
        auxRegiao=auxRegiao->prox;

    }while(q->inicio->regiao != auxRegiao->regiao);
    if(auxRegiao->times == NULL)
    {
        auxRegiao->times = auxTimes;
        strcpy(auxTimes->times,times);
        auxTimes->titulos = titulos;
        auxTimes->prox = NULL;
        return 1;
    }
        auxTimes->prox = auxRegiao->times;
        auxRegiao->times = auxTimes;
        strcpy(auxTimes->times,times);
        auxTimes->titulos = titulos;
}

//diogo

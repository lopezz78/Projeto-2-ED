#ifndef BIBLIOTECAP2_H_INCLUDED
#define BIBLIOTECAP2_H_INCLUDED

#define M 37


/*

O que adicionar ao arquivo para funcionamento da árvore:

- Inserir
- Verificar se existe elemento( busca )
- Criar
- Verificar se está vaiza
- Imprimir
- Liberar

- Remover


Funcionamento do HASH

- Inserção


*/


typedef struct NoArvore
{
    int Id_Incidente;
    int codigoEquipamento;
    int gravidade;

    struct NoArvore *esq;
    struct NoArvore *dir;

}NoArv;

typedef struct arvore
{
    NoArv *raiz;

}Arv;

typedef struct guarda_incidente
{
    int Id_Icidente;

    struct guarda_incidente *prox;

} guarda;

typedef struct No_Hash
{
    int Id;
    char Nome_equipamento[11];
    struct No_Hash *prox;

    guarda *inc;

}NoH;

guarda* guardaIncidente(NoH* equip,int Id_inc)
{
    guarda* aux = equip->guarda;
    guarda* novo = (guarda*)malloc(sizeof(guarda));
    novo->Id_Incidente = Id_inc;

    if(aux == NULL)
    {
        return novo;
    }
    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novo;
    return equip->guarda;
}

NoH* auxinsercaoHash(NoH* Vetor[], int Id, char Nome_equi[], int pos){


    NoH* aux;
    NoH* novo = (NoH*)malloc(sizeof(NoH));
    novo->Id = Id;
    strcpy(novo->Nome_equipamento, Nome_equi);
    novo->prox = NULL;

    aux = Vetor[pos];

    if(aux == NULL)
    {
        return novo;
    }
    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = novo;
    return Vetor[pos];


}

void insecaoHash(NoH* Vetor[], int Id, char nome[])
{
    int pos;

    pos = Id % M;

    Vetor[pos] = auxinsercaoHash(Vetor, Id, nome, pos);

}

Arv* Criar_arvore(){

    Arv *aux;

    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;

    return aux;

}


int ver_vazia(Arv *base){

    if(base->raiz == NULL)
    {
        return 1;
    }

    return 0;

}


NoArv* aux_insere(NoArv *no, int cod_equipamento, int id, char nome_equi)
{
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->Id_incidente = id;
    novo->codigoEquipamento = cod_equipamento;
    strcpy()
    novo->esq = NULL;
    novo->dir = NULL;

    if(no == NULL)
    {
        return novo;
    }

        Pai = no;
        flag = 0;
        while (flag==0)
        {
            if(Pai->info < num)
            {
                if(Pai->dir == NULL)
                {
                    Pai->dir = novo;
                    flag = 1;
                }
                else
                {
                    Pai = Pai->dir;
                }
            }
            else{
                if(Pai->info>num)
                {
                    if(Pai->esq == NULL)
                    {
                        Pai->esq = novo;
                        flag = 1;
                    }
                    else
                    {
                        Pai = Pai->esq;
                    }
                }
                else
                {
                    flag = 1;
                    free(novo); // se chegou aqui, significa que o num é igual a outro valor da árvore
                }               // portanto não será adicionado!
            }
        }

}
void insere(Arv *Arvore, int cod_equipamento, int id, char nome_equi)
{
    Arvore->raiz = aux_insere(Arvore->raiz, cod_equipamento, id, nome_equi);
}
/*
    Criar noArvore
    Adicionar pelo Id
*/




#endif // BIBLIOTECAP2_H_INCLUDED

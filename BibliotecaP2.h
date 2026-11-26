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
*/
          
Funcionamento do HASH

- Inserção





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

guarda* guardaIncidente(guarda* equip,int Id_inc)
{
    guarda* aux = equip;
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
    return equip;
}

guarda* removeIncidente(guarda* apag, int Id_inc)
{
    guarda* aux1 = apag;
    guarda* aux = NULL;

    while((aux1 != NULL) && (aux1->Id_incidente != Id_inc))
    {
        aux = aux1;
        aux1 = aux1->prox;
    }
    if(aux == NULL)
    {
        aux1=apag;
        apag = apag->prox;
        free(aux1);
        return apag;
    }

    aux->prox = aux1->prox;
    free(aux1);
    return apag;

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
Arv* remover(Arv *RAIZ, int Id_Incidente)
{
    if (RAIZ == NULL || RAIZ->raiz == NULL)
    {
        return RAIZ;
    }

    NoArv *aux = RAIZ->raiz;

    if (aux->info == Id_Incidente && aux->dir == NULL && aux->esq == NULL)
    {
        free(aux);
        free(RAIZ);
        return NULL;
    }

    RAIZ->raiz = remover_aux(RAIZ->raiz, Id_Incidente);

    return RAIZ;
}

NoArv* remover_aux(NoArv *pai, int Id_Incidente)
{
    if (pai == NULL)
    {
        printf("\nNao encontrado na arvore");
    }
    else
    {
        if (Id_Incidente > pai->Id_Incidente)
        {
            pai->dir = remover_aux(pai->dir, Id_Incidente);
        }
        else if (Id_Incidente < pai->Id_Incidente)
        {
            pai->esq = remover_aux(pai->esq, Id_Incidente);
        }
        else
        {
            // Encontrou o nó

            if (pai->dir == NULL && pai->esq == NULL)
            {
                // CASO 1: nó folha

                free(pai);
                pai = NULL;
            }
            else if (pai->esq == NULL)
            {
                // CASO 2: somente filho direito

                NoArv *aux = pai;
                pai = pai->dir;
                free(aux);
            }
            else if (pai->dir == NULL)
            {
                // CASO 2: somente filho esquerdo

                NoArv *aux = pai;
                pai = pai->esq;
                free(aux);
            }
            else
            {
                // CASO 3: dois filhos

                NoArv *aux = pai->esq;

                while (aux->dir != NULL)
                {
                    aux = aux->dir;
                }

                pai->Id_Incidente = aux->Id_Incidente;

                aux->Id_Incidente = Id_Incidente;

                pai->esq = remover_aux(pai->esq, Id_Incidente);
            }
        }
    }

    return pai;
}
// funcao impressao IN order esquerda->pai->direita
void ImprimirCrescente(NoArv *pai)
{
    if (pai != NULL)
    {
        ImprimirCrescente(pai->esq);

        printf("\nID do incidente: %04d", pai->Id_Incidente);
        printf("\nCodigo do equipamento: %d", pai->codigoEquipamento);
        printf("\nGravidade: %d\n", pai->gravidade);

        ImprimirCrescente(pai->dir);
    }
}//ImprimirCrescente(Arvore->raiz);

//Impressao solicitacao
void PesquisarIncidente(Arv *Arvore, int Id_Incidente)
{
    NoArv *Pai;
    int flag;

    if (Arvore == NULL || Arvore->raiz == NULL)
    {
        printf("\nArvore vazia!");
        return 0;
    }

    Pai = Arvore->raiz;
    flag = 0;

    while (flag == 0)
    {
        if (num > Pai->Id_Incidente)
        {
            if (Pai->dir == NULL)
            {
                flag = 2;
            }
            else
            {
                Pai = Pai->dir;
            }
        }
        else
        {
            if (num < Pai->Id_Incidente)
            {
                if (Pai->esq == NULL)
                {
                    flag = 2;
                }
                else
                {
                    Pai = Pai->esq;
                }
            }
            else
            {
                flag = 1;
            }
        }
    }

    if (flag == 1)
    {
        printf("\nID: %04d", Pai->Id_Incidente);
        printf("\nCodigo do equipamento: %d", Pai->codigoEquipamento);
        printf("\nGravidade: %d", Pai->gravidade);
    }
    else
    {
        printf("\nIncidente nao encontrado!");
    }
}




#endif // BIBLIOTECAP2_H_INCLUDED

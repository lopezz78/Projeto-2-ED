#ifndef BIBLIOTECAP2_H_INCLUDED
#define BIBLIOTECAP2_H_INCLUDED

#define M 37


/*

O que adicionar ao arquivo para funcionamento da árvore:

- Inserir +
- Verificar se existe elemento( busca )
- Criar
- Verificar se está vaiza
- Imprimir
- Liberar
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
    int Id_Incidente;

    struct guarda_incidente *prox;

} guarda;

typedef struct No_Hash
{
    int Id;
    char Nome_equipamento[11];
    struct No_Hash *prox;

    guarda *inc;

}NoH;

NoArv* remover_aux(NoArv *pai, int id)
{
    if (pai == NULL)
    {
        printf("\nNao encontrado na arvore");
    }
    else
    {
        if (id > pai->Id_Incidente)
        {
            pai->dir = remover_aux(pai->dir, id);
        }
        else if (id < pai->Id_Incidente)
        {
            pai->esq = remover_aux(pai->esq, id);
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
                pai->codigoEquipamento = aux->codigoEquipamento;
                pai->gravidade = aux->gravidade;

                pai->esq = remover_aux(pai->esq, aux->Id_Incidente);
            }
        }
    }

    return pai;
}

Arv* remover(Arv *RAIZ, int num)
{
    if (RAIZ == NULL || RAIZ->raiz == NULL)
    {
        return RAIZ;
    }


    RAIZ->raiz = remover_aux(RAIZ->raiz, num);

    return RAIZ;
}
// funcao impressao IN order esquerda->pai->direita
void ImprimirCrescente(NoArv *pai)
{
    if (pai != NULL)
    {
        ImprimirCrescente(pai->esq);

        printf("\nID do incidente: %d", pai->Id_Incidente);
        printf("\nCodigo do equipamento: %d", pai->codigoEquipamento);
        printf("\nGravidade: %d\n", pai->gravidade);

        ImprimirCrescente(pai->dir);
    }
}//ImprimirCrescente(Arvore->raiz);

//Impressao solicitacao
No Arv* PesquisarIncidente(Arv *Arvore, int num)
{
    NoArv *Pai;
    int flag;

    if (Arvore == NULL || Arvore->raiz == NULL)
    {
        return NULL;
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
        return pai;
    }
    else
    {
        return NULL;
    }
}


guarda* guardaIncidente(NoH* equip,int Id_inc)
{
    guarda* aux = equip->inc;
    guarda* novo = (guarda*)malloc(sizeof(guarda));
    if(novo == NULL)
    {
        return equip->inc;
    }
    novo->Id_Incidente = Id_inc;
    novo->prox = NULL'

    if(aux == NULL)
    {
        return novo;
    }
    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novo;
    return equip->inc;
}

/*

Hash:
- inserção
- remoção

*/
NoH* auxinsercaoHash(NoH* Vetor[], int Id, char Nome_equi[], int pos){


    NoH* aux;
    NoH* novo = (NoH*)malloc(sizeof(NoH));
    if(novo == NULL)
{
    return Vetor[pos];
}
    novo->Id = Id;
    strcpy(novo->Nome_equipamento, Nome_equi);
    novo->prox = NULL;
    novo->inc = NULL;

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

void insercaoHash(NoH* Vetor[], int Id, char nome[])
{
    int pos;

    pos = Id % M;

    Vetor[pos] = auxinsercaoHash(Vetor, Id, nome, pos);

}

Arv* Criar_arvore(){

    Arv *aux;

    aux = (Arv*)malloc(sizeof(Arv));
    if(aux == NULL)
{
    return NULL;
}
    aux->raiz = NULL;

    return aux;

}


int ver_vazia(Arv *base){

    if(base == NULL || base->raiz == NULL)
    {
        return 1;
    }

    return 0;

}


NoArv* aux_insere_arvore(NoArv *no, int cod_equipamento, int id_inc, int gravidade)
{
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));

    if(novo == NULL)
    {
        printf("\nErro de alocacao!");
        return no;
    }
    
    novo->Id_Incidente = id_inc;
    novo->codigoEquipamento = cod_equipamento;
    novo->gravidade = gravidade;
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
            if(Pai->Id_Incidente < id_inc)
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
                if(Pai->Id_Incidente > id_inc)
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
            return no;
        }

}
void insereArvore(Arv *Arvore, int cod_equipamento, int id_incidente, int gravidade)
{
    Arvore->raiz = aux_insere_arvore(Arvore->raiz, cod_equipamento, id_incidente, gravidade);
}

NoH* procura_equipamento_Hash(NoH* Vetor[], int cod_equipamento){

    int pos;

    pos = cod_equipamento % M;

    if(Vetor[pos] == NULL){

        printf("Equipamento não encontrado!");
        return NULL;

    }

    NoH* aux = Vetor[pos];

    while((aux != NULL) && (aux->Id != cod_equipamento))
    {
        aux = aux->prox;
    }
    
    return aux;

}

void remover_incidentes(NoH* Equipamento){

    while(aux->inc->prox != NULL)
    {

    }

    
void RegistrarIncidente(Arv *Arvore, NoH *Vetor[],
                       int cod_equipamento, int id_incidente,
                       int gravidade)
{
    NoH *equip;
    guarda *lista;

    equip = procura_equipamento_Hash(Vetor, cod_equipamento);

    if(equip == NULL)
    {
        printf("\nEquipamento nao encontrado!");
    }
    else if(PesquisarIncidente(Arvore, id_incidente) != NULL)
    {
        printf("\nIncidente ja cadastrado!");
    }
    else
    {
        insereArvore(Arvore, cod_equipamento,
                     id_incidente, gravidade);

        if(PesquisarIncidente(Arvore, id_incidente) != NULL)
        {
            lista = guardaIncidente(equip, id_incidente);

            if(lista != NULL)
            {
                equip->inc = lista;

                printf("\nIncidente cadastrado com sucesso!");
            }
            else
            {
                Arvore->raiz = remover_aux(Arvore->raiz, id_incidente);

                printf("\nErro ao associar incidente!");
            }
        }
        else
        {
            printf("\nErro ao inserir incidente!");
        }
    }
}

void ConsultarEquipamento(Arv *Arvore, NoH *Vetor[], int codigo)
{
    NoH *equip;
    guarda *aux;
    NoArv *incidente;

    equip = procura_equipamento_Hash(Vetor, codigo);

    if(equip == NULL)
    {
        printf("\nEquipamento nao encontrado!");
    }
    else
    {
        printf("\nCodigo: %d", equip->Id);
        printf("\nNome: %s", equip->Nome_equipamento);

        aux = equip->inc;

        if(aux == NULL)
        {
            printf("\nEquipamento sem incidentes!");
        }
        else
        {
            while(aux != NULL)
            {
                incidente = PesquisarIncidente(Arvore, aux->Id_Incidente);

                if(incidente != NULL)
                {
                    printf("\n\nID: %d", incidente->Id_Incidente);
                    printf("\nGravidade: %d", incidente->gravidade);
                }

                aux = aux->prox;
            }
        }
    }
}
void ConsultarIncidente(Arv *Arvore, NoH *Vetor[], int id)
{
    NoArv *incidente;
    NoH *equip;

    incidente = PesquisarIncidente(Arvore, id);

    if(incidente == NULL)
    {
        printf("\nIncidente nao encontrado!");
    }
    else
    {
        printf("\nID do incidente: %d", incidente->Id_Incidente);
        printf("\nGravidade: %d", incidente->gravidade);

        equip = procura_equipamento_Hash(Vetor, incidente->codigoEquipamento);

        if(equip != NULL)
        {
            printf("\nCodigo do equipamento: %d", equip->Id);
            printf("\nNome do equipamento: %s", equip->Nome_equipamento);
        }
        else
        {
            printf("\nEquipamento nao encontrado!");
        }
    }
}
//Usa a ordem Pos order pra liberar
void aux_libera_arvore(NoArv *Pai)
{
    if(Pai != NULL)
    {
        aux_libera_arvore(Pai->dir);
        aux_libera_arvore(Pai->esq);

        free(Pai);
    }
}
Arv* LiberarArvore(Arv *Arvore)
{
    if(Arvore != NULL)
    {
        aux_libera_arvore(Arvore->raiz);
        free(Arvore);
    }

    return NULL;
}
void LiberarListaIncidentes(guarda *inicio)
{
    guarda *aux;

    while(inicio != NULL)
    {
        aux = inicio;
        inicio = inicio->prox;

        free(aux);
    }
}
void LiberarHash(NoH *Vetor[])
{
    int i;
    NoH *aux;

    for(i = 0; i < M; i++)
    {
        while(Vetor[i] != NULL)
        {
            aux = Vetor[i];

            LiberarListaIncidentes(aux->inc);

            Vetor[i] = Vetor[i]->prox;

            free(aux);
        }
    }
}
/*
    Criar noArvore
    Adicionar pelo Id
*/




#endif // BIBLIOTECAP2_H_INCLUDED

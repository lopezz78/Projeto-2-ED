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
    int id;
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
    int Incidente;

    struct guarda_incidente *prox;

} guarda;

typedef struct No_Hash
{
    int Id;
    char Nome_equipamento[11];
    struct No_Hash *prox;

    guarda *inc;

}NoH;



insercaoHash(NoH* Vetor, int Id, char Nome_equi){

    NoH* aux = (*NoH)malloc(sizeof(NoH));
    aux->Id = Id;
    strcpy(aux->Nome_equipamento, Nome_equi);


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
    novo->id = id;
    novo->codigoEquipamento = cod_equipamento;
    strcpy()
    novo->esq = NULL;
    novo->dir = NULL;

    if(no == NULL)
    {
        return novo;
    }
    else
    {
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

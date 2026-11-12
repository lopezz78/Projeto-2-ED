#ifndef BIBLIOTECAP2_H_INCLUDED
#define BIBLIOTECAP2_H_INCLUDED


/*

O que adicionar ao arquivo para funcionamento da árvore:

- Inserir
- Verificar se existe elemento( busca )
- Criar
- Verificar se está vaiza
- Imprimir
- Liberar
- Remover



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


NoArv* aux_insere(NoArv *no, int num)
{
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = num;
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
void insere(Arv *Arvore, int num)
{
    Arvore->raiz = aux_insere(Arvore->raiz,num);
}
/*
    Criar noArvore
    Adicionar pelo Id
*/




#endif // BIBLIOTECAP2_H_INCLUDED

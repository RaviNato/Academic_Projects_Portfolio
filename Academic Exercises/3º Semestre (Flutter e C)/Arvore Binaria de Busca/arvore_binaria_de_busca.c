#include <stdio.h>
#include "arvore_binaria_de_busca.h"

U32 qtos_elementos_comuns (Arvore_binaria_de_busca* a, Arvore_binaria_de_busca* b)
{
    if (a->raiz==NULL || b->raiz==NULL) return 0;

    Ptr_de_no_de_arvore_binaria_de_busca backup = a->raiz;
    a->raiz=backup->esquerda;
    U32 qtdNaEsq = qtos_elementos_comuns(a,b);
    a->raiz=backup->direita;
    U32 qtdNaDir = qtos_elementos_comuns(a,b);
    a->raiz=backup;

    if (tem_na_arvore_binaria_de_busca(b,a->raiz->informacao))
        return 1+qtdNaEsq+qtdNaDir;
    else
        return qtdNaEsq+qtdNaDir;

}

static Ptr_de_no_de_arvore_binaria_de_busca novo_no_de_arvore_binaria_de_busca (Ptr_de_no_de_arvore_binaria_de_busca e, Elemento i, Ptr_de_no_de_arvore_binaria_de_busca d)
{
    Ptr_de_no_de_arvore_binaria_de_busca novo = (Ptr_de_no_de_arvore_binaria_de_busca)malloc(sizeof(Struct_do_no_de_arvore_binaria_de_busca));

    novo->esquerda=e;
    novo->informacao=i;
    novo->direita=d;

    return novo;
}

void nova_arvore_binaria_de_busca (Arvore_binaria_de_busca* a, I32 (*c) (Elemento x, Elemento y), void (*m) (Elemento x))
{
    a->raiz=NULL;
    a->comparacao=c;
    a->mostra=m;
}

boolean guarde_na_arvore_binaria_de_busca (Arvore_binaria_de_busca* a, Elemento i)
{
    if (a->raiz==NULL)
    {
        a->raiz=novo_no_de_arvore_binaria_de_busca(NULL,i,NULL);
        return true;
    }
    
    Ptr_de_no_de_arvore_binaria_de_busca atual=a->raiz;
        
    for(;;) // forever
    {
        I32 comp=a->comparacao(i,atual->informacao);

        if (comp==0) return false;
        
        if (comp<0)
        {
            if (atual->esquerda==NULL)
            {
                atual->esquerda=novo_no_de_arvore_binaria_de_busca(NULL,i,NULL);
                return true;
            }
            else
                atual=atual->esquerda;
        }
        else // comp>0
        {
            if (atual->direita==NULL)
            {
                atual->direita=novo_no_de_arvore_binaria_de_busca(NULL,i,NULL);
                return true;
            }
            else
                atual=atual->direita;
        }
    }
}
/*
boolean tem_na_arvore_binaria_de_busca (Arvore_binaria_de_busca* a, Elemento i) // nao precisava passar a arvore por referencia; foi só pão-durismo
{
    if (a->raiz==NULL) return false;

    int comp=*(a->comparacao)(i,a->raiz->informacao);
    if (comp==0) return true;

    Ptr_de_no_de_arvore_binaria_de_busca bkp_raiz=a->raiz;

    if (comp<0)
        a->raiz=a->raiz->esquerda;
    else // comp>0
        a->raiz=a->raiz->direita;

    boolean ret=tem_na_arvore_binaria_de_busca(a,i);
    a->raiz=bkp_raiz;

    return ret;
}
*/
/*
boolean tem_na_arvore_binaria_de_busca (Arvore_binaria_de_busca a, Elemento i) // se escolher essa versao, altere o .h para passar a arvore por valor (nao por referencia)
{
    if (a.raiz==NULL) return false;

    int comp=*(a->comparacao)(i,a.raiz->informacao);
    if (comp==0) return true;

    if (comp<0)
        a.raiz=a.raiz->esquerda;
    else // comp>0
        a.raiz=a.raiz->direita;

    return tem_na_arvore_binaria_de_busca(a,i);
}
*/
boolean tem_na_arvore_binaria_de_busca (Arvore_binaria_de_busca* a, Elemento i) // nao precisava passar a arvore por referencia; foi só pão-durismo
{
    Ptr_de_no_de_arvore_binaria_de_busca atual = a->raiz;

    while (atual!=NULL)
    {
        I32 comp=a->comparacao(i,atual->informacao);

        if (comp==0) return true;

        if (comp<0)
            atual=atual->esquerda;
        else // comp>0
            atual=atual->direita;
    }

    return false;
}

U32 quantas_info_tem_na_arvore_binaria_de_busca (Arvore_binaria_de_busca* a) // nao precisava passar a arvore por referencia; foi só pão-durismo
{
    if (a->raiz==NULL) return 0;

    Ptr_de_no_de_arvore_binaria_de_busca bkp_raiz=a->raiz;
    a->raiz=a->raiz->esquerda;
    U32 qtsEsq=quantas_info_tem_na_arvore_binaria_de_busca(a);

    a->raiz=bkp_raiz;
    a->raiz=a->raiz->direita;
    U32 qtsDir=quantas_info_tem_na_arvore_binaria_de_busca(a);

    a->raiz=bkp_raiz;
    return qtsEsq+1+qtsDir;
}

static void aux_print_pre_ordem(Ptr_de_no_de_arvore_binaria_de_busca no, void (*mostra)(Elemento)) {
    if (no == NULL) return;
    mostra(no->informacao);
    aux_print_pre_ordem(no->esquerda, mostra);
    aux_print_pre_ordem(no->direita, mostra); 
}

void print_pre_ordem (Arvore_binaria_de_busca* a) {
    if (a == NULL) return;
    aux_print_pre_ordem(a->raiz, a->mostra);
}

void print_in_ordem (Arvore_binaria_de_busca* a) // nao precisava passar a arvore por referencia; foi só pão-durismo
{
    if (a->raiz==NULL) return;

    Ptr_de_no_de_arvore_binaria_de_busca bkp_raiz=a->raiz;

    a->raiz=a->raiz->esquerda;
    print_in_ordem(a);
    a->raiz=bkp_raiz;

    a->mostra(a->raiz->informacao);
    printf(" ");

    a->raiz=a->raiz->direita;
    print_in_ordem(a);
    a->raiz=bkp_raiz;
}

void print_pos_ordem (Arvore_binaria_de_busca* a) // nao precisava passar a arvore por referencia; foi só pão-durismo
{
    if (a->raiz==NULL) return;

    Ptr_de_no_de_arvore_binaria_de_busca bkp_raiz=a->raiz;

    a->raiz=a->raiz->esquerda;
    print_pos_ordem(a);
    a->raiz=bkp_raiz;

    a->raiz=a->raiz->direita;
    print_pos_ordem(a);
    a->raiz=bkp_raiz;

    a->mostra(a->raiz->informacao);
    printf(" ");
}

boolean remova_da_arvore_binaria_de_busca (Arvore_binaria_de_busca* a, Elemento i)
{
    if (a == NULL || a->raiz == NULL) return false;

    Ptr_de_no_de_arvore_binaria_de_busca pai = NULL;
    Ptr_de_no_de_arvore_binaria_de_busca atual = a->raiz;
    Ptr_de_no_de_arvore_binaria_de_busca *ligacao_do_atual_com_pai = &a->raiz; 

    for(;;) 
    {
        if (atual == NULL) return false;

        I32 comp = a->comparacao(i, atual->informacao);

        if (comp == 0) break;

        pai = atual;
        if (comp < 0)
        {
            ligacao_do_atual_com_pai = &atual->esquerda;
            atual = atual->esquerda;
        }
        else // comp > 0
        {
            ligacao_do_atual_com_pai = &atual->direita;
            atual = atual->direita;
        }
    }

    if (atual->esquerda == NULL || atual->direita == NULL)
    {
        Ptr_de_no_de_arvore_binaria_de_busca proximo;
        if (atual->esquerda != NULL)
            proximo = atual->esquerda;
        else
            proximo = atual->direita;

        *ligacao_do_atual_com_pai = proximo;
        
        free(atual->informacao);
        free(atual);
    }

    else
    {
        Ptr_de_no_de_arvore_binaria_de_busca substituto, pai_substituto;
        Ptr_de_no_de_arvore_binaria_de_busca *ligacao_substituto;

        unsigned long int aleatorio = rand() % 2;

        if (aleatorio == 0)
        {
            substituto = atual->esquerda;
            pai_substituto = atual;
            ligacao_substituto = &atual->esquerda;

            while (substituto->direita != NULL)
            {
                pai_substituto = substituto;
                ligacao_substituto = &substituto->direita;
                substituto = substituto->direita;
            }
            
            free(atual->informacao); 
            atual->informacao = substituto->informacao;
            
            *ligacao_substituto = substituto->esquerda;
        }
        else
        {
            substituto = atual->direita;
            pai_substituto = atual;
            ligacao_substituto = &atual->direita;

            while (substituto->esquerda != NULL)
            {
                pai_substituto = substituto;
                ligacao_substituto = &substituto->esquerda;
                substituto = substituto->esquerda;
            }

            free(atual->informacao);
            atual->informacao = substituto->informacao;

            *ligacao_substituto = substituto->direita;
        }
        
        free(substituto);
    }

    return true;
}

#define abs(x) ((x)<0?-(x):(x))

void balanceie_a_arvore_binaria_de_busca(Arvore_binaria_de_busca* a)
{
    if (a == NULL || a->raiz == NULL) return;

    Ptr_de_no_de_arvore_binaria_de_busca bkp_raiz = a->raiz;

    a->raiz = bkp_raiz->esquerda;
    U32 qtd_esquerda = quantas_info_tem_na_arvore_binaria_de_busca(a);
    
    a->raiz = bkp_raiz->direita;
    U32 qtd_direita = quantas_info_tem_na_arvore_binaria_de_busca(a);
    
    a->raiz = bkp_raiz;

    U32 transferir = 0;

    if (qtd_esquerda > qtd_direita)
    {
        U32 diff = qtd_esquerda - qtd_direita;
        if (diff > 1) 
        {
            transferir = diff / 2;
            for (U32 i = 0; i < transferir; i++)
            {
                Ptr_de_no_de_arvore_binaria_de_busca pai = bkp_raiz;
                Ptr_de_no_de_arvore_binaria_de_busca atual = bkp_raiz->esquerda;
                Ptr_de_no_de_arvore_binaria_de_busca *ligacao = &bkp_raiz->esquerda;

                while (atual->direita != NULL)
                {
                    pai = atual;
                    ligacao = &atual->direita;
                    atual = atual->direita;
                }

                Elemento info_substituto = atual->informacao;
                *ligacao = atual->esquerda;
                free(atual);

                Elemento info_raiz_antiga = bkp_raiz->informacao;
                bkp_raiz->informacao = info_substituto;
                
                a->raiz = bkp_raiz;
                guarde_na_arvore_binaria_de_busca(a, info_raiz_antiga);
            }
        }
    }
    else if (qtd_direita > qtd_esquerda)
    {
        U32 diff = qtd_direita - qtd_esquerda;
        if (diff > 1)
        {
            transferir = diff / 2;
            for (U32 i = 0; i < transferir; i++)
            {
                Ptr_de_no_de_arvore_binaria_de_busca pai = bkp_raiz;
                Ptr_de_no_de_arvore_binaria_de_busca atual = bkp_raiz->direita;
                Ptr_de_no_de_arvore_binaria_de_busca *ligacao = &bkp_raiz->direita;

                while (atual->esquerda != NULL)
                {
                    pai = atual;
                    ligacao = &atual->esquerda;
                    atual = atual->esquerda;
                }

                Elemento info_substituto = atual->informacao;
                *ligacao = atual->direita;
                free(atual);

                Elemento info_raiz_antiga = bkp_raiz->informacao;
                bkp_raiz->informacao = info_substituto;
                
                a->raiz = bkp_raiz;
                guarde_na_arvore_binaria_de_busca(a, info_raiz_antiga);
            }
        }
    }

    bkp_raiz = a->raiz;

    if (bkp_raiz->esquerda != NULL) {
        a->raiz = bkp_raiz->esquerda;
        balanceie_a_arvore_binaria_de_busca(a);
        bkp_raiz->esquerda = a->raiz;
    }

    if (bkp_raiz->direita != NULL) {
        a->raiz = bkp_raiz->direita;
        balanceie_a_arvore_binaria_de_busca(a);
        bkp_raiz->direita = a->raiz;
    }

    a->raiz = bkp_raiz;
}

void free_arvore_binaria_de_busca (Arvore_binaria_de_busca* a)
{
    if (a->raiz==NULL) return;
    
    Ptr_de_no_de_arvore_binaria_de_busca esq=a->raiz->esquerda;
    Ptr_de_no_de_arvore_binaria_de_busca dir=a->raiz->direita;
    
    free(a->raiz->informacao);
    free(a->raiz);
    
    a->raiz=esq;
    free_arvore_binaria_de_busca(a);
    
    a->raiz=dir;
    free_arvore_binaria_de_busca(a);
}

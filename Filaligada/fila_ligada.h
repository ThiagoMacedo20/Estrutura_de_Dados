#ifndef FILA_LIGADA_H_INCLUDED
#define FILA_LIGADA_H_INCLUDED
template <typename Tipo>

struct Node{
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>

struct Fila{
    Node<Tipo> *inicio;
    Node<Tipo> *fim;
    Fila(){
        inicio= NULL;
        fim=NULL;
    }

    bool filaVazia(){
        return inicio==NULL;
    }

    bool AdicionaFim(Tipo x)
    {
        bool v=true;
        Node<Tipo> *aux=new Node<Tipo>;
        if (aux == NULL)
        {
            v=false;
        }
        else
        {
            aux->info=x;
            aux->prox=NULL;
            if (inicio==NULL)
            {
                inicio=aux;
                fim=aux;
            }
            else
            {
                fim->prox=aux;
                fim=aux;
            }
        }
        return v;
    }
    Tipo getFirst(){
        return inicio->info;
    }
    Tipo remover(){
        Tipo temp= inicio->info;
        Node <Tipo> *aux=inicio;
        inicio = inicio->prox;
        delete aux;
        return temp;
    }

};


#endif // FILA_LIGADA_H_INCLUDED

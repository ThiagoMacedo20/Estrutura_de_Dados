#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#define W 5
using namespace std;

struct Node{
    int info;
    Node *prox;
};

struct Hash{
    Node *h[W];

    Hash(){
        for(int i=0;i<W;i++)
            h[i]=NULL;
    }
    int fht(int x){
        return x % W;
    }
    bool listavazia(int lista){
        return h[lista]==NULL;
    }

    void insere(int x){
        Node *aux = new Node;
        aux->info = x;
        if(h[fht(x)] == NULL || x <= h[fht(x)]->info){
            aux->prox = h[fht(x)];
            h[fht(x)] = aux;
        }
        else{
            Node *aux2 = h[fht(x)];
            while(aux2->prox!=NULL && aux2->prox->info<x){
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

     void mostralista(){
        for(int i=0;i<W;i++){
            Node *aux = h[i];
            cout<<"h["<<i<<"]->";
            while(aux != NULL){
                cout<<aux->info<<"->";
                aux = aux->prox;
            }
            cout<<"NULL"<<endl;
        }
    }
        bool remover(int x){
        bool v=true;
        Node *aux2=h[fht(x)];
        Node *aux=h[fht(x)];
        if(aux==NULL)
            v=false;
        else
        {
            if(aux2->info == x)
            {
                aux->info = h[fht(x)]->info;
                h[fht(x)] = h[fht(x)]->prox;
            }
            else
            {
                while ( aux2->prox != NULL && x == aux2->prox->info)
                {
                    aux2=aux2->prox;
                }
                if (x == aux2->info)
                {
                    aux->prox = aux2 -> prox;
                    aux2->prox=aux;
                }
                else
                    v=false;
            }
        }

        delete aux;
        return v;
        }
};



#endif

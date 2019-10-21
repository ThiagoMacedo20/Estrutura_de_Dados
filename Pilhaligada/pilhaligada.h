#ifndef PILHALIGADA_H_INCLUDED
#define PILHALIGADA_H_INCLUDED
template <typename Tipo>
struct Node{
    Tipo info;
    Node<Tipo> *prox;

};

template <typename Tipo>
struct Pilha{
    Node<Tipo> *topo;

    Pilha(){
        topo=NULL;
    }

    bool empilha(Tipo x){
        bool v=true;
        Node<Tipo> *aux=new Node<Tipo>; //1
        if (aux == NULL){
            v=false;
        }
        else{
            aux->info=x; //2
            aux->prox=topo; //3
            topo=aux;  //4
        }
        return v;
    }
    Tipo desempilha(){
        Tipo temp = topo->info;
        Node<Tipo> *aux = topo;
        topo=topo->prox;
        delete aux;
        return temp;
    }
    Tipo getTopo(){
        return topo->info;
    }
    bool vazia(){
        return topo==NULL;
    }
};


#endif // PILHALIGADA_H_INCLUDED

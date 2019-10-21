#include <iostream>
#include "pilhaligada.h"
using namespace std;

int main(){
    Pilha<int> p;
    int x, opc;

    do{
        cout<<"1 - Adicionar Inicio"<<endl;
        cout<<"2 - Remover Inicio"<<endl;
        cout<<"3 - Exibir Inicio"<<endl;
        cout<<"4 - Exibir Todos"<<endl;
        cout<<"9 - Sair"<<endl;
        cin>>opc;

        switch(opc){
            case 1:
                cout<<"Digite um numero: ";
                cin>>x;
                p.empilha(x);
                break;
            case 2:
                if(p.vazia()){
                    cout<<"Pilha vazia! "<<endl;
                }else{
                    cout<<p.desempilha()<<endl;
                }
                break;
            case 3:
                cout<<p.getTopo()<<"\t"<<endl;
                break;
            case 4:
                Node<int> *aux = p.topo;
                while (aux!=NULL){
                    cout<< aux->info<<" ";
                    aux= aux->prox;
                }
                cout<<endl;
                break;
        }
    }while(opc != 9);
}

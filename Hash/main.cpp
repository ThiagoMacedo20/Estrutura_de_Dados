#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
    Hash h;
    int opc;
    int x;
    do{cout << "HASH TABLE" << endl;
    cout<<"1- insere"<<endl;
    cout<<"2- Remover"<<endl;
    cout<<"3- exibir Hash"<<endl;
    cout<<"9- fim"<<endl;
    cout<<"Selecione:";
    cin>>opc;
    switch(opc)
    {
    case 1:
        cout<<"Digite o numero:";
        cin>>x;
        h.insere(x);
        cout<<"Sucesso!"<<endl;
        break;
    case 2:
            cout<<"Insira o valor para remover : "<<endl;
            cin>>x;
            if(h.remover(x))
            {
                cout<<"Sucesso!"<<endl;
            }
            else
                cout<<"Valor n encontrado!"<<endl;

        break;
    case 3:
            cout<<"Elementos da Lista"<<endl;
            h.mostralista();
            cout<<"\n-------------"<<endl;
        break;
    case 9:
        cout<<"fim"<<endl;
        break;
    default:
        cout<<"opcao invalida"<<endl;
        break;
    }
}
while (opc!=9);
return 0;
};

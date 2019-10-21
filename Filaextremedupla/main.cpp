#include <iostream>
#include "Filadupla.h"
using namespace std;

int main()
{
    cout << "Fila em alocacao sequencial"<<endl;

    Fila<int>f(10);
    int opc,x;
    do
    {
        cout<<"\n 1 - Inserir no inicio"<<endl;
        cout<<" 2 - Inserir no fim"<<endl;
        cout<<" 3 - Remover o primeiro"<<endl;
        cout<<" 4 - Remover o ultimo"<<endl;
        cout<<" 5 - Exibir o primeiro"<<endl;
        cout<<" 6 - Exibir o final"<<endl;
        cout<<" 7 - Exibe a fila"<<endl;
        cout<<" 9 - Encerramento"<<endl;
        cout<<"\n Selecione: ";
        cin>>opc;

        switch (opc)
        {
        case 1:
            if(!f.filacheia())
            {
                cout<<"Digite o numero no incio: ";
                cin>>x;
                f.insereInicio(x);

            }
            break;
        case 2:
            if(!f.filacheia())
            {
                cout<<"Digite o numero no final: ";
                cin>>x;
                f.insereFinal(x);
            }
            break;
        case 3:
            if(!f.filavazia())
            {
                cout<<"Valor removido do inicio= "<< f.removerInicio();
            }
            break;
        case 4:
            if(!f.filavazia())
            {
                cout<<"Valor removido do final= "<< f.removerFinal();
            }
            break;
        case 5:
            if(!f.filavazia())
            {
                cout<<f.primeiroFila()<<endl;

            }
            break;
        case 6:
            if(!f.filavazia())
            {
                cout<<f.ultimoFila()<<endl;

            }
            break;
        case 7:
            if(f.inicio <= f.fim)
            {
                for(int i = f.inicio; i <= f.fim; i++)
                {
                    cout<<f.todosFila(i)<<"\t  "<<endl;
                }
            }
            else
            {
                for(int i = f.inicio; i < f.tamanho; i++)
                {
                    cout<<f.todosFila(i)<<"\t  "<<endl;
                }
                for(int i = 0; i <= f.fim; i++)
                {
                    cout<<f.todosFila(i)<<"\t "<<endl;
                }
            }


            break;
        case 9:

            cout<< "FIM"<<endl;
            break;
        }
    } while(opc!=9);






    return 0;

}

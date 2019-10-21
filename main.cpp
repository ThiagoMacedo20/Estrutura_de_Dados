#include <iostream>
#include "pilhasequencial.h"
using namespace std;

int main()
{
    string expressao;
    cout<<"Digite a expressao: ";
    //cin>>expressao;
    getline(cin,expressao);
    cout<< "Tamanho: "<<expressao.size()<<endl;
    for(int i=0; i<expressao.size(); i++)
    {
        char a=expressao.at(i);
        cout<<a<<endl;
        cout<<expressao.at(i)<<endl;
    }
    return 0;
}

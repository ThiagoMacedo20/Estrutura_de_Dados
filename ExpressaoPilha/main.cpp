#include <iostream>
#include "Pilha.h"
using namespace std;

int main()
{   string expressao;
    int i=0;
    int tamamnho=50;
    char simbolo;
    bool valido=true;

    cout << "Digite uma expressao: ";
    getline(cin, expressao);;
    Pilha <char> p (tamamnho);
    while (i<tamamnho) {
        simbolo = expressao[i];
        if (simbolo=='{'||simbolo=='['||simbolo=='(') {
            p.empilha(simbolo);
        } else if (simbolo=='}'||simbolo==']'||simbolo==')') {
            if (p.pilhaVazia()){
                valido = false;}

            else if (simbolo=='}'&& p.elementoDoTopo()=='{') {
                p.desempilha();
            } else if (simbolo==']' && p.elementoDoTopo() == '[') {
                p.desempilha();
            } else if (simbolo == ')' && p.elementoDoTopo() == '(') {
                p.desempilha();
            }
        }
        i++;
    }
    if (p.pilhaVazia()&& valido){
        cout << "Expressao Correta\n";
    }
    else
        cout << "Expressao Incorreta";

    return 0;
}



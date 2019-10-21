#include <iostream>
#include <stdlib.h>
#include "FilaLigada.h"
#include "PilhaLigada.h"
#include "Node.h"

//VERIFICAR A POSSIBILIDADE DE CRIAR UM METODO PERCORRER ESTRUTURA DENTRO DA ESTRUTURA

using namespace std;
/*Considere uma pilha e uma fila implementadas em alocação ligada.
*Construa uma aplicação para as seguintes atividades:
*1-carregar uma fila com 20 números aleatórios compreendidos entre 1 e 9(garanta a fila vazia ao selecionarmos esta opção)
*>>>>>>>>>2-Transferir todos os elementos da Fila para uma Pilha (garanta a pilha vazia ao selecionarmos esta opção)
*>>>>>>>>>3-Transferir todos os elementos da pilha para a fila (garanta a fila vazia ao selecionarmos esta opção)
*>>>>>>>>>4-Transferir todos os elementos da Fila para uma Pilha (garanta a pilha vazia ao selecionarmos esta opção)
de modo que os elementos sejam ordenados (crescente ou decrescente)*/
int main()
{
    FilaLigada<int> fl;                                                                     //DECLARANDO FILA LIGADA DE TIPO INT
    PilhaLigada<int> pl;                                                                    //DECLARANDO PILHA LIGADA DE TIPO INT
    int opc, x;
    do{                                                                                     //FAÇA ENQUANTO

        cout<<">>Menu do TP 4<<"<<endl;                                                     //MENU
        cout<<"1 - Iniciar randomico e inserir 20 numeros na fila"<<endl;
        cout<<"2 - Transferir elementos da fila para pilha"<<endl;
        cout<<"3 - Transferir elementos da pilha para fila"<<endl;
        cout<<"4 - Tranferir elementos da fila para pilha em ordem crescente"<<endl;
        cout<<"5 - Tranferir elementos da fila para pilha em ordem decrescente"<<endl;
        cout<<"6 - Exibir fila"<<endl;
        cout<<"7 - Exibir pilha"<<endl;
        cout<<"8 - sair"<<endl;
        cin>>opc;

        switch(opc){                                                                        //ESTRUTURA SWITCH
        case 1:
            int x;
            for(int i=0; i<20;i++){                                                         //REPETIR POR 20 VEZES
                x = rand()%10; /* gera numero randomico de 0 a 9 */

                if( fl.inserir(x)){//INSERE NA FILA
                    cout<<i<<" Inserido: "<<x<<endl;                                        //PRINTAR O NUMERO DO RANDOMICO
                 }else{
                   cout<<"Pau nelas"<<endl;
                 }
            }
            break;
        case 2: //FILA PARA PILHA
            if(fl.filaVazia()){                                                             //FILA VAZIA?
               cout<<"Fila vazia..."<<endl;                                                 //SIM
            }else{                                                                          //NÃO

                    int x=0, y=0;                                                                //VARIAVEL DO TIPO DE FILA
                    if(pl.pilhaVazia()){                                                    //*1 PILHA VAZIA? SE SIM

                        while(fl.inicio != NULL){                                            //INICIO DA FILA É DIFERENTE DE NULL? SE SIM ENTRA NA ESTRUTURA
                            y++;
                            x = fl.remover();                                               //X RECEBE RETORNO DO REMOVER

                            if(pl.empilha(x)){                                              //*2 PEGA VALOR REMOVIDO DA FILHA E EMPILHA
                                                                                            //SE EMPILHAR E VOLTAR TRUEL ELE PRINTA O ELEMENTO EMPILHADO
                                cout<< y <<" Empilhando: " << x <<endl;
                            }else{                                                          //*2 NÃO DEVERIA VOLTAR SO SE MEMOORIA ESTIVER CHEIA
                                cout<<"Erro"<<endl;
                            }
                        }
                    }else{                                                                  //*1 SE NÃO
                        cout<<"Pilha cheia...."<<endl;
                    }


            }
            break;
        case 3: //PILHA PARA FILA
                if(pl.pilhaVazia()){                                                        //*1 PILHA VAZIA? SE SIM
                    cout<<"Pilha Vazia..."<<endl;
                }else{                                                                      //NÃO
                    int x=0;                                                                //VARIAVEL DO TIPO DE PILHA
                    if(fl.filaVazia()){                                                     //*2 FILA VAZIA? SE SIM
                        while(pl.topo != NULL){                                             //REPETIR ENQUANTO TOPO FOR DIFERENTE DE NULL
                            x= pl.desempilha();                                             //X RECEBE O ELENTO DESEMPILHADO

                            if(fl.inserir(x)){                                              //*3 SE INSERIDO RETORNA TRUE
                                cout<<"Inserido: "<<x<<endl;                                //PRINTA  O ELEMENTO INSERIDO NA PILHA
                            }else{
                                cout<<"Erro.."<<endl;
                            }
                        }
                    }
                }
            break;
        case 4: //FILA PARA PILHA C
            if(fl.filaVazia()){                                                             //*1 FILA VAZIA? SE SIM
                cout<<"Fila vazia"<<endl;
            }else{                                                                          //*1 NÃO
                if(pl.pilhaVazia()){                                                        //*2 PILHA VAZIA? SE SIM
                    Node<int> * aux1 = fl.inicio;                                             //AUX1 APONTA PARA INICIO DA FILA;
                    Node<int> * aux2;                                             //CRIA UM PONTEIRO AUX2 QUE RECEBE O ENDEREÇO DE ONDE O PONTEIRO DENTRO DE INICIO ESTA APONTANDO.
                    int aux3 =0;
                    //ESSE LAÇO FUNCIONA COMO 2 FORS UM ROLANDO DENTRO DO OUTRO
                    while(aux1 != NULL){                                                      //ENQUANTO AUX 1 FOR DIFERENTE DE NULL
                        aux2 = aux1->prox;                                                     //AUX2 APONTA PARA ESTRUTURA QUE PROX APONTA
                        while(aux2 != NULL){                                                  //ENQUANTO AUX 2 FOR DIFERENTE DE NULL
                            if(aux1->info < aux2->info){                                      //VERIFICA SE INFO DE AUX 1 É MENOR QUE INFO DE AUX 2 (SE SIM)
                                aux3 = aux2->info;                                            //VARIAVEL AUX 3 RECEBE INFO DE AUX 2
                                aux2->info = aux1->info;                                      //INFO DE AUX2 RECEBE A INFO DE AUX 1
                                aux1->info = aux3;                                            //INFO DE AUX1 RECEBE AUX 3(ANTIGA  INFO DE AUX2)
                                }
                            aux2 = aux2->prox;                                                //AUX 2 PASSA APONTAR PARA A PROXIMA ESTRUTURA

                        }
                        aux1= aux1->prox;                                                     //AUX1 PASSA A APONTAR PARA O PROXIMO NUMERO
                    }
                    //MESMO METODO DO CASE 2
                    while(fl.inicio != NULL){                                               //INICIO DA FILA É DIFERENTE DE NULL? SE SIM ENTRA NA ESTRUTURA

                            x = fl.remover();                                               //X RECEBE RETORNO DO REMOVER

                            if(pl.empilha(x)){                                              //*2 PEGA VALOR REMOVIDO DA FILHA E EMPILHA
                                                                                            //SE EMPILHAR E VOLTAR TRUEL ELE PRINTA O ELEMENTO EMPILHADO
                                cout<<"Empilhando: " <<x<<endl;
                            }else{                                                          //*2 NÃO DEVERIA VOLTAR SO SE MEMOORIA ESTIVER CHEIA
                                cout<<"Erro"<<endl;
                            }
                    }
                }else{                                                                      //*2 NÃO
                    cout<<"Pilha Cheia..."<<endl;
                }
            }
            break;
        case 5: //FILA PARA PILHA D
            if(fl.filaVazia()){                                                             //*1 FILA VAZIA? SE SIM
                cout<<"Fila vazia"<<endl;
            }else{                                                                          //*1 NÃO
                if(pl.pilhaVazia()){                                                        //*2 PILHA VAZIA? SE SIM
                    Node<int> * aux1 = fl.inicio;                                             //AUX1 APONTA PARA INICIO DA FILA;
                    Node<int> * aux2;                                             //CRIA UM PONTEIRO AUX2 QUE RECEBE O ENDEREÇO DE ONDE O PONTEIRO DENTRO DE INICIO ESTA APONTANDO.
                    int aux3 =0;
                    //ESSE LAÇO FUNCIONA COMO 2 FORS UM ROLANDO DENTRO DO OUTRO
                    while(aux1 != NULL){                                                      //ENQUANTO AUX 1 FOR DIFERENTE DE NULL
                        aux2 = aux1->prox;                                                     //AUX2 APONTA PARA ESTRUTURA QUE PROX APONTA
                        while(aux2 != NULL){                                                  //ENQUANTO AUX 2 FOR DIFERENTE DE NULL
                            if(aux1->info > aux2->info){                                      //VERIFICA SE INFO DE AUX 1 É MENOR QUE INFO DE AUX 2 (SE SIM)
                                aux3 = aux2->info;                                            //VARIAVEL AUX 3 RECEBE INFO DE AUX 2
                                aux2->info = aux1->info;                                      //INFO DE AUX2 RECEBE A INFO DE AUX 1
                                aux1->info = aux3;                                            //INFO DE AUX1 RECEBE AUX 3(ANTIGA  INFO DE AUX2)
                                }
                            aux2 = aux2->prox;                                                //AUX 2 PASSA APONTAR PARA A PROXIMA ESTRUTURA

                        }
                        aux1= aux1->prox;                                                     //AUX1 PASSA A APONTAR PARA O PROXIMO NUMERO
                    }
                    //MESMO METODO DO CASE 2
                    while(fl.inicio != NULL){                                               //INICIO DA FILA É DIFERENTE DE NULL? SE SIM ENTRA NA ESTRUTURA

                            x = fl.remover();                                               //X RECEBE RETORNO DO REMOVER

                            if(pl.empilha(x)){                                              //*2 PEGA VALOR REMOVIDO DA FILHA E EMPILHA
                                                                                            //SE EMPILHAR E VOLTAR TRUEL ELE PRINTA O ELEMENTO EMPILHADO
                                cout<<"Empilhando: " <<x<<endl;
                            }else{                                                          //*2 NÃO DEVERIA VOLTAR SO SE MEMOORIA ESTIVER CHEIA
                                cout<<"Erro"<<endl;
                            }
                    }
                }else{                                                                      //*2 NÃO
                    cout<<"Pilha Cheia..."<<endl;
                }
            }
            break;
        case 6: //EXIBIR FILA
            if(fl.filaVazia()){                                 //FILA VAZIA?
                cout<<"Fila vazia..."<<endl;                    //SIM
            }else{                                              //NÃO
                cout<<"Numeros na Fila: "<<endl;
                Node<int> * aux=fl.inicio;                      //CRIA UM PONTEIRO DO TIPO NODE(QUE A FILA É FORMADA) AUX,
                                                                //ATRIBUI O ENDEREÇO DE MEMORIA DE INICIO DA FILA(REFERENCIA A FILA)
                                                                //AUX É IGUAL AO ENDEREÇO DE INICIO PQ A FILA SEGUE DO INICIO PARA O FIM

                while(aux !=NULL){                              //AUX DIFERENTE DE NULL? SE SIM (ENTRA NA ESTRUTURA)
                    cout<<aux->info<<" ";                       //AUX QUE REPRESENTA INICIO NA PRIMEIRA PASSAGEM E O PROXIMO ELEMENTO NAS SEGUINTES
                    aux = aux->prox;                             //APOS PRINTAR AUX COMEÇA  APONTAR PARA PROXIMO ELEMENTO DA FILA(PROX QUE ESTA DENTRO DELE)
                }
            }
            break;
        case 7: //EXIBIR  PILHA
            if(pl.pilhaVazia()){                                //FILA VAZIA?
                cout<<"Pilha vazia..."<<endl;                   //SIM
            }else{                                              //NÃO
                cout<<"Numeros na pilha: "<<endl;
                Node<int> * aux = pl.topo;                       //CRIA UM PONTEIRO DO TIPO NODE(QUE A PILHA É FORMADA) AUX,
                                                                //ATRIBUI O VALOR DE TOPO A AUX, PQ TOPO QUEM TEM O ENDEREÇO DE MEMORIA DO ELEMENTO ANTERIOR,
                                                                //ENTÃO AUX TEM O MESMO ENDEREÇO DE MEMORIA DE TOPO

                while(aux != NULL){                             //AUX DIFERENTE NULL? SE SIM(ENTRA NA ESTRUTURA)
                    cout<<aux->info<<" ";                      //AUX QUE REPRESENTA TOPO NA PRIMEIRA PASSAGEM E NAS SEGUINTES O NUMERO ANTERIOR
                    aux = aux->prox;                            //APOS PRINTAR AUX COMEÇA A APONTAR PARA O PROX  DELE MESMO(OU SEJA O ANTERIOR DA PILHA)
                }
                cout<<"saiu do laço"<<endl;
            }
            break;
        case 8:
            cout<<"Saindo da aplicação..."<<endl;
            break;
        default:
            cout<<"Opção invalida..."<<endl;
            break;

        }



    }while(opc != 8);


}


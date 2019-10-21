#ifndef PILHALIGADA_H_INCLUDED
#define PILHALIGADA_H_INCLUDED

template <typename Tipo>                        //TEMPLATE PARA TORNA UMA ESTRUTURA CORINGA
struct PilhaLigada{                             //A PILHA TEM AS CARARCTERISCAS DO UEPS
                                                //O ULTIMO ELEMENTO OU ELEMENTO DO TOPO, QUEM VAI APONTAR PARA O ELEMENTO ANTERIOR
                                                //ASSIM PROX DE NODE NA PILHA SE REFERE A ANTERIOR
                                                //TRABALHA COM "NO" IGUAL AO A FILA LIGADA(NÃO ALOCA DE FORMA SEQUENCIAL)

    Node<Tipo> * topo;                          //DECLARA UM PONTEIRO PARA UMA ESTRUTURA NODE

    PilhaLigada(){                              //CONSTRUTOR DA PILHA
                                                //QUANDO SE INICIA LOGO NÃO HA ELEMENTOS ENTÃO TOPO É IGUAL A NULL
        topo = NULL;
    }

    bool pilhaVazia(){                          //PRIMEIRO METODO É VERIFICA SE HA ELEMENTOS NA PILHA
        return topo==NULL;                      //SE HOUVER RETORNA FALSE
    }

    bool empilha(Tipo x){                       //INSERE ELEMENTO TIPO(CORINGA) NO TOPO DA PILHA
        bool v= true;                           //A VARIAVEM QUE IRA RETORNAR
        Node<Tipo> * aux = new Node<Tipo>;      //CRIA UUM PONTEIRO DO TIPO NODE, E ATRIBUI A ELE UMA NOVA ESTRUTURA
        if(aux==NULL){                          //SE ELE CONSEGUIR ALOCAR NA MEMORIA VAI RETORNA O ENDEREÇO DE MEMORIA
            v=false;                            //SE ENTRAR QUE DIZER QUE NÃO ALOCOU
        }else{                                  //SE ALOCAR
            aux->info = x;                      //A INFO DE AUX RECEBE O ELEMENTO X
            aux->prox = topo;                   //PROX DE AUX APONTA PARA ENDEREÇO DE MEMORIA DE TOPO(QUE ERA O ULTIMO DA PILHA)
            topo = aux;                         //ENTÃO TOPO AGORA APONTA PARA O AUX QUE É O ULTIMO ELEMENTO DA PILHA
        }
        delete aux;
        return v;                               //RETORNA V

                                                //AQUI DIFERENDE TA FILA TOPO APONTA PARA O ELEMENTO ANTERIOR(FIM APONTA PRO PROXIMO)
                                                //ISSO OCORRE PQ NA PILHA VOCE NÃO REMOVE NA BASE SO NO TOPO, PARA A PILHA N RUIR
    }

    Tipo desempilha(){                          //REMOVE O ULTIMO ELEMNTO E APONTA TOPO PARA O ELEMENTO ANTERIOR
        Tipo temp = topo->info;                 //A VARIAVEL (CORINGA), QUE VAI RETORNAR O VALOR QUE VAI SER APAGADO INFO DE TOPO
        Node<Tipo> * aux =  topo;                 //CRIA UM PONTEIRO AUX DO TIPO NODE E ATRIBUI O ENDEREÇO DE MEMORIA DE TOPO
        topo = topo->prox;                      //É ATRIBUIDO AO PONTEIRO TOPO O ENDEREÇO DE MEMORIA QUE SEU PROX ESTA APONTANDO(ELEMENTO ANTERIOR)

        delete aux;                             //DEVOLVE O ESPAÇO DA MEMORIA PARA O SISTEMA OPERACIONAL

        return temp;
    }
    Tipo infoTopo(){                            //RETORNA A INFO DENTRO DO PONTEIRO TOPO
        return topo->info;
    }

};


#endif // PILHALIGADA_H_INCLUDED

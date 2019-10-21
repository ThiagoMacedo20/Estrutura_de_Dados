#ifndef PILHALIGADA_H_INCLUDED
#define PILHALIGADA_H_INCLUDED

template <typename Tipo>                        //TEMPLATE PARA TORNA UMA ESTRUTURA CORINGA
struct PilhaLigada{                             //A PILHA TEM AS CARARCTERISCAS DO UEPS
                                                //O ULTIMO ELEMENTO OU ELEMENTO DO TOPO, QUEM VAI APONTAR PARA O ELEMENTO ANTERIOR
                                                //ASSIM PROX DE NODE NA PILHA SE REFERE A ANTERIOR
                                                //TRABALHA COM "NO" IGUAL AO A FILA LIGADA(N�O ALOCA DE FORMA SEQUENCIAL)

    Node<Tipo> * topo;                          //DECLARA UM PONTEIRO PARA UMA ESTRUTURA NODE

    PilhaLigada(){                              //CONSTRUTOR DA PILHA
                                                //QUANDO SE INICIA LOGO N�O HA ELEMENTOS ENT�O TOPO � IGUAL A NULL
        topo = NULL;
    }

    bool pilhaVazia(){                          //PRIMEIRO METODO � VERIFICA SE HA ELEMENTOS NA PILHA
        return topo==NULL;                      //SE HOUVER RETORNA FALSE
    }

    bool empilha(Tipo x){                       //INSERE ELEMENTO TIPO(CORINGA) NO TOPO DA PILHA
        bool v= true;                           //A VARIAVEM QUE IRA RETORNAR
        Node<Tipo> * aux = new Node<Tipo>;      //CRIA UUM PONTEIRO DO TIPO NODE, E ATRIBUI A ELE UMA NOVA ESTRUTURA
        if(aux==NULL){                          //SE ELE CONSEGUIR ALOCAR NA MEMORIA VAI RETORNA O ENDERE�O DE MEMORIA
            v=false;                            //SE ENTRAR QUE DIZER QUE N�O ALOCOU
        }else{                                  //SE ALOCAR
            aux->info = x;                      //A INFO DE AUX RECEBE O ELEMENTO X
            aux->prox = topo;                   //PROX DE AUX APONTA PARA ENDERE�O DE MEMORIA DE TOPO(QUE ERA O ULTIMO DA PILHA)
            topo = aux;                         //ENT�O TOPO AGORA APONTA PARA O AUX QUE � O ULTIMO ELEMENTO DA PILHA
        }
        delete aux;
        return v;                               //RETORNA V

                                                //AQUI DIFERENDE TA FILA TOPO APONTA PARA O ELEMENTO ANTERIOR(FIM APONTA PRO PROXIMO)
                                                //ISSO OCORRE PQ NA PILHA VOCE N�O REMOVE NA BASE SO NO TOPO, PARA A PILHA N RUIR
    }

    Tipo desempilha(){                          //REMOVE O ULTIMO ELEMNTO E APONTA TOPO PARA O ELEMENTO ANTERIOR
        Tipo temp = topo->info;                 //A VARIAVEL (CORINGA), QUE VAI RETORNAR O VALOR QUE VAI SER APAGADO INFO DE TOPO
        Node<Tipo> * aux =  topo;                 //CRIA UM PONTEIRO AUX DO TIPO NODE E ATRIBUI O ENDERE�O DE MEMORIA DE TOPO
        topo = topo->prox;                      //� ATRIBUIDO AO PONTEIRO TOPO O ENDERE�O DE MEMORIA QUE SEU PROX ESTA APONTANDO(ELEMENTO ANTERIOR)

        delete aux;                             //DEVOLVE O ESPA�O DA MEMORIA PARA O SISTEMA OPERACIONAL

        return temp;
    }
    Tipo infoTopo(){                            //RETORNA A INFO DENTRO DO PONTEIRO TOPO
        return topo->info;
    }

};


#endif // PILHALIGADA_H_INCLUDED

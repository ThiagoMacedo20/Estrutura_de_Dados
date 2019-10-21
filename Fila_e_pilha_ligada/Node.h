#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <typename Tipo>                    //DEFINE NODE COMO UMA ESTRUTURA GENERICA QUE SERVE PARA TODO TIPO DE VARIAVEL
struct Node{                                //(NODE) NO DE ESTRUTURA
                                            //(STRUCT) REPRESENDA TODOS OS OBJETOS COM MESMA CARACTERISTICA
    Tipo info;                              //VARIAVEL DO TIPO(GENERICA) QUE VAI VIR PELO TEMPLATE
    Node<Tipo> * prox;                      //UM PONTEIRO QUE A PONTA PARA UMA ESTRUTURA IGUAL A QUE ESTA SENDO CRIADA
};
#endif // NODE_H_INCLUDED

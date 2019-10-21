#ifndef PILHASEQUENCIAL_H_INCLUDED
#define PILHASEQUENCIAL_H_INCLUDED
template <typename Tipo>
struct Pilha
{

    Tipo *v;
    int topo;
    int tamanho;

    Pilha(int tam)
    {
        tamanho = tam;
        v = new Tipo[tamanho];
        topo=-1;
    }
    ~Pilha()
    {
        delete v;
    }
    void empilha(Tipo x)
    {
        topo++;
        v[topo]=x;
    }
    Tipo desempilha()
    {
        Tipo temp=v[topo];
        topo--;
        return temp;
    }
    Tipo elementoDoTopo()
    {
        return v[topo];
    }
    bool pilhaCheia()
    {
        return topo==tamanho-1;
    }
    bool pilhaVazia()
    {
        return topo==-1;
    }
    int getTopo()
    {
        return topo;
    }
    int getTamanho()
    {
        return tamanho;
    }
    Tipo getValor(int pos)
    {
        return v[pos];
    }
};
#endif



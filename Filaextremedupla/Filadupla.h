#ifndef FILADUPLA_H_INCLUDED
#define FILADUPLA_H_INCLUDED
template <typename Tipo>
struct Fila
{

    Tipo *v;
    int inicio;
    int fim;
    int qtde;
    int tamanho;

    Fila(int tam)
    {
        tamanho=tam;
        v=new Tipo [tamanho];
        inicio=0;
        fim=-1;
        qtde=0;
    }
    ~Fila()
    {
        delete v;
    }

    void insereInicio(Tipo x)
    {
        inicio++;
        if(inicio==tamanho)
        {
            inicio=0;
        }
        v[inicio]=x;
        qtde++;
    }
    void insereFinal(Tipo x)
    {
        fim++;
        if(fim==tamanho)
        {
            fim=0;
        }
        v[fim]=x;
        qtde++;
    }
    Tipo removerInicio()
    {
        Tipo temp=v[inicio];
        inicio++;
        if(inicio==tamanho)
        {
            inicio=0;
        }
        qtde--;
        return temp;

    }
    Tipo removerFinal()
    {
        Tipo temp=v[fim];
        fim++;
        if(fim==tamanho)
        {
            fim=0;
        }
        qtde--;
        return temp;

    }
    Tipo primeiroFila()
    {
        return v[inicio];
    }
    Tipo todosFila(int i){
         return v[i];
    }

    Tipo ultimoFila()
    {
        return v[fim];
    }
    bool filacheia()
    {
        return qtde==tamanho;
    }
    bool filavazia()
    {
        return qtde==0;
    }




};


#endif // FILADUPLA_H_INCLUDED

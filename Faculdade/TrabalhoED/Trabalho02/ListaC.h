#include "Nod.h"
template <typename dados>
class ListaC
{
private:
   Nod <dados> *Head;
   Nod <dados> *it;
    int N;

public:

    ListaC()
    {
        Head = 0;
        N = 0;
    }
    ~ListaC()
    {
       Nod <dados> *P;
        while (N)
        {
            P = Head->next;
           Nod <dados> ::DesmontaNod(Head);
            Head = P;
            N--;
        }
    }
    bool insert(dados X)
    {
       Nod <dados> *P =Nod <dados> ::MontaNod(X);
        if (!P)
            return false;
        if (!Head)
        {
            Head = it = P->next = P->previous = P;
        }
        else
        {
            P->previous = Head->previous;
            P->next = Head;
            (Head->previous)->next = P;
            Head->previous = P;
            Head = P;
        }
        N++;
        return true;
    }
bool insert(dados X, int Pp)
    {
       Nod <dados> *P =Nod <dados> ::MontaNod(X, Pp);
        if (!P)
            return false;
        if (!Head)
        {
            Head = it = P->next = P->previous = P;
        }
        else
        {
            P->previous = Head->previous;
            P->next = Head;
            (Head->previous)->next = P;
            Head->previous = P;
            Head = P;
        }
        N++;
        return true;
    }
    int size()
    {
        return N;
    }
    dados erase()
    {
        dados R;
       Nod <dados> *Aux;
        if (!Head)
            return R;
        Aux = it;
        if (it->next != it)
        {
            (it->next)->previous = it->previous;
            (it->previous)->next = it->next;
        }
        else
        {
            Head = 0;
        }
        if (Head == it)
        {
            Head = it = it->next;
        }
        else
        {
            it = it->next;
        }
        N--;
        R =Nod <dados> ::DesmontaNod(Aux);
        return R;
    }
   Nod <dados> * IT()
    {
        return it;
    }
    void IT_begin()
    {
        it = Head;
    }
    void ITend()
    {
        it = Head->previous;
    }
    void ITMais()
    {
        it = it->next;
    }
    void ITMenos()
    {
        it = it->previous;
    }
    /*bool Search(int X,Nod *PX)
    {

    }*/
};

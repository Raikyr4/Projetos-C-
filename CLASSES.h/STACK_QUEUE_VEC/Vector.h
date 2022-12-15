#include "Node.h"
template <typename T>
class VECTOR
{
public:
    Node<T> *Pi;
    Node<T> *Pf;
    int N;

public:
    VECTOR()
    {
        Pi = Pf = 0;
        N = 0;
    }

    ~VECTOR()
    {
        Node<T> *aux;
        while (Pi)
        {
            aux = Pi->next;
            Node<T> ::DesmontaNode(Pi);
            Pi = aux;
        }
    }
    bool insert(T Y)
    {
        Node<T> *aux = Node<T> ::MontaNode(Y);
        if (!Pi)
        {
            Pi = aux;
            Pf = aux;
            N++;
            return true;
        }
        else
        {
            Pf->next = aux;
            Pf = aux;
            N++;
            return true;
        }
        return false;
    }
    T get(int Da)
    {
        Node<T> *P = Pi;
        if (Da >= 0)
        {
            for (int i = 0; i < Da; i++)
            {
                P = P->next;
            }
            if (P)
            {
                return P->D;
            }
        }
    }
    int size()
    {
        if (!N)
        {
            return 0;
        }
        return N;
    }
};


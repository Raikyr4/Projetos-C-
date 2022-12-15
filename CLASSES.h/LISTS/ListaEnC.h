#include "Node.h"
template <typename T>
class ListaEnC
{
private:
    Node<T> *Head;
    int N;

public:
    ListaEnC()
    {
        Head = 0;
        N = 0;
    }
    ~ListaEnC()
    {
        Node<T> *P;
        while (N)
        {
            P = Head->next;
            Node<T>::DesmontaNode(Head);
            Head = P;
            N--;
        }
    }
    bool insert(T X)
    {
        Node<T> *P = Node<T>::MontaNode(X);
        if (!P)
            return false;
        if (!Head)
        {
            P->next = Head = P;
        }
        else
        {
            P->next = Head->next;
            Head->next = P;
            Head = P; // minha mudança
        }
        N++;
        return true;
    }
    T Search(int X)
    {
        Node<T> **P = &Head;
        T K;
        int cont = 0;
        if (!*P)
            return K;
        while (cont < N && ((*P)->D).Mat != X)
        {
            P = &((*P)->next);
            cont++;
        }
        if (cont < N)
        {
            K = (*P)->D;
        }

        return K;
    }
    T erase(int M)
    {
        Node<T> *Aux;
        T K;
        Node<T> **P = &Head;
        int cont = 0;
        while (cont < N && ((*P)->D).Mat != M)
        {
            P = &((*P)->next);
            cont++;
        }
        if (cont < N)
        {
            Aux = *P;
            *P = (*P)->next;
            K = Node<T>::DesmontaNode(Aux);
            N--;
        }
        return K;
    }
    int size()
    {
        return N;
    }
};
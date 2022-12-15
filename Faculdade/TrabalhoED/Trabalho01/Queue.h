#include "Node.h"
#include <iostream>
class Queue
{
private:
    Node *Head; // ponteiro para Node que ira apontar pra onde fica a cabeça/inicio da fila
    Node *Tail; // ponteiro para node que ira apontar pra onde fica o final da fila/rabo
    int N;

public:
    Queue();
    ~Queue();
    bool push(Fichas X) // caso a fila n estiver vazia um elemento é add
    {
        Node *P = Node ::MontaNode(X);
        if (!P)
        {
            return false;
        }
        if (Head)
        {
            Tail->next = P;
        }
        else
        {
            Head = P;
        }
        Tail = P;
        Tail->next = 0;
        N++;
        return true;
    }
    Fichas front()
    {
        Fichas X;
        if (Head)
        {
            X = Head->D;
        }
        return X;
    }
    Fichas pop()
    {
        Fichas X;
        if (Head)
        {
            Node *P = Head;
            Head = Head->next;
            X = Node ::DesmontaNode(P);
            if (!Head)
            {
                Tail = 0;
            }
            N--;
        }
        return X;
    }
    int size()
    {
        return N;
    }
    bool empty()
    {
        return !Head;
    }
};

Queue::Queue()
{
    Head = Tail = nullptr;
    N = 0;
}

Queue::~Queue()
{
    Node *P = Head;
    while (Head)
    {
        Head = P->next;
        Node ::DesmontaNode(P);
        P = Head;
    }
}
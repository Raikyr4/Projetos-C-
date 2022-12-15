#include <iostream>

#include "Queue.h"
/*aki será criado um classe Stack que usa alocamento dinâmico de memoria . A Pilha será composta por Nós !!!que possuem um elemento/trem/aluno  */
class Stack
{
private:
    Node *top; // ponteiro para Node
    int N;     // tamanho da pilha

public:
    Stack();           // vai setar valores NULL para Node * top e N;
    ~Stack()       // enquanto não estiver vazia ele irá desalocar os nodes criados
    {
        Node *P;
        while (top)
        {
            P = top;
            top = top->next;
            Node ::DesmontaNode(P);
        }
    } 
    bool push(Fichas X) // add um elemento na pilha. Monta um Nó e passa os valores do parâmetro e o top pra dentro dele 
    {
        Node *P = Node ::MontaNode(X);
        if (!P)
            return false;
        P->next = top;
        top = P;
        N++;
        return true;
    }
    bool empty()
    {
        return !top;
    }
    Fichas Top() // se a pilha não estiver vazia ele retorna o elemento do topo
    {
        Fichas X;
        if (top)
            X = top->D;
        return X;
    }
    Fichas pop() //se a pilha não estiver vazia a função guarda o top em um ponteiro de node  , aponta o top para o próximo e desaloca o o node do antigo top que será passado por ponteiro para o DesmontaNode 
    {
        Fichas X;
        if (top)
        {
            Node *P = top;
            top = top->next;
            X = Node ::DesmontaNode(P);
            N--;
        }
        return X;
    }
    int size()
    {
        return N;
    }
};

Stack::Stack()
{
    top = 0;
    N = 0;
}


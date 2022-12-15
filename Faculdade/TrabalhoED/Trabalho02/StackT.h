#include "Node.h"
template <typename T>
/*aki será criado um classe StackT que usa alocamento dinâmico de memoria . A Pilha será composta por Nós !!!que possuem um elemento/trem/aluno  */
class StackT
{
private:
    Node <T> *top; // ponteiro para Node
    int N;      // tamanho da pilha

public:
    StackT(); // vai setar valores NULL para Node <T> * top e N;
    ~StackT() // enquanto não e{
    top = 0;
    N = 0;
}stiver vazia ele irá desalocar os nodes criados
    {
        Node <T> *P;
        while (top)
        {
            P = top;
            top = top->next;
            Node <T> ::DesmontaNode(P);
        }
    }
    bool push(string X) // add um elemento na pilha. Monta um Nó e passa os valores do parâmetro e o top pra dentro dele
    {
        Node <T> *P = Node <T> ::MontaNode(X);
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
    string Top() // se a pilha não estiver vazia ele retorna o elemento do topo
    {
        string X;
        if (top)
        X = top->D;
        return X;
    }
    string pop() // se a pilha não estiver vazia a função guarda o top em um ponteiro de node  , aponta o top para o próximo e desaloca o o node do antigo top que será passado por ponteiro para o DesmontaNode
    {
        string X;
        if (top)
        {
            Node <T> *P = top;
            top = top->next;
            X = Node <T> ::DesmontaNode(P);
            N--;
        }
        return X;
    }
    int size()
    {
        return N;
    }
};

StackT::StackT()


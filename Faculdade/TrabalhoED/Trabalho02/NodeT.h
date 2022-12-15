#include <iostream>
using namespace std;
class NodeT
{
public:
    string D;    // tipo de objeto que sera copiado para dentro do Nó
    NodeT *next; // ponteiro que irá apontar para o Nó seguinte

public:
    static NodeT *MontaNodeT(string Date) // método estático que nao roda em cima de um objeto da classe node , ele cria um ponteiro pra node que recebe um novo node que recebe um trem/aluno para dentro do seu D e o seu next aponta para null
    {
        NodeT *P = new NodeT;
        if (P)
        {
            P->D = Date;
            P->next =0;
        }
        return P;
    }
    static string DesmontaNodeT(NodeT *P) // método estático que nao roda em cima de um objeto da classe node , ele salva o elemento do Nó que será excluído e logo após deleta o Nó que foi alocado e logo em seguida retorna o elemento salvo
    {
        string X;
        if (P)
        {
            X = P->D;
            delete P;
        }
        return X;
    }
};
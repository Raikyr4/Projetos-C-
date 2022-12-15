#include "Stack.h"// CLASSES.h
template <typename dado>
class Nod
{
public:
    dado D;
    int ID_Player;
    int Pontos;
    Nod *next;
    Nod *previous;

public:
    static Nod *MontaNod(dado Date,int Play)
    {
        Nod *P = new Nod;
        if (P)
        {
            P->D = Date;
            P->ID_Player = Play;
            P->Pontos=0;
            P->next = 0;
            P->previous = 0;
        }
        return P;
    }
static Nod *MontaNod(dado Date)
    {
        Nod *P = new Nod;
        if (P)
        {
            P->D = Date;
            P->ID_Player =0;
            P->Pontos=0;
            P->next = 0;
            P->previous = 0;
        }
        return P;
    }
    static dado DesmontaNod(Nod *P) 
    {
        dado X;
        if (P)
        {
            X = P->D;
            delete P;
        }
        return X;
    }
};


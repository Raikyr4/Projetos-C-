#include <iostream>
#include "ListaC.h"
using namespace std;

void ZeraPontos(ListaC<ListaC<string>> P)
{
    for (int h = 0; h < P.size(); h++)
    {
        P.IT()->Pontos = 0;
        P.ITMais();
    }
    P.IT_begin();
}

void VerificaMonte(Stack <string> M, Stack <string> L)
{
    if (M.size() == 0)
    {
        string aux = L.pop();
        while (L.size() != 0)
        {
            M.push(L.Top());
            L.pop();
        }
        L.push(aux);
    }
    else
        return;
}

bool VerificaMao(ListaC<ListaC<string>> P)
{
    bool T = false;
    for (int i = 0; i < P.size() && T == false; i++)
    {
        if (P.IT()->D.size() == 0)
        {
            T = true;
        }
        P.ITMais();
    }
    P.IT_begin();
    return T;
}

void Esvazialixo(Stack <string> Mm, Stack <string> Ll)
{
    while (Ll.size() != 0)
    {
        Mm.push(Ll.Top());
        Ll.pop();
    }
}
int main()
{
    int N; // numero de partidas
    int J; // numero de jogadores
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> J;
        ListaC<ListaC<string>> Players;
        Stack <string> Monte, Lixo;
        for (int i2 = 1; i2 <= J; i2++) // lista de jogadores
        {
            ListaC<string> X;
            Players.insert(X, i2);
        }

        string Card;
        string C;
        for (int i3 = 0; i3 < 104; i3++) // recebendo as cartas do monte
        {
            cin >> Card;
            C = Card;
            Monte.push(C);
        }

        Players.IT_begin();
        int cont = 0;
        while (cont < J * 5) //  distribuindo as cartas para cada jogador
        {
            Players.IT()->D.insert(Monte.Top());
            Monte.pop();
            Players.ITMais();
            cont++;
        }

        bool ordem = false; // normal == false / invertida == true
        bool pula = false;  // n pula ==false / pula ==true
        Players.IT_begin(); // o jogo começa no jogador 1

        while (Players.size() != 1)
        {
            Players.IT()->D.IT_begin();
            if (VerificaMao(Players))
            {
                int Maior_ponto = 0;
                int Id_Maior_Player;
                int Id_Mao_Zero;
                for (int i4 = 0; i4 < Players.size(); i4++)
                {
                    if (Players.IT()->Pontos > Maior_ponto)
                    {
                        Maior_ponto = Players.IT()->Pontos;
                        Id_Maior_Player = Players.IT()->ID_Player;
                    }
                    if (Players.IT()->D.size() == 0)
                    {
                        Id_Mao_Zero = Players.IT()->ID_Player;
                    }
                    Players.ITMais();
                }

                Players.IT_begin();

                for (int i5 = 0; i5 < Players.size(); i5++)
                {
                    if (Id_Maior_Player == Players.IT()->ID_Player || Id_Mao_Zero == Players.IT()->ID_Player)
                    {
                        Players.erase();
                    }
                    Players.ITMais();
                }
                int cont2 = 0;
                Players.IT_begin();
                Esvazialixo(Monte, Lixo);
            }
            else // rodada ainda ñ acabou
            {
                if (Lixo.size() == 0)
                {

                    string cc;
                    cout<<"oi"<<endl;
                    cc = Players.IT()->D.erase();
                    Players.IT();
                    cout << "ta em cima " << endl;
                    Lixo.push(cc);
                    cout << "ta em baixo " << endl;
                    string aux = Lixo.Top();
                    if (aux[0] == 'L')
                    {
                        ordem = true;
                        Players.IT()->Pontos += 12;
                    }
                    else
                    {
                        if (aux[0] == 'A')
                        {
                            pula = true;
                            Players.IT()->Pontos += 1;
                        }
                        else
                        {
                            if (aux[0] == 'G')
                            {
                                Players.IT()->Pontos += 7;
                                (Players.IT()->next)->D.insert(Monte.pop());
                                VerificaMonte(Monte, Lixo);
                                (Players.IT()->next)->D.insert(Monte.pop());
                                VerificaMonte(Monte, Lixo);
                                (Players.IT()->next)->D.insert(Monte.pop());
                                VerificaMonte(Monte, Lixo);
                            }
                            else
                            {
                                if (aux[0] == 'I')
                                {
                                    Players.IT()->Pontos += 9;
                                    (Players.IT()->previous)->D.insert(Monte.pop());
                                    VerificaMonte(Monte, Lixo);
                                    (Players.IT()->previous)->D.insert(Monte.pop());
                                    VerificaMonte(Monte, Lixo);
                                }
                                else
                                {
                                    if (aux[0] == 'B')
                                    {
                                        Players.IT()->Pontos += 2;
                                    }
                                    else
                                    {
                                        if (aux[0] = 'C')
                                        {
                                            Players.IT()->Pontos += 3;
                                        }
                                        else
                                        {
                                            if (aux[0] = 'D')
                                            {
                                                Players.IT()->Pontos += 4;
                                            }
                                            else
                                            {
                                                if (aux[0] = 'E')
                                                {
                                                    Players.IT()->Pontos += 5;
                                                }
                                                else
                                                {
                                                    if (aux[0] = 'F')
                                                    {
                                                        Players.IT()->Pontos += 6;
                                                    }
                                                    else
                                                    {
                                                        if (aux[0] = 'H')
                                                        {
                                                            Players.IT()->Pontos += 8;
                                                        }
                                                        else
                                                        {
                                                            if (aux[0] = 'J')
                                                            {
                                                                Players.IT()->Pontos += 10;
                                                            }
                                                            else
                                                            {
                                                                if (aux[0] = 'K')
                                                                {
                                                                    Players.IT()->Pontos += 11;
                                                                }
                                                                else
                                                                {
                                                                    if (aux[0] = 'M')
                                                                    {
                                                                        Players.IT()->Pontos += 13;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    bool tem = false;
                    string L = Lixo.Top();
                    int PosicaoDaMaiorstring;
                    string Maior = "@";
                    for (int i6 = 1; i6 <= Players.IT()->D.size(); i6++)
                    {
                        string aux2 = Players.IT()->D.IT()->D;
                        if ((aux2[0] == L[0] || aux2[1] == L[1])) // se for do mesmo nipe ou se for do mesmo numero
                        {
                            if (aux2[0] > Maior[0]) // se for a maior q ele pode jogar salva a posição
                            {
                                Maior = aux2;
                                PosicaoDaMaiorstring = i6;
                                tem = true;
                            }
                        }
                        Players.IT()->D.ITMais();
                    }
                    Players.IT()->D.IT_begin();

                    if (tem)
                    {
                        for (int i7 = 0; i7 < PosicaoDaMaiorstring; i7++)
                        {
                            Players.IT()->D.ITMais();
                        }
                        Lixo.push(Players.IT()->D.erase());
                        string aux3 = Lixo.Top();
                        if (aux3[0] == 'L')
                        {
                            ordem = true;
                            Players.IT()->Pontos += 12;
                        }
                        else
                        {
                            if (aux3[0] == 'A')
                            {
                                pula = true;
                                Players.IT()->Pontos += 1;
                            }
                            else
                            {
                                if (aux3[0] == 'G')
                                {
                                    Players.IT()->Pontos += 7;
                                    (Players.IT()->next)->D.insert(Monte.pop());
                                    VerificaMonte(Monte, Lixo);
                                    (Players.IT()->next)->D.insert(Monte.pop());
                                    VerificaMonte(Monte, Lixo);
                                    (Players.IT()->next)->D.insert(Monte.pop());
                                    VerificaMonte(Monte, Lixo);
                                }
                                else
                                {
                                    if (aux3[0] == 'I')
                                    {
                                        Players.IT()->Pontos += 9;
                                        (Players.IT()->previous)->D.insert(Monte.pop());
                                        VerificaMonte(Monte, Lixo);
                                        (Players.IT()->previous)->D.insert(Monte.pop());
                                        VerificaMonte(Monte, Lixo);
                                    }
                                    else
                                    {
                                        if (aux3[0] == 'B')
                                        {
                                            Players.IT()->Pontos += 2;
                                        }
                                        else
                                        {
                                            if (aux3[0] = 'C')
                                            {
                                                Players.IT()->Pontos += 3;
                                            }
                                            else
                                            {
                                                if (aux3[0] = 'D')
                                                {
                                                    Players.IT()->Pontos += 4;
                                                }
                                                else
                                                {
                                                    if (aux3[0] = 'E')
                                                    {
                                                        Players.IT()->Pontos += 5;
                                                    }
                                                    else
                                                    {
                                                        if (aux3[0] = 'F')
                                                        {
                                                            Players.IT()->Pontos += 6;
                                                        }
                                                        else
                                                        {
                                                            if (aux3[0] = 'H')
                                                            {
                                                                Players.IT()->Pontos += 8;
                                                            }
                                                            else
                                                            {
                                                                if (aux3[0] = 'J')
                                                                {
                                                                    Players.IT()->Pontos += 10;
                                                                }
                                                                else
                                                                {
                                                                    if (aux3[0] = 'K')
                                                                    {
                                                                        Players.IT()->Pontos += 11;
                                                                    }
                                                                    else
                                                                    {
                                                                        if (aux3[0] = 'M')
                                                                        {
                                                                            Players.IT()->Pontos += 13;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else // ñ tem carta na mao
                    {
                        string aux4 = Monte.Top();
                        string L2 = Lixo.Top();
                        if (aux4[0] == L2[0] || aux4[1] == L2[1])
                        {
                            Lixo.push(Monte.pop());
                            VerificaMonte(Monte, Lixo);
                        }
                        else
                        {
                            Players.IT()->D.insert(Monte.pop());
                            VerificaMonte(Monte, Lixo);
                        }
                    }
                }

                if (ordem)
                {
                    if (pula)
                    {
                        Players.ITMenos();
                        Players.ITMenos();
                    }
                    else
                    {
                        Players.ITMenos();
                    }
                }
                else
                {
                    if (pula)
                    {
                        Players.ITMais();
                        Players.ITMais();
                    }
                    else
                    {
                        Players.ITMais();
                    }
                }
            }
        }
        cout << "O Vencedor da Partida " << i << " eh o Jogador " << Players.IT()->ID_Player << endl;
        ////////////////////////////////////////////
    }
}
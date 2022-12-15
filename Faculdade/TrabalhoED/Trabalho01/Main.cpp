#include <iostream>
//#include "Interface.h"
#include "Stack.h"
using namespace std;
int Maior(int P1, int P2, int P3, int P4)
{
    int maiorponto = 0;

    if (P1 > maiorponto)
    {
        maiorponto = P1;
    }
    if (P2 > maiorponto)
    {
        maiorponto = P2;
    }
    if (P3 > maiorponto)
    {
        maiorponto = P3;
    }
    if (P4 > maiorponto)
    {
        maiorponto = P4;
    }
    return maiorponto;
}

int main()
{
    char Player, Torre, Cor;
    string D;
    Stack *P = new Stack[6];
    Queue *Mao = new Queue[4];
    Fichas *Cardsss = new Fichas[52];
    Fichas M;

    for (int i = 0; i < 52; i++) // ORGANIZANDO AS JOGADAS

    {
        cin >> D;
        Player = D[0];
        Cor = D[1];
        Torre = D[2];
        M.set_ficha(Player, Cor, Torre);
        Cardsss[i] = M;
        if (Cor == 'A')
        {
            Mao[0].push(Cardsss[i]);
        }
        else
        {
            if (Cor == 'V')
            {
                Mao[1].push(Cardsss[i]);
            }
            else
            {
                if (Cor == 'R')
                {
                    Mao[2].push(Cardsss[i]);
                }
                else
                {
                    Mao[3].push(Cardsss[i]);
                }
            }
        }
    }

    bool aux;
    aux = false;
    for (int i = 0; i < 13 && aux == false; i++) // EMPILHANDO !!
    {
        for (int j = 0; j < 4; j++)
        {
            if (Mao[j].front().Tower == '1')
            {
                if (P[0].size() == 6) //&& (Mao[j].front().Card != 'P'))
                {
                    for (int h = 1; h < 6; h++)
                    {
                        if (P[h].size() < 6)
                        {
                            P[h].push(Mao[j].front());
                            break;
                        }
                    }
                }
                else
                {
                    if (P[0].size() > 0 && P[0].size() <= 6 && (Mao[j].front().Card == 'P'))
                    {
                        P[0].pop();
                        // P[0].push(Mao[j].front());
                        Mao[j].pop();
                    }
                    if (P[0].size() >= 0 && P[0].size() < 6 && (Mao[j].front().Card != 'P'))
                    {
                        P[0].push(Mao[j].front());
                        Mao[j].pop();
                    }
                }
            }
            else
            {

                if (Mao[j].front().Tower == '2')
                {
                    if (P[1].size() == 6) //&& (Mao[j].front().Card != 'P'))
                    {
                        for (int h = 2, k = 0; k < 6; k++)
                        {
                            if (P[h].size() < 6)
                            {

                                P[h].push(Mao[j].front());
                                break;
                            }
                            h = (h + 1) % 6;
                        }
                    }
                    else
                    {
                        if (P[1].size() >= 0 && P[1].size() <= 6 && (Mao[j].front().Card == 'P'))
                        {
                            P[1].pop();
                            // P[1].push(Mao[j].front());
                            Mao[j].pop();
                        }
                        if (P[1].size() >= 0 && P[1].size() < 6 && (Mao[j].front().Card != 'P'))
                        {
                            P[1].push(Mao[j].front());
                            Mao[j].pop();
                        }
                    }
                }
                else
                {
                    if (Mao[j].front().Tower == '3')
                    {
                        if (P[2].size() == 6) //&& (Mao[j].front().Card != 'P'))
                        {
                            for (int h = 3, k = 0; k < 6; k++)
                            {
                                if (P[h].size() < 6)
                                {

                                    P[h].push(Mao[j].front());
                                    break;
                                }
                                h = (h + 1) % 6;
                            }
                        }
                        else
                        {
                            if (P[2].size() >= 0 && P[2].size() <= 6 && (Mao[j].front().Card == 'P'))
                            {
                                P[2].pop();
                                //  P[2].push(Mao[j].front());
                                Mao[j].pop();
                            }
                            if (P[2].size() >= 0 && P[2].size() < 6 && (Mao[j].front().Card != 'P'))
                            {
                                P[2].push(Mao[j].front());
                                Mao[j].pop();
                            }
                        }
                    }
                    else
                    {
                        if (Mao[j].front().Tower == '4')
                        {
                            if (P[3].size() == 6) //&& (Mao[j].front().Card != 'P'))
                            {
                                for (int h = 4, k = 0; k < 6; k++)
                                {
                                    if (P[h].size() < 6)
                                    {

                                        P[h].push(Mao[j].front());
                                        break;
                                    }
                                    h = (h + 1) % 6;
                                }
                            }
                            else
                            {
                                if (P[3].size() >= 0 && P[3].size() <= 6 && (Mao[j].front().Card == 'P'))
                                {
                                    P[3].pop();
                                    //  P[3].push(Mao[j].front());
                                    Mao[j].pop();
                                }
                                if (P[3].size() >= 0 && P[3].size() < 6 && (Mao[j].front().Card != 'P'))
                                {
                                    P[3].push(Mao[j].front());
                                    Mao[j].pop();
                                }
                            }
                        }
                        else
                        {
                            if (Mao[j].front().Tower == '5')
                            {
                                if (P[4].size() == 6) //&& (Mao[j].front().Card != 'P'))
                                {
                                    for (int h = 5, k = 0; k < 6; k++)
                                    {
                                        if (P[h].size() < 6)
                                        {

                                            P[h].push(Mao[j].front());
                                            break;
                                        }
                                        h = (h + 1) % 6;
                                    }
                                }
                                else
                                {
                                    if (P[4].size() >= 0 && P[4].size() <= 6 && (Mao[j].front().Card == 'P'))
                                    {
                                        P[4].pop();
                                        //   P[4].push(Mao[j].front());
                                        Mao[j].pop();
                                    }
                                    if (P[4].size() >= 0 && P[4].size() < 6 && (Mao[j].front().Card != 'P'))
                                    {
                                        P[4].push(Mao[j].front());
                                        Mao[j].pop();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((P[0].size() == 6) && (P[1].size() == 6) && (P[2].size() == 6) && (P[3].size() == 6) && (P[4].size() == 6) && (P[5].size() == 6))
        {
            aux = true;
        }
    }

    // QUEM GANHOU !!
    cout << endl;
    cout << endl;
    int Mat[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << P[i].Top().Play << P[i].Top().Card << P[i].Top().Tower << " ";
            Mat[i][j] = P[i].Top().Play - '0';
            P[i].pop();
        }
        cout << "\n";
    }
    cout << endl;
    int Po1 = 0, Po2 = 0, Po3 = 0, Po4 = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == i)
            {

                if (Mat[i][j] == 1)
                {
                    Po1++;
                }
                else
                {
                    if (Mat[i][j] == 2)
                    {
                        Po2++;
                    }
                    else
                    {
                        if (Mat[i][j] == 3)
                        {
                            Po3++;
                        }
                        else
                        {
                            Po4++;
                        }
                    }
                }
            }
        }
    }

    cout << "\n";
    cout << "O VENCEDOR FOI O JOGADOR : " << Maior(Po1, Po2, Po3, Po4) << endl;
    cout << endl;
    cout << "MAO DO JOGADOR 1 : ";
    while (!P[0].empty())
    {
        cout << P[0].Top().Play << P[0].Top().Card << P[0].Top().Tower << " ";
    }
    cout << endl;
    cout << "MAO DO JOGADOR 2 : ";
    while (!P[1].empty())
    {
        cout << P[1].Top().Play << P[1].Top().Card << P[1].Top().Tower << " ";
    }
    cout << endl;
    cout << "MAO DO JOGADOR 3 : ";
    while (!P[2].empty())
    {
        cout << P[2].Top().Play << P[2].Top().Card << P[2].Top().Tower << " ";
    }
    cout << endl;
    cout << "MAO DO JOGADOR 4 : ";
    while (!P[3].empty())
    {
        cout << P[3].Top().Play << P[3].Top().Card << P[3].Top().Tower << " ";
    }
}
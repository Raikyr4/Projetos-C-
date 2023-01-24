#include <iostream>
using namespace std;

int M, N, cont;
char Mat[101][101];
char Instructions;
bool reto = true;

void flood(int i, int j,string Ordens)
{
    cont++;
    Mat[i][j] = 'x';

    if (j - 1 >= 0 && Mat[i][j - 1] == '*' || Mat[i][j - 1] == '.')
        flood(i, j - 1,Ordens[]);

    if (j + 1 < N && Mat[i][j + 1] == '*' || Mat[i][j + 1] == '.')
        flood(i, j + 1);

    if (i - 1 >= 0 && Mat[i - 1][j] == '*' || Mat[i - 1][j] == '.')
        flood(i - 1, j);

    if (i + 1 < M && Mat[i + 1][j] == '*' ||  Mat[i + 1][j] == '.')
        flood(i + 1, j);

    /* if (i - 1 >= 0 && j - 1 >= 0 && Mat[i - 1][j - 1] == '*')
         flood(i - 1, j - 1);

     if (i - 1 >= 0 && j + 1 < N && Mat[i - 1][j + 1] == '*')
         flood(i - 1, j + 1);

     if (i + 1 < M && j + 1 < N && Mat[i + 1][j + 1] == '*')
         flood(i + 1, j + 1);

     if (i + 1 < M && j - 1 >= 0 && Mat[i + 1][j - 1] == '*')
         flood(i + 1, j - 1);*/
}
int main()
{
    int In;
    char North[4];

    while (cin >> M >> N >> In && M && N && In)
    {
        int stickers = 0, count = 0;
        string S, Ordens;
        int x, y;
        for (int i = 0; i < M; i++)
        {
            cin >> S;
            for (int j = 0; j < N; j++)
            {
                Mat[i][j] = S[j];
                if (S[j] == '*')
                {
                    stickers++;
                }
                else
                {
                    if (Mat[i][j] == 'N')
                    {
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cin >> Ordens;
        for (int i = 0; i < Ordens.size(); i++)
        {
            flood(x,y);
        }
    }
}
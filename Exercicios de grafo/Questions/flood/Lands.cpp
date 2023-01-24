#include <iostream>
using namespace std;
int lin, col;
char M[21][21];
int cont, maior;
char land;
void flood(int i, int j)
{
    M[i][j] = land + 9; // substitui uma land sempre q entrar
    cont++;             //
    if (j - 1 >= 0 && M[i][j - 1] == land)
        flood(i, j - 1);

    if (j + 1 < col && M[i][j + 1] == land)
        flood(i, j + 1);

    if (i - 1 >= 0 && M[i - 1][j] == land)
        flood(i - 1, j);

    if (i + 1 < lin && M[i + 1][j] == land)
        flood(i + 1, j);

    if (j == 0 && M[i][col - 1] == land)
        flood(i, col - 1);

    if (j == col - 1 && M[i][0] == land)
        flood(i, 0);
}
int main()
{
    cont = 0;
    int x, y;
    while (cin >> lin>> col && lin && col)
    {
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> M[i][j];
            }
        }
        cin >> x >> y;
        land = M[x][y];
        flood(x, y);
       // cout << land << endl;
        cont = 0;
        maior = 0;
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j <col; j++)
            {
                if (M[i][j] == land)
                {
                    flood(i, j);
                    maior = max(maior, cont);
                    cont = 0;
                }
            }
        }
        cout << maior << endl; 
        cont = 0;
    }
}
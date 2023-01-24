#include <iostream>
using namespace std;
char M[200][200];
int lin, col, cont;
void flood(int i, int j)
{
    cont++;
    M[i][j] = '.';

    if (j - 1 >= 0 && M[i][j - 1] == '*')
        flood(i, j - 1);

    if (j + 1 < col && M[i][j + 1] == '*')
        flood(i, j + 1);

    if (i - 1 >= 0 && M[i - 1][j] == '*')
        flood(i - 1, j);

    if (i + 1 < lin && M[i + 1][j] == '*')
        flood(i + 1, j);

    if (i - 1 >= 0 && j - 1 >= 0 && M[i - 1][j - 1] == '*')
        flood(i - 1, j - 1);

    if (i - 1 >= 0 && j + 1 < col && M[i - 1][j + 1] == '*')
        flood(i - 1, j + 1);

    if (i + 1 < lin && j + 1 < col && M[i + 1][j + 1] == '*')
        flood(i + 1, j + 1);

    if (i + 1 < lin && j - 1 >= 0 && M[i + 1][j - 1] == '*')
        flood(i + 1, j - 1);
}
int main()
{
    cont = 0;
    int stars = 0;
    while (cin >> lin >> col && lin && col)
    {
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> M[i][j];
            }
        }
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (M[i][j] == '*')
                {
                    flood(i, j);
                    if (cont == 1)
                    {
                        stars++;
                    }
                    cont = 0;
                }
            }
        }
        cout << stars << endl;
        stars = 0;
    }
}
#include <iostream>
using namespace std;

char M[5][5];
int cont;

void flood(int i, int j)
{
    cont++;
    M[i][j] = '.';

    if (j - 1 >= 0 && M[i][j - 1] == '1')
        flood(i, j - 1);

    if (j + 1 < 5 && M[i][j + 1] == '1')
        flood(i, j + 1);

    if (i - 1 >= 0 && M[i - 1][j] == '1')
        flood(i - 1, j);

    if (i + 1 < 5 && M[i + 1][j] == '1')
        flood(i + 1, j);

    if (i - 1 >= 0 && j - 1 >= 0 && M[i - 1][j - 1] == '1')
        flood(i - 1, j - 1);

    if (i - 1 >= 0 && j + 1 < 5 && M[i - 1][j + 1] == '1')
        flood(i - 1, j + 1);

    if (i + 1 < 5 && j + 1 < 5 && M[i + 1][j + 1] == '1')
        flood(i + 1, j + 1);

    if (i + 1 < 5 && j - 1 >= 0 && M[i + 1][j - 1] == '1')
        flood(i + 1, j - 1);
}

int main()
{
    string X;
    int N, big = 0;
    cin >> N;
    gets(M[0]);
    gets(M[0]);
    while (N--)
    {

        cont = 0;
        for (int i = 0; i < 5; i++)
        {
            cin >> X;
            for (int j = 0; j < 5; j++)
            {
                M[i][j] = X[j];
            }
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (M[i][j] == '1')
                {
                    flood(i, j);
                    if (cont > big)
                    {
                        big = cont;
                    }
                    cont = 0;
                }
            }
        }
        cout << big << endl;
        if (N)
            cout << endl;
    }
}
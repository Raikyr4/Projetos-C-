#include <iostream>
using namespace std;
// 1 + eagles
char M[30][30];
int lin, col, cont;
void flood(int i, int j)
{
    M[i][j] = '*';
    cont++;
    if (j - 1 >= 0 && M[i][j - 1] == '1')
        flood(i, j - 1);

    if (j + 1 < col && M[i][j + 1] == '1')
        flood(i, j + 1);

    if (i - 1 >= 0 && M[i - 1][j] == '1')
        flood(i - 1, j);

    if (i + 1 < lin && M[i + 1][j] == '1')
        flood(i + 1, j);

    if (i - 1 >= 0 && j - 1 >= 0 && M[i - 1][j - 1] == '1')
        flood(i - 1, j - 1);

    if (i - 1 >= 0 && j + 1 < col && M[i - 1][j + 1] == '1')
        flood(i - 1, j + 1);

    if (i + 1 < lin && j + 1 < col && M[i + 1][j + 1] == '1')
        flood(i + 1, j + 1);

    if (i + 1 < lin && j - 1 >= 0 && M[i + 1][j - 1] == '1')
        flood(i + 1, j - 1);
}
int main()
{
    int eagles = 0, round = 1;
    cont = 0;
    while (cin >> lin && lin)
    {
        string S;
        col = lin;
        for (int i = 0; i < lin; i++)
        {
            cin >> S;
            for (int j = 0; j < col; j++)
            {
                M[i][j] = S[j];
            }
        }

        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (M[i][j] == '1')
                {
                    flood(i, j);
                    eagles++;
                    /*
                    if(cont>=1)
                    {
                        eagles++;
                    }
                    cont=0;
                    */
                }
            }
        }

        cout << "Image number " << round << " contains " << eagles << " war eagles." << endl;
        round++;
        eagles = 0;
    }
}
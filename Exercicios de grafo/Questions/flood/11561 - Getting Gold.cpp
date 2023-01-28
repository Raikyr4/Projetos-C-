#include <iostream>
#include <vector>
using namespace std;
char Ma[200][200];
int N, M, x, y, cont;
char Y = 'G';
void floodt(int i, int j)
{
    if (Ma[i][j] == Y)
    {
        cont++;
    }
    Ma[i][j] = '*';

    if (j - 1 >= 0 && Ma[i][j - 1] == Y || Ma[i][j - 1] == '.')
        floodt(i, j - 1);

    if (j + 1 < N && Ma[i][j + 1] == Y || Ma[i][j + 1] == '.')
        floodt(i, j + 1);

    if (i - 1 >= 0 && Ma[i - 1][j] == Y || Ma[i - 1][j] == '.')
        floodt(i - 1, j);

    if (i + 1 < M && Ma[i + 1][j] == Y || Ma[i + 1][j] == '.')
        floodt(i + 1, j);
}

int main()
{

    string S;
    while (cin >> N >> M && N && M)
    {
        cont = 0;
        for (int i = 0; i < M; i++)
        {
            cin >> S;
            for (int j = 0; j < N; j++)
            {
                Ma[i][j] = S[j];
                if (S[j] == 'P')
                {
                    x = i;
                    y = j;
                }
            }
        }
        floodt(x, y);
        cout << cont << endl;
    }
}
#include <iostream>
using namespace std;
int lin, col;
char M[101][101];
int alive;
void flood(int i, int j)
{
    if (i >= lin || j >= col || i < 0 || j < 0)
        return;
    if (M[i][j] == '.')
        return;
    M[i][j] = '.';
    flood(i + 1, j);
    flood(i - 1, j);
    flood(i, j + 1);
    flood(i, j - 1);
}
int main()
{
    alive = 0;
    int N;
    cin >> N;
    for (int h = 0, round = 1; h < N; h++, round++)
    {
        cin >> lin;
        col = lin;

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
                if (M[i][j] == 'x')
                {
                    flood(i, j);
                    alive++;
                }
            }
        }

        cout << "Case " << round << ": " << alive << endl;
        alive = 0;
    }
}
#include <iostream>
#include <vector>
using namespace std;
char M[200][200];
int lin, col,cont;
char Y;
void floodt(int i, int j)
{
    M[i][j] = '.';
    cont++;
    if (j - 1 >= '0' && M[i][j - 1] == Y)
        floodt(i, j - 1);

    if (j + 1 < col && M[i][j + 1] == Y)
        floodt(i, j + 1);

    if (i - 1 >= '0' && M[i - 1][j] == Y)
        floodt(i - 1, j);

    if (i + 1 < lin && M[i + 1][j] == Y)
        floodt(i + 1, j);

    if (i - 1 >= '0' && j - 1 >= '0' && M[i - 1][j - 1] == Y)
        floodt(i - 1, j - 1);

    if (i - 1 >= '0' && j + 1 < col && M[i - 1][j + 1] == Y)
        floodt(i - 1, j + 1);

  /*  if (i + 1 < lin && j + 1 < col && M[i + 1][j + 1] == Y)
        floodt(i + 1, j + 1);

    if (i + 1 < lin && j - 1 >= '0' && M[i + 1][j - 1] == Y)
        floodt(i + 1, j - 1);*/
}
 
int main()
{
    int N;
    string S;

    for(int K=0;K<N;K++)
    {
        for(int i=0 ; i<9; i++)
        {
            cin>>S;
            for(int j=0;j<9;j++)
            {
                M[i][j]=S[j];
            }
        }
    }
}
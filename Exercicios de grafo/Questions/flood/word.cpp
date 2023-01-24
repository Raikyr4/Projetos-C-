#include <iostream>
#include <map>
#include <vector>
using namespace std;
char M[500][500], aux;
int lin, col, cont;
void flood(int i, int j)
{
    cont++;
    M[i][j] = '.';

    if (j - 1 >= 0 && M[i][j - 1] == aux)
        flood(i, j - 1);

    if (j + 1 < col && M[i][j + 1] == aux)
        flood(i, j + 1);

    if (i - 1 >= 0 && M[i - 1][j] == aux)
        flood(i - 1, j);

    if (i + 1 < lin && M[i + 1][j] == aux)
        flood(i + 1, j);

    /* if (i - 1 >= 0 && j - 1 >= 0 && M[i - 1][j - 1] == aux)
         flood(i - 1, j - 1);

     if (i - 1 >= 0 && j + 1 < col && M[i - 1][j + 1] == aux)
         flood(i - 1, j + 1);

     if (i + 1 < lin && j + 1 < col && M[i + 1][j + 1] == aux)
         flood(i + 1, j + 1);

     if (i + 1 < lin && j - 1 >= 0 && M[i + 1][j - 1] == aux)
         flood(i + 1, j - 1);*/
}
int main()
{
    int N;
    cin >> N;
    
    vector<pair<char, int>> W;
    vector<pair<char, int>>::iterator it;
    for (int k = 0, round = 1; k < N; k++, round++)
    {
        cin >> lin >> col;
        string S;
        bool flag = true;
        for (int i = 0; i < lin; i++)
        {
            cin >> S;
            for (int j = 0; j < col; j++)
            {
                M[i][j] = S[j];

                for (int a = 0; a < W.size() && flag; a++)
                {
                    if (S[j] == W[a].first)
                    {
                        flag = false;
                    }
                }
                if (flag)
                {
                    W.push_back({S[j], 0});
                }
                flag=true;
                // W.insert({S[j],0});
            }
        }
        for (it = W.begin(); it != W.end(); it++)
        {
            aux = it->first;
            for (int i = 0; i < lin; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (M[i][j] == aux)
                    {
                        flood(i, j);
                        it->second++;
                    }
                }
            }
        }
        cout << "World #" << round << endl;
        for (it = W.begin(); it != W.end(); it++)
        {
            cout << (it)->first << ": " << it->second << endl;
        }
        W.clear();
    }
}
#include <iostream>
#include <map>
using namespace std;
char M[200][200],aux;
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
    int N;
    cin>>N;
    map<char,int> words;
    map<char,int> :: iterator it;
    for(int k=0,round=1;k<N;k++,round++)
    {
        cin>>lin>>col;
         string S;
         for(int i=0;i<lin;i++)
         {
            cin>>S;
            for(int j=0; j<col;j++)
            {
                M[i][j]=S[j];
                words.insert({S[j],0});
            }
         }
         for(it=words.begin();it!=words.end();it++)
         {
            aux=it->first;
            for(int i=0;i<lin;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(M[i][j]==aux)
                    {
                        flood(i,j);
                        if(cont>)
                    }
                }
            }
         }
         cout<<"World #"<<round<<endl;
         for(it =words.begin(); it!=words.end();it++)
         {
            cout<<(it)->first<<": "<<it->second<<endl;
         } 
    }
}
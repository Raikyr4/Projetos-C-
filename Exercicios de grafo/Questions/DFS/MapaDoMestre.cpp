#include <iostream>
#include <vector>
using namespace std;
int M,N;
char Mat[100][100];
void flood(int i, int j)
{

     Mat[i][j] = 'P';

    if (j - 1 >= 0 && Mat[i][j - 1] == '.' || Mat[i][j-1]=='<' || Mat[i][j-1]=='>' || Mat[i][j-1]=='^' || Mat[i][j-1]=='v')
        flood(i, j - 1);

    if (j + 1 < N && Mat[i][j + 1] == '.' || Mat[i][j+1]=='<' || Mat[i][j+1]=='>' || Mat[i][j+1]=='^' || Mat[i][j+1]=='v')
        flood(i, j + 1);

    if (i - 1 >= 0 && Mat[i - 1][j] == '.' || Mat[i-1][j]=='<' || Mat[i-1][j]=='>' || Mat[i-1][j]=='^' || Mat[i-1][j]=='v')
        flood(i - 1, j);

    if (i + 1 < M && Mat[i + 1][j] == '.' || Mat[i+1][j]=='<' || Mat[i+1][j]=='>' || Mat[i+1][j]=='^' || Mat[i+1][j]=='v')
        flood(i + 1, j);

   
}

int main()
{
    bool flag=false;
    cin>>M>>N;
    for(int i=0;i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>Mat[i][j];
            
        }
    } 
    flood(0,0);
    for(int i=0;i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
          if(Mat[i][j]=='*')
          {
            flag=true;
          }
        }
    }
  
    if(flag)
    {
        cout<<'*'<<endl;
    }
    else
    {
        cout<<'!'<<endl;
    }
}
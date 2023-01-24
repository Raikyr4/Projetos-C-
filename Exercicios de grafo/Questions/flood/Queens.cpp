#include <iostream>
using namespace std;
char M[8][8];
void imprime()
{
    for(int i=0; i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(M[i][j]==' ')
            {
                cout<<'0'<<" ";
            }
            else
            {
                cout<<M[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
bool IsValid(int L,int C)
{
    for(int i=L-1;i>=0;i--)
    {
        if(M[i][C]=='Q')
        return false;
    }
    for(int i=L-1,j=C-1;i>=0 && j>=0;i--,j--)
    {
        if(M[i][j]=='Q')
        return false;
    }
    for(int i=L-1,j=C+1;i>=0 && j<8;i--,j++)
    {
        if(M[i][j]=='Q')
        return false;
    }
    return true;
}
bool Queens(int i)
{
    if(i==8)
    {
        //imprime();
        return true;
    }
    for(int C=0;C<8;C++)
    {
        if(IsValid(i,C))
        {
            M[i][C]='Q';
             if(Queens(i+1))
             { 
                return true;
             }
            
        }
        M[i][C]=' ';
    }
    return false;
}
int main()
{
    for(int i=0; i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
          M[i][j]=' ';
        }
        cout<<endl;
    }
     Queens(0);
     imprime();
}
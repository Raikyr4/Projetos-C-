#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

map<string,vector<string>> adjlist;
vector<string> Vet;

bool compara(string a,string b)
{
    int cont=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<abs(b.size()-a.size());j++)
        {
            if(a[i]!=b[j])
            {
                cont++;
            }
        }
    }
    if(cont<=1)
        return true;

    return false;
}

int BFS(string a,string b)
{
    map<string,int>dist;
    dist[a]=0;
    queue<string> Q;
    Q.push(a);
    while (Q.size())
    {
        string U = Q.front();
        Q.pop();
        if(U==b)
        {
            return dist[U];
        }
        for(auto it : dist)
        {
            
            if(dist)
        }
    }
    
}

int main()
{
    int N;
    string A,B;
    cin>>N;

    while (N--)
    {
        while(cin>>A && A!="*")
        {
            Vet.push_back(A);
        }
        for(int i=0;i<Vet.size();i++)
    }
    while (cin>>A>>B)
    {
       
    }
    
    
}
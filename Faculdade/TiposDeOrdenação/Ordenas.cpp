#include <iostream>
using namespace std;
bool ordenas (pair<string,pair<int,pair<int,int>>>a,pair<string,pair<int,pair<int,int>>>b)
{
	if(a.second.first > b.second.first)
	{
		return true;
	}
	if(a.second.first==b.second.first && a.second.second.first > b.second.second.first)
	{
		return true;
	}
	if(a.second.first==b.second.first &&  a.second.second.first == b.second.second.first && a.second.second.second > b.second.second.second)
	{
		return true;
	}
	if(a.second.first==b.second.first &&  a.second.second.first == b.second.second.first && a.second.second.second == b.second.second.second && a.first < b.first)
	{
		return true;
	}
	return false;
}
int main()
{

}

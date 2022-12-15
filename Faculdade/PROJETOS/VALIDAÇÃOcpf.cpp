#include <iostream>
using namespace std;
 
int main()
{
	long long int cpf,cpfM1,cpfM2,CPF,z=10000000000;
    int v1=0,v2=0,y=2,i,valida;
	cout <<"DIGITE UM CPF SEM PONTOS E ESPACOS ou digite 0 para parar o programa: ";
    cin>>cpf;
	while(cpf!=0)
	{
			CPF=cpf;
		cpfM1=cpf/100;
		cpfM2=cpfM1;
		
		for(i=1;i<=9;i++)
		{
			v1+=(cpfM1%10)*y;
			cpfM1=cpfM1/10;
			y=y+1;
		}
		v1=v1%11;
		v1=11-v1;
		
		if(v1==10 || v1==11)
		{
			v1=0;
		}
		y=3;
		for(i=1;i<=9;i++)
		{
			v2+=(cpfM2%10)*y;
			cpfM2=cpfM2/10;
			y=y+1;
		}
		
		v2+=v1*2;
		
		v2=v2%11;
		v2=11-v2;
		
		if(v2==10 || v2==11)
		{
			v2=0;
		}
		
		
		
		valida=v1*10+v2;
		
		
		
		cout<<"o CPF ";
		for(i=1;i<=11;i++)
		{
			cout<<cpf/z;
			cpf=cpf%z;
			z=z/10;
			
			if(i==3||i==6)
			{
				cout<<'.';
			}
			if(i==9)
			{
				cout<<'-';
			}
		}
		
		if(valida == CPF%100)
		{
			cout<<" eh valido"<<endl;
		}
		else
		{
			cout<<" eh invalido"<<endl;
		}
		z=10000000000;
         v1=0,v2=0,y=2,valida=0;
		 cout <<"DIGITE UM CPF SEM PONTOS E ESPACOS ou digite 0 para parar o programa : ";
         cin>>cpf;
	}
    
	
}

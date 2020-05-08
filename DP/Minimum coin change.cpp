#include<iostream>
using namespace std;

int min(int a, int b)
{
	if(a > b)
		return b;
	
	else
		return a;
}

int main()
{
	int n, w;
	
	cout<<"Enter number of coins : ";
	cin>>n;
	cout<<"\nEnter the total amount : ";
	cin>>w;
	
	int c[n], v[n][w+1];
	
	for(int i = 0; i < n; i++)
	{
		cout<<"Amount "<<i<<" = ";
		cin>>c[i];
	}
	
	for(int i = 0; i < n; i++)
	{
		v[i][0] = 0;
	}
	
	for(int j = 1; j <= w; j++)
	{
		if(j % c[0] == 0)
			v[0][j] = j/c[0];
		else
			v[0][j] = 32767;
	}
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			if(c[i] > j)
				v[i][j] = v[i-1][j];
			else
				v[i][j] = min(v[i-1][j], 1 + v[i][j - c[i]]);
		}		
	}
	cout<<"The minimum number of coins : "<<v[n-1][w];
}

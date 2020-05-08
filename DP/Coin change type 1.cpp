#include<iostream>
using namespace std;

int main()
{
	int n, w;
	
	cout<<"Enter number of coins : ";
	cin>>n;
	cout<<"\nEnter the total amount : ";
	cin>>w;
	
	int c[n+1], v[n+1][w+1];
	
	c[0] = 0;
	cout<<"\nEnter the amounts : ";
	
	for(int i = 1; i <= n; i++)
	{
		cout<<"Amount "<<i<<" = ";
		cin>>c[i];
	}

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= w; j++)
		{	
			if(j == 0)
				v[i][j] = 1;
			
			else if(i == 0)
				v[i][j] = 0;
			
			else
			{	
				if(c[i] <= j)
				{
					v[i][j] = v[i-1][j] + v[i][(j - (c[i]))];					
					
				}
				
				else
				{
					v[i][j] = v[i-1][j];
					
				}
			}
		}
	}
	cout<<"\nTotal number of ways : "<<v[n][w];

	return 0;
}

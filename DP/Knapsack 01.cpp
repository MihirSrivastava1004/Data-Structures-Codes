#include<iostream>
using namespace std;

int maximum(int a, int b)
{
	int max;
	
	if(a > b)
		max = a;
	else
		max = b;
		
	return max;
}

int main()
{
	int n, m;
	
	cout<<"Enter the number of objects : ";
	cin>>n;
	
	int p[n+1], wt[n+1];
	
	p[0] = 0;
	wt[0] = 0;
	
	cout<<"\nEnter the capacity of the bag : ";
	cin>>m;
	
	cout<<"\nEnter the weight(W) and profit(P) of each object : ";
	
	for(int i = 1; i <= n; i++)
	{
		cout<<"\nW"<<i<<" = ";
		cin>>wt[i];
		cout<<"\tP"<<i<<" = ";
		cin>>p[i];
	}
	
	int k[n+1][m+1];
	
	
	for(int i = 0; i <= n; i++)
	{
		for(int w = 0; w <= m; w++)
		{
			if(i == 0 || w == 0)
				k[i][w] = 0;
			
			else if(wt[i] <= w)
				k[i][w] = maximum(p[i] + k[i-1][w - wt[i]], k[i-1][w]);
				
			else
				k[i][w] = k[i-1][w];
		}
	}
	cout<<k[n][m]<<endl;
	
	int i = n, j = m;
	
	while(i > 0 || j > 0)
	{
		if(k[i][j] == k[i-1][j])
		{
			cout<<i<<" = 0"<<endl;
			i--;
		}
		
		else
		{
			cout<<i<<" = 1"<<endl;
			j = j - wt[i];
			i--;
		}
	}
	
	return 0;
}

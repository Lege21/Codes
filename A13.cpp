#include<iostream>
using namespace std;

int main()
{
int n,temp;
int min=-1;

	cout<<"Enter how many products \n";
	cin>>n;
	
	int price[n];
	
	cout<<"Enter prices of product\n";
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	
	cout<<"\nEntered product prices are\n";
	for(int i=0;i<n;i++)
	{
		cout<<price[i]<<"\t";
	}
	cout<<endl;
	
	for(int i=0;i<n-1;i++)
	{
		int mIndex=i;
		
		for(int j=i+1;j<n;j++)
		{
			if(price[j]<price[mIndex])
			{
				mIndex=j;
			}
			
		}
		int temp=price[i];
		price[i]=price[mIndex];
		price[mIndex]=temp;
	}
	
	cout<<"\nProduct prices in Sorted order using selection sort are\n";
	for(int i=0;i<n;i++)
	{
		cout<<price[i]<<"\t";
	}
	cout<<endl;

}


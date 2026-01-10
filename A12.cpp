#include<iostream>
using namespace std;

int main()
{
	int n,temp;
	cout<<"Enter how many student \n";
	cin>>n;
	
	int marks[n];
	
	cout<<"Enter students Marks\n";
	for(int i=0;i<n;i++)
	{
		cin>>marks[i];
	}
	
	cout<<"Entered Students Marks are\n";
	for(int i=0;i<n;i++)
	{
		cout<<marks[i]<<"\t";
	}
	cout<<endl;
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(marks[j] > marks[j+1])
			{
				temp=marks[j];
				marks[j]=marks[j+1];
				marks[j+1]=temp;
			}
		}
	}
	
	cout<<"Students Marks in Sorting Order using Bubble Sort\n";
	for(int i=0;i<n;i++)
	{
		cout<<marks[i]<<"\t";
	}
	cout<<endl;
	
	return 0;
}

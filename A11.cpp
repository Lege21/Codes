#include<iostream>
using namespace std;

int main()
{
	int n,roll,low,high;
	cout<<"Enter how many students\n";
	cin>>n;
	
	int Uni[n];
	
	cout<<"Enter "<<n<<" Roll Numbers in assending order";
	for(int i=0;i<n;i++)
	{
		cin>>Uni[i];
	}
	
	cout<<"Enter Roll number to search\n";
	cin>>roll;
	
	low=0;
	high=n-1;
	bool found=false;
		while(low<=high)
		{
			int mid =(low+high)/2;
			if(Uni[mid]==roll)
			{
				found=true;
				break;
			}
			else if(roll<Uni[mid])
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		
	if(found)
		cout<<"Given Roll Number are Exist\n";
	else
		cout<<"Given Roll Number are Not Exist\n";
	

	return 0;
}

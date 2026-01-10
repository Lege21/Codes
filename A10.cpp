#include<iostream>
using namespace std;

int main()
{
	int n;
	string name;
	cout<<"Enter how many students: \t";
	cin>>n;
	
	string stud[n];
	cout<<"Enter "<<n<<" students names: \n";
	for(int i= 0;i<n;i++)
	{
		cin>>stud[i];
	}
	
	cout<<"Student list are:\n";
	for(int i= 0;i<n;i++)
	{
		cout<<stud[i]<<endl;
	}
	
	cout<<"Enter a name you want to search:\t";
	cin>>name;
	
	bool Found=false;
	for(int i=0;i<n;i++)
	{
		if(stud[i]==name){
			Found=true;
			break;
		}
	}
	
	if(Found)
		cout<<"Student is Registered\n";
		
	else
		cout<<"Student is not Registered\n";
	
	return 0;

}



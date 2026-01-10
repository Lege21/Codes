#include<iostream>
using namespace std;
class Student{
    string student[50],name;
    int i,n=0;
    public:
    void insert(){
        cout<<"Enter how many students: ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"\nEnter student name: ";
                cin>>student[i];
            }
    }
    void Delete(){
         if(n==0){
             cout<<"Array is empty"<<endl;
             return;
        }
        cout<<"Enter student name to delete: ";
        cin>>name;

        for (int i = 0; i < n; i++)
        {
            if (student[i] == name)
            {
                for (int j = i; j < n-1; j++)
                {
                    student[j]=student[j+1];
                }
            n--;
            cout<<"Student name deleted"<<endl;
            return;
            }
        }
        cout<<"Student not found."<<endl;
    }
    void Display(){
        cout<<"Students Names: ";
        for(int i=0;i<n;i++)
        {
            cout<<student[i]<<endl;
        }
    }
};
int main(){
    Student s;
    int choice;
    do{
        cout<<"Menu "<<endl;
        cout<<"1.Insert "<<endl;
        cout<<"2.Delete "<<endl;
        cout<<"3. Traverse "<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            s.insert();
        break;
        case 2:
            s.Delete();

        break;
        case 3:
            s.Display();
        break;
        case 4:cout<<"Exiting..."<<endl;
            exit(0);
        default:
            cout<<"Invalid Input,please try again!"<<endl;
            break;
        }
    }
    while (choice!=4);
    return 0;
    
}
#include<iostream>
using namespace std;
int arr[17]={0}; const int n=17;
void insert(int a)
{
	int i=a%n;
	while(arr[i]!=0) i++;
	arr[i]=a;
}
int main()
{
	int i,flag=0,n,target,pos;
	do
	{
		cout<<"\nEnter a term to be inserted : ";
		cin>>n;
		insert(n);
		cout<<"Do you want to insert again? (1-Yes/0-No) : ";
		cin>>flag;
	}while(flag==1);
	
	cout<<"\nArray : ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
	
	cout<<"\n\nEnter element to find : ";
	cin>>target;
	
	pos= target % 17;
	while(arr[pos]!=0)
	{
		if(arr[pos]==target) { cout<<"Element found at index "<<pos;  exit(1);  }
		pos++;
	}cout<<"Element not found!";
	return 0;
}

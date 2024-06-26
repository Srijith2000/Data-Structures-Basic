#include<iostream>
using namespace std;
int main()
{
	int a[20],i,target,n,pos=-1;
	cout<<"Enter number of terms : ";
	cin>>n;
	cout<<"Enter array terms : ";
	for(i=0; i<n; i++)  cin>>a[i];
	cout<<"\nEnter number to find : ";
	cin>>target;
	
	for(i=0; i<n; i++)  if(a[i]==target) pos=i;
	if(pos==-1) cout<<"\nElement not found";
	else cout<<"\nElement found at position "<<pos;
	return 0;
}

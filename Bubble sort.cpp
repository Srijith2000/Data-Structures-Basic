#include<iostream>
using namespace std;
int main()
{
	int a[10],i,j,n,t;
	cout<<"Enter number of terms : ";
	cin>>n;
	cout<<"\nEnter terms : ";
	for(i=0; i<n; i++)  cin>>a[i];
    for (i=0; i<n-1; i++)
    	for (j=0; j<n-i-1; j++) 
        	if (a[j] > a[j+1]) 
        	{
        		t=a[j];  a[j]=a[j+1];  a[j+1]=t;
        	}
    cout<<"\nSorted Array : ";
    for(i=0; i<n; i++)  cout<<a[i]<<" ";
	return 0;
}

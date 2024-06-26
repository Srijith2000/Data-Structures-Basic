#include<iostream>
using namespace std;
int main()
{
	int a[10],i,j,n,last;
	cout<<"Enter number of terms : ";
	cin>>n;
	cout<<"\nEnter terms : ";
	for(i=0; i<n; i++)  cin>>a[i];
    for(i=1; i<n; i++) 
	{
		last=a[i];
		for(j=i; j>0 && last<a[j-1]; j--)
			a[j]=a[j-1];
		a[j]=last;	
    }
    cout<<"\nSorted Array : ";
    for(i=0; i<n; i++)  cout<<a[i]<<" ";
	return 0;
}

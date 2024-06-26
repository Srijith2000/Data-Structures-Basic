#include<iostream>
using namespace std;
int main()
{
	int a[20],i,j,target,n;
	int fpos,lpos,count;
	int first,mid,last;
	cout<<"Enter number of terms : ";
	cin>>n;
	cout<<"Enter sorted array elements : ";
	for(i=0; i<n; i++)  cin>>a[i];
	cout<<"Enter number to find : ";
	cin>>target;
	
	first=0; last=n-1; mid=(first+last)/2;
	while (first<=last)
	{
		if (a[mid]<target)	first=mid+1;
		else if (a[mid]==target)
		{
			cout<<"\nElement found at index "<<mid;
			break;
		}
		else	last=mid-1;
		mid=(first+last)/2;
	}
	if(first>last) { cout<<"\nElement not found"; exit(1); }
	lpos=fpos=mid;
	i=mid+1; j=mid-1;
	while(a[i]==target || a[j]==target)
	{
		if(a[i]==target) { lpos=i; i++;	}
		if(a[j]==target) { fpos=j; j--;	}
	}
	count=lpos-fpos+1;
	cout<<"\n\nFirst occurrence position = "<<fpos<<"\nLast occurrence position = "<<lpos;
	cout<<"\nOccurrence count = "<<count;
	return 0;
}

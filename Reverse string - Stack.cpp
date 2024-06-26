#include<iostream>
#include<cstring>
using namespace std;
char stack[25]; int top=-1;
void push(char ch)
{
	top++;
	stack[top]=ch;
}
char pop()
{
	return stack[top--];
}
int main()
{
	int i,n;
	char str[25];
	cout<<"Enter a word : ";
	cin>>str;
	n=strlen(str);
	for(i=0; i<n; i++)  push(str[i]);
	stack[top+1]='\0';
	for(i=0; i<n; i++)  str[i]=pop();
	str[i]='\0';
	cout<<"\nReversed String : "<<str;
	return 0;
}

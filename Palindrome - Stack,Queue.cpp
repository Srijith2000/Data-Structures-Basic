#include<iostream>
#include<cstring>
using namespace std;
char stack[25]; int top=-1;
char queue[25]; int F=-1,L=-1;
void push(char ch)
{
	if(top==24) cout<<"Stack Overflow ";
	stack[++top]=ch;
}
char pop()
{
	return stack[top--];
}
void enqueue(char ch)
{
	if(F==-1 && L==-1) { F=L=0; queue[F]=ch; }
	else if(L==24) cout<<"Queue is full ";
	else queue[++L]=ch;
}
char dequeue()
{
	if(F==-1) cout<<"Queue is Empty ";
	return queue[F++];
}
int main()
{
	char str[25],ch;
	int i,n,flag=1;
	cout<<"Enter a word : ";
	cin>>str;
	n=strlen(str);
	for(i=0; i<n; i++)
	{
		enqueue(str[i]); push(str[i]);
	}
	for(i=0; i<n; i++)
	{
		if(dequeue()!=pop()) { cout<<endl<<str<<" is not a palindrome "; flag=0; break; }
	}
	if(flag==1) cout<<endl<<str<<" is a palindrome ";
	return 0;
}

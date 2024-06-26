#include<iostream>
#include<cstring>
using namespace std;
char stack[25]; int top=-1;
void push(char ch)
{
	stack[++top]=ch;
}
char pop()
{
	return stack[top--];
}
int main()
{
	int i,n;
	char str[25];
	cout<<"Enter Expression of brackets : ";
	cin>>str;
	n=strlen(str);
	for(i=0; i<n; i++)
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[') push(str[i]);
		else if( (str[i]==')' && stack[top]=='(')||(str[i]=='}' && stack[top]=='{')||(str[i]==']' && stack[top]=='[') )
			cout<<"Popped '"<<pop()<<"'\n";
	}
	if(top==-1) cout<<"\nIt is a Balanced Expression";
	else cout<<"\nIt is not a Balanced Expression";
	cout<<endl<<"Items remaining in stack : "<<top+1;
	return 0;
}

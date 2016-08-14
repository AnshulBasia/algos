#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s;
	string x;
	cin>>s;
	cout<<" what to search for ?"<<endl;
	cin>>x;
	int lps[x.length()];   //Longest proper suffix

	lps[0]=0;
	int len=0;
	int i=1;
	while(i<x.length())
	{
		if(x[i]==x[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;

			}
			
		}
	}
	i=0;
	int j=0;
	while(i<s.length())
	{
		if(s[i]==x[j])
		{
			i++;
			j++;
		}

		if(j==x.length()){cout<<"found at index "<<i-j;  j=lps[j-1];}
		else if(i<s.length()&&s[i]!=x[j])
		{
			if(j!=0)
			{
				j=lps[j-1];

			}
			else
			{
				i++;
			}
		}
	}
	
}
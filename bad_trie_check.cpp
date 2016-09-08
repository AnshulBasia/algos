#include <bits/stdc++.h>
using namespace std;

struct node
{
	struct node * parent;
	struct node* children[11];
	vector<int> occurrences;
	char ch;
	int no;
	bool terminated;
};

void InsertWord(struct node *trieTree,char *word,int index)
{
	struct node *traverse=trieTree;
	

	while(*word!='\0')
	{
		if(traverse->children[(int)*word-97]==NULL)
		{
			traverse->children[(int)*word-97]=(struct node*)calloc(1,sizeof(struct node));
			traverse->children[(int)*word-97]->no=0;
			traverse->children[(int)*word-97]->terminated=false;
			traverse->children[(int)*word-97]->parent=traverse;
			traverse->children[(int)*word-97]->ch=*word;
		}

		
		traverse->no++;
		
		//cout<<traverse->no<<" "<<traverse->ch<<endl;
		traverse=traverse->children[(int)*word-97];
		++word;
		//cout<<"inserting "<<traverse->terminated<<" "<<traverse->ch<<endl;
	}
	traverse->no++;	
	
	traverse->occurrences.push_back(index);
	traverse->terminated=true;
	//cout<<"inserting "<<traverse->terminated<<" "<<traverse->ch<<endl;
	
}


int SearchWord(struct node* trieTree,char* word)
{
	int v;
	
	
	struct node* traverse=trieTree;
	while(*word!='\0')
	{
		v=(int)*word-97;
		
		if(traverse->children[v]==NULL)
		{
			//cout<<"Not found"<<endl;
			return 0;
		}
		else
		{
			traverse=traverse->children[(int)*word-97];
			++word;
		}
	}
	

   
    return traverse->no;
}

bool check_if_bad(struct node* tree,char *word)
{
	struct node* traverse=tree;
	while(*word!='\0')
	{
		traverse=traverse->children[(int)*word-97];
		++word;
		//cout<<"no "<<traverse->no<<" "<<traverse->terminated<<" "<<traverse->ch<<endl;
	
		if(traverse->no>1&&traverse->terminated==true)
		{
			return true;
		}
	}
	//
	return false;
}
int main()
{
	int t;
	cin>>t;
	string ans;
	int flag=0;
	node *tree=(struct node*)calloc(1,sizeof(struct node));

	while(t--)
	{	
		string s;
		cin>>s;
		char a[65];
		int i;
		
		for(i=0;i<s.length();i++)
		{
			
				a[i]=s[i];
				
			
		}
		a[i]='\0';
		InsertWord(tree,a,t);
		if(check_if_bad(tree,a)==1&&flag==0)
		{
			ans=a;
			flag=1;
		}
	}

	if(flag==0){cout<<"GOOD SET"<<endl;}
	else
	{
		cout<<"BAD SET"<<endl;
		cout<<ans<<endl;
	}

	

	
}
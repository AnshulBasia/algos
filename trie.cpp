#include <bits/stdc++.h>
using namespace std;

struct node
{
	struct node * parent;
	struct node* children[25];
	vector<int> occurrences;
	char ch;
	int no;
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
			traverse->children[(int)*word-97]->parent=traverse;
			traverse->children[(int)*word-97]->ch=*word;
		}

		
		traverse->no++;
		//cout<<traverse->no<<" "<<traverse->ch<<endl;
		traverse=traverse->children[(int)*word-97];
		++word;
	}
	traverse->no++;	
	cout<<traverse->no<<" "<<traverse->ch<<endl;
	traverse->occurrences.push_back(index);
	
	
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
			cout<<"Not found"<<endl;
			return 0;
		}
		else
		{
			traverse=traverse->children[(int)*word-97];
			++word;
		}
	}
	

    cout<<traverse->ch<<endl;
    return traverse->no;
}

int main()
{
	int t;
	cin>>t;
	
	node *tree=(struct node*)calloc(1,sizeof(struct node));

	while(t--)
	{	
		string s,task;
		cin>>task;
		cin>>s;
		char a[25];
		int i;
		
		for(i=0;i<s.length();i++)
		{
			
				a[i]=s[i];
				
			
		}
		a[i]='\0';
		
		if(task[0]=='a')  //add a word
		{
			
			
			InsertWord(tree,a,t);
			cout<<"INSERTED"<<endl;
		}
		
		if(task[0]=='f')
		{
			cout<<"FINDING "<<a<<" "<<endl;

			cout<<SearchWord(tree,a)<<endl;
		}
	}
	
}
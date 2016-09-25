#include <bits/stdc++.h>
using namespace std;
#include <stdexcept> // out_of_range exception

int main()
{
	int n;
	int mask;
	int heights[100];
	vector<int> p;
	int index,maxx;
	while(1>0)
	{
		cin>>n;
		if(n==0){break;}
		mask=0;
		for(int i=0;i<n;i++)
		{
			cin>>heights[i];
		}
		p.push_back(heights[0]);
		int j=1;
		while(p.size()<n)
		{
			maxx=0;
			index=0;
			for(int i=0;i<p.size()+1;i++)
			{	
				if(i==0)
				{
					if(maxx<heights[j]+abs(heights[j]-p[i])-p[0])
					{
						maxx=heights[j]+abs(heights[j]-p[i]);
						index=i;
					}
				
				}
				if(i==p.size())
				{
					if(maxx<heights[j]+abs(heights[j]-p[i-1]))
					{
						maxx=heights[j]+abs(heights[j]-p[i-1]);
						index=i;
					}
				
				}

				if(i!=0&&i!=p.size())
				{	if(maxx<abs(heights[j]-p[i-1])+abs(heights[j]-p[i])-p[i-1])
					{
						maxx=abs(heights[j]-p[i-1])+abs(heights[j]-p[i]);
						index=i;
					}
				}	
			}
			int count=0;
			for(int i=0;i<p.size()+1;i++)
			{	
				if(i==0)
				{
					if(maxx==heights[j]+abs(heights[j]-p[i])-p[0])
					{
						count++;
					}
				
				}
				if(i==p.size())
				{
					if(maxx==heights[j]+abs(heights[j]-p[i-1]))
					{
						count++;
					}
				
				}

				if(i!=0&&i!=p.size())
				{	if(maxx==abs(heights[j]-p[i-1])+abs(heights[j]-p[i])-p[i-1])
					{
						count++;
					}
				}	
			}
			cout<<"count"<<count<<endl;
			//cout<<index<<" "<<heights[j]<<endl;
			//cout<<maxx<<endl;
			p.insert(p.begin()+index,heights[j]);
			/*
			vector<int> temp;
			for(int i=0;i<index;i++){temp.push_back(p[i]);}
			temp.push_back(heights[j]);
			for(int i=index;i<p.size();i++){temp.push_back(p[i]);}

			p=temp;
			temp.clear();
			*/
			j++;
		}
		for(int i=0;i<p.size();i++){cout<<p[i]<<" ";}
			cout<<endl;
		p.clear();
	}
}
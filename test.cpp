#include <iostream>
using namespace std;
#include <map>
#include <vector>

int main() {
	// your code goes here
	map<int,vector<int> > g;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	g[1]=v;
	g[1].push_back(3);
	cout<<g[1][2];

	map<int,vector<int> >::iterator it = g.begin();

	for(;it!=g.end();++it)
	{
		cout<< it->first << " " << it->second[0];
	}
	return 0;
}

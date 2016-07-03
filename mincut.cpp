#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<fstream>
#include <stdlib.h>
#include <time.h>
int main()
{           srand (time(NULL));

    ifstream file("mincut.in");
    string str;

    int a;
    vector<vector<int> > graph;
    vector<int> temp;
    int ans=17;
    while(getline(file,str,'\n'))
    {   a=0;

    if(str.length()==0){continue;}
        //cout<<str<<endl;
        for(int i=0;i<str.length();i++)
        {


            if(str[i]==' '||i==str.length())
            {

                temp.push_back(a);

                a=0;
            }
            else
            {
               a=(10*a)+(static_cast<int>(str[i])-48);
            }
        }

        graph.push_back(temp);

        temp.clear();

    }

    //cout<<graph.size()<<endl;




    vector< vector<int> >tempp;
    vector<int> mincut;
    tempp=graph;
    for(int t=0;t<500;t++){
    while(graph.size()!=2)
    {

        int x=rand()%graph.size();
        int y=rand()%(graph[x].size()-1);
        int j;
        y++;
        //cout<<"Node-"<<graph[x][0]<<" edge-"<<graph[x][y]<<endl;
        int node=graph[x][0];
        int edge=graph[x][y];
        for( j=0;j<graph.size();j++)
        {

            if(graph[j][0]==graph[x][y])
            {
                break;
            }
        }
       // cout<<endl<<j<<endl;
        for(int i=1;i<graph[j].size();i++)
        {
            if(graph[j][i]!=graph[x][0])
            {
                graph[x].push_back(graph[j][i]);
            }
        }

       // graph[x].erase(graph[x].begin()+y);


        //cout<<edge<<" "<<node<<endl;

        for(int m=0;m<graph.size();m++)
        {
            for(int n=0;n<graph[m].size();n++)
            {
                if(graph[m][n]==edge)
                {
                    graph[m][n]=node;
                }
            }
        }
        for(int m=1;m<graph[x].size();m++)
        {
            if(graph[x][m]==graph[x][0])
            {
                graph[x].erase(graph[x].begin()+m);
                m--;
            }
        }

        //cout<<endl;
        graph.erase(graph.begin()+j);//Delete graph[j]



    }


    cout<<graph[0].size()-1<<endl;
    if(graph[0].size()-1<ans){ans=graph[0].size()-1;}
    mincut.push_back(graph[0].size()-1);
    graph.clear();
    temp.clear();
    graph=tempp;
    }
    cout<<"       "<<ans;

}

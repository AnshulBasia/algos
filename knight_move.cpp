#include <bits/stdc++.h>
using namespace std;

bool moved[8][8];
int moves;

void move(int x, int y){

	moved[x][y]=true;
	//cout<<x<<" "<<y<<endl;
	moves++;

	if((!moved[x+1][y+2])&&(x+1<8)&&(y+2<8)){
		move(x+1,y+2);
		return;
	}
	if((!moved[x-1][y+2])&&(x-1>=0)&&(y+2<8)){
		move(x-1,y+2);
		return;
	}
	if((!moved[x-1][y-2])&&(x-1>=0)&&(y-2>=0)){
		move(x-1,y-2);
		return;
	}
	if((!moved[x+1][y-2])&&(x+1<8)&&(y-2>=0)){
		move(x+1,y-2);
		return;
	}
	if((!moved[x+2][y+1])&&(x+2<8)&&(y+1<8)){
		move(x+2,y+1);
		return;
	}
	if((!moved[x+2][y-1])&&(x+2<8)&&(y-1>=0)){
		move(x+2,y-1);
		return;
	}
	if((!moved[x-2][y+1])&&(x-2>=0)&&(y+1<8)){
		move(x-2,y+1);
		return;
	}
	if((!moved[x-2][y-1])&&(x-2>=0)&&(y-1>=0)){
		move(x-2,y-1);
		return;
	}
	cout<<"nowhere to go"<<x<<" "<<y<<endl;
	
}

int main(){
	
	memset(moved,false,sizeof(moved));
	
	moves=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			move(i,j);
			memset(moved,false,sizeof(moved));
			cout<<"for "<<i<<" , "<<j<<" "<<moves<<endl;
			moves=0;
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

class minHeap
{
	 int size;
	 int* array;
	 int position;
	public:
		minHeap(int size);
		void createHeap(int *ar,int size);
		void bubbleUp();
		void insert(int x);
		void display();
		int extractMin();
		void sinkDown(int k);

};


minHeap::minHeap(int size)
	{
		this->size=size;
		position=0;
		array=new int[size+1];
	}

void minHeap::createHeap(int *arr,int size)
	{
		if(size>0)
		{
			for(int i=0;i<size;i++)
			{
				insert(arr[i]);
			}
		}
	}

void minHeap::insert(int x)
{
	array[position++]=x;
	if(position!=0)
	{
		bubbleUp();
	}
}

void minHeap::bubbleUp()
{
	int pos=position-1;
	while(pos>0&&array[pos/2]>array[pos])
	{
		int y=array[pos];
		array[pos]=array[pos/2];
		array[pos/2]=y;
		pos/=2;
	}
}

void minHeap::display()
{
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int minHeap::extractMin()
{
	if(position==0)
	{
		cout<<"heap is already empty"<<endl;
		return -1;
	}
	int min=array[0];
	array[0]=array[position-1];
	sinkDown(0);
	return min;
}

void minHeap::sinkDown(int k)
{
	
	int a=array[k];
	int smallest=k;
	

	if(k==0)
	{
		array[0]=array[1];
		array[1]=a;
		sinkDown(1);
	}
	else
	{
		if(2*k<position-1)
		{
			array[k]=array[2*k];
			array[2*k]=a;
			sinkDown(2*k);
		}
		else
		{
			bubbleUp();
			position--;
		}
	}
	
}

int main()
{
	int arrA [] = {3,2,1,7,8,4,10,16,12};
	minHeap h(9);
	h.createHeap(arrA,9);
	h.display();
	int x=h.extractMin();
	h.display();
	h.sinkDown(1);
	h.display();

}




#include <iostream>
using namespace std;

int size=10000;
int quicksort(int a[],int low,int high)
{
    if(low<0||high<0){return 0;}
    if(low==high||low>high){return 0;}
     int temp;
     int mid=(high+low)/2;
     
     if(a[low]>a[mid]&&a[low]>a[high])
     {
         if(a[high]>a[mid])
         {
             temp=a[low];
             a[low]=a[high];
             a[high]=temp;
         }
         else
         {
             temp=a[low];
             a[low]=a[mid];
             a[mid]=temp;
         }
     }
     if(a[low]<a[mid]&&a[low]<a[high])
     {
         if(a[high]>a[mid])
         {
             temp=a[low];
             a[low]=a[mid];
             a[mid]=temp;
         }
         else
         {
             temp=a[low];
             a[low]=a[high];
             a[high]=temp;
         }
     }
    
     
     
     
    
    int p=a[low];
    int j=low+1;
   
    
    
    for(int i=low+1;i<=high;i++)
    {
        if(a[i]<p)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            j++;
        }
    }
    temp=a[low];
    a[low]=a[j-1];
    a[j-1]=temp;
    j--;
    //for(int i=0;i<size;i++)
    //{cout<<a[i]<<" ";}
    //cout<<endl;
    //cout<<ans<<endl;
    if(j<high)
    {return high-low+quicksort(a,low,j-1)+quicksort(a,j+1,high);}
    else
    {return high-low+quicksort(a,low,j-1);}
}

int main() {
	// your code goes here
	int a[size];
	for(int i=0;i<size;i++)
	{
	    cin>>a[i];
	}
	//int ans=0;
	cout<<quicksort(a,0,size-1);
	
	return 0;
}

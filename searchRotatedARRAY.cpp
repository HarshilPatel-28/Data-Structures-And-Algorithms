#include<iostream>
using namespace std;
int pivot(int arr[],int len){
int start = 0;
int end=len-1;
int mid = start+(end-start)/2;
while (start<end)
{
    if(arr[mid]>=arr[0]){
        start=mid+1;
    }
    else{
        end=mid;
    }
    mid = start+(end-start)/2;
}

return start;
}
int binarySearch(int arr[],int s,int e,int key){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){return mid;}
        else if (arr[mid]>key)
        {
            e = mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }

}
int findPosition(int arr[],int len,int key){
    int pivots=pivot(arr,len);
    if(key>=arr[pivots]&&key<=arr[len-1]){
        return binarySearch(arr,pivots,len-1,key);
    }
    else{
        return binarySearch(arr,0,pivots-1,key);
    }
}
int main()
{
   int a[5]={10,20,1,2,3};
   cout<<"Position is "<<findPosition(a,5,2);
    
    return 0;
}

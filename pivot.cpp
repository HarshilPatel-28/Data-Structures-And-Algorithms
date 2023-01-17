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
int main()
{
    int a[4]={10,20,1,4};
    cout<<"Pivot is at index :"<<pivot(a,4);
    
    return 0;
}

//Selection Sort
#include <iostream>
#include <vector>
using namespace std;
vector <int> selectionSort(vector <int> arr,int n){
   for(int i=0;i<n;i++){
       int minIndex=i;
       for(int j=i+1;j<n;j++){
           if(arr[j]<arr[minIndex]){
               minIndex=j;
           }
       }
       swap(arr[i],arr[minIndex]);
   }
   return arr;
}
int main() {
    vector <int> arr={10,80,20,15,30};
    vector <int> v;
    v=selectionSort(arr,5);

  for(int i=0;i<5;i++){
      cout<<v[i]<<" ";
  }
   
  return 0;
}

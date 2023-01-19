//Bubble Sort
#include <iostream>
#include <vector>
using namespace std;
void bubblesort(int arr[],int a){
    bool swapped=false;
    for(int i=1;i<a;i++){
        for (int j=0;j<a-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped == false) {
           
            break; }
    }
}

void input (int arr[],int a){
    int i=0;
  for(int i=0;i<a;i++){
        cout<<"Enter Element "<<i<<" : ";
        cin>>arr[i];
     } 
 }


void print (int arr[],int a){
    cout<<"Array:";
   for(int i=0;i<a;i++){
        cout<<arr[i]<<" ";
     
    }
    cout<<endl;
}
int main() {
    int a;
    
  cout<<"Enter the size of ARRAY: ";
  cin>>a;
  int arr[a];
  input(arr,a);
  print(arr,a);
  bubblesort(arr,a);
  print(arr,a);
 
 

    return 0;
}

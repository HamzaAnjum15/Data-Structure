#include <iostream>
using namespace std;
void LinearSearch(int a[],int n){
   int temp=-1;
   for(int i=0;i<5;i++){
    if(a[i]==n){
        cout<<"element found at position "<<i<<endl;
        temp=0;
    }
   }
   if(temp==-1){
    cout<<"element not found"<<endl;
   }
    

}


int main(){
    int Arr[5];
    cout<<"enter five numbers"<<endl;
    for(int i=0;i<5;i++){
        cin>>Arr[i];
    }
    int num;
    cout<<"enter an element to search"<<endl;
    cin>>num;
    LinearSearch(Arr,num);
    return 0;
}
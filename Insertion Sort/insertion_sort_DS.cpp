#include <iostream>
using namespace std;
int InsertionSort(int Arr[]){
    int j=0;
    int key;
    for(int i=1;i<5;i++){
        key=Arr[i];
        j=i-1;
        while (j>=0 && Arr[j]>key)
        {
            Arr[j+1]=Arr[j];
            j=j-1;
        }
        Arr[j+1]=key;
        
    }
}
int main(){
    int MyArr[5];
    cout<<"enter five numbers in any order"<<endl;
    for(int i=0;i<5;i++){
        cin>>MyArr[i];
    }
    cout<<"before sorting "<<endl;
    for(int i=0;i<5;i++){
        cout<<MyArr[i]<<" ";
    }
    InsertionSort(MyArr);
    cout<<endl<<"After sorting "<<endl;
    for(int i=0;i<5;i++){
        cout<<MyArr[i]<<" ";
    }
    return 0;
}
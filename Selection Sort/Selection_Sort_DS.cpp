#include <iostream>
using namespace std;
void SelectionSort(int Arr[])
{
    for (int i = 0; i < 4; i++)
    {
        int min = i;
        for (int j = i+1; j < 5; j++)
        {
            if (Arr[j] < Arr[min])
            {
                min = j;
            }
        }
        if(min!=i){
            int temp=Arr[min];
            Arr[min]=Arr[i];
            Arr[i]=temp;
        }
    }
}
int main()
{
    int MyArr[5];
    cout << "enter random array numbers" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> MyArr[i];
    }
    cout << "unsorted array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << MyArr[i] << " ";
    }
    cout << endl;
    
    SelectionSort(MyArr);
     cout << "sorted array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << MyArr[i] << " ";
    }

    return 0;
}
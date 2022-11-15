#include <iostream>
using namespace std;
void BubbleSort(int Arr[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                int temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
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

    BubbleSort(MyArr);
    cout << "sorted array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << MyArr[i] << " ";
    }

    return 0;
}
#include <iostream>
using namespace std;
int BinarySearch(int a[], int _left, int _right, int x)
{
    while (_left <= _right)
    {

        int mid = _left + (_right - _left) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            _left = mid + 1;
        }
        else
        {
            _right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[10];
    int num;
    int output;
    cout << "enter 10 integers" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "enter number to search in the array" << endl;
    cin >> num;
    output = BinarySearch(arr, 0, 9, num);
    if (output == -1)
    {
        cout << "element not found" << endl;
    }
    else
    {
        cout << "matching element found at position " << output << endl;
    }

    return 0;
}

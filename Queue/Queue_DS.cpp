#include <iostream>
// #include <string>
using namespace std;
class Queue
{
private:
    int Rear;
    int Front;
    int Arr[5];

public:
    Queue()
    {
        Rear = -1;
        Front = -1;
        for (int i = 0; i < 5; i++)
        {
            Arr[i] = 0;
        }
    }
    bool IsEmpty()
    {
        if (Rear == -1 && Front == -1)
        
            return true;
        
        else
        
            return false;
        
    }
    bool IsFull()
    {
        if (Rear == 4)
        
            return true;
        
        else
        
            return false;
        
    }
    void Enqueue(int _value)
    {
        if (IsFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (IsEmpty())
        {
            Rear = 0;
            Front = 0;
            Arr[Rear] = _value;
        }
        else
        {
            Rear++;
            Arr[Rear] = _value;
        }
    }
    
    int Dequeue()
    {
        int x;
        if (IsEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else if (Rear == Front)
        {
            x = Arr[Front];
            Arr[Front] = 0;
            Rear = -1;
            Front = -1;
            return x;
        }
        else
        {
            x = Arr[Front];
            Arr[Front] = 0;
            Front++;
            return x;
        }
    }
    int Count()
    {
        return (Rear - Front + 1);
    }
    int Display()
    {
        cout<<"Values in queue are "<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout << Arr[i] << "  ";
        }
    }
};
int main()
{
    Queue Q1;
    int Option, Value;
    do
    {
        cout << "What operation do you want to perform? Selet option no., Press 0 to exit" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. IsEmpty" << endl;
        cout << "4. IsFull" << endl;
        cout << "5. Count" << endl;
        cout << "6. Display" << endl;
        cout << "7. Clear Screen" << endl<< endl;
        cin >> Option;

        switch (Option)
        {
        case 1:
            cout << "enter a number to enqueue" << endl;
            cin >> Value;
            Q1.Enqueue(Value);
            break;
        case 2:
            cout << "Dequeue function is called" << Q1.Dequeue() << endl;
            break;
        case 3:
            if (Q1.IsEmpty())
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue is not Empty" << endl;
            }
            break;
        case 4:
            if (Q1.IsFull())
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                cout << "Queue is not full" << endl;
            }
            break;
        case 5:
            cout << "Count function is called" << Q1.Count() << endl;
            break;
        case 6:
            cout << "Display is function is called " << Q1.Display() << endl;
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter proper option" << endl;
            break;
        }
    } while (Option != 0);
    {
        return 0;
    }
}

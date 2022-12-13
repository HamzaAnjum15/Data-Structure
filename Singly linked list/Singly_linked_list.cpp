#include <iostream>
using namespace std;
class Node
{
public:
    int Key;
    int Data;
    Node *Next;
    Node()
    {
        Key = 0;
        Data = 0;
        Next = NULL;
    }
    Node(int _k, int _d)
    {
        Key = _k;
        Data = _d;
    }
};
class SinglyLinkedList
{
public:
    Node *Head;
    SinglyLinkedList()
    {
        Head = NULL;
    }
    SinglyLinkedList(Node *_n)
    {
        Head = _n;
    }
    // checks if node exists
    Node *NodeExists(int _k)
    {
        Node *Temp = NULL;
        Node *Ptr = Head;
        while (Ptr != NULL)
        {
            if (Ptr->Key == _k)
            {
                Temp = Ptr;
            }
            Ptr = Ptr->Next;
        }
        return Temp;
    }
    // Appending a new node
    void AppendNode(Node *_n)
    {
        if (NodeExists(_n->Key) != NULL)
        {
            cout << "Node already exist. Try a new node" << endl;
        }
        else
        {
            if (Head == NULL)
            {
                Head = _n;
                cout << "Node appended" << endl;
            }
            else
            {
                Node *Ptr = Head;
                while (Ptr->Next != NULL)
                {
                    Ptr = Ptr->Next;
                }
                Ptr->Next = _n;
                cout << "Node appended" << endl;
            }
        }
    }
    // Prepending a node
    void PrependNode(Node *_n)
    {
        if (NodeExists(_n->Key) != NULL)
        {
            cout << "Node Already Exist. Try new node" << endl;
        }
        else
        {
            _n->Next = Head;
            Head = _n;
            cout << "node prepended" << endl;
        }
    }
    // Inserting a node at a specific position
    void InsertNode(int _k, Node *_n)
    {
        Node *Ptr = NodeExists(_k);
        if (Ptr == NULL)
        {
            cout << "Node doesnt exist" << endl;
        }
        else
        {
            if (NodeExists(_n->Key) != NULL)
            {
                cout << "Node already exist with key value:" << _n->Key << "Try a new node" << endl;
            }
            else
            {
                _n->Next = Ptr->Next;
                Ptr->Next = _n;
                cout << "Node Inserted" << endl;
            }
        }
    }
    // Deleting a node at a specific position
    void DeleteNode(int _k)
    {
        if (Head == NULL)
        {
            cout << "Singly linked List is empty, cant delete any thing" << endl;
        }
        else if (Head != NULL)
        {
            if (Head->Key == _k)
            {
                Head = Head->Next;
                cout << "Node unlinked" << endl;
            }
            else
            {
                Node *Temp = NULL;
                Node *PrevPtr = Head;
                Node *CurrPtr = Head->Next;
                while (CurrPtr != NULL)
                {
                    if (CurrPtr->Key == _k)
                    {
                        Temp = CurrPtr;
                        CurrPtr = NULL;
                    }
                    else
                    {
                        PrevPtr = PrevPtr->Next;
                        CurrPtr = CurrPtr->Next;
                    }
                }
                if (Temp != NULL)
                {
                    PrevPtr->Next = Temp->Next;
                    cout << "Node unlinked of key " << _k << endl;
                }
                else
                {
                    cout << "Node doesnt exist" << endl;
                }
            }
        }
    }
    // Updating the node
    void UpdateNodeByKey(int _k, int _d)
    {
        if (Head == NULL)
        {
            cout << "Singly linked list is empty" << endl;
        }
        else
        {
            Node *Ptr = NodeExists(_k);
            if (Ptr != NULL)
            {
                Ptr->Data = _d;
                cout << "Node data updated" << endl;
            }
            else
            {
                cout << "Node doesnt exist" << endl;
            }
        }
    }
    // printing the Nodes
    void PrintList()
    {
        if (Head == NULL)
        {
            cout << "Singly linked list is empty" << endl;
        }
        else
        {
            Node *Temp = Head;
            cout << "Items of singly linked list are: " << endl;
            while (Temp != NULL)
            {
                cout << "(" << Temp->Key << "," << Temp->Data << ") -->";
                Temp = Temp->Next;
            }
        }
        cout << endl;
    }
};
int main()
{
    SinglyLinkedList S;
    int Option;
    int Key1, K1, Data1;
    do
    {
        cout << "What operation do you want to perform? Selet option no., Press 0 to exit" << endl;
        cout << "1. Append" << endl;
        cout << "2. Prepend" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Update" << endl;
        cout << "6. Print" << endl;
        cout << "7. Clear Screen" << endl
             << endl;
        cin >> Option;
        Node *N1 = new Node();

        switch (Option)
        {
        case 1:
            cout << "enter a node key and data to be appended" << endl;
            cin >> Key1;
            cin >> Data1;
            N1->Key = Key1;
            N1->Data = Data1;
            S.AppendNode(N1);
            break;
        case 2:
            cout << "enter a node key and data to be prepended" << endl;
            cin >> Key1;
            cin >> Data1;
            N1->Key = Key1;
            N1->Data = Data1;
            S.PrependNode(N1);
            break;
        case 3:
            cout << "enter the key at which you want to insert a node after" << endl;
            cin >> K1;
            cout << "enter the node" << endl;
            cin >> Key1;
            cin >> Data1;
            N1->Key = Key1;
            N1->Data = Data1;
            S.InsertNode(K1, N1);
            break;
        case 4:
            cout << "enter the key of the node to be deleted" << endl;
            cin >> K1;
            S.DeleteNode(K1);
            break;
        case 5:
            cout << "enter the key of the node you want to update" << endl;
            cin >> Key1;
            cout << "enter the updated data" << endl;
            cin >> Data1;
            S.UpdateNodeByKey(Key1, Data1);

            break;
        case 6:
            S.PrintList();
            break;
        case 7:
            system("cls");
            break;
        default:

            break;
        }
    } while (Option != 0);

    return 0;
}
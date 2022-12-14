#include <iostream>
#define SPACE 10
using namespace std;
class TreeNode
{
public:
    int Value;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode()
    {
        Value = 0;
        Left = NULL;
        Right = NULL;
    }
    TreeNode(int _v)
    {
        Value = _v;
        Left = NULL;
        Right = NULL;
    }
};
class BST
{
public:
    TreeNode *Root;
    BST()
    {
        Root = NULL;
    }
    bool IsEmpty()
    {
        if (Root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void InsertNode(TreeNode *_new_node)
    {

        if (Root == NULL)
        {
            Root = _new_node;
            cout << "Value inserted as root node" << endl;
        }
        else
        {
            TreeNode *Temp = Root;

            while (Temp != NULL)
            {
                if (_new_node->Value == Temp->Value)
                {
                    cout << "Value already exist" << endl;
                    cout << "Try new node" << endl;
                    return;
                }
                else if ((_new_node->Value < Temp->Value) && (Temp->Left == NULL))
                {
                    Temp->Left = _new_node;
                    cout << "Value inserted to the left" << endl;
                    break;
                }
                else if (_new_node->Value < Temp->Value)
                {
                    Temp = Temp->Left;
                }
                else if ((_new_node->Value > Temp->Value) && (Temp->Right == NULL))
                {
                    Temp->Right = _new_node;
                    cout << "Value inserted to the right" << endl;
                    break;
                }
                else
                {
                    Temp = Temp->Right;
                }
            }
        }
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += SPACE;           // Increase distance between levels   2
        print2D(r->Right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
            cout << " ";                    // 5.1
        cout << r->Value << "\n";           // 6
        print2D(r->Left, space);            // Process left child  7
    }
    

};
int main()
{
    int Option;
    int Val;
    BST Obj;

    do
    {
        cout << "What operation do you want to perform" << endl;
        cout << "Enter the operation number. Enter 0 for exit" << endl;
        cout << "1. Insert " << endl;
        cout << "2. Search " << endl;
        cout << "3. Delete " << endl;
        cout << "4. Print BST values " << endl;
        cout<<"5. Height of the tree"<<endl;
        cout << "6. Clear screen " << endl;
        cout << "0. Exit program" << endl;
        cin >> Option;

        TreeNode *NewNode = new TreeNode();
        switch (Option)
        {
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter the value of tree node you want to insert" << endl;
            cin >> Val;
            NewNode->Value = Val;
            Obj.InsertNode(NewNode);
            cout << endl;

            break;
        case 2:
            cout << "SEARCH" << endl;

            break;
        case 3:
            cout << "DELETE" << endl;
            break;
        case 4:
            cout << "PRINT 2D" << endl;
            Obj.print2D(Obj.Root, 5);
            cout << endl;
        case 5:
            cout<<"TREE HEIGHT"<<endl;
            break;
        case 6:
            system("cls");
            break;

        default:
            break;
        }
    } while (Option != 0);

    return 0;
}
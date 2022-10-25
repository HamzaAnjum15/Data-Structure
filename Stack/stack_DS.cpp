#include <iostream>
// #include <string>
using namespace std;
class Stack{
    private:
        int Top;
        int Arr[5];
    public:
        Stack(){
            Top=-1;
            for(int i=0;i<4;i++){
                Arr[i]=0;
            }
        }
        bool IsEmpty(){
            if(Top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool IsFull(){
            if(Top==4){
                return true;
            }
            else{
                return false;
            }
        }
        void Push(int _val){
            if(IsFull()){
                cout<<"stack overflow"<<endl;
            }
            else{
                Top++;
                Arr[Top]=_val;
            }
        }
        int Pop(){
            if(IsEmpty()){
                cout<<"stack underflow"<<endl;
                return 0;
            }
            else{
                int PopValue=Arr[Top];
                Arr[Top]=0;
                Top--;
                return PopValue;
            }
        }
        int Count(){
            return(Top+1);
        }
        int Peek(int _pos){
            if(IsEmpty()){
                cout<<"stack underflow"<<endl;
            }
            else{
                return Arr[_pos];
            }
        }
        void Change(int _pos,int _val){
            Arr[_pos]=_val;
            cout<<"the value at position "<<_pos<<" is changed"<<endl;
        }
        void Display(){
            cout<<"All items in the array are: "<<endl;
            for(int i=4;i>=0;i--){
                cout<<Arr[i]<<endl;
            }
        }


    
};
int main(){
    Stack S1;
    int Position,Option,Value;
    do{
        cout<<"What operation do you want to perform? Selet option no., Press 0 to exit"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. IsEmpty"<<endl;
        cout<<"4. IsFull"<<endl;
        cout<<"5. Peek"<<endl;
        cout<<"6. Count"<<endl;
        cout<<"7. Change"<<endl;
        cout<<"8. Display"<<endl;
        cout<<"9. Clear Screen"<<endl<<endl;

        cin>>Option;
        switch (Option)
        {
        case 1:
        cout<<"enter a number to push in stack"<<endl;
        cin>>Value;
        S1.Push(Value);
            break;
        case 2:
        cout<<"Pop function is called"<<S1.Pop()<<endl;
        break;
        case 3:
        if(S1.IsEmpty()){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<"stack is not empty"<<endl;
        }
        break;
        case 4:
        if(S1.IsFull()){
            cout<<"stack is full"<<endl;
        }
        else{
            cout<<"stack is not full"<<endl;
        }
        break;
        case 5:
        cout<<"Enter position you want to peek"<<endl;
        cin>>Position;
        cout<<"Value at position "<<Position<<" is "<<S1.Peek(Position)<<endl;
        break;
        case 6:
        cout<<"Number of items in the stack are "<<S1.Count()<<endl;
        break;
        case 7:
        cout<<"Enter the position"<<endl;
        cin>>Position;
        cout<<"Enter the new value"<<endl;
        cin>>Value;
        S1.Change(Position,Value);
        break;
        case 8:
        S1.Display();
        break;
        case 9:
        system("cls");
        break;
        default:
        cout<<"Enter proper option"<<endl;
            break;
        }
    }while(Option!=0);
        
    
    
    return 0;
}
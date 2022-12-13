#include<iostream>
using namespace std;

class Node{
    public: 
        int key,data;
        Node* next;

        Node(){
            key=0;
            data=0;
            next=NULL; 
        }

        Node(int k,int d){
            key=k;
            data=d;
            next=NULL;
        }

};

class SinglyLinkedList{
    public: 
        Node* head;

        SinglyLinkedList(){
            head = NULL;
        }
        SinglyLinkedList(Node* n){
            head=n;
        }
        // check if node exist using key value
        Node* nodeExist(int k){
            Node* temp=NULL;
            Node* ptr=head;
            while (ptr!=NULL){
                if (ptr->key==k){
                    temp=ptr;
                }
                ptr=ptr->next;
                
            }
            return temp;
        }

        // append a node to the list
        void appendNode(Node* n){
            if( nodeExist(n->key)!=NULL){
                    cout<<"NODE ALREADY EXIST WITH THE KEY VALUE OF : "<<n->key<<"APPEND ANOTHER NODE WITH DIFFERNT KEY VALUE"<<endl;
                }
            else{
                if (head==NULL){
                    head=n;
                    cout<<"NODE APPENDED"<<endl;
                }
                else{
                    Node* ptr=head;
                    while (ptr->next !=NULL){
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    }
                
            }
        }

        // prepend node at the start

        void prependNode (Node * n){
            if (nodeExist(n->key)!=NULL)
            {
                cout<<"NODE ALREADY EXIST WITH THE KEY VALUE OF : "<<n->key<<"APPEND ANOTHER NODE WITH DIFFERNT KEY VALUE"<<endl;
            }
            else{
                n->next=head;
                head=n;
                cout<<"NODE PREPENDED"<<endl;
            }
            
        }

        //  insert a node after a particular node in the list
        void insertNodeAfter(int k, Node* n){
            Node* ptr = nodeExist(k);
            if(ptr==NULL){
                cout<<"NO NODE EXIST WITH KEY VALUE "<<k<<endl;
            }
            else{
                if( nodeExist(n->key)!=NULL){
                    cout<<"NODE ALREADY EXIST WITH THE KEY VALUE OF : "<<n->key<<"APPEND ANOTHER NODE WITH DIFFERNT KEY VALUE"<<endl;
                }
                else{
                    n->next=ptr->next;
                    ptr->next=n;
                    cout<<"NODE INSERTED"<<endl;
                }
            }
        }

        // delete node by unique key
        void deleteNodeByKey(int k){
            if(head==NULL){
                cout<<"SINGLY LINKED LIST ALREADY EMPTY. CANT DELTE "<<endl;
            }
            else if(head!=NULL){
                if(head->key==k){
                    head=head->next;
                    cout<<"NODE UNLINKED WITH KEY VALUE "<<k<<endl;
                }
                else
                {
                    Node* temp=NULL;
                    Node* prevptr=head;
                    Node* currentptr=head->next;
                    while(currentptr!=NULL){
                        if(currentptr->key==k){
                            temp=currentptr;
                            currentptr=NULL;
                        }
                        else{
                            prevptr=prevptr->next;
                            currentptr=currentptr->next;
                        }
                    }
                    if(temp!=NULL){
                        prevptr->next=temp->next;
                        cout<<"NODE UNLINKED WITH KEY VALUE "<<k<<endl;
                    }
                    else{
                        cout<<"NODE DOESNT EXIST WITH KEY VALUE "<<k<<endl;
                    }
                }
                
            }
        }

        // update node by key
        void updateNodeByKey(int k,int d){
            Node* ptr= nodeExist(k);
            if(ptr!=NULL){
                ptr->data=d;
                cout<<"NODE UPDATED SUCESSFULLY"<<endl;
            }
            else{
                cout<<"NODE DOESNT EXIST WITH KEY VALUE "<<k<<endl;
            }

        }

        // print entire list
        void printList(){
            if(head==NULL){
                cout<<"NO NODE EXIST IN THE SINGLY LINKED LIST";
            }
            else{
                cout<<endl<<"SINGLY LINKED LIST VALUES : ";
                Node* temp=head;

                while (temp!=NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<") --> ";
                    temp=temp->next;
                }
                

            }
        }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
    do
    {
        cout<<"WHAT OPERATIONS YOU WANT TO PERFORM? SELECT OPTION NUMBER. ENTER 0 TO EXIT."<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter()"<<endl;
        cout<<"4. deleteNodeByKey()"<<endl;
        cout<<"5. updateNodeByKey()"<<endl;
        cout<<"6. print()"<<endl;

        cin>>option;
        Node* n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout<<"APPEND NODE OPERATION \nENTER KEY & DATA OF THE NODE TO BE APPEND"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.appendNode(n1);
            break;

        case 2:
         cout<<"PREPEND NODE OPERATION \nENTER KEY & DATA OF THE NODE TO BE PREPENDED"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prependNode(n1);
            break;
        case 3:
            cout<<"INSERT NODE OPERATION AFTER \nENTER KEY OF EXISTING NODE AFTER WHICH YOU WANT TO INSERT THIS NODE: "<<endl;
            cin>>k1;
            cout<<"ENTER KEY AND DATA OF NEW NODE"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.insertNodeAfter(k1,n1);
            break;
        case 4:
            cout<<"DELETE NODE BY KEY OPERATION - \nENTER KEY & NEW DATA TO BE DELETED"<<endl;
            cin>>k1;
            s.deleteNodeByKey(k1);
            break;
        case 5:
            cout<<"UPDATE NODE BY KEY OPERATION - \nENTER KEY & NEW DATA TO BE UPDATED "<<endl;
            cin>>key1;
            cin>>data1;
            s.updateNodeByKey(key1,data1);
            break;

        case 6 :
            s.printList();

        default:
            break;
        }
        
    } while (option!=0);
    

    
    return 0;
}
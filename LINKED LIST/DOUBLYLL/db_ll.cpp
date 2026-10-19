#include <iostream>
using namespace std;
class Node
{ 
public:
 int data;
 Node*next;
 Node * prev;

  Node(int data){
  this->data = data;
   prev=next=NUll;
     }

    
      ~Node(){
        // cout<<"~Node="<<data<<endl;
       if(next != NULL){          
        delete next;
         next=NULL;
       }
     }
};

class List{
   Node *head;
   Node*tail;
public:
    List(){
     head=NULL;
     tail=NULL;
     }
       //destructor of list
      
     ~List(){
      //  cout<<"List\n";
       if(head != NULL){
          delete head;
          head= NULL;
       }
     }



 void push_front(int val){
    //new node created
     Node* newNode =new Node(val);
    //  Node* newNode(val);   //static  
    if(head==NULL)
    {
      head=tail=newNode;
    }
    else{
           newNode->next=head;
           head=newNode;
       }
     }

 void push_back(int val){
    //new node created
     Node* newNode =new Node(val);
    //  Node* newNode(val);   //static
    if(head==NULL)
    {
      head=tail=newNode;
    }
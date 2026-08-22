#include <iostream>
using namespace std;
class Node
{ 
public:
 int data;
 Node*next;

     Node(int data){
     this->data = data;
        next = NULL;
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
    else{   
           tail->next=newNode;
           tail=newNode;
       }
  }
   void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data <<"->";       //0(n) t.c
            temp = temp->next;
        }
        cout << "NULL\n";
    }



 void insert(int val,int pos){
   Node* newNode =new Node(val);//newnode create
   
   Node*temp=head;//A temporary node is created, which is updated 
   for(int i=0;i<pos-1;i++){
   temp=temp->next;
   }  newNode->next=temp->next;// new node joined with it, right element of the link list
      temp->next=newNode;  //note joined with the left element of the link. 
 }

};

  

int main(){
        List ll;
        ll.push_front(5);
        ll.push_front(4);
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1);
    //1->2->3->4->5->null
        ll.push_back(8);
        ll.insert(34,3);
        ll.printList();
        
        

  return 0;

}
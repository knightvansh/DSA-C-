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

    
      ~Node(){
        cout<<"~Node="<<data<<endl;
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
       cout<<"List\n";
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
    else{   
           tail->next=newNode;
           tail=newNode;
       }
  }
   void printList() {
        Node* temp = head;//tenmporary node created
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

  void pop_front(){
    if(head ==NULL){
  cout<<"ll is empty\n";
  return;
    }
    Node*temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
  }


  void pop_back(){
   Node*temp=head;
   while(temp->next->next !=NULL){
     temp=temp->next;
   }
   temp->next =tail;
   delete tail;
   tail=temp;
  }

  //
int searchItr( int key){
  Node *temp=head;
  int idx=0;
  while(temp != NULL){
   if(temp->data== key){
    return idx;
    break;
   }
    temp=temp->next;
    idx++;
  }

  return -1;

  }

  int searchRec(int key) {
        return searchHelper(head, key);
    }

    int searchHelper(Node*temp, int key) {
        if(temp== NULL) {
            return -1;
        }

        if(temp-> data == key) {
            return 0; //current idx
        }

        int idx = searchHelper(temp->next, key);
        if(idx == -1) {
            return -1;
        }

        return idx + 1;
    }


  

};

  

int main(){
        List ll;
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1);
    //1->2->3->null
        ll.push_back(8);

        // ll.insert(34,3);

        ll.printList();

        // ll.pop_front();//

        //  ll.printList();

        //  cout<<ll.searchItr(8)<<endl;

           cout<<ll.searchRec(2)<<endl;
        

  return 0;

}
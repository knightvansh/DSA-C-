#include<iostream>
#include<list>
#include <iterator>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

    // void push_back(int val){
    // //new node created
    //  Node* newNode =new Node(val);
    // //  Node* newNode(val);   //static
    // if(head==NULL)
    // {
    //   head=tail=newNode;
    // }
    // else{   
    //        tail->next=newNode;
    //        tail=newNode;
    //    }
    // }

    Node*SplitAtMid(Node*head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        prev = slow;//slow ki purani value hogi
       }
  if(prev != NULL) {
        prev->next = NULL;
     }
 return slow;//right head milega
    };


Node* merge(Node* h1, Node*h2) {
    List ans;
    Node* i = h1;
    Node* j = h2;

    while(i != NULL && j != NULL) {
        if(i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}





   Node*mergeSort(Node*head){
    if(head == NULL || head->next == NULL) {
        return head;
    }   
      Node* righthead= SplitAtMid(head);
      Node*h1= mergeSort(head);//left head
      Node*h2=mergeSort(rightHead);//right

    return merge(h1,h2);//head of sorted ll
}






int main(){

        List ll;
        ll.push_front(0);
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1);
        // ll.tail->next=ll.head; //1->2->3->4->1
        // cout << iscycle(ll.head) << endl;
        
        // removeCycle(ll.head);
        // cout << isCycle(ll.head) << endl;
        // ll.printList(); 
        printlist(ll.head);

        ll.head=mergeSort(ll.head);
        printlist(ll.head);



}
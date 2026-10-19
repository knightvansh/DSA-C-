#include <bits/stdc++.h>
using namespace  std;
//FIRST: Define what a Node is
class  Node{
 public:
 int data;
 Node* left;
 Node* right;
 // A quick way to create a new node
Node(int data){
    this->data= data;
    left=right=NULL;
}
};
// SECOND: Now you can write your function because the computer knows what a Node is
Node* buildTree(vector<int> &nodes){
  static int idx=-1;
   idx++;
   if(nodes[idx]==-1){
      return NULL;
   }
  Node* currNode = new Node(nodes[idx]);
  currNode->left= buildTree(nodes);
  currNode->right= buildTree(nodes);
  return currNode;
 }

void preorder(Node* root){
     if(root == NULL){
       return ;
     }
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
 }

 void inorder(Node* root){
     if(root == NULL){
       return ;
     }
   inorder(root->left);
    cout<<root->data<<" ";
   inorder(root->right);
 }

 void postorder(Node* root){
   if(root == NULL){
    return ;
      }
     postorder(root->left); 
     postorder(root->right);  
    cout<<root->data<<" "; 
  }


void levelorder(Node*root){
   if(root ==NULL){
    return;
    }
      queue<Node*> q;

       q.push(root);

       while (!q.empty()) {       
        Node* current = q.front();
         q.pop();   
        cout << current->data << " ";

        if (current->left != NULL) {
           q.push(current->left);
       }
        if (current->right != NULL) {
           q.push(current->right);
        }
      }

 }

 int height(Node*root){
 if(root ==NULL){
    return 0;
    }
   int leftheight=height(root->left);
   int  rightheight=height(root->right);
    return 1+max(leftheight, rightheight); 
 }



 int countNodes(Node* root) {
    // Line 1: Base Case — An empty node contributes 0 to the count
    if (root == NULL) {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    // Line 4: Return 1 (myself) + left subtree count + right subtree count
    return 1 + leftCount + rightCount;
}

int sumNodes(Node* root) {
    // Line 1: Base Case — An empty node contributes 0 to the sum
    if (root == NULL) {
        return 0;
    }
    // Line 2: Recursively sum all values in the left subtree
    int leftSum = sumNodes(root->left);
    // Line 3: Recursively sum all values in the right subtree
    int rightSum = sumNodes(root->right);
    // Line 4: Return current node's value + left sum + right sum
    return root->data + leftSum + rightSum;
}



int main(){
vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root =buildTree( nodes);
// cout<<"root ="<<root->data<<endl;
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;

cout << "Levelorder: ";
levelorder(root);
cout << endl;
cout << "Height of tree: " << height(root) << endl;
return 0;


cout<<"countNodes:"<<countNodes( root)<< endl;
}

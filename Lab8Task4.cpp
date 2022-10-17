// Online C++ compiler to run C++ program online
#include <iostream>
struct node{
    int value;
    node *left;node *right;node *parent;
    
};
node* create_node(int item){
node *new_node=new node();
if(new_node==NULL)
std::cout<<"Error";
else{new_node->value=item;
new_node->left=NULL;
new_node->right=NULL;
new_node->parent=NULL;}
return new_node;
}
node* Tree_insert(struct node* x, int key){
if (x == NULL) 
return create_node(key);
if (key < x->value)
x->left= Tree_insert(x->left, key);
else if (key > x->value)
x->right = Tree_insert(x->right, key);
return x;
}
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
       std:: cout << root->value<<' ';
        inorder(root->right);
    }
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
  
   
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}
struct node* deleteNode(struct node* root, int key)
{
   
    if (root == NULL)
        return root;
  
   
    if (key < root->value)
        root->left = deleteNode(root->left, key);
  
  
    else if (key > root->value)
        root->right = deleteNode(root->right, key);
  
   
    else {
       
        if (root->left==NULL and root->right==NULL)
            return NULL;
        
       
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
  
       
        struct node* temp = minValueNode(root->right);
  
        
        root->value= temp->value;
  
        
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}
  
int main() {
  
   
    struct node* root = NULL;
    root = Tree_insert(root, 50);
    root = Tree_insert(root, 75);
    root =Tree_insert(root, 25);
    root = Tree_insert(root, 29);
    root = Tree_insert(root, 45);
    root = Tree_insert(root, 60);
    root =Tree_insert(root, 90);
    root = Tree_insert(root, 10);
    root = Tree_insert(root, 80);
    root = Tree_insert(root, 100);
    root = Tree_insert(root, 84);
  
  // std:: cout << "Inorder traversal of the given tree \n";
    //inorder(root);
    std::cout << "\nDelete 29\n";
    root = deleteNode(root, 29);
    //std ::cout << "Inorder traversal of the modified tree //\n";
    inorder(root);
     std::cout << "\nDelete 25\n";
    root = deleteNode(root, 25);
    inorder(root);
     std::cout << "\nDelete 75\n";
    root = deleteNode(root, 75);
    inorder(root);
     std::cout << "\nDelete 45\n";
    root = deleteNode(root, 45);
    inorder(root);
     std::cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    inorder(root);
     std::cout << "\nDelete 80\n";
    root = deleteNode(root, 80);
    inorder(root);
     std::cout << "\nDelete 100\n";
    root = deleteNode(root, 100);
    inorder(root);
     std::cout << "\nDelete 90\n";
    root = deleteNode(root, 90);
    inorder(root);
  
  

    return 0;
}
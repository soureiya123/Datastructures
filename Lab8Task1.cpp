#include<bits/stdc++.h>
using namespace std;
struct node{
int value;
node *left;
node *right;node *parent;
};

node* create_node(int item){
node *new_node=new node();
if(new_node==NULL)
cout<<"Error"<<endl;
else{
new_node->value=item;
new_node->left=NULL;
new_node->right=NULL;
new_node->parent=NULL;}
return new_node;
}
int Tree_search(node *x,int key){
if( x==NULL)
return 0;
else if(x->value==key)
return x->value;
else if(key<x->value)
return Tree_search(x->left,key);
else if(key>x->value)
return Tree_search(x->right,key);
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
void inorder(node *x){
if(x != NULL){
inorder(x->left);
cout<<x->value<<" ";
inorder(x->right);
}
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int v,n,i;
node *root;
root=NULL;
cin>>v;
root=Tree_insert(root,v);
while(1){
cin>>v;
if(v==-1)
break;
else if(v+1==Tree_search(root,v+1)){
inorder(root);
cout<<"Reservation failed"<<endl;
}
else if(v+2==Tree_search(root,v+2)){
inorder(root);
cout<<"Reservation failed"<<endl;
}
else if(v+3==Tree_search(root,v+3)){
inorder(root);
cout<<"Reservation failed"<<endl;
}
else if(v-1==Tree_search(root,v-1)){
inorder(root);
cout<<"Reservation failed"<<endl;
}
else if(v-2==Tree_search(root,v-2)){
inorder(root);
cout<<"Reservation failed"<<endl;
}
else if(v-3==Tree_search(root,v-3)){
inorder(root);
cout<<"Reservation failed"<<endl;
}
else
{
root=Tree_insert(root,v);
inorder(root);
cout<<endl;
}
}
}


#include <stdio.h>
#include<bits/stdc++.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};

    node* newNode (int data){
     node *temp=new node;
     temp->data=data;
     temp->left=NULL;
     temp->right=NULL;
     return temp;

 }

 int minValue(struct node* node)
{
    if (node->left == NULL)
        return node->data;
    return minValue(node->left);
}

 int countNumber(node * root, int low,int high){


     if(!root)
        return 0;
    if (root->data == high && root->data == low)
        return 1;
    if (root->data < high && root->data >= low)
         return 1 + countNumber(root->left, low, high) +
                    countNumber(root->right, low, high);
    else if (root->data < low)
         return countNumber(root->right, low, high);
    else return countNumber(root->left, low, high);

 }
int main() {


    node *root        = newNode(50);
    root->right       = newNode(75);
    root->left        = newNode(25);
    root->left->right  = newNode(29);
    root->left->right->right  = newNode(45);
    root->right->left  = newNode(60);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    root->left->left = newNode(10);
    int l = minValue(root);
    int h = 45;
    //std:: cout << "min node  " << l<<'\n';
    std:: cout << " nodes " << countNumber(root, l, h)<<'\n';
    h = 75;
    std:: cout << " nodes " << countNumber(root, l, h)<<'\n';
    h = 50;
    std:: cout << " nodes " << countNumber(root, l, h);


    return 0;
}

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

int Height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->data = key;
    node->left = node->right = NULL;
    node->height = 1;
    return(node);
}
void update_height(Node *t)
{
     t->height = max(Height(t->left),Height(t->right)) + 1;
}

int BalanceFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return Height(N->left)-Height(N->right);
}

Node* Insert(Node* node, int key)  {
    if (node == NULL)
        return(newNode(key));
    if (key < node->data)
        node->left = Insert(node->left, key);
    else if (key > node->data)
        node->right = Insert(node->right, key);
    else
        return node;
    update_height(node);
    return node;
}

void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->data<<"("<<BalanceFactor(root)<<")" << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *root=0;
    int val;
    for(int i=0;i<9;i++)
    {
    cin>>val;
    root = Insert(root, val);
    inOrder(root);
    cout<< "\n";
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct Node
{
	struct Node *left, *right;
	int data;
};


Node *createNode(int x)
{
	Node *p = new Node;
	p -> data = x;
	p -> left = p -> right = NULL;
	return p;
}


void insertNode(struct Node *root, int x)
{
	Node *p = root, *q = NULL;

	while (p != NULL)
	{
		q = p;
		if (p -> data < x)
			p = p -> right;
		else
			p = p -> left;
	}

	if (q == NULL)
		p = createNode(x);
	else
	{
		if (q -> data < x)
			q -> right = createNode(x);
		else
			q -> left = createNode(x);
	}
}


int maxelpath(Node *q, int x)
{
	Node *p = q;

	int mx = INT_MIN;


	while (p -> data != x)
	{
		if (p -> data > x)
		{
			mx = max(mx, p -> data);
			p = p -> left;
		}
		else
		{
			mx = max(mx, p -> data);
			p = p -> right;
		}
	}

	return max(mx, x);
}


int maximumElement(struct Node *root, int x, int y)
{
	Node *p = root;

	
	while ((x < p -> data && y < p -> data) ||
		(x > p -> data && y > p -> data))
	{
		
		if (x < p -> data && y < p -> data)
			p = p -> left;

		
		else if (x > p -> data && y > p -> data)
			p = p -> right;
	}


	return max(maxelpath(p, x), maxelpath(p, y));
}



int main()
{
	int arr[] = { 50, 75, 25, 29, 45, 60, 10, 80 };
	int a = 25, b = 60;
	int n = sizeof(arr) / sizeof(arr[0]);

	// Creating the root 
	struct Node *root = createNode(arr[0]);

	
	for (int i = 1; i < n; i++)
		insertNode(root, arr[i]);

	cout << maximumElement(root, a, b) << endl;

	return 0;
}

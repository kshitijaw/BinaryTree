#include<iostream>
#include<queue>

using namespace std;

struct Node
{
	int data;
	struct Node *left,*right;

};

//Printing the elements of a level using queue data structure
void printLevelOrder(Node *root)
{
	if(root==NULL)
		return;

	queue<Node *> q;

	q.push(root);


	while(!q.empty())
	{
		Node *node = q.front();

		cout<<node->data<<" ";
		q.pop();

		if(node->left !=NULL)
			q.push(node->left);

		if(node->right !=NULL)
			q.push(node->right);


	} 

}


Node* newNode(int k)
{
	Node *node = new Node;

	node->data =k;

	node->right = node->left = NULL;
	return node;

}
int main()
{
	Node *root = newNode(1);
	 root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;



}



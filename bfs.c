//Binary Tree traversal using recursion

#include<stdlib.h>
#include<stdio.h>


//Structure construction
struct node
{
	int data;
	struct node *left,*right;


};

//Creation of new node
struct node* newNode(int k)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->data = k;
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}

//Function to claculate the height of the tree
int height(struct node* node)
{	
	if(node==NULL)
		return 0;
	else
	{
		
		int lheight= height(node->left);
		int rheight = height(node->right);

		if(lheight>rheight)
			return(lheight+1);
		else
			return(rheight+1); 

	}


}

//Function to print the overall binary tree
void printLevelOrder(struct node* node)
{	
	int h = height(node);

	if(h==0)
		return;

	for(int i = 1; i<=h;i++)
		printGivenLevel(node,i);
		
}

//Function to print the nodes of a given level
void printGivenLevel(struct node* node,int level)
{	
	if(node==NULL)
		return;

	if(level==1)
		printf("%d ",node->data);

	else if(level>1)
	{	printGivenLevel(node->left,level-1);
		printGivenLevel(node->right,level-1);
	}
		
}

int main()
{
	struct node *root = newNode(1);

	root->left = newNode(2);
	root->right= newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	 printf("Level Order traversal of binary tree is \n");
    	printLevelOrder(root);
 
    return 0;
	
}


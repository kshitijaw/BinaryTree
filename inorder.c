/*inorder traversal using stack*/

#include<stdio.h>
#include<stdlib.h>
#define bool int


//Tree node
struct tNode
{
	int data;
	struct tNode *left;
	struct tNode *right;


};

//Stack Node
struct sNode
{
	struct tNode *t;
	struct sNode *next;


};

void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);


void inOrder(struct tNode *root)
{
	struct sNode *s = NULL;			//initializing the node of the stack
	bool done = 0;
	
	struct tNode *current = root;		//Tree node current pointing to the root of the tree

	while(!done)
	{

		if(current!=NULL)		
		{	
			push(&s,current);		//pushing nodes to the stack till the farthest left
			current = current->left;


		}

		else
		{
			if(!isEmpty(&s))
			{
				current = pop(&s);			//popping the node with data 
				printf("%d ",current->data);

				current=current->right;			//moving to the right 


			}
			else
				done = 1;
		}
	}
}


void push(struct sNode **top, struct tNode *t)
{

	struct sNode *new_node = (struct sNode*)malloc(sizeof(struct sNode));
	
	new_node->t = t;
	
	if(new_node == NULL)
  	{
     	   printf("Stack Overflow \n");
           getchar();
     	   exit(0);
  	}  


		new_node->next = *top;
		*top = new_node;
		 
}

bool isEmpty(struct sNode *top)
{
	
	return (top==NULL) ? 1:0;

}
struct tNode *pop(struct sNode** top_ref)
//struct tNode *pop(struct sNode** top_ref)
{

	struct sNode *top;
	struct tNode *res; 
	if(isEmpty(*top_ref))
	{
		
     		printf("Stack Underflow \n");
     		getchar();
    		 exit(0);
	}

	else
	{
		top= *top_ref;
		res = top->t;
		*top_ref = top->next;
		free(top);
		return(res);

	}
}

struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
 
  return(tNode);
}

int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct tNode *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5); 
 
  inOrder(root);
 
  getchar();
  return 0;
}


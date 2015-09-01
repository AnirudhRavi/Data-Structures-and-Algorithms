#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(int value);

struct tree{
	int val;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
	char *color;
};

struct tree *root;

void left_rotate(struct tree *x)
{											
	printf("%d",x->val);
	struct tree *y;
	y = x->right;
	x->right = y->left;
	if(y->left != NULL)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if(x->parent == NULL)
	{
		root = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;printf("%d\n",x->val);
}


void right_rotate(struct tree *x)
{
	struct tree *y;
	y = x->left;
	x->left = y->right;
	if(y->right != NULL)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if(x->parent == NULL)
	{
		root = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}


void insert_fixup(struct tree *node)
{
	struct tree *z;
	z = node;                                                                     
	struct tree *temp;
	
	while(  z != root && (z)->parent->color == "red")
	{                                                                           
		printf("222222222\n");
			
		if((z)->parent == (z)->parent->parent->left)
		{                                                                     
			temp = (z)->parent->parent->right;
			if(temp != NULL && strcmp(temp->color,"red") == 0)
			{								
				(z)->parent->color = "black";
				temp->color = "black";
				(z)->parent->parent->color = "red";
				(z) = (z)->parent->parent;printf("%d",z->val);				
				printf("3333333331\n");
			}
			else if((z) == (z)->parent->right)
			{
				(z) =(z)->parent;                                      
				printf("%d\n",z->parent->val); 														
				printf("444441\n");
				left_rotate(z);                                                    
				printf("%d\n",z->parent->val);
			
				(z)->parent->color = "black";
				(z)->parent->parent->color = "red";
				right_rotate(z->parent->parent);					
				printf("555551\n");
			}
			else
			{
				(z)->parent->color = "black";
				(z)->parent->parent->color = "red";
				right_rotate(z->parent->parent);					
				printf("555551\n");
			}
		}
		else 
		{
			temp = z->parent->parent->left;
			if(temp != NULL && strcmp(temp->color,"red") == 0)
			{								
				printf("3333333332\n");
				z->parent->color = "black";
				temp->color = "black";
				z->parent->parent->color = "red";
				z = z->parent->parent;
			}
			else if(z == z->parent->left)
			{
				z = z->parent;
				right_rotate(z);							
				printf("444442\n");
				z->parent->color = "black";
				z->parent->parent->color = "red";
				left_rotate(z->parent->parent);			
			}
			else
			{
				z->parent->color = "black";
				z->parent->parent->color = "red";
				left_rotate(z->parent->parent);				
				printf("555552\n");
			}
		}printf("\n");
	}printf("1234566778\n");
	root->color = "black";
}

void insert(int value)
{
	struct tree *temp,*t;t = NULL;
	temp = root;
	while(temp != NULL)
	{
		t = temp;
		if(value <= temp->val)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	struct tree *new;
	(new) = (struct tree *)malloc(sizeof(struct tree));
	(new)->parent = t;
	(new)->val = value;
	if(t == NULL)
	{
		root = (new);
	}
	else if(value <= t->val)
	{
		t->left = (new);
	}
	else
	{
		t->right = (new);
	}
	(new)->left = NULL;
	(new)->right = NULL;
	(new)->color = (char *)malloc(sizeof(char)*5);	
	(new)->color = "red";
	insert_fixup(new);										
}

main()
{
	insert(7);                                                         
	insert(3);
	insert(18);
	insert(10);
	insert(8);
	insert(11);
	insert(22);
	insert(26);
}

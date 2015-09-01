#include <stdio.h>
#include <stdlib.h>

struct rowNode
{
	int row;
  	struct cellNode* firstNode;
  	struct rowNode* nextRow;
}*rowHead = NULL, *start = NULL, *s = NULL;

struct cellNode
{
	int col;
  	char value;
  	struct cellNode* nextNode;
}*curr = NULL, *p = NULL;

void sparseMatrixStore();
void printNonZero();
void printSparseMatrix();

int main()
{
	sparseMatrixStore();
	printNonZero();
	printSparseMatrix();
  	return 0;
}

void sparseMatrixStore()
{
	int i = 0, j = 0, f = 2;
	char ch;
	FILE* fp = fopen("sparsematrix.txt", "r");
	rowHead = (struct rowNode*)(malloc(sizeof(struct rowNode)));
	rowHead->row = 0;
	start = rowHead;
	while(fscanf(fp, "%c", &ch) == 1)
 	{
  		if(ch == ' ')
   			j++;
   		if(ch == '\n')
  		{
   			j=0;
   			i++;
   			f=1;
  		}     
  		if(ch != '0'&& ch != '\n' && ch != ' ')
  		{
 			curr = (struct cellNode*)(malloc(sizeof(struct cellNode)));
  			curr->col = j;
        	curr->value = ch;
        	curr->nextNode = NULL;
			if(f == 2)
			{
	 			rowHead->firstNode = curr;
	 			f = 0;
			}
			else if(f == 1)
			{
	  			s = (struct rowNode*)malloc(sizeof(struct rowNode));
	  			rowHead->nextRow = s;
	  			rowHead = rowHead->nextRow;
	  			rowHead->firstNode = NULL;
	  			rowHead->firstNode = curr;
	  			rowHead->row = i;
	  			f=0;
			}
			else
			{
	  			p = rowHead->firstNode;
	  			while(p->nextNode != NULL)
	  				p = p->nextNode;
	  			p->nextNode = curr;
			}
		}
 	}      
 	fclose(fp);	
}

void printNonZero()
{
	printf("\nNon-zero values of Sparse Matrix (Row Wise) : \n");
    s = start;
    while(s != NULL)
    {
    	printf("\n[%d]:\t",s->row);
        p = s->firstNode;
		while(p != NULL)
        {
  	      	printf(" %c  ", p->value);
           	p = p->nextNode;
        }
        s = s->nextRow;           			
	}	
}

void printSparseMatrix()
{
	int i = 0, j = 0, t = 0;
	printf("\n\nThe Sparse Matrix given in sparsematrix.txt is \n(displayed using list of list form) :\n\n");
	s = start;
	while(s != NULL)
	{		
		if(i < s->row)
			while(i < s->row)
			{
				t = 0;
				while(t < 50)
				{
					printf("0");
					t++;
				}
				i++;
				printf("\n");				
			}
		p = s->firstNode;
		for(j=0; j < p->col; j++)
			printf("0");
		printf("%c", p->value);
		j++;
		p = p->nextNode;
		while(p != NULL)
		{
			for(j; j < p->col; j++)
				printf("0");
			printf("%c",p->value);
			j++;
			p = p->nextNode;
		}
		if(j < 50)
		{
			while(j < 50)
			{	
				printf("0");
				j++;
			}
		}
		printf("\n");
		s = s->nextRow;
		i++;	
	}
}

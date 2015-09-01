#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void huffman_algorithm(char s[]);
void decode(int a[],int n);
struct node{
	char ch;
	int frequency;
	struct node *left;
	struct node *right;
};
struct node *letters[28];
struct encode{
	char ch;
	int *code;
	int si;
};
void ppreorder(struct node *temp)
{
	if(temp != NULL)
	{
		
		printf("%c\t%d\n",temp->ch,temp->frequency);
		ppreorder(temp->left);		
		ppreorder(temp->right);
	}
}
int partition(struct node **a,int low,int high)
{	
	int x;
	x = a[high]->frequency;
	char c;
	c = a[high]->ch;
	int k,p;
	struct node *temp;
	p=low-1;
	for(k=low;k<high;k++)
	{
		if(a[k]->frequency <= x)
		{
			p=p+1;
			temp=a[k];
			a[k]=a[p];
			a[p]=temp;
		}
	}
	a[high]->ch = a[p+1]->ch;
	a[high]->frequency = a[p+1]->frequency;
	a[p+1]->frequency = x;
	a[p+1]->ch = c;
	return p+1;
}
void quickSort(struct node **a,int low,int high)
{	
	if(low<high)
	{
		int x;
		x=partition(a,low,high);
		quickSort(a,low,x-1);
		quickSort(a,x+1,high);
	}
}
struct encode *e[28];
int s = 0;
void preorder(struct node *temp,int *a,int n)
{
	int i =0;
	int *a1 = (int*)malloc((n+1)*sizeof(int));
	int *a2 = (int*)malloc((n+1)*sizeof(int));
	if(temp != NULL)
	{
		if(temp == letters[0])
		{
			a1[0] = 0;
			a2[0] = 1;
		}
		else
		{
			for(i = 0;i<n;i++)
			{			
				a1[i] = a[i];
				a2[i] = a[i];
			}
			n = n+1;
			a1[n-1] = 0;
			a2[n-1] = 1;		
		}
		if(temp->left->ch != '\0' && temp->right->ch != '\0')
		{  
			e[s] = (struct encode *)malloc(sizeof(struct encode));
			e[s]->si = n;
			e[s]->ch = temp->left->ch;				
			e[s]->code = (int*)malloc(e[s]->si*sizeof(int));
			for(i = 0;i<e[s]->si;i++)
			{
				e[s]->code[i] = a1[i];		
			}
			s++;
			e[s] = (struct encode *)malloc(sizeof(struct encode));
			e[s]->si = n;	
			e[s]->ch = temp->right->ch;			
			e[s]->code = (int*)malloc(e[s]->si*sizeof(int));			
			for(i = 0;i<e[s]->si;i++)
			{
				e[s]->code[i] = a2[i]; 		
			}
			s++;
		}
		else if(temp->left->ch != '\0')
		{
			e[s] = (struct encode *)malloc(sizeof(struct encode));
			e[s]->si = n;	
			e[s]->ch = temp->left->ch;			
			e[s]->code = (int*)malloc(e[s]->si*sizeof(int));
			for(i = 0;i<e[s]->si;i++)
			{
				e[s]->code[i] = a1[i];		
			}
			s++;
			preorder(temp->right,a2,n);
		}
		else if(temp->right->ch !='\0')	
		{
			e[s] = (struct encode *)malloc(sizeof(struct encode));
			e[s]->si = n;	
			e[s]->ch = temp->right->ch;			
			e[s]->code = (int*)malloc(e[s]->si*sizeof(int));
			for(i = 0;i<e[s]->si;i++)
			{
				e[s]->code[i] = a2[i];		
			}
			s++;
			preorder(temp->left,a1,n);			
		}
		else
		{
			preorder(temp->left,a1,n);
			preorder(temp->right,a2,n);
		}
	}
}
void huffman_algorithm(char s[])
{
	if(strlen(s) == 1)
	{
		printf("%s  0\n",s);
		printf("encoded as 0\ndecoded as :%s\n",s);
		return;
	}
	int i = 0;
	int j = 0;
	int flag = 0;
	int n = 0;
	int k = 0;
	for(i = 0;s[i]!='\0';i++)
	{
		for(j=0;j<n;j++)
		{
			if(s[i] == letters[j]->ch)
			{
				flag = 1;k=j;
			}
		}
		if(flag == 0)
		{
			letters[n] = (struct node *)malloc(sizeof(struct node));
			letters[n]->ch = s[i];
			letters[n]->frequency = 1;
			letters[n]->left = NULL;
			letters[n]->right = NULL;
			n = n+1;
		}
		else
		{
			if(letters[k]->ch == s[i])
			{
				letters[k]->frequency += 1;
			}
			flag = 0;
		}
	}
	quickSort(letters,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%c    %d\n",letters[i]->ch,letters[i]->frequency);
	}
	int size = n;
	int count;
	count = n;
	int rootfreq = 0;	
	struct node *leftsub;
	struct node *rightsub;
	while(count >= 2)
	{	
		i = 0;
		leftsub = letters[i];
		rightsub = letters[i+1];
		rootfreq = leftsub->frequency + rightsub->frequency;
		for(j = 2;j<n && letters[j]->frequency <= rootfreq ;j++)
		{
			letters[i] = letters[j];
			i++;
		}
		struct node *new;
		new = (struct node *)malloc(sizeof(struct node));
		new->frequency = rootfreq;
		new->left = leftsub;
		new->right = rightsub;
		letters[i] = new;
		for(j = i+1;j<n-1;j++)
		{
			letters[j] = letters[j+1];
		}
		n = n - 1; 	  		
		count--;	
	}
	struct node *temp;
	temp = letters[0];	
	int p[]={-1};	
printf("preorder traversal:\n");	
	ppreorder(temp);
	preorder(temp,p,1);
printf("encoded each letter as :\n");	 
	for(i=0;i<size;i++)
	{
		printf("%c    ",e[i]->ch);
		for(j =0;j<e[i]->si;j++)
		{
			printf("%d",e[i]->code[j]);
		}
		printf("\n");
	}
	printf("encoded as\n");
	int pa[500];int t = 0;
	for(i =0 ;s[i] !='\0';i++)
	{
		for( j = 0; j<size;j++)
		{
			if(s[i] == e[j]->ch)
			{
				for( k = 0;k<e[j]->si;k++)
				{
					pa[t] = e[j]->code[k];t++;
					printf("%d",e[j]->code[k]);
				}
			}
		}
	}
	printf("\n");
	decode(pa,t);
}
void decode(int a[],int n)
{
	int i,j,k; 
	struct node *temp;
	temp = letters[0];	
	printf("decoded as   :");	
	for(i = 0;i<n;i++)
	{
		if(a[i] == 0)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
		if(temp->left == NULL && temp->right == NULL)
		{
			printf("%c",temp->ch);
			temp = letters[0];
		}
	}printf("\n");
}

main()
{	
	char s[]= "Eerie eyes seen near lake.";
	huffman_algorithm(s);
}

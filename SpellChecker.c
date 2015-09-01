#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void retrieving();
void checkspell(int a);

struct node{
	char *misspelt;
	char *corrected;
	struct node *next;
};
struct node *address[100];

void retrieving()
{
	FILE *fp;
	int i = 0;
	int sum = 0;
	int j = 1;
	int k = 0;	
	fp = fopen("spell.txt","r");
	char ch[100];                                           
	while(fscanf(fp,"%s",ch) != EOF)
	{
		sum = 0;
		for(i = 0; ch[i] != '\0';i++)
		{
			sum = sum+ch[i];
		}
		i = sum %100;
		if(address[i] == NULL)
		{
			struct node *temp;
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->misspelt = (char *)malloc(sizeof(char)*100);
			char *c1 = (char *)malloc(sizeof(char)*100);
			for(k = 0; ch[k] != '\0';k++)
			{
				c1[k] = ch[k];
			}	
			temp->misspelt = c1;
			temp->corrected = (char *)malloc(sizeof(char)*100);
			fscanf(fp,"%s",ch);
			char *c2 = (char *)malloc(sizeof(char)*100); 
			for(k = 0; ch[k] != '\0';k++)
			{
				c2[k] = ch[k];
			}
			temp->corrected = c2;
			address[i] = temp;
		}
		else
		{
			struct node *temp;
			temp = address[i];
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = (struct node *)malloc(sizeof(struct node *));			
			temp->next->misspelt = (char *)malloc(sizeof(char)*100);
			char *c1 = (char *)malloc(sizeof(char)*100);
			for(k = 0; ch[k] != '\0';k++)
			{
				c1[k] = ch[k];
			}	
			temp->next->misspelt = c1;
			temp->next->corrected = (char *)malloc(sizeof(char)*100);
			fscanf(fp,"%s",ch);
			char *c2 = (char *)malloc(sizeof(char)*100); 
			for(k = 0; ch[k] != '\0';k++)
			{
				c2[k] = ch[k];
			}
			temp->next->corrected = c2;
		}
	}
	fclose(fp);
	int count =0;
	for(i = 0;i<100;i++)
	{
		printf("%d   ",i);
		struct node *temp;
		if(address[i] != NULL)
		{
	 		temp = address[i];
			printf("%s\t",temp->misspelt);			
			while(temp->next != NULL)
			{
				temp = temp->next;
				printf("%s\t",temp->misspelt);	
			} 
		}printf("\n");
	}
}


void checkspell(int a)
{
	int i = 0;
	int j = 0;
	int k = 0; 
	int sum = 0;
	int change = 0;
	FILE *fp_in,*fp_out;
	fp_in = fopen("inputfile","r");
	fp_out = fopen("outputfile","w");
	char *ch = (char *)malloc(sizeof(char)*100);
	while( fscanf(fp_in,"%s",ch) != EOF)
	{
		sum = 0;j = 0;
		for(i = 0;ch[i] != '\0';i++)
		{
			sum = sum+ch[i];
		}
		i = sum%100;
		if(address[i] == NULL)
		{
			fprintf(fp_out,"%s ",ch);
		}
		else
		{        
			struct node *temp;
			temp = address[i];
			while(temp != NULL)
			{
				if(strcmp(temp->misspelt,ch) == 0)
				{	
					
					if(a == 1)
					{
						fprintf(fp_out,"%s ",temp->corrected);
					}
					else
					{
						printf("%s  %s\n to change press 1 else press 2 :",temp->misspelt,temp->corrected);
						scanf("%d",&change);
						if(change == 1)
						{				     	
							fprintf(fp_out,"%s ",temp->corrected);
						}
						else
						{
							fprintf(fp_out,"%s ",temp->misspelt);
						}
					}
					break;
				}
				temp = temp->next;
			}
			if(temp == NULL)
			{
				fprintf(fp_out,"%s ",ch);
			}			
		}
	}					 
	fclose(fp_in);
	fclose(fp_out);
	fp_in = fopen("inputfile","w");
	fp_out = fopen("outputfile","r");
	while( fscanf(fp_out,"%s",ch) != EOF)
	{
		fprintf(fp_in,"%s ",ch);
	}
	fclose(fp_in);
	fclose(fp_out);
}

int main()
{
	retrieving();
	int i;
	printf("For autochecking press 1 otherwise press 2 :");
	scanf("%d",&i);
	switch(i)
	{
		case 1  :
			 checkspell(i);
			 break;
		default :
			 checkspell(i);
			 break;
	}			
}

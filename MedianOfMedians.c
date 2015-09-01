#include<stdio.h>
#include<string.h>

char med[10][40];

void insertion_sort(char a[][40], int p, int q)
{
	int i, j, k;
	char key[40];
	for(j=p+1;j<=q;j++)
	{	
		strcpy(key,a[j]);
		i=j-1;
		while( i>=p && (strcmp(a[i],key)> 0) )
		{
			strcpy(a[i+1],a[i]);
			i--;
		}
		strcpy(a[i+1],key);
	}
	j = q;
}

void find_medians(char a[][40],int p,int q)
{
	int i=0, j=p;
	do
	{
		if(q-j+1<5) 
  		{
		  	insertion_sort(a,j+1,q);
			strcpy(med[i],a[(q+j)/2]);
			break;
		}
		insertion_sort(a,j,j+4);
		strcpy(med[i],a[j+2]);
		i++;		
		j=j+5;
	}while(j<=q);
}

char* get_mom(char a[][40], int p, int q)
{
	if(p==q) 
		return(med[0]); 
	find_medians(a, p, q);
	get_mom(med, 0, ((q-p)/5));
}

int partition(char arr[][40],int p,int q,char *mom)
{
	int i,j;
	char temp[40];
	i=p-1;
	for(j=p;j<=q;j++)
	{
		if(strcmp(arr[j],mom)<0)
		{
			i+=1;
			strcpy(temp,arr[j]);
			strcpy(arr[j],arr[i]);
			strcpy(arr[i],temp);
		}
		else if(strcmp(arr[j],mom)==0)
		{
			strcpy(arr[j],arr[q]);
			strcpy(arr[q],mom);
		}
		
	}
	strcpy(temp,arr[i+1]);
	strcpy(arr[i+1],arr[q]);
	strcpy(arr[q],temp);
	return(i+1);	
}

char* select(char a[][40],int p,int q,int t)
{
	int k, num;
	char mom[40];
	strcpy(mom, get_mom(a, p, q));	
	if(p==q) 
		return(a[p]);
	k=partition(a, p, q, mom);
	num=k-p+1;
	if(num==t) 
		return(a[k]);
	else if(t < num)
 		return (select(a, p, k-1, t));
	else
	 	return (select(a, k+1, q, t-num));
}

int main()
{
	FILE *f;
	char b[50][40];
	int i=0, s, k=0;
	char *r;
	f = fopen("random.txt","r");
	while(fgets(b[i], 40, f)!=NULL)
		i++;
	s=i;
	while(k>=0 && k<=s)
	{
		do
		{
			printf("\nEnter K [To find Kth largest word; Enter -ve to exit] : ");
			scanf("%d", &k);
			if(k>s)
				printf("\nK is greater than number of words in file. Please re-enter K.\n");
			if(k<0)
				return 0;
		}while(k>s);
		r=select(b, 0, s-1, s-k+1);
		printf("\nThe %d largest word is %s", k, r);
	}
	return 0;
}	



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int *, int);
void insertionsort(int *, int);
void quicksort(int *, int, int);
int partition(int *, int, int);
void merge(int *, int, int, int, int, int *);
void mergesort(int *, int, int, int, int *);
void run(int);

int main()
{
	int i, a[8]={100,1000,5000,10000,25000,50000,100000,500000};
	printf("\nN\tBubble Sort\tInsertion Sort\tQuick Sort\tMerge Sort"); 
	for(i=0; i<8; i++)
		run(a[i]);
	return 0;
}

void bubblesort(int *arr, int n)
{
	int i, j, t;
	for(i=0; i<n; i++)
		for(j=0; j<n-1; j++)
			if(arr[j] > arr[j+1])
			{
				t = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = t;
			}
}

void insertionsort(int *arr, int n)
{
	int i, j, t;
    	for(i=1; i<n; i++) 
    	{
   			j=i;
    		while (j>0 && (arr[j]<arr[j-1])) 
			{
        		t = arr[j];
         		arr[j] = arr[j-1];
         		arr[j-1] = t;
         		j--;
     		}
    	}
}

void quicksort(int *arr, int l, int r)
{
	int i;
   	if(l < r) 
   	{
   		i = partition(arr, l, r);
       		quicksort(arr, l, i-1);
       		quicksort(arr, i+1, r);
   	}
}

int partition(int *arr, int l, int r) 
{
	int p, i, j, t;
   	p = arr[l];
   	i = l; 
	j = r+1;
	while(1)
   	{
   		do 
			++i; 
		while((arr[i]<=p) && (i<=r));
   		
		do 
			--j; 
		while(arr[j]>p);
   		
		if( i >= j ) 
			break;
   		
		t = arr[i]; 
		arr[i] = arr[j]; 
		arr[j] = t;
   	}
   	t = arr[l]; 
	arr[l] = arr[j]; 
	arr[j] = t;
   	return j;
}

void merge(int *arr, int l, int r, int mid,int n,int * c)
{          
	int i, j, k;
        i=l;
        j=mid+1;
        k=l;
        while((i<=mid)&&(j<=r))
        {
        	if(arr[i]<arr[j])
           	{
               		c[k]=arr[i];
               		k++;
               		i++;
           	}
           	else
           	{
              		c[k]=arr[j];
              		k++;
              		j++;
           	}
     	}
        
	while(i<=mid)
        {
        	c[k]=arr[i];
                k++;
                i++;
        }
        
	while(j<=r)
        {
                c[k]=arr[j];
                k++;
                j++;
        }
        
	for(i=l;i<k;i++)
        	arr[i]=c[i];
          
} 

void mergesort(int *arr, int l, int r,int n, int *c)
{
	int mid;
 	if(l<r)
 	{
        	mid=(l+r)/2;
          	mergesort(arr,l,mid,r,c);
          	mergesort(arr,mid+1,n,r,c);
          	merge(arr,l,r,mid,r,c);
 	}
}

void run(int size)
{
	int *arr, *b, n, i, *copy;
	clock_t start, end;
	n = size;
	arr=(int*)(malloc(n*sizeof(int)));
	copy=(int*)(malloc(n*sizeof(int)));
	int *c = malloc (n*sizeof(int));
    	
	for(i=1;i<=n;i++)
        	*(arr+i-1) = rand() % 100000;
        
	for(i=1;i<=n;i++)
	        *(copy+i-1) = *(arr+i-1);
        
        printf("\n%d\t", n);
        start = clock();
        bubblesort(copy,n);
	end = clock();
	printf("%5.10f\t", (double)(end - start) / CLOCKS_PER_SEC);
        
	for(i=1;i<=n;i++)
        	*(copy+i-1)=*(arr+i-1);
        
        start = clock();
        insertionsort(copy,n);
        end = clock();
        printf("%5.10f\t", (double)(end - start) / CLOCKS_PER_SEC);
         
	for(i=1;i<=n;i++)
        	*(copy+i-1)=*(arr+i-1);
          
        start = clock();
        quicksort(copy,0,n);
	end = clock();
        printf("%5.10f\t", (double)(end - start) / CLOCKS_PER_SEC);
         
	for(i=1;i<=n;i++)
        	*(copy+i-1)=*(arr+i-1);
         
        start = clock();
        mergesort(copy,0,n-1,n,c);
	end = clock();
        printf("%5.10f\t", (double)(end - start) / CLOCKS_PER_SEC);
}

        
        

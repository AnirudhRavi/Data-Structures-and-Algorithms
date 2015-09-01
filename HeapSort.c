#include <stdio.h>

void SortHeap(int[], int);

int main()
{
	int i, j, a[10], b[100];
	for(i=0;i<10;i++)
		a[i] = rand() % 1000;
	//Calls SortHeap function for (Size - 2) times.
	for(i=10; i>1; i--)
		SortHeap(a, i - 1);
	printf("\nThe Sorted Array a[10]\n----------------------\n");
	for (i = 0; i < 10; i++)
		printf("%d\t",a[i]);
	for(i=0;i<100;i++)
		b[i] = rand() % 1000;
	//Calls SortHeap function for (Size - 2) times.
	for(i=100; i>1; i--)
		SortHeap(b, i - 1);
	printf("\n\nThe Sorted Array b[100]\n-----------------------\n");
	for(i = 1; i <= 100; i++)
	{
		printf("%d\t",b[i-1]);
		if(i%10 == 0 )
			printf("\n");
	}
	printf("\n");
	return 0;
}

void SortHeap(int arr[], int ub)
{
	int i, j;
	int l, r, m, rt, t;
	//Find the root element of the current element
	rt = (ub-1)/2;
	//Create the heap
	for(i=rt;i>=0;i--)
		for(j=i;j>=0;j--)
 		{
			l = (2*j)+1;
			r = (2*j)+2;
			if ((l <= ub) && (r <= ub))
			{
 				if(arr[r] >= arr[l])
					m = r;
 				else
					m = l;
			}
			else
			{
 				if(r > ub)
					m = l;
 				else
					m = r;
			}
			//Swap elements
			if (arr[j] < arr[m])
			{
 				t = arr[j];
 				arr[j] = arr[m];
 				arr[m] = t;
			}
 		}
	//Move the max element to the end of the array
	t = arr[0];
	arr[0] = arr[ub];
	arr[ub] = t;
	return;
}

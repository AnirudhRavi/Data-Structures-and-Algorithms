#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point
{
	int x;
	int y;
};

int partition(struct point a[],int low,int high)
{	
	int xx,yy;
	xx=a[high].x;
	yy=a[high].y;
	int k,p;
	struct point temp;
	p=low-1;
	for(k=low;k<high;k++)
	{
		if(a[k].x<=xx)
		{
			p=p+1;
			temp=a[k];
			a[k]=a[p];
			a[p]=temp;
		}
	}
	a[high]=a[p+1];
	a[p+1].x=xx;
	a[p+1].y=yy;
	return p+1;
}

void quickSort(struct point a[],int low,int high)
{	
	if(low<high)
	{
		int x;
		x=partition(a,low,high);
		quickSort(a,low,x-1);
		quickSort(a,x+1,high);
	}	
}


float distance(struct point p1,struct point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y-p2.y)*(p1.y-p2.y));      
}

float minimum_distance(struct point p[],int n,struct point *p1,struct point *p2)
{
	p1->x = p[0].x;
	p1->y = p[0].y;
	p2->x = p[1].x;
	p2->y = p[1].y;
	float min = distance(p[0],p[1]);
	int i = 0,j = 0;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(min>distance(p[i],p[j]))
			{
				p1->x = p[i].x;
				p1->y = p[i].y;
				p2->x = p[j].x;
				p2->y = p[j].y;
				min = distance(p[i],p[j]);
			}
	return min;
}
 

float minimum(float x,float y)
{
	if(x<=y)
		return x;
	else
		return y;
}

float recursive(struct point p[],int n,struct point *p1,struct point *p2)
{
	if(n <= 3)
		minimum_distance(p,n,p1,p2);
	else
	{
		int i;
		int mid;		
		mid = n/2;
		float dleft = recursive(p,mid,p1,p2);
		float dright = recursive(p+mid,n-mid,p1,p2);
												
		float d;
		d = minimum(dleft,dright);
												
		int j;
		j = 0;
		int sizeleft = n/2;
		struct point left[sizeleft];
		for(i =0;i<n/2;i++)
			if(abs(p[i].x - p[mid-1].x) <= d)
			{
				left[j] = p[i];
						       					
				j++;
			}
		sizeleft = j;
												
		j = 0;
		int sizeright;
		
		if(n%2 == 0)
			sizeright = n/2;
		else
			sizeright = n/2+1;
		
		struct point right[sizeright];
		for(i =n/2;i<n;i++)
			if(abs(p[i].x - p[mid-1].x) <= d)
			{
				right[j] = p[i];
							  				
				j++;
			}
		sizeright = j;
		
		float median_minimum = d;
		for(i=0;i<sizeleft;i++)
		{
			int yc = left[i].y;
			for(j = 0;j<sizeright;j++)
				if(right[j].y >= yc-d && right[j].y <= yc+d)
				{
					if(distance(left[i],right[j]) < median_minimum)
					{
						p1->x = left[i].x;
						p1->y = left[i].y;
						p2->x = right[j].x;
						p2->y = right[j].y;
						median_minimum = distance(left[i],right[j]);
					}							
				}
		}
		d = median_minimum;													
		return median_minimum;
	}	
}

main()
{
	int n;
	struct point p[] ={{2,3},{12,30},{40,50},{5,1},{12,10},{3,4},{2,4}};
	int i;	
	n = sizeof(p)/sizeof(p[0]);
	quickSort(p,0,n-1);
	for(i = 0;i<n;i++)
		printf("%d %d\n",p[i].x,p[i].y);
	printf("\n");
	struct point *p1,*p2;
	p1 = (struct point *)malloc(sizeof(struct point));
	p2 = (struct point *)malloc(sizeof(struct point));
	printf("Closest Distance [D & C Algorithm]  = %f\n", recursive(p,n,p1,p2));
	printf("Closest Distance [O(n^2) Algorithm] = %f\n", minimum_distance(p,n,p1,p2));
	printf("Closest pair - (%d,%d) -> (%d,%d)\n",p1->x,p1->y,p2->x,p2->y);
}

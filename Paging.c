#include <stdio.h>
struct page
{
	int n;
	int p[50];
};
int frame[100] = {0};
int nof;

int no_free_frames()
{
	int i, count = 0;
	for (i = 0; i < nof; i++)
	{
		if (frame[i] == 0)
		{
			count++;
		}
	}
	return count;
}


void main()
{
	
	int mem_size,frame_size,nop,i,j,y,pno,z,frame1,temp,k,l;
	struct page process[50];
	printf("\nEnter the main memory size in bytes:");
	scanf("%d", &mem_size);
	printf("\nEnter the page size/frame size:");
	scanf("%d", &frame_size);
	
	nof = mem_size / frame_size;
	
	printf("%d frames are present in main memory and let them be numbered from 0 to %d", nof, nof - 1);
	printf("\nEnter the number of processes:");
	scanf("%d", &nop);
	
	for (i = 0; i < nop; i++)
	{
		printf("\nEnter the number of pages for process %d:", i);
		scanf("%d", &process[i].n);
	}
	for (i = 0; i < nop; i++)
	{
		for (j = 0; j < process[i].n; j++)
		{
			x:
			if (process[i].n > nof)
			{
				printf("Only %d frames are available! This process cannot be allocated!", nof);
				for (j = 0; j < process[i].n; j++)
				{
					process[i].p[j] = -1;
				}
				
				break;
			}
			printf("\nPage no %d of Process %d is allocated to which frame:", j, i);
			scanf("%d", &frame1);
			k = frame1;
			if (frame[k] == 0 && frame1 < nof)
			{
				frame[k] = 1;
				process[i].p[j] = frame1;
			}
			
			else
			{
				if (frame1 >= nof)
				{
					printf("\n\t Error! %d is out of bound of frame.",frame1);
				}
				printf("\nAlready Allocated Frame:");
				y = no_free_frames();
				printf("\nNumber of free frames: %d", y);
				printf("\nThe free frames are: ");
				int o;
				for (o = 0; o < nof; o++)
				{
					if (frame[o] == 0)
					{
						printf("%d ", o);
					}
				}
				if (y == 0 || y < process[i].n)
				{
					printf("\nNo enough frames are free to be allocated to this process!");
					printf("\nEnter the process to be terminated:");
					scanf("%d", &pno);
					for (z = 0; z < process[pno].n; z++)
					{
						temp = process[pno].p[z];
						l = temp;
						frame[l] = 0;
						process[pno].p[z] = -1;
					}
					goto x;
				}
				else
				{
					goto x;
				}
			}
		}
	}
	
	printf("\n -----Page Table-----\n");
	for (i = 0; i < nop; i++)
	{
		printf("\n-----------------------------------");
		printf("\nPage no\t\tProcess No.\t\tFrame no");
		printf("\n-----------------------------------");
		for (j = 0; j < process[i].n; j++)
		{
			printf("\n%d\t\t%d\t\t%d", j,i, process[i].p[j]);
		}
	}
	printf("\n");
}

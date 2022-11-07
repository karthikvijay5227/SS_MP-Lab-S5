#include <stdio.h>
struct page
{
	int n; // No of Pages for each process
	int p[50];
};
int frame[100] = {0};
int nof;

int no_free_frames()
{
	int i, count = 0;
	for (int i = 0; i < nof; i++)
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

	int mem_size, frame_size, nopr, y, pno, z, frame1, temp, k, l;
	struct page process[50];
	printf("\nEnter the main memory size in bytes:");
	scanf("%d", &mem_size);
	printf("\nEnter the page size/frame size:");
	scanf("%d", &frame_size);

	nof = mem_size / frame_size;

	printf("\n%d frames are present in main memory and let them be numbered from 0 to %d", nof, nof - 1);
	printf("\n\nEnter the number of processes:");
	scanf("%d", &nopr);

	for (int i = 0; i < nopr; i++)
	{
		printf("\nEnter the number of pages for process %d:", i);
		scanf("%d", &process[i].n);
	}
	for (int i = 0; i < nopr; i++)
	{
		for (int j = 0; j < process[i].n; j++)
		{
		x:
			if (process[i].n > nof) //If no of pages > no of frames
			{
				printf("Only %d frames are available! This process cannot be allocated!", nof);
				for (int j = 0; j < process[i].n; j++)
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
				if (frame1 >= nof) //If user enters frame_no greater than avail no of frames
				{
					printf("\n\t Error! %d is out of bound of frame.", frame1);
				}
				y = no_free_frames();
				printf("\nNumber of free frames: %d", y);
				printf("\nThe free frames are: ");
				for (int o = 0; o < nof; o++)
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
	for (int i = 0; i < nopr; i++)
	{
		printf("\n----------------------------------------");
		printf("\nPage no\t\tProcess No.\tFrame no");
		printf("\n----------------------------------------");
		for (int j = 0; j < process[i].n; j++)
		{
			printf("\n%d\t\t%d\t\t%d", j, i, process[i].p[j]);
		}
	}
	printf("\n");

	printf("\n**** -1 indicates Not Allocated\n\n");

	printf("\n -----Frame Table-----\n");
	printf("\n-----------------------------------------");
	printf("\nFrame no\tPage No.\tProcess no");
	printf("\n-----------------------------------------\n");
	int framear[50], pagear[50], processar[50], ab = 0;
	for (int i = 0; i < nof; i++)
	{
		for (int j = 0; j < process[i].n; j++)
		{
			if (process[i].p[j] != -1)
			{
				framear[ab] = process[i].p[j];
				pagear[ab] = j;
				processar[ab++] = i;
			}
		}
	}

	int tempf, pos;
	for (int i = 0; i < ab; i++)
	{
		pos = i;
		for (int j = i + 1; j < ab; j++)
		{
			if (framear[j] < framear[pos])
				pos = j;
		}
		tempf = framear[i];
		framear[i] = framear[pos];
		framear[pos] = tempf;

		tempf = pagear[i];
		pagear[i] = pagear[pos];
		pagear[pos] = tempf;

		tempf = processar[i];
		processar[i] = processar[pos];
		processar[pos] = tempf;
	}

	for (int i = 0; i < ab; i++)
	{
		printf("%d\t\t%d\t\t%d\n", framear[i], pagear[i], processar[i]);
	}
}

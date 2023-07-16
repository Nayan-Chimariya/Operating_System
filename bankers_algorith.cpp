#include <stdio.h>
int main()
{
	int n, r, i, j, k;
	int alloc[10][10], Max[10][10], avail[10];
	printf("Enter number of processes: ");
	scanf("%d",&n);

	printf("Enter number of resources: ");
	scanf("%d",&r);

    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("For process p[%d]\n",i+1);
        for(j=0;j<r;j++)
	  	{
	  		printf("Enter Allocation |%d|: ",j+1);
	  		scanf("%d",&alloc[i][j]);
		}
		printf("\n");
    }

    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("For process p[%d]\n",i+1);
        for(j=0;j<r;j++)
	  	{
	  		printf("Enter Max |%d|: ",j+1);
	  		scanf("%d",&Max[i][j]);
		}
		printf("\n");
    }

    for(i=0;i<r;i++)
    {
        printf("Enter available resources |%d|: ",i+1);
        scanf("%d",&avail[i]);
    }

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++)
    {
		f[k] = 0;
	}

	int need[n][r];
	for (i = 0; i < n; i++)
    {
		for (j = 0; j < r; j++)
			need[i][j] = Max[i][j] - alloc[i][j];
	}

	int y = 0;
	for (k = 0; k < 5; k++)
    {
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{
				int flag = 0;
				for (j = 0; j < r; j++)
				{
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0)
                {
					ans[ind++] = i;
					for (y = 0; y < r; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	printf("\nThe SAFE Sequence is as follows\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);

	return (0);
}


#include<stdio.h>
int main()
{
    int alloc[10][10], request[10][10], avail[10], work[10], n, m, i, j,k, true=1, false=0, finish[n];
    printf("Enter number of processes: \n");
    scanf("%d",&n);

    printf("Enter number of resources: \n");
    scanf("%d",&m);

    printf("Enter allocation: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter request: \n");
    for(i=0; i<n; i++)
        {
                for(j=0; j<m; j++)
                {
                        scanf("%d", &request[i][j]);
                }
        }

    printf("Enter available: \n");
    for(i=0; i<m; i++)
    {
        scanf("%d", &avail[i]);
    }

    for(i=0; i<n; i++)
    {
                   finish[i]=false;
        }

    for(i=0; i<m; i++)
        {
                work[i]=avail[i];
        }





   for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            k=0;
            if(finish[i]==false && request[i][k]<=work[k] && request[i][k+1]<=work[k+1] && request[i][k+2]<=work[k+2])
            {
                    work[k]+=alloc[i][k];
                    work[k+1]+=alloc[i][k+1];
                    work[k+2]+=alloc[i][k+2];
                    finish[i]=true;
            }
        }
    }

    for(i=0; i<n; i++)
    {
            if(finish[i]==false)
            {
                printf("Deadlock detected! \n");
            }
            else
            {
                printf("No deadlock! \n");
            }
    }
}

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
		int bt[10],tat[10],wt[10],p[10];
		int temp,i,j,pos,total=0,n;
		float avg_wt=0,avg_tat=0;
		printf("Enter the number of processes : ");
		scanf("%d",&n);
		printf("Enter the process id : ");
		for(i=0;i<n;i++)
		{
				scanf("%d",&p[i]);
		}
		printf("Enter the burst times : ");
		for(i=0;i<n;i++)
		{
				scanf("%d",&bt[i]);
		}
		for(i=0;i<n-1;i++)
		{
			pos=i;
			for(j=i+1;j<n;j++)
			{
					if(bt[j]<bt[pos])
					{
							pos=j;
					}
			}
						temp=bt[i];
						bt[i]=bt[pos];
						bt[pos]=temp;
						temp=p[i];
						p[i]=p[pos];
						p[pos]=temp;
		}
		wt[0]=0;
		for(i=1;i<n;i++)
		{
				wt[i]=wt[i-1]+bt[i-1];
				total=total+wt[i];
		}
		avg_wt=(float)total/n;
		total=0;
		printf("Process\tB.T\tT.A.T\tW.T\n");
		for(i=0;i<n;i++)
		{
				tat[i]=bt[i]+wt[i];
				total=total+tat[i];
				printf("%d\t%d\t%d\t%d\n",p[i],bt[i],tat[i],wt[i]);
	}
		avg_tat=(float)total/n;
		printf("Average Turnaround Time : %f\n",avg_tat);
		printf("Average Waiting Time : %f\n",avg_wt);
		return 0;
}
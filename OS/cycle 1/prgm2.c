// SJF Preemptive
#include<stdio.h>
typedef struct Process
{
	int AT;
	int BT;
	int Pid;
	int remT;
	int CT;
	int TAT;
	int RT;
	int WT;
}Process;
void SJFP(Process p[],int n)
{
	float avgWT,avgTAT,avgRT;
	int totalWT=0,totalTAT=0,totalRT=0;
	int proTrack[100],timeProgress[100];
	int remprocess=n;
	int elapTime=0;
	int j=-1,k=-1;
	timeProgress[++j]=0;
	while(remprocess)
	{
		int exec=-1;
		int sBT=9999;
		// For loop selects the process with shortest remaining time
		for(int i=0;i<n;i++)
		{
			if(p[i].AT <= elapTime && p[i].remT > 0)
			{
				if(p[i].remT < sBT)
				{
					sBT=p[i].remT;
					exec=i;
				}
			}
		}
		// exec stores the value of current process
		// if exec is -1 no process is selected 
		if(exec==-1)
		{
			proTrack[++k]=0;
			elapTime++;
			timeProgress[++j]=elapTime;
			continue;
		}
		if(p[exec].remT == p[exec].BT)
		{
			p[exec].RT=elapTime-p[exec].AT;
		}
		p[exec].remT--;
		elapTime++;
		proTrack[++k]=p[exec].Pid;
		timeProgress[++j]=elapTime;
		if(p[exec].remT==0)
		{
			p[exec].CT=elapTime;
			p[exec].TAT=p[exec].CT-p[exec].AT;
			p[exec].WT=p[exec].TAT-p[exec].BT;
			totalWT+=p[exec].WT;
			totalTAT+=p[exec].TAT;
			totalRT+=p[exec].RT;
			remprocess--;

		}
	}
	avgTAT=(float)totalTAT/n;
	avgWT=(float)totalWT/n;
	avgRT=(float)totalRT/n;
	printf("Observation Table\nPId\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].Pid,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
	}
	printf("\nGantt chart\n(P)--> idle time)\n");
	for(int i=0;i<=k;i++)
		printf("| p%d\t",proTrack[i]);
	printf("\n");
	for(int i=0;i<=j;i++)
		printf("%d\t",timeProgress[i]);
	printf("\n");
	printf("Average WT : %.2f\n",avgWT);
	printf("Average TAT : %.2f\n",avgTAT);
	printf("Average RT : %.2f\n",avgRT);

	
}
void main()
{
	int n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	Process p[n];
	printf("\nEnter the process details\n");
	for(int i=0;i<n;i++)
	{
		printf("Process : %d\n",i+1);
		printf("Enter the Arrival time : ");
		scanf("%d",&p[i].AT);
		printf("Enter the Burst time : ");
		scanf("%d",&p[i].BT);
		p[i].Pid=i+1;
		p[i].remT=p[i].BT;
	}
	SJFP(p,n);
}

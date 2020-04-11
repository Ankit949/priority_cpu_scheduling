#include<stdio.h>
#include<conio.h>
int main()
{
      int i,j, num,pos,t, total = 0, x, counter = 0, time_quantum,Atime=0;
      int waitingtime = 0, turnaroundtime = 0, p[10],arrivaltime[10], bursttime[10],Priority[10], temp[10],flag=0;
      float Avgwt, Avgtat;
      printf("\nEnter Total Number of Processes\t");
      scanf("%d", &num);
      x = num;
      for(i = 0; i < num; i++) //block1
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Priority \t");
            scanf("%d",&Priority[i]);
			printf("Arrival Time\t");
            scanf("%d", &arrivaltime[i]);
			printf("Burst Time\t");
			scanf("%d", &bursttime[i]);
			temp[i] = bursttime[i];
      }
 
      printf("nEnter Time Quantum:t");
      scanf("%d", &time_quantum);
      for(i=0;i<num;i++)// sorting the array based on priority
	{
		pos = i;
            for(j = i + 1; j < num; j++)
            {
                  if(Priority[j] > Priority[pos])
                  {
                        pos = j;
                  }
            }
            t = arrivaltime[i];                     //Swaping the Arival time
            arrivaltime[i] = arrivaltime[pos];
            arrivaltime[pos] = t; 
            t=Priority[i];                            //Swaping the priority 
            Priority[i]=Priority[pos];
            Priority[pos]=t;
            t=bursttime[i];                     //Swaping the Bursttime
            bursttime[i]=bursttime[pos];
            bursttime[pos]=t;
            t=p[i];                        // Swaping the process
            p[i]=p[pos];
            p[pos]=t;
            
	}
      
      for(total = 0, i = 0; x != 0;)//Block 2
      {
      	for(j=0;j<num;j++)//Block 3
      	{
		Atime=Atime+temp[i];
		if(Atime<=temp[j])
		{
			flag=1;
		}
		else{
			flag=0;
		}
	    }
	    if (flag==0)
	    {
	       if(temp[i] <= time_quantum && temp[i] > 0)
           {
               total = total + temp[i];
               temp[i] = 0;
               counter = 1;
           }
           else if(temp[i] > 0)
           {
               temp[i] = temp[i] - time_quantum;
               total = total + time_quantum;
           }
          if(temp[i] == 0 && counter == 1)
           {
               x--;
               printf("nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bursttime[i], total - arrivaltime[i], total - arrivaltime[i] - bursttime[i]);
               waitingtime = waitingtime + total - arrivaltime[i] - bursttime[i];
               turnaroundtime = turnaroundtime + total - arrivaltime[i];
               counter = 0;
            
		   }   
        
        
        if(i == num - 1)
        {
            i = 0;
        }
        else if(arrivaltime[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
        
    }
    else
    {
    	x--;
        printf("\nProcess[%d]", i + 1);
        waitingtime = 0;
        turnaroundtime = 0;
        counter = 0;
	}
    }
     printf("Gantt chart\n");
     for(i=0;i<num;i++)
     {
        printf("P[%d]",p[i]);
     }
 
      Avgwt = waitingtime * 1.0 / num;
      Avgtat = turnaroundtime * 1.0 / num;
      printf("\n\nAverage Waiting Time:\t%f", Avgwt);
      printf("\nAvg Turnaround Time:\t%fn", Avgtat);
      return 0;
      
      
}

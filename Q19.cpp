#include<stdio.h>
#include<conio.h>

int main()
{
	int student[10],num,n,i,j,k=1,s,ArivalTime[10],gifts[10],execute[10],t,pos,BillingTime[10],ready[10],time=0,maxgift;
	printf("Enter the no. of students :  ");
	scanf("%d",&num);
	printf("\nEnter the Arival time and number of gifts of each student:\n");
	for(i=0;i<num;i++)//Taking inputs for each parameter.  block 1
	{
		printf("student[%d]\n",i+1);
		printf("Arival time :");
		scanf("\t%d",&ArivalTime[i]);
		printf("No.of Gifts :");
		scanf("\t%d",&gifts[i]);
		printf("Total no. of time taken in billing:");
		scanf("\t%d",&BillingTime[i]);
		student[i]=i+1;
		printf("\n");
		
		
	}
	for(i=0;i<num;i++)// sorting the array based on Arival Time
	{
		pos = i;
            for(j = i + 1; j < num; j++)
            {
                  if(ArivalTime[j] < ArivalTime[pos])
                  {
                        pos = j;
                  }
            }
            t = ArivalTime[i];                     //Swaping the ArivalTime
            ArivalTime[i] = ArivalTime[pos];
            ArivalTime[pos] = t; 
            t=gifts[i];                            //Swaping the no. of gifts 
            gifts[i]=gifts[pos];
            gifts[pos]=t;
            t=BillingTime[i];                     //Swaping the Billing time
            BillingTime[i]=BillingTime[pos];
            BillingTime[pos]=t;
            t=student[i];                        // Swaping the student
            student[i]=student[pos];
            student[pos]=t;
            
	}
	printf("Student\t\tArivalTime\tgifts\t\tBillingTime\n");
	for(i=0;i<num;i++) // Printing the array after swaping    
	{
		printf(" %d\t\t%d\t\t%d\t\t%d\n",student[i],ArivalTime[i],gifts[i],BillingTime[i]);
	}
	
	printf("\nstudent[%d]\n",student[0]); // The Stdent arrived first will get the cpu first 
	time=time+BillingTime[0];
	maxgift=gifts[0];
	for(i=0;i<num;i++)      //  Checking the priority of student arrived till the billing of first one completes. 
	{
		
	   	for(j=1;j<num;j++)
	   	{   
	   		if(BillingTime[j]<=time && gifts[j]>maxgift)
	   		{
	   			maxgift=gifts[j];
	   			s=j;
	   			time=time+BillingTime[i];
			}
			
			
		}
		
	}
	execute[i]=k;
	printf("student[%d]\n",execute[i]);
	for(i=2;i<=num;i++)                    // Swaping the student based on their priority i.e no. of gifts. 
	 	{
		pos = i;
            for(j = i + 1; j < num; j++)
            {
                  if(gifts[j] > gifts[pos])
                  {
                        pos = j;
                  }
            }
            
            t=gifts[i];
            gifts[i]=gifts[pos];
            gifts[pos]=t;
            t=student[i];
            student[i]=student[pos];
            student[pos]=t;
            
    }
    for(i=2;i<num;i++) // Printing the order of billing of students.
	{
		printf("student[%d]\n",student[i]);
	}
	
}

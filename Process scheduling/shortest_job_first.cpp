#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int burst_time[10], waiting_time[10], turnaround_time[10];
  int number_of_processes,i,j;
  int total_wait=0, total_turnaround=0;
  int avg_wait=0,avg_turnaround=0;
  int temp1,temp2,processes[10];

  cout<<"Enter number of processes: ";
  cin>> number_of_processes;

  cout<<"\n";

  //storage of burst time
  for(i=0;i<number_of_processes;i++)
  {
      cout<<"Burst time for process "<<i+1 <<" :";
      cin>>burst_time[i];
      processes[i]=i+1;
  }

  //finding the shortest job, using ascending order sort

  for(i=0;i<number_of_processes;i++)
  {
      for(j=i+1;j<number_of_processes;j++)
      {
          if(burst_time[j]<burst_time[i])
          {
              temp2=processes[i];
              processes[i]= processes[j];
              processes[j]=temp2;

              temp1=burst_time[i];
              burst_time[i]=burst_time[j];
              burst_time[j] = temp1;
          }
      }
  }

  //calculation of waiting time,turnaround time
  //total wait time and total turnaround time
  waiting_time[0]=0;
  for(i=0;i<number_of_processes;i++)
  {
      waiting_time[i+1]=burst_time[i]+waiting_time[i];
      turnaround_time[i]=burst_time[i]+waiting_time[i];
      total_wait+=waiting_time[i];
      total_turnaround+=turnaround_time[i];
  }

  avg_wait=total_wait/number_of_processes;
  avg_turnaround=total_turnaround/number_of_processes;

  cout<< "\nProcesses" <<setw(15) <<"Burst Time" <<setw(17) << "Waiting Time" <<setw(20)<< "Turnaround Time" <<"\n";

  for(i=0;i<number_of_processes;i++)
  {
      cout<< "P["<<processes[i]<<"]" <<setw(15) <<burst_time[i] <<setw(17) << waiting_time[i] <<setw(20)<< turnaround_time[i] <<"\n";
  }

  cout<<"\n" <<"Average wait time= " <<avg_wait <<"\n" <<"Average Turnaround time= " <<avg_turnaround <<"\n";
  return 0;
}



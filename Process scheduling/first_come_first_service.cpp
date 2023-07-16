#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int burst_time[10], waiting_time[10], turnaround_time[10];
  int number_of_processes,i;
  int total_wait=0, total_turnaround=0;
  int avg_wait=0,avg_turnaround=0;

  cout<<"Enter number of processes: ";
  cin>> number_of_processes;

  cout<<"\n";

  //storage of burst time
  for(i=0;i<number_of_processes;i++)
  {
      cout<<"Burst time for process "<<i+1 <<" :";
      cin>>burst_time[i];
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
      cout<< "P["<<i<<"]" <<setw(15) <<burst_time[i] <<setw(17) << waiting_time[i] <<setw(20)<< turnaround_time[i] <<"\n";
  }

  cout<<"\n" <<"Average wait time= " <<avg_wait <<"\n" <<"Average Turnaround time= " <<avg_turnaround <<"\n";
  return 0;
}


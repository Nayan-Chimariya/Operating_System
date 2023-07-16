#include<iostream>

using namespace std;
int main()
{
    int arrival_time[10],burst_time[10],x[10];
    int waiting[10],turnaround[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

    cout<<"Enter the number of Processes: ";
    cin>>n;

    cout<< "\n";
    for(i=0; i<n; i++)
    {
        cout<<"Enter arrival time of process["<<i+1<<"]: ";
        cin>>arrival_time[i];
    }

    cout<< "\n";
    for(i=0; i<n; i++)
    {
        cout<<"Enter burst time of process["<<i+1<<"]: ";
        cin>>burst_time[i];
    }

    for(i=0; i<n; i++)
        x[i]=burst_time[i];

    burst_time[9]=9999;

    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(arrival_time[i]<=time && burst_time[i]<burst_time[smallest] && burst_time[i]>0 )
                smallest=i;
        }
        burst_time[smallest]--;

        if(burst_time[smallest]==0)
        {
            count++;
            end=time+1;
            waiting[smallest] = end - arrival_time[smallest] - x[smallest];
            turnaround[smallest] = end - arrival_time[smallest];
        }
    }

    cout<<"\nProcess"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time = "<<avg/n <<endl;
    cout<<"  Average Turnaround time = "<<tt/n<<endl;
}

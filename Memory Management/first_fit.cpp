#include<bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m,int processSize[], int n)
{
    int allocation[n];

    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int blockSize[20],processSize[20];
    int i,m,n;

    /*int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};*/
    cout<< "Enter numbers of blocks: ";
    cin>> m;
    cout<<"\n";

    for(i=0;i<m;i++)
    {
        cout<<"Enter size for block " <<i+1 <<" : ";
        cin>> blockSize[i];
    }
    cout<< "\nEnter numbers of processes: ";
    cin>> n;
    cout<<"\n";

    for(i=0;i<n;i++)
    {
        cout<<"Enter size for process " <<i+1 <<" : ";
        cin>> processSize[i];
    }

    firstFit(blockSize, m, processSize, n);

    return 0 ;
}

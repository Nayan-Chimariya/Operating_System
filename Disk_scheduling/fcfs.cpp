#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int numRequests, initialPosition;
    cout << "Enter the number of disk requests: ";
    cin >> numRequests;
    cout << "Enter the initial position of the disk head: ";
    cin >> initialPosition;

    vector<int> requests(numRequests);
    cout << "Enter the disk requests: ";

    for (int i = 0; i < numRequests; i++)
    {
        cin >> requests[i];
    }

    int totalHeadMovements = 0;

    int currentPosition = initialPosition;
    for (int i = 0; i < numRequests; i++)
    {
        totalHeadMovements += abs(currentPosition - requests[i]);
        currentPosition = requests[i];
    }

    cout << "Total head movements: " << totalHeadMovements << endl;
    return 0;
}


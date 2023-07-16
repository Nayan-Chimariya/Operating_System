#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numRequests, initialPosition, maxTrack;
    cout << "Enter the number of disk requests: ";
    cin >> numRequests;
    cout << "Enter the initial position of the disk head: ";
    cin >> initialPosition;
    cout << "Enter the maximum track of the disk: ";
    cin >> maxTrack;

    vector<int> requests(numRequests);
    cout << "Enter the disk requests: ";

    for (int i = 0; i < numRequests; i++)
    {
        cin >> requests[i];
    }

    requests.push_back(initialPosition);

    sort(requests.begin(), requests.end());

    int initialIndex = 0;
    while (requests[initialIndex] < initialPosition)
    {
        initialIndex++;
    }

    int totalHeadMovements = 0;

    for (int i = initialIndex; i < requests.size() - 1; i++)
    {
        totalHeadMovements += abs(requests[i] - requests[i + 1]);
    }

    for (int i = initialIndex; i > 0; i--)
    {
        totalHeadMovements += abs(requests[i] - requests[i - 1]);
    }

    cout << "Total head movements: " << totalHeadMovements << endl;

    return 0;
}


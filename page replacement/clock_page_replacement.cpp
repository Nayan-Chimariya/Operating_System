#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Page
{
    int id;
    bool referenced;
};

int main()
{

    int pageSize, frameSize, numPages;
    cout << "Enter frame size: ";
    cin >> frameSize;
    cout << "Enter the number of pages: ";
    cin >> numPages;

    vector<Page> pages(numPages);
    unordered_set<int> frameSet;
    queue<int> frameQueue;

    cout << "Enter the page IDs: ";
    for (int i = 0; i < numPages; i++)
    {
        cin >> pages[i].id;
        pages[i].referenced = false;
    }

    int pageFaults = 0;

    for (int i = 0; i < numPages; i++)
    {
        int pageId = pages[i].id;
        if (frameSet.find(pageId) == frameSet.end())
        {
            if (frameSet.size() == frameSize)
            {
                while (true)
                {
                    int frontPageId = frameQueue.front();
                    frameQueue.pop();
                    if (pages[frontPageId].referenced)
                    {
                        pages[frontPageId].referenced = false;
                        frameQueue.push(frontPageId);
                    } else
                    {
                        frameSet.erase(frontPageId);
                        break;
                    }
                }
            }
            frameSet.insert(pageId);
            frameQueue.push(pageId);
            pages[pageId].referenced = true;
            pageFaults++;
        }
        else
        {
            pages[pageId].referenced = true;
        }
    }

    cout << "Page Faults: " << pageFaults << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool isPossibleToSwitchOnBulbs(int n, vector<int> &bulbs)
{
    int count = 0;
    int consecutiveOff = 0;

    for (int i = 0; i < bulbs.size(); i++)
    {
        if (bulbs[i] == 0)
        {
            consecutiveOff++;
            if (consecutiveOff == 2)
            {
                count++;
                consecutiveOff = 0;
            }
        }
        else
        {
            consecutiveOff = 0;
        }
    }

    return (count >= n);
}

int main()
{
    int numBulbs;
    cout << "Enter the number of bulbs: ";
    cin >> numBulbs;

    vector<int> bulbs(numBulbs);
    cout << "Enter the state of bulbs (0 for off, 1 for on): ";
    for (int i = 0; i < numBulbs; i++)
    {
        cin >> bulbs[i];
    }

    int n;
    cout << "Enter the number of bulbs to switch on: ";
    cin >> n;

    bool possible = isPossibleToSwitchOnBulbs(n, bulbs);

    if (possible)
    {
        cout << "Possible to switch on " << n << " bulbs without having two adjacent bulbs switched on." << endl;
    }
    else
    {
        cout << "Not possible to switch on " << n << " bulbs without having two adjacent bulbs switched on." << endl;
    }

    return 0;
}

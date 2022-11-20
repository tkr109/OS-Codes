#include <iostream>
using namespace std;

int main()
{
    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 417, 112, 426};

    int allocation[4];

    int proc = 4;
    int blk = 5;

    for (int i = 0; i < proc; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < proc; i++)
    {
        for (int j = 0; j < blk; j++)
        {
            if (process[i] <= block[j])
            {
                allocation[i] = j;

                block[j] -= process[i];

                break;
            }
        }
    }

    cout << "Pid\t\tProcess\t\tBlock" << endl;
    for (int i = 0; i < proc; i++)
    {
        cout << i << "\t\t" << process[i] << "\t\t";
        if (allocation[i] == -1)
        {
            cout << "Not Allocated" << endl;
        }
        else
        {
            cout << allocation[i] + 1;
        }
        cout << endl;
    }
}
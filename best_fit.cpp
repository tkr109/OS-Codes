#include <iostream>
using namespace std;

int main()
{
    int process[] = {212, 417, 112, 426};
    int block[] = {100, 500, 200, 300, 600};

    int proc = 4;
    int blk = 5;

    int allocation[proc];

    for (int i = 0; i < proc; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < proc; i++)
    {
        int index = -1;

        for (int j = 0; j < blk; j++)
        {
            if (index == -1 and block[j] >= process[i])
            {
                index = j;
            }
            else if (block[index] > block[j] and block[j] >= process[i])
            {
                index = j;
            }
        }

        allocation[i] = index;
        if (index != -1)
            block[index] -= process[i];
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
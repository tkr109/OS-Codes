#include <iostream>
#include <algorithm>
using namespace std;

struct process
{
    int pid;
    int bt;
    int priority;
};

bool compare(process a, process b)
{
    return a.priority > b.priority;
}

int main()
{
    process proc[3] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};

    int n = 3;

    sort(proc, proc + n, compare);

    int wt[n];
    int tat[n];

    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + proc[i - 1].bt;
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }

    cout << "Pid"
         << "\t\t"
         << "BT"
         << "\t\t"
         << "WT"
         << "\t\t"
         << "TAT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << proc[i].pid << "\t\t" << proc[i].bt << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
}
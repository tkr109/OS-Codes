#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the  no of processes" << endl;
    cin >> n;

    int bt[n];
    int wt[n];
    int tat[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter bt of process [" << i << "] ";
        cin >> bt[i];
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << wt[i] << ' ' << tat[i] << endl;
    }
}
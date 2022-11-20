#include <iostream>
using namespace std;

bool isFinish(int *finish, int n)
{
    int a = true;

    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            a = false;
        }
    }

    return a;
}

int main()
{
    int n;
    cout << "Enter the number of processes" << endl;
    cin >> n;

    int time = 0, i = 0;
    int bt[n];
    int rem[n];
    int tat[n];
    int wt[n];
    int finish[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cout << "Enter bt of process[" << i << "] ";
        cin >> bt[i];
    }

    for (int i = 0; i < n; i++)
    {
        rem[i] = bt[i];
    }

    int tq;
    cout << "Enter time quantum" << endl;
    cin >> tq;

    while (!isFinish(finish, n))
    {
        if (rem[i] >= tq)
        {
            time = time + tq;
            rem[i] -= tq;
            if (rem[i] == 0)
            {
                wt[i] = time - bt[i];
                finish[i] = 1;
            }
        }
        else
        {
            if (finish[i] == 0)
            {
                time = time + rem[i];
                rem[i] = 0;
                wt[i] = time - bt[i];
                finish[i] = 1;
            }
        }
        i = (i + 1) % 3;
        // cout << i << endl;
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "p[" << i << "] " << bt[i] << ' ' << wt[i] << ' ' << tat[i] << endl;
    }
}
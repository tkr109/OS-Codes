#include <iostream>
using namespace std;

int main()
{
    int p = 5;
    int r = 3;
    int allocation[5][3] = {{0, 2, 1}, {3, 1, 0}, {0, 2, 1}, {4, 3, 2}, {1, 1, 0}};
    int max[5][3] = {{5, 7, 6}, {4, 2, 9}, {6, 7, 5}, {4, 10, 3}, {3, 1, 5}};
    int available[3] = {4, 4, 8};
    int need[5][3];

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int result[p];
    int finish[p] = {0};
    int index = 0;

    for (int m = 0; m < p; m++)
    {
        for (int i = 0; i < p; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < r; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    finish[i] = 1;
                    result[index++] = i;
                    for (int j = 0; j < r; j++)
                    {
                        available[j] += allocation[i][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < p; i++)
    {
        cout << result[i] << ' ';
    }
}
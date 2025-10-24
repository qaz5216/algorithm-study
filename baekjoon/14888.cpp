#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
vector<int> arr;
int oper[4]; // 3 4 2 1 0001111223
int rmin = 1000000000;
int rmax = -1000000000;
int n;
int test[10];

int cal()
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (test[i - 1] == 0)
        {
            result = result + arr[i];
        }
        else if (test[i - 1] == 1)
        {
            result = result - arr[i];
        }
        else if (test[i - 1] == 2)
        {
            result = result * arr[i];
        }
        else if (test[i - 1] == 3)
        {
            result = result / arr[i];
        }
    }
    return result;
}

void DFS(int idx, int start, int end)
{
    /*
    cout <<"oper: ";
         for(int i=0;i<4;i++){
            cout << oper[i]<<" ";
        }
        cout << " ,test ";
        for(int i=0;i<10;i++){
            cout << test[i]<<" ";
        }
        cout <<"\n";
        */
    if (start == end)
    {
        int tmp = cal();
        if (rmin > tmp)
            rmin = tmp;
        if (rmax < tmp)
            rmax = tmp;
    }
    for (int j = 0; j < 4; j++)
    {
        if (oper[j] > 0)
        {
            oper[j]--;
            test[start] = j;
            // cout << "dfs:"<<j<<","<<start+1<<","<<end<<"=";
            DFS(j, start + 1, end);
            oper[j]++;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }
    fill_n(test, 10, -1);
    DFS(0, 0, n - 1);
    cout << rmax << "\n"
         << rmin;
    return 0;
}
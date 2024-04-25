#include <iostream>
#include <vector>

using namespace std;

vector<string> arr;

int main()
{
    for(int i=0;i<5;i++)
    {
        string tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(arr[j].size()<=i) continue;
            cout<<arr[j][i];
        }
    }
    return 0;
}
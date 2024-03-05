#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr[1000];


int main()
{
    int t,tmp;
    cin >> t;
    for(int i=0;i<t;i++){
        for(int j=0;j<10;j++){
        cin >> tmp;
        arr[i].push_back(tmp);
        }
        sort(arr[i].begin(),arr[i].end());
    }
    for(int i=0;i<t;i++){
        cout << arr[i][7] << "\n";
    }
    return 0;
}
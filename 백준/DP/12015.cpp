#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1000001];


int main()
{
    int n,t,tmp,result=0;
    vector <int> arr;
    cin >> n;
    arr.push_back(-1);
    for(int i=1;i<=n;i++){
        cin >> t;
        if(t>arr.back())
            arr.push_back(t);
        else{
            auto it = lower_bound(arr.begin(),arr.end(),t);
            *it=t;
        }
    }
    
    cout << arr.size()-1;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ex[1000001];
int idx[1000001];
    vector <int> arr;
    vector <int> ans;


int main()
{
    int n,t,tmp,result=0;
    cin >> n;
    arr.push_back(-1e9 - 1);
    for(int i=0;i<n;i++){
        cin >> t;
        ex[i]=t;
        if(t>arr.back()){
            arr.push_back(t);
            idx[i]= arr.size()-1;
        }
        else{
            auto it = lower_bound(arr.begin(),arr.end(),t);
            *it=t;
            idx[i]=it -arr.begin();
        }
    }
    tmp= arr.size()-1;
    for(int i=n-1;i>=0;i--){
        if(idx[i]==tmp){
            tmp--;
            ans.push_back(ex[i]);
        }
    }
   reverse(ans.begin(), ans.end());
    
    cout << arr.size()-1 << '\n';
    for(int e : ans)
        cout << e << ' ';
    return 0;
}

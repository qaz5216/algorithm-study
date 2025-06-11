#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[100001];
stack<int> s;
vector<bool> ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cur=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=cur){
            for(;cur<=arr[i];cur++){
                s.push(cur);
                ans.push_back(true);
            }
            s.pop();
            ans.push_back(false);
        }
        else{
            if(!s.empty()){
                if(s.top()!=arr[i]){
                    flag=false;
                    break;
                }
                else{
                    s.pop();
                    ans.push_back(false);
                }
            }
            else{
                flag=false;
                break;
            }
        }
    }
    if(!flag) cout<<"NO";
    else{
        for(bool answer:ans){
            if(answer)cout<<"+\n";
            else cout<<"-\n";
        }
    }
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;
int arr[100001];
int lsum[100001];
int rsum[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('){
            arr[i]=1;
        }
        else{
            arr[i]=-1;
        }
    }
    lsum[0]=arr[0];
    rsum[s.size()-1]=arr[s.size()-1];
    for(int i=1;i<s.size();i++)
    {
        lsum[i]=lsum[i-1]+arr[i];
    }
    for(int i=s.size()-2;i>=0;i--)
    {
        rsum[i]=rsum[i+1]+arr[i];
    }
    if(lsum[s.size()-1]==-2){
        for(int i=0;i<s.size();i++)
        {
            if(arr[i]==-1)
            {
                cnt++;
            }
            if(lsum[i]==-1){
                break;
            }
        }
    }
    else if(lsum[s.size()-1] == 2){
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(arr[i]==1)
            {
                cnt++;
            }
            if(rsum[i]==1){
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
/*
    
*/
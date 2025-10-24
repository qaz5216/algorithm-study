#include <iostream>
#include <vector>
using namespace std;

bool visit[1000002];
vector<int> prime;
int n;

bool check(int x){
    string s=to_string(x);
    string a=s.substr(0,s.size()/2);
    
    for(int i=0;i<s.size()/2;i++){
        if(a[i]!=s[s.size()-1-i])return false;
    }
    return true;
}

int main()
{
    cin>>n;
    for(int i=2;i<=1000000;i++){
        for(int j=2;i*j<=1000000;j++){
            visit[i*j]=true;
        }
    }
    for(int i=2;i<=1000000;i++){
        if(visit[i]) continue;
        prime.push_back(i);
    }
    prime.push_back(1003001);
    for(int p:prime){
        if(p<n)continue;
        if(check(p)){cout<<p;return 0;}
    }
    return 0;
}
/*
소수해봐야 몇개나 된다고...


*/
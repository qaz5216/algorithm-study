#include <iostream>
#include <vector>
using namespace std;

bool isprime[1001];//false가 소수임
vector<int> prime;
int main()
{
    int t;
    cin>>t;
    for(int i=2;i<=34;i++){
        for(int j=i ; j*i<=1000; j++){
            isprime[i*j]=true;
        }
    }
    for(int i=2;i<=1000;i++){
        if(!isprime[i])prime.push_back(i);
    }
    while(t--)
    {
        int k;
        cin>>k;
        bool flag=false;
        for(int i=0;i<prime.size();i++)
        {
            if(flag) break;
            int a=prime[i];
            if(a>=k)continue;
            for(int j=i;j<prime.size();j++){
                if(flag) break;
                int b=prime[j];
                int find=k-a-b;
                if(find<2||find>1000)continue;
                if(!isprime[find]){
                    cout<<a<<' '<<b<<' '<<find<<'\n';
                    flag=true;
                }
            }
        }
        if(flag){
            continue;
        }
        cout<<0<<'\n';
    }
    return 0; 
}

/*
소수 해봐야 몇개나된다고
그냥 조합구하고 다돌려;;
168 c 3
*/
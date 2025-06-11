#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll T,N;

ll CUT=1e9+7;

vector <ll> ans;
ll jump(ll x)//x는 남은 거리
{
    if(x==1)
        return 2;
    ll k=jump(x/2)%CUT;
    if(x%2==0)
        return k%CUT*k%CUT;
    else
        return k%CUT*k%CUT*2%CUT;
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;
        if(N<=2)
        ans.push_back(1);
        else
        ans.push_back(jump(N-2));
    }
    for(ll answer:ans)
    {
        cout << answer << "\n";
    }
    return 0;
}
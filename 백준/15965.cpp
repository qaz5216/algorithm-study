#include <iostream>
#include <vector>

using namespace std;
bool dp[7500001]={false};
vector<int> sosu;
int K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    for(int i=2;sosu.size()<K;i++)
    {
        if (!dp[i])
        {
            sosu.push_back(i);
           for(int j=1;j*i<7500001;j++)
           {
                dp[i*j]=true;
           } 
        }
    }
    cout << sosu[K-1];
    return 0;

    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

bool visit[1001][1001];

int main()
{
	int test_case;
	int T;
	std::ios::sync_with_stdio(false);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		int n;
        cin>>n;
        int a[4];
        int b[4];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        memset(visit,false,sizeof(visit));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visit[i][j]&&a[i]==b[j])
                {
                    int tmp=0;
                    int aidx=i;
                    int bidx=j;
                    while(aidx<n&&bidx<n)
                    {
                        if(a[aidx]==b[bidx])
                        {
                            tmp+=1;
                            aidx++;
                            bidx++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    ans=max(tmp,ans);
                    for(int k=0;k<tmp;k++)
                    {
                        visit[i+k][j+k]=true;
                    }
                    j+=tmp;
                }
            }   
        }
		cout << "#" << test_case <<" "<<ans<<endl;
	}
	return 0; 
}
/*
#include <iostream>

using namespace std;


int main()
{
	int test_case;
	int T;
	std::ios::sync_with_stdio(false);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		int n;
        cin>>n;
        int dp[1001];
        int a[1001];
        int b[1001];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            dp[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i]==b[j])
                {
                    int tmp=0;
                    int aidx=i;
                    int bidx=j;
                    while(aidx<n&&bidx<n)
                    {
                        if(a[aidx]==b[bidx])
                        {
                            tmp+=1;
                            aidx++;
                            bidx++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    for(int k=tmp;k>0;k--)
                    {
                        dp[i+tmp-k]=max(dp[i+tmp-k],k);
                    }
                }
            }   
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
		cout << "#" << test_case <<" "<<ans<<endl;
	}
	return 0; 
}
*/
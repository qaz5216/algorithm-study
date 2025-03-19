#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int student[4][1001];//반,학생

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> sum;
    sum.resize(0);
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        int ans;
        int diff=1e9;
        cin>>k>>n;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<n;j++)
                cin>>student[i][j];   
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                sum.push_back(student[0][i]+student[1][j]);
            }
        }
        sort(sum.begin(),sum.end());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int tmp=student[2][i]+student[3][j];
                int l=0;int r=sum.size();
                while(l<r)
                {
                    int mid=(l+r)/2;
                    if(sum[mid]<k-tmp)
                    {
                        l=mid+1;
                    }
                    else
                    {
                        r=mid;
                    }
                }
                if(r==sum.size())
                {
                    r--;
                    if(abs(sum[r]+tmp-k)<diff)
                    {
                        ans=sum[r]+tmp;
                        diff=abs(k-ans);
                    }
                }
                else
                {
                    if(abs(sum[r]+tmp-k)<diff)
                    {
                        ans=sum[r]+tmp;
                        diff=abs(k-ans);
                    }

                    if(r>=1)
                    {
                        r--;
                        if(abs(sum[r]+tmp-k)<diff)
                        {
                            ans=sum[r]+tmp;
                            diff=abs(k-ans);
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

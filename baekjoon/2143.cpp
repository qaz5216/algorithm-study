#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t,n,m;
int A[1001];
int B[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long ans=0;
    cin>>t>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>B[i];
    }
    vector<int> asum,bsum;
    for (int i = 0; i < n; i++) {
		int sum = A[i];
		asum.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += A[j];
			asum.push_back(sum);
		}
	}
    for (int i = 0; i < m; i++) {
		int sum = B[i];
		bsum.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += B[j];
			bsum.push_back(sum);
		}
	}
    sort(bsum.begin(),bsum.end());
    for(int i=0;i<asum.size();i++)
    {
        int check=t-asum[i];
        int lo=0;
        int hi=0;
        int l=0;int r=bsum.size();
        while(l<r)
        {
            int mid=(l+r)/2;
            if(bsum[mid]<check)
            {
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        lo=r;
        l=0;r=bsum.size();
        while(l<r)
        {
            int mid=(l+r)/2;
            if(bsum[mid]<=check)
            {
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        hi=r;
        ans+=hi-lo;
    }
    cout<<ans<<'\n';
    return 0;
}
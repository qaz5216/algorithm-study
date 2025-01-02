#include <iostream>

using namespace std;

int arr[501];
int n,d,x;

int main()
{
	int test_case;
	int T;
	std::ios::sync_with_stdio(false);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
        cin>>n>>d>>x;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        int ans=n*arr[d];
        int cnt=x-d;
        ans+=cnt;
        if(d>x)
        {
            ans+=n;
        }
		// 표준출력(화면)으로 답안을 출력합니다.
		cout << "#" << test_case <<" "<<ans<<endl;
	}

	return 0;
}

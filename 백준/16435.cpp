#include <iostream>
#include <algorithm>
using namespace std;

int N,L;
int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>L;
    int x;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    for(int i=0;i<N;i++)
    {
        if(arr[i]<=L)L+=1;
    }
    cout<<L;
    return 0;
}
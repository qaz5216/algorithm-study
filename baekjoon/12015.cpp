// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int record[1000001];


// int main()
// {
//     int n,t,tmp,result=0;
//     vector <int> arr;
//     cin >> n;
//     arr.push_back(-1);
//     for(int i=1;i<=n;i++){
//         cin >> t;
//         if(t>arr.back())
//             arr.push_back(t);
//         else{
//             auto it = lower_bound(arr.begin(),arr.end(),t);
//             *it=t;
//         }
//     }
    
//     cout << arr.size()-1;
//     return 0;
// }

//이분탐색 직접해봐

#include <iostream>

using namespace std;

int N;
int arr[1000001];
int len=1;

int binaryfind(int s,int e,int value)
{
    if(s==e)
    {
        return s;
    }
    int mid=(s+e)/2;
    if(arr[mid]>=value)
    {
        return binaryfind(s,mid,value);
    }
    else
    {
        return binaryfind(mid+1,e,value);
    }
}

int main()
{
    cin>>N;
    cin>>arr[0];
    for(int i=1;i<N;i++)
    {
        int a;
        cin >> a;
        if(arr[len-1]<a)
        {
            arr[len]=a;
            len++;
        }
        else
        {
            int idx=binaryfind(0,len-1,a);
            arr[idx]=a;
        }
    }
    cout<<len;
    return 0;
}
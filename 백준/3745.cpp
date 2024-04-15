#include <iostream>

using namespace std;

int arr[100001];
int N;
int len;

int binarysearch(int s,int e,int value)
{
    if(s>=e){
        return s;
    }
    int mid=(s+e)/2;
    if(arr[mid]>=value)
    {
        return binarysearch(s,mid,value);
    }
    else
    {
        return binarysearch(mid+1,e,value);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> N)
    {
        cin >> arr[0];
        len=1;
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
                int idx=binarysearch(0,len-1,a);
                arr[idx]=a;
            }
        }
        cout<<len<<"\n";
    }
    return 0;
}
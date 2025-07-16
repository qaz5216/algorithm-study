#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int s = 0;
    int e = N - 1;
    int min = abs(arr[0] + arr[N - 1]);
    int tmp = arr[s] + arr[e];
    int anss = arr[s];
    int anse = arr[e];
    while (s < e)
    {
        tmp = arr[s] + arr[e];
        if (abs(tmp) < min)
        {
            anss = arr[s];
            anse = arr[e];
            min = abs(tmp);
        }
        if (tmp < 0)
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    cout << anss << " " << anse;
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;

int main(){
int n,t;
cin >> n;
for (int i=0;i<n;i++)
{
    cin >> t;
    arr.push_back(t);
}
sort(arr.begin(),arr.end());
int start=0,end=n-1;
long long min,tmp,ress,rese;
min = abs(arr[end]+arr[start]);
ress=arr[start];
rese=arr[end];
while(start<end){
tmp=arr[end]+arr[start];
if(abs(tmp)<min){
    ress=arr[start];
    rese=arr[end];
    min=abs(tmp);
}
if(tmp<0){
    start++;
}
else{
    end--;
    }
}
cout << ress << " " <<rese;
}
*/

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
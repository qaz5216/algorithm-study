#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int,int>> arr;


int main()
{
    int t,sum=0,tmp;
    for(int i=0;i<9;i++){
        cin >> t;
        arr.push_back(pair<int,int>(t,1));
        sum+=t;
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<9;i++){
        tmp=0;
        for(int j=i+1;j<9;j++){
            if(arr[i].first+arr[j].first==sum-100){
            arr[i].second=0;
            arr[j].second=0;
            for(int k=0;k<9;k++){
                if(arr[k].second==1){
                    cout<<arr[k].first<<"\n";
                }
            }
            return 0;
            }
        }
    }
    return 0;
}
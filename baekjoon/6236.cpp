#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector <int> arr;

int main(){
int n,m,t,k,max=0;
cin >> n >> m;
for(int i=0;i<n;i++){
    cin >> t;
    arr.push_back(t);
}
long long sum=0;
for(int i=0;i<n;i++){
    if(max<=arr[i])
        max=arr[i];
    sum+=arr[i];
}
long long mid,start=max,end=sum,num,tmp,rap=1;;
while(end-start>=0){
        mid=(start+end)/2;
        num=1;
        tmp=mid;
        for(int i=0;i<n;i++)
        {   
            if(tmp>=arr[i])
                tmp-=arr[i];
            else{
                num++;
                tmp=mid;
                tmp-=arr[i];
            }     
            
        }
        
        if(num>m){
            start=mid+1;
        }
        else{ 
            k=mid;
            end=mid-1;
        }
    }
cout << k;
return 0;
}
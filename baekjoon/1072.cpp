#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
long long mid,x,y,n,start=0,end;
cin >> x >> y;
int z=(100*y)/x;
end=x;
if(z>=99){
    cout << -1;
}
else{
    while(end-start>=0){
        mid=(start+end)/2;
        if(z==(100*(y+mid))/(x+mid)){
        n=mid+1;
        start=mid+1;
        }
        else
        end=mid-1;    
        }
        cout << n;
    }
    return 0;
}
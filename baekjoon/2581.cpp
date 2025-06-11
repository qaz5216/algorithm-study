#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;

int primecheck(int n){
    if(n<=1){
        return 0;
    }
    else{
        for(int i=2;i<n;i++){
            if((n%i)==0){
                return 0;
            }
        }
    }
    return 1;

}

int main()
{
    int m,n,sum=0,check=0,min;
    cin >> m>>n;
    min=n;
    for(int i=m;i<=n;i++){
        if(primecheck(i))
        {
            check=1;
            if(min>i)
            min=i;
            sum+=i;
        }
    }
    if(check==0){
        cout << -1;
    }
    else{
        cout<<sum<<"\n"<<min;
    }
    return 0;
}
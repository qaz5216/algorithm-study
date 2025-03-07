#include <iostream>

using namespace std;

int main()
{
    int t=1;
    while(true){
    int l,p,v; // 5 8 20 4 5 6
    cin>>l>>p>>v;
    if(l==0&&p==0&&v==0) break;
    if(v%p>l){
        cout<<"Case "<<t<<": "<<(v/p)*l+l<<'\n';
    }
    else{
        cout<<"Case "<<t<<": "<<(v/p)*l+v%p<<'\n';
    }
    t++;
    }
}
/*
22일
5 3 5 3 5 21일
          22일
5 3 5 3 5 

*/
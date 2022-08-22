#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int n,k;
int arr[100];
int con[100];
int result=100;
int fillcon(){
    int idx;
    for(int i=0;i<k;i++){
        int check=1;
        for(int j=0;j<n;j++){
            if(con[j]==0||con[j]==arr[i]){
                con[j]=arr[i];
                check=0;
                break;
            }
        }
        if(check==1){
            idx=i;
            break;
        }
    }
    return idx;
}

void plug(int a,int b){
    if(a==k){
        result=min(result,b);
    }
    else if(result<=b){
        //이거안해주면 시간초과나옴
    }
    else{
    int check=0;
    for(int i=0;i<n;i++){
        if(con[i]==arr[a]){
                con[i]=arr[a];
                check=1;
                break;
            }
    }
    if(check==1){
        plug(a+1,b);
    }
    else{
        for(int i=0;i<n;i++){
            int tmp=con[i];
            con[i]=arr[a];
            plug(a+1,b+1);
            con[i]=tmp;
        }
    }
    }
}

int main()
{
    fill_n(con,100,0);
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> arr[i];
    }
    int idx=fillcon();
    if(idx==k){
        cout << 0;
        return 0;
    }
    plug(idx,0);
    cout<<result;
    return 0;
}

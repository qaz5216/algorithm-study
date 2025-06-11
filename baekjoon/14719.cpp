#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int w,h;
int arr[500];
int map[500][500];


int main()
{
    cin >> h >> w;
    for(int i=0;i<w;i++){
        cin >> arr[i];
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            map[i][j]=-1;
        }
        for(int j=0;j<arr[i];j++){
            map[i][j]=1;
        }
    }
    for(int i=h-1;i>=0;i--){
        int l=0,r=w-1,lb=-1,rb=-1;
        for(int j=0;j<w;j++){
            if(lb!=-1){
            }
            else{
                if(map[l][i]==-1){
                    map[l][i]=0;
                    l++;
                }
                else{
                    lb=1;
                }
            
            }
            if(rb!=-1){}
            else{
                if(map[r][i]==-1){
                    map[r][i]=0;
                    r--;
                }
                else{
                    rb=1;
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(map[i][j]==-1)
                sum+=1;
        }
    }
    cout<<sum;
    return 0;
}

q
/*
-1 -1 -1 -1 1 -1 -1 -1
1 -1 -1 1 1 -1 -1 -1
1 -1 1 1 1 -1 -1 1
1 1 1 1 1 1 1 1 
*/

4 3 3 2 2 1 1
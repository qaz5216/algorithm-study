#include <iostream>

using namespace std;

int n,m,r;
int arr[302][302];

int main()
{
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    return 0;
}

/*
R번회전 시킨다 x 
R%? 번 회전시킨다 O



*/
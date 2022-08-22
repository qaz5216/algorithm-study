#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1000001];


int main()
{
    int t,tmp,min=1000000,max=-1000000;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> tmp;
        if(tmp>max)
        max=tmp;
        if(tmp<min)
        min=tmp;
    }
    cout << min << " " << max;
    return 0;
}
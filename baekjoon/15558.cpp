#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
 
using namespace std;
 
bool map[2][200000];
bool check[2][200000];
 
int main() {

    memset(map, true, sizeof(map));

    int n, k;
    cin >> n >> k;
 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin>>c;
            map[i][j]=c-'0';
        }
    }
    queue < tuple<bool, int, int>>q;
    q.push({ 0,0,0 });
    check[0][0] = true;
 
    while (!q.empty()) {
        int line, x, sec;
        tie(line, x, sec) = q.front();
        q.pop();
        //나갔나 안나갔나 체크
        if (x >= n) {
            cout << 1 << endl;
            return 0;
        }
 
        //case 1
        if (map[line][x + 1]&& check[line][x + 1] == false) {
            check[line][x + 1] = true;
            q.push({ line,x + 1,sec + 1 });
        }
        //case 2
        if (x-1>sec && map[line][x - 1]&& check[line][x - 1] == false) {
            check[line][x - 1] = true;
            q.push({ line,x - 1,sec + 1 });
        }
        if (map[!line][x + k]&& check[!line][x + k] == false) {
            check[!line][x + k] = true;
            q.push({!line,x + k,sec + 1 });
        }
    }
 
 
    cout << 0 << endl;
}

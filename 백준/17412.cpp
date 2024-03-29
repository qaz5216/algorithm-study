#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int MN = 401;
const int INF = 1e9;

int c[MN][MN];
vector<int> edge[MN];
int d[MN];
int tryn=0;

int maxflow(int src, int snk) {
    int ret = 0;
    while(1) {
        queue<int> q; q.push(src);
        memset(d, -1, sizeof(d)); d[src] = src;
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(int nxt : edge[now]) {
                if(c[now][nxt] > 0 && d[nxt] == -1) {
                    q.push(nxt);
                    d[nxt] = now;
                }
            }
        }
        if(d[snk] == -1) break;
        for(int i = snk; i != src; i = d[i]) {
            c[d[i]][i] -= 1;
            c[i][d[i]] += 1;
        }
        ret += 1;
    }

    return ret;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, P; cin >> N >> P;
    while(P--) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);

        c[u][v]++;
    }

    cout << maxflow(1, 2);
}
#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;
const int MN=51;
const int MM=MN*MN;
int arr[MN][MN];
int c[MM][MM];
int p[MM];
map<pair<int,int>, int> idx;
vector <int> g[MM];

int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

int maxflow(int src, int snk) {
    int ret = 0;
    while(1) {
        queue<int> q; q.push(src);
        memset(p, -1, sizeof(p));
        p[src] = src;
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(int nxt : g[now]) {
                if(c[now][nxt] > 0 && p[nxt] == -1) {
                    q.push(nxt);
                    p[nxt] = now;
                }
            }
        }

        if(p[snk] == -1) break;
        int flow = INF;
        for(int i = snk; i != src; i = p[i])
            flow = min(flow, c[p[i]][i]);

        for(int i = snk; i != src; i = p[i]) {
            c[p[i]][i] -= flow;
            c[i][p[i]] += flow;
        }

        ret += flow;
    }

    return ret;
}int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    int sum=0;
    int cnt=1;
    while(T--)
    {
        memset(arr,0,sizeof(arr));
        memset(c,0,sizeof(c));
        memset(f, 0, sizeof(f));
        idx.clear();
        sum=0;
        cnt=1;
        for(int i=0;i<=MM;i++)
        {
            g[i].clear();
        }
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                cin>>arr[i][j];
                sum+=arr[i][j];
                idx[make_pair(i,j)]=cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                int idx1=idx[make_pair(i,j)];
                if((i+j)%2){
                    g[idx1].push_back(cnt);
                    g[cnt].push_back(idx1);
                    c[idx1][cnt]+=arr[i][j];
                    continue;
                }
                else{
                    g[idx1].push_back(0);
                    g[0].push_back(idx1);
                    c[0][idx1]+=arr[i][j];
                }
                for(int d=0;d<4;d++)
                {
                    int nx=i+dx[d];
                    int ny=j+dy[d];
                    if(nx>0&&nx<=n&&ny>0&&ny<=m){
                        if(arr[nx][ny]==0&&arr[nx][ny]==0) continue;
                        int idx2=idx[make_pair(nx,ny)];
                        g[idx1].push_back(idx2);
                        g[idx2].push_back(idx1);
                        c[idx1][idx2]+=1000;
                    }
                }
                
            }
        }
        int ret=maxflow(0,cnt);
        cout<<sum-ret<<'\n';
    }
    return 0;
}
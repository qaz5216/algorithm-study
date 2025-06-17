//  #include <iostream>
//  #include <vector>
//  #include <algorithm>
//  using namespace std;

// int n;
// string s;
// bool board[25][25];
// bool visit[25][25];
// int dx[4]={1,-1,0,0};
// int dy[4]={0,0,1,-1};
// int cnt=0;
// vector<int> ans;

// void dfs(int x,int y){
//     cnt++;
//     visit[x][y]=true;
//     for(int i=0;i<4;i++){
//         int nx=x+dx[i];
//         int ny=y+dy[i];
//         if(0<=nx&&nx<n&&0<=ny&&ny<n){
//             if(board[nx][ny]&&!visit[nx][ny]){
//                 dfs(nx,ny);
//             }
//         }
//     }
// }

// int main()
// {
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>s;
//         for(int j=0;j<n;j++){
//             board[i][j]=s[j]-'0';
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(board[i][j]&&!visit[i][j]){
//                 cnt=0;
//                 dfs(i,j);
//                 ans.push_back(cnt);
//             }
//         }
//     }
//     cout<<ans.size()<<'\n';
//     sort(ans.begin(),ans.end());
//     for(int answer:ans){
//         cout<<answer<<'\n';
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

#define MAX_N 22
#define MAX_INT 987654321
int N;              // 벽장의 개수
int board[22];      // 벽장
int L, R;           // 초기 열린문두개
int M;              // 사용할 벽장들의 순서의 길이
int visit[20][488]; //={ MAX_INT 초기화하기 } // 20 : cnt , 488 (left)*20+(right)
int arr[20];        // 사용할벽장 담을 배열
int ans = MAX_INT;  // 정답
int mtime = 0;

// dfs(cnt,left,right,cost){
// 	if(cnt==M) // M개 다사용했으면
// 		정답 최소값으로 갱신
// 	if visit[cnt][(left+1)*20+(right+1)]<cost  //가지치기
// 		종료
// 	//left, right 는 swap 을통해 left<right 유지하기
// 	case:1
// 		left arr[cnt]로 이동
// 	case:2
// 		right arr[cnt]로 이동
// }
void dfs(int cnt, int left, int right, int cost)
{
    mtime++;
    if (cost >= ans)
        return;
    if (cnt == M)
    {
        ans = min(ans, cost);
        return;
    }
    int idx = 20 * left + right;
    // if(visit[cnt][idx]<cost) return;
    // visit[cnt][idx]=cost;

    int des = arr[cnt];
    // 왼쪽이 움직이기
    int tmp = abs(left - des);
    des < right ? dfs(cnt + 1, des, right, cost + tmp) : dfs(cnt + 1, right, des, cost + tmp);
    // 오른쪽이 움직이기
    tmp = abs(right - des);
    left < des ? dfs(cnt + 1, left, des, cost + tmp) : dfs(cnt + 1, des, left, cost + tmp);
}

int main()
{
    cin >> N;
    cin >> L >> R;
    if (L > R)
        swap(L, R);
    board[L] = 1;
    board[R] = 1;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }
    for (int k = 0; k < M; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                int idx = i * 20 + j;
                visit[k][idx] = MAX_INT;
            }
        }
    }
    dfs(0, L, R, 0);
    cout << "time:" << mtime << ' ';
    cout << ans;
    return 0;
}

// MAX_N 22
// int N= //벽장의 개수
// int board[22] //벽장
// int left,right //초기 열린문두개
// int M= //사용할 벽장들의 순서의 길이
// int visit[20][488] ={ MAX_INT 초기화하기 } // 20 : cnt , 488 (left+1)*20+(right+1)
// int arr[20]; 사용할벽장 담을 배열
// int ans=MAX_INT //정답
// dfs(cnt,left,right,cost){
// 	if(cnt==M) // M개 다사용했으면
// 		정답 최소값으로 갱신
// 	if visit[cnt][(left+1)*20+(right+1)]<cost  //가지치기
// 		종료
// 	//left, right 는 swap 을통해 left<right 유지하기
// 	case:1
// 		left arr[cnt]로 이동
// 	case:2
// 		right arr[cnt]로 이동
// }

// 문이 닫힘 =0;
// 문이 열림 =1;

// 문 두개 left right

// 001000010
//         ta
// case:1 000001010
// case:2 001001000

// 001000010
// ta
// case:1 101000000 //개수체크해 left right , swap
// case:2 100000010

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 0 1 2 3 4 5 6
// 24 15 39
// 30 12 42
// 무조건 큰순서대로 묶기
// 0 1 2 =3
// 0 (1,2)=2
// 1,0은 절대 묶지마
/*
-일땐
-끼리 묶어
-값이 홀수개다.
    ㄴ0 이있으면 묶어서 0만들기

1000*1000=1000000 100만
*50= 5000만 int범위 안
*/
int n;
vector<int> pv; // 양수담을벡터
vector<int> mv; // 마이너스 담을 벡터
int zerocnt;    // 0은 따로관리
int onecnt;     // 1도 따로관리
int ans = 0;

int main()
{
    cin >> n;
    int x;
    zerocnt = 0;
    onecnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > 1)
        { // 1이 아닌 양수면
            pv.push_back(x);
        }
        else if (x == 1)
        { // 1이면
            onecnt++;
        }
        else if (x < 0)
        { // 음수면
            mv.push_back(x);
        }
        else
        { // 0이면
            zerocnt++;
        }
    }
    sort(pv.begin(), pv.end(), greater<int>()); // 양수 내림차순
    sort(mv.begin(), mv.end());                 // 음수 오름차순
    int pvsum = 0;                              // 양수합
    int mvsum = 0;                              // 음수합
    int idx = 0;
    while (idx < pv.size())
    {
        if (idx + 1 < pv.size())
        {
            pvsum += pv[idx] * pv[idx + 1]; // 묶어서 더하기
        }
        else
        {
            pvsum += pv[idx]; // 남은 양수가 1개
        }
        idx += 2; // 2개 묶어서 썼으니 idx+=2
    }
    idx = 0;
    while (idx < mv.size())
    { // 음수
        if (idx + 1 < mv.size())
        { // 음수가 두개이상있으면 양수로 바꿔지니까
            mvsum += mv[idx] * mv[idx + 1];
        }
        else
        {
            if (zerocnt == 0)
            { // 0이 없으면
                mvsum += mv[idx];
            }
        }
        idx += 2;
    }

    // cout<<pvsum<<","<<mvsum<<","<<onecnt<<'\n';
    cout << pvsum + mvsum + onecnt;
    return 0;
}
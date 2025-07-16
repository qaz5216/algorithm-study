#include <iostream>

using namespace std;

int m, n;

int dx[3] = {-1, -1, 0};
int dy[3] = {-1, 0, -1};

int board[701][701];
int arr[1401];

void printboard()
{
    for (int i = 0; i < m; i++)
    { // 아래로읽고 옆으로이동
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    int zero, one, two, len;
    len = 2 * m - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> zero >> one >> two;
        /*
        처음 코드
        for(int i=0;i<len;i++){
            if(zero){
                arr[i]+=0;
                zero--;
            }
            else if(one)
            {
                arr[i]+=1;
                one--;
            }
            else{
                arr[i]+=2;
            }
        }
        */
        // 이배열도 나중에 갱신할수있음!!
        ++arr[zero];
        ++arr[zero + one];
    }
    for (int i = 1; i < len; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < len; i++)
    {
        if (i < m)
        {
            // 왼쪽아래부터
            board[m - 1 - i][0] = arr[i];
        }
        else
        { // i=m 일때 1 i=2m-2일때 m-1
            // 왼쪽위부터
            board[0][i - m + 1] = arr[i];
        }
    }
    int mx;
    for (int i = 1; i < m; i++)
    { // 아래로읽고 옆으로이동
        for (int j = 1; j < m; j++)
        {
            mx = board[j - 1][i - 1];
            mx = max(mx, board[j - 1][i]);
            board[j][i] = max(mx, board[j][i - 1]);
        }
    }
    printboard();
    return 0;
}

/*
1 1 1 1     2 2 3 4
1 1 1 1     2 2 3 4
1 1 1 1     1 2 3 4
1 1 1 1     1 2 3 4

1 1     1 2
1 1     0
2 3     1 1
1 3     1
3 4     2 2
2 4     2

        4 5
        3 5

        5 6
        4 6

1 2
1 2

0 2
0 2

2 3
1

*/
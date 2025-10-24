#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int arr[50][50];
int n;
int fre[50];
int cnt;
void dfs(int x,int y,int dan){
    
}

int main()
{
    cin >> n;
    int t=n;
    int ans=0;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<n;j++){
            if(str[j]=='Y')
                arr[i][j]=1;
        }
    }
    for(int i=0;i<n;i++){
        memset(fre,0,sizeof(fre));
        cnt=0;
        fre[i]=1;
        for(int j=0;j<n;j++){    
            if(arr[i][j]==1)
            {
                if(fre[j]==0){
                cnt++;
                fre[j]=1;
                }
                for(int k=0;k<n;k++){
                    if(arr[j][k]==1&&fre[k]==0)
                    {
                    cnt++;
                    fre[k]=1;
                    }
                }
            }
        }
        ans=max(cnt,ans);
    }
    cout << ans;
}

// #include <iostream>

// using namespace std;

// #define BJ1058

// #ifdef BJ1058
// int N;
// char arr[51][51];
// int check[51];

// void initCheck() {
// 	for (int i = 0; i < N; i++)
// 		check[i] = 0;
// }

// int cntFriend(int num, int depth) {
// 	if (depth == 2)
// 		return 0;//ģ���� ģ�������� ����
// 	int result = 0;
// 	for (int i = 0; i < N; i++) {
// 		if (arr[num][i] == 'Y' && check[i] == 0) {//ģ���̰� �湮�� ���� �ʾҴٸ� ���
// 			check[i] = 1;//üũ
// 			result++;//ģ�� �� ����
// 			result += cntFriend(i, depth + 1);//���
// 		}
// 	}
// 	return result;
// }

// void printfriends() {
// 	//cout << "friends : ";
// 	for (int i = 0; i < N; i++) {
// 		if (check[i] == 1)
// 			cout << i << ' ';
// 	}
// 	//cout << '\n';
// }

// int findMax() {
// 	int max = 0;

// 	for (int i = 0; i < N; i++) {
//         //cout<<i;
// 		initCheck();//��Ϳ� ���� ���� check �迭 �ʱ�ȭ
// 		//check[i] = 1;//�ڱ� �ڽ��� ����
// 		int temp = cntFriend(i, 0);//����Ͽ� ģ�� �� ����
// 		if (max < temp){
//             //cout<<temp<<"!"<<'\n';
// 			max = temp;
//         }
// 	}
// 	return max;
// }

// int main() {
// 	cin >> N;
// 	//N = 50;
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			cin >> arr[i][j];
// 			//arr[i][j] = 'N';
// 		}
// 	}
// 	cout << findMax();
// }
// #endif
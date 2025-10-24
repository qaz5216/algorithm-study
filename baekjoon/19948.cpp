#include <iostream>
#include <sstream>

using namespace std;

int arr[26];
int space;

int main()
{
    string str,ans;
    getline(cin,str);
    stringstream ss(str);
    cin>>space;
    for(int i=0;i<26;i++){
        cin>>arr[i];
    }
    bool flag=true;
    while(ss>>str){
        if(space<0||!flag){
            flag=false;
            break;
        }
        space--;
        for(int i=1;i<str.size();i++){
            if('a'<=str[i]&&str[i]<='z'){
                str[i]=str[i]-'a'+'A';
            }
            if(--arr[str[i]-'A']<0){
                flag=false;
                break;
            }
        }
        if('a'<=str[0]&&str[0]<='z'){
                str[0]=str[0]-'a'+'A';
        }
        if(arr[str[0]-'A']-2<0){
                arr[str[0]-'A']-=2;
                flag=false;
                break;
        }
        ans.push_back(str[0]);
    }
    if(flag)
    cout<<ans;
    else
    cout<<-1;
    return 0;
}
//문자가 연속으로 나오거나 빈칸이 연속으로 나오는 경우 영재는 자판을 꾹 눌러 한 번만 사용해서 키보드를 좀 더 효율적으로 쓸 수 있다. (A와 a는 다른 문자이므로 'Aa'는 2번의 a자판을 누른 것으로 한다.)
#include <iostream>
#include <cstring>
using namespace std;

int n;
int a1[30];
int a2[30];

int main()
{
    cin>>n;
    while (n--)
    {
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<s1<<" & "<<s2<<" are NOT anagrams.\n";
        }
        else{
            bool flag=true;;
            for(int i=0;i<s1.size();i++){
                a1[s1[i]-'a']++;
                a2[s2[i]-'a']++;
            }
            for(int i=0;i<30;i++){
                if(a1[i]!=a2[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<s1<<" & "<<s2<<" are anagrams.\n";
            }
            else{
                cout<<s1<<" & "<<s2<<" are NOT anagrams.\n";
            }
        }
    }
    
    return 0;
}
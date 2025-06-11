#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ans;

struct DB{
    DB* next[26];
    int x;
    bool can;
    DB(){
        for(int i=0;i<26;i++)
        {
            next[i]=nullptr;
        }
        x=0;
        can=true;
    }

    void insert(string s,int idx,string tmp)
    {
        if(can)
        {
            can=false;
            if(tmp.size()==0)
            {
                tmp=s.substr(0,idx);
            }
        }
        if(s.size()==idx)
        {
            x+=1;
            if(x==1)
            {
                if(tmp.size()!=0)
                ans.push_back(tmp);
                else
                ans.push_back(s);
            }
            else
            {
                string sx=to_string(x);
                ans.push_back(s+sx);
            }
            return;
        }
        if(next[s[idx]-'a']!=nullptr)
        {
            next[s[idx]-'a']->insert(s,idx+1,tmp);
        }
        else
        {
            next[s[idx]-'a']=new DB();
            next[s[idx]-'a']->insert(s,idx+1,tmp);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    DB* d=new DB;
    d->can=false;
    for(int i=0;i<t;i++)
    {
        string str;
        cin>>str;
        d->insert(str,0,string());
    }
    for(string s:ans)
    {
        cout<<s<<"\n";
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie
{
    bool finish;
    Trie* next[10];
    
    Trie() : finish(false) {
        memset(next,0,sizeof(next));
    }
    ~Trie() {
        for(int i=0;i<10;i++)
        {
            if(next[i])
                delete next[i];
        }
    }
    void insert(string s,int idx){
        if(idx==s.size())
            finish=true;
        else {
            int curr = s[idx]-'0';
            if(next[curr]==NULL)
                next[curr] = new Trie();
            next[curr]->insert(s,idx+1);
        }
    }

    bool find(string s,int idx)
    {
        if(finish) return false;
        if(idx==s.size()) return true;
        int curr = s[idx]-'0';
        if(next[curr])
        {
            if(next[curr]->find(s,idx+1)) return true;
            else return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Trie* root=new Trie();
        int n;
        cin>>n;
        bool check=true;
        vector <string> arr;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            arr.push_back(s);
        }
        sort(arr.begin(),arr.end());
        for(string s:arr)
        {
            if(!root->find(s,0)) {check=false;}
            root->insert(s,0);
        }
        if(check) cout<<"Yes"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}
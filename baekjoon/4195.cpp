#include <iostream>
#include <vector>
#include <map>
using namespace std;

int T, F;
vector<int> ans;
int p[200002];
int frinum[200002];
map<string, int> usermap;
vector<string> users;
vector<vector<string>> friends;
vector<vector<string>> usertable;
int find(int x)
{
    if (x == p[x])
        return x;
    else
    {
        return p[x] = find(p[x]);
    }
}

void myunion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (b > a)
    {
        frinum[a] += frinum[b];
        p[b] = a;
    }
    else
    {
        frinum[b] += frinum[a];
        p[a] = b;
    }
}

void solve()
{
    int index = 0;
    cin >> F;
    for (int i = 0; i < F * 2; i++)
    {
        p[i] = i;
        frinum[i] = 1;
    }
    for (int i = 0; i < F; i++)
    {
        string tmp, tmp2;
        cin >> tmp >> tmp2;
        if (usermap.count(tmp) == 0)
        {
            usermap[tmp] = index;
            index++;
        }
        // cout<<"usermap count tmp"<<usermap.count(tmp)<<endl;
        // cout<<"usermap count tmp2"<<usermap.count(tmp2)<<endl;
        if (usermap.count(tmp2) == 0)
        {
            usermap[tmp2] = index;
            index++;
            // cout<<"usermap2= "<<usermap[tmp2]<<endl;
        }
        // cout<<"usermap "<<usermap[tmp]<<" "<<usermap[tmp2]<<endl;
        myunion(usermap[tmp], usermap[tmp2]);
        // vector  <string> fri;
        // for(int i=0;i<users.size();i++)
        //{
        // cout<<" f="<<f<<" p["<<i<<"]="<<p[i]<<endl;
        //    if(f==find(i)){
        //        num++;
        // fri.push_back(users[i]);
        //    }
        //}
        // cout<<endl;
        ans.push_back(max(frinum[find(usermap[tmp])], frinum[find(usermap[tmp2])]));
        // friends.push_back(fri);
        // usertable.push_back(users);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
        users.clear();
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
        /*
        cout<<" friend = ";
        for(string tmp:friends[i])
        {
            cout<<tmp<<" ";
        }
        cout<< " users = ";
        for(string tmp:usertable[i])
        {
            cout<<tmp<<" ";
        }
        cout<<endl;
        */
    }
    return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;


int calcHash(string s) {
	int hash = 0;
	for (char c : s) {
		hash *= 31;
		hash += c;
	}

	return hash;
}

int main()
{
    cin >>N>>M;
    map<int,bool> nhash;
    vector<string> ans;
    string s;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        nhash[calcHash(s)]=true;
    }
    for(int i=0;i<M;i++)
    {
        cin>>s;
        if(nhash.find(calcHash(s))!=nhash.end())
        {
            ans.push_back(s);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(string answer:ans)
    {
        cout<<answer<<"\n";
    }
    return 0;
}
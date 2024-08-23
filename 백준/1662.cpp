#include <iostream>
#include <stack>


using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<int> st;
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==')')
        {
            int len=0;
            int a=0;
            while(true)
            {
                int c=st.top();st.pop();
                if(c==-1)
                {
                    break;
                }
                a+=c;
            }
            char c=st.top();st.pop();
            len+=a*c;
            st.push(len);
        }
        else
        {
            if(i+1<s.size()-1&&s[i+1]=='(')
            {
                st.push(s[i]-'0');
            }
            else if(s[i]=='(')
            {
                st.push(-1);
            }
            else
            {
                st.push(1);
            }
        }
    }
    while (!st.empty())
    {
        int c=st.top();st.pop();
        sum+=c;
    }
    
    cout<<sum<<"\n";
    return 0;
}

/*

*/
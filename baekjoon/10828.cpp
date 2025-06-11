#include <iostream>
#include <stack>

using namespace std;

stack <int> st;

int N;

int main()
{
    cin>>N;
    while(N--)
    {
        string s;
        cin>>s;
        if(s=="push")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else
        {
            if(s=="pop"){
                if(!st.empty()){
                int x=st.top();
                cout<<x<<"\n";
                st.pop();
                }
                else
                {
                    cout<<-1<<"\n";
                }
            }
            if(s=="size")
            {
                cout<<st.size()<<"\n";
            }
            if(s=="empty")
            {
                cout<<st.empty()<<"\n";
            }
            if(s=="top")
            {
                if(!st.empty()){
                int x=st.top();
                cout<<x<<"\n";
                }
                else
                {
                    cout<<-1<<"\n";
                }
            }
        }
    }
    return 0;
}
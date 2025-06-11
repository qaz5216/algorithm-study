#include <iostream>

using namespace std;

int N;
int arr[27][2];

void front(int x)
{
    char chr=x+'A';
    cout<<chr;
    if(arr[x][0]!=-1)
        front(arr[x][0]);
    if(arr[x][1]!=-1)
        front(arr[x][1]);
    return;
}

void center(int x)
{
    char chr=x+'A';
    if(arr[x][0]!=-1)
        center(arr[x][0]);
    cout<<chr;
    if(arr[x][1]!=-1)
        center(arr[x][1]);
    return;
}

void back(int x)
{
    char chr=x+'A';
    if(arr[x][0]!=-1)
        back(arr[x][0]);
    if(arr[x][1]!=-1)
        back(arr[x][1]);
    cout<<chr;
    return;
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        char a,b,c;
        int y,z;
        cin >> a >> b >> c;
        if(b=='.')
            y=-1;
        else
            y=b-'A';
        if(c=='.')
            z=-1;
        else
            z=c-'A';
        arr[a-'A'][0]=y;
        arr[a-'A'][1]=z;
    }
    //전위순회
    front(0);
    cout<<"\n";
    //중위순회

    center(0);
    cout<<"\n";
    //후위순회

    back(0);
    cout<<"\n";
    return 0;
}
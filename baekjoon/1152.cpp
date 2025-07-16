#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string s, tmp;
    getline(cin, s);
    stringstream stream(s);
    int cnt = 0;
    while (stream >> tmp)
    {
        cnt++;
    }
    cout << cnt;
    return 0;
}
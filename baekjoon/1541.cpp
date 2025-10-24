#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string input;
    vector<int> num;
    vector<int> pm; // + = 1 , - = 0
    cin >> input;
    string tmp = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '+' || input[i] == '-')
        {
            num.push_back(stoi(tmp));
            if (input[i] == '+')
                pm.push_back(1);
            else
                pm.push_back(0);
            tmp = "";
        }
        else
        {
            tmp += input[i];
        }
    }
    num.push_back(stoi(tmp));
    // 수집끝
    int ans = num[0];
    int sum;
    bool minus = false;
    for (int i = 0; i < pm.size(); i++)
    {
        if (pm[i] == 0)
        {
            minus = true;
            ans -= num[i + 1];
        }
        else if (minus)
        {
            ans -= num[i + 1];
        }
        else
        {
            ans += num[i + 1];
        }
    }
    cout << ans << endl;
    return 0;
}
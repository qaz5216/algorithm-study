#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
map<string, int> lan;
map<string, int> work;
map<string, int> career;
map<string, int> food;

vector<int> arr[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    lan["cpp"] = 0;
    lan["java"] = 1;
    lan["python"] = 2;
    work["backend"] = 0;
    work["frontend"] = 1;
    career["junior"] = 0;
    career["senior"] = 1;
    food["chicken"] = 0;
    food["pizza"] = 1;
    for (string data : info)
    {
        int score;
        string l, w, c, f;
        istringstream iss(data);
        iss >> l >> w >> c >> f >> score;
        arr[lan[l]][work[w]][career[c]][food[f]].push_back(score);
    }

    for (string data : query)
    {
        int score, sum = 0;
        string l, w, c, f, waste;
        istringstream iss(data);
        iss >> l >> waste >> w >> waste >> c >> waste >> f >> score;
        for (int ia = 0; ia < 3; ia++)
        {
            if (l == "-" || ia == lan[l])
            {
                for (int ib = 0; ib < 2; ib++)
                {
                    if (w == "-" || ib == work[w])
                    {
                        for (int ic = 0; ic < 2; ic++)
                        {
                            if (c == "-" || ic == career[c])
                            {
                                for (int id = 0; id < 2; id++)
                                {
                                    if (f == "-" || id == food[f])
                                    {
                                        for (int sc : arr[ia][ib][ic][id])
                                        {
                                            if (sc >= score)
                                                sum++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(sum);
    }

    return answer;
}
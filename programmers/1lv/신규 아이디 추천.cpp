#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if ('A' <= new_id[i] && new_id[i] <= 'Z')
            answer += new_id[i] - 'A' + 'a';
        else
            answer += new_id[i];
    }
    new_id = answer;
    answer = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if (('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_')
            answer += new_id[i];
    }
    new_id = answer;
    answer = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] == '.')
        {
            if (i + 1 < new_id.size())
            {
                if (new_id[i + 1] != '.')
                {
                    answer += new_id[i];
                }
            }
            else
            {
                answer += new_id[i];
            }
        }
        else
            answer += new_id[i];
    }
    new_id = answer;
    answer = "";
    int dot_idx = 0;
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] == '.')
        {
            if (dot_idx == 0)
                continue;
            else
            {
                answer += new_id[i];
                dot_idx++;
            }
        }
        else
        {
            answer += new_id[i];
            dot_idx++;
        }
    }
    new_id = answer;
    answer = "";
    dot_idx = 0;
    for (int i = new_id.size() - 1; i >= 0; i--)
    {
        if (new_id[i] == '.')
        {
            if (dot_idx == 0)
                continue;
            else
            {
                answer += new_id[i];
                dot_idx++;
            }
        }
        else
        {
            answer += new_id[i];
            dot_idx++;
        }
    }
    new_id = answer;
    answer = "";
    for (int i = new_id.size() - 1; i >= 0; i--)
    {
        answer += new_id[i];
    }
    new_id = answer;
    answer = "";
    if (new_id.size() == 0)
    {
        new_id += 'a';
    }
    if (new_id.size() >= 16)
    {
        for (int i = 0; i < 15; i++)
        {
            answer += new_id[i];
        }
        new_id = answer;
        answer = "";
    }
    dot_idx = 0;
    for (int i = new_id.size() - 1; i >= 0; i--)
    {
        if (new_id[i] == '.')
        {
            if (dot_idx == 0)
                continue;
            else
            {
                answer += new_id[i];
                dot_idx++;
            }
        }
        else
        {
            answer += new_id[i];
            dot_idx++;
        }
    }
    new_id = answer;
    answer = "";
    for (int i = new_id.size() - 1; i >= 0; i--)
    {
        answer += new_id[i];
    }
    new_id = answer;
    if (new_id.size() <= 2)
    {
        while (answer.size() != 3)
        {
            answer += new_id[new_id.size() - 1];
        }
        new_id = answer;
    }
    return new_id;
}
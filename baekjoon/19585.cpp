#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int c, n, q;

unordered_map<int, bool> color59;
unordered_map<string, bool> name59;

int calcHash(int magicNum, string &s)
{
	int hash = 0;
	for (char c : s)
	{
		hash *= magicNum;
		hash += c;
	}

	return hash;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n;
	while (c--)
	{
		string color;
		cin >> color;
		color59[calcHash(59, color)] = true;
	}
	while (n--)
	{
		string name;
		cin >> name;
		name59[name] = true;
	}
	cin >> q;
	while (q--)
	{
		string s;
		cin >> s;
		int size = s.size();
		int leftHash59 = 0;
		bool no = true;
		// rolling hash
		for (int i = 0; i < min(1000, size); i++)
		{
			leftHash59 *= 59;
			leftHash59 += s[i];

			if (size - i - 1 > 1000)
				continue;

			if (color59.find(leftHash59) != color59.end())
			{
				string sub = s.substr(i + 1, size - i - 1);
				if (name59.find(sub) != name59.end())
				{
					cout << "Yes" << "\n";
					no = false;
					break;
				}
			}
		}

		if (no)
			cout << "No" << "\n";
	}
}
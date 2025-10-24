#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <string.h>
#include <math.h>
#include <cassert>
#include <limits.h>
#pragma warning(disable : 4996)
using namespace std;

const int INF = 987654321;
int n;

vector<int> adj[10001];
int ret = INF;

int maxVal = 0;
int maxIdx = 0;

int cost[10001];

vector<int> starts;
vector<pair<int, int>> ends;

void dfs(int here, int prev, int c)
{

	if (maxVal < c)
	{
		maxVal = c;
		starts.clear();
		starts.push_back(here);
	}
	else if (maxVal == c)
	{
		starts.push_back(here);
	}

	for (auto &next : adj[here])
	{
		if (next == prev)
			continue;

		dfs(next, here, c + cost[next]);
	}
}

// 트리의 지름 위의 출발 정점에서 가능한 도착 정점들을 탐색
void dfs2(int here, int prev, int c, int origin_start)
{

	if (maxVal < c)
	{
		maxVal = c;
		::ends.clear();

		if (origin_start < here)
			::ends.push_back({origin_start, here});
		else
			::ends.push_back({here, origin_start});
	}
	else if (maxVal == c)
	{
		if (origin_start < here)
			::ends.push_back({origin_start, here});
		else
			::ends.push_back({here, origin_start});
	}

	for (auto &next : adj[here])
	{
		if (next == prev)
			continue;

		dfs2(next, here, c + cost[next], origin_start);
	}
}

void solve()
{
	dfs(1, 1, cost[1]);

	maxVal = 0;

	for (auto &s : starts)
		dfs2(s, s, cost[s], s);

	sort(::ends.begin(), ::ends.end());

	cout << maxVal << " " << ::ends[0].first << endl;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cost[i + 1];

	for (int i = 0; i < n - 1; i++)
	{
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}

	solve();

	return 0;
}
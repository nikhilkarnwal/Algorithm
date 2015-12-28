#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
struct node
{
	int cost;
	int x, y;
};
bool comp(node n1, node n2)
{
	return (n1.cost < n2.cost);
}
class CableDonation {
public:
	int p[60], r[60];
	int getl(char a)
	{
		if (a == '0')return 0;
		else if (a >= 'a'&&a <= 'z')return int(a) - 'a' + 1;
		else return a - 'A' + 27;
	}
	void makeset(int a, int b)
	{
		for (int i = 0; i < 60; i++)
		if (p[i] == b)
			p[i] = a;
	}
	int cable(vector<string> ln)
	{
		int l = ln.size();
		vector<node> n;
		node nd;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				nd.cost = getl(ln[i][j]);
				if (nd.cost == 0)continue;
				nd.x = i;
				nd.y = j;
				n.push_back(nd);
			}
			p[i] = i;
			r[i] = i;
		}
		int tlen = 0, last = 0;
		sort(n.begin(), n.end(), comp);
		for (int i = 0; i < n.size(); i++)
		{
			if (n[i].x == n[i].y)
				tlen += n[i].cost;
			else if (r[p[n[i].x]] == r[p[n[i].y]])
				tlen += n[i].cost;
			else
			{
				makeset(p[n[i].x], p[n[i].y]); last = p[n[i].x];
			}
		}
		int count = 0;
		for (int i = 0; i < l; i++)
		if (p[i] == last)count++;
		if (count == l)
			return tlen;
		else
			return -1;
	}
};
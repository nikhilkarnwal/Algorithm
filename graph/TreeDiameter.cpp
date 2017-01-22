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
//user - nikhil (sunny08)
//https://community.topcoder.com/stat?c=problem_statement&pm=13416

class LonglongestPathTree {
private:
vector<vector<pair<int,int>> > gp;
long long diam(int u,long long &mx,vector<bool> &used){
	long long ans =0;
	used[u]=1;
	for(pair<int,int> x:gp[u]){
		if(!used[x.first]){
			long long t = diam(x.first,mx,used) + x.second;
			mx = max(mx,t+ans);
			ans = max(ans,t);
		}
	}
	return ans;
}
void addEdge(int u,int v,int l){
	gp[u].push_back(make_pair(v,l));
	gp[v].push_back(make_pair(u,l));
}
public:
	long long getLength(vector <int> A, vector <int> B, vector <int> L) {
		int n = A.size();
		gp.clear();
		gp.resize(n+1);
		for(int i=0;i<n;i++){
			addEdge(A[i],B[i],L[i]);
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			long long mx1 =0,mx2=0;
			vector<bool> used(n+1,0);
			used[A[i]]=used[B[i]]=1;
			diam(A[i],mx1,used);
			diam(B[i],mx2,used);
			ans = max(ans,mx1+mx2+L[i]);
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

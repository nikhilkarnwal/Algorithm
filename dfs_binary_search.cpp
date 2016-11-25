#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define rb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())

typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;

const ll mod = 1000000007;

const int n = 200001;
int a[n], nd[n], ans[n];
ll ds[n];
vector<PII> gp[n];
void dfs(int u, int lvl, ll dis){
    ds[lvl]=dis;
    nd[lvl]=u;
    int l = lower_bound(ds,ds+lvl+1,dis-a[u])-ds-1;
    ans[u]++;
    ans[nd[l]]--;
    for(PII v:gp[u]){
        dfs(v.fi,lvl+1,dis+v.se);
        ans[u]+=ans[v.fi];
    }
}
int main(){
    int nn;
    cin>>nn;
    rep(i,1,nn+1)scanf("%d",a+i);
    rep(i,2,nn+1)
    {
        int p,w;
        scanf("%d %d",&p,&w);
        gp[p].pb(mp(i,w));
    }
    dfs(1,0,1);
    rep(i,1,nn+1)printf("%d ",ans[i]-1);
    return 0;
}

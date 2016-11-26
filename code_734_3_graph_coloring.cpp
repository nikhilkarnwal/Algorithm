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

/*
http://codeforces.com/contest/734/problem/E
*/
const int N = 200005;
bool clr[N];
VI gp[N];
bool used[N];
int st[N];
void dfs(int u, int lvl){
    st[u]=lvl;
    used[u]=1;
    for(auto v:gp[u]){
        if(!used[v]&&(clr[u]==clr[v])){
            dfs(v, lvl);
        }
    }
}
int ans=0;
VI ngp[N];
int diam(int u){
    int mx1=0, mx2=0;
    used[u]=1;
    for(auto v:ngp[u]){
        if(!used[v]){
            mx2=max(mx2, diam(v));
        }
        if(mx2>mx1)swap(mx1,mx2);
    }
    ans=max(ans,mx1+mx2+1);
    return mx1+1;
}
int main(){
    int n;
    cin>>n;
    rep(i,1,n+1)cin>>clr[i];
    rep(i,1,n){
        int u,v;
        cin>>u>>v;
        gp[u].pb(v);
        gp[v].pb(u);
    }
    int lvl=0;
    rep(i,1,n+1)
    if(!used[i])
        dfs(i,lvl++);
    rep(i,1,n+1){
        for(auto v:gp[i]){
            if(st[i]!=st[v]){
                ngp[st[i]].pb(st[v]);
            }
        }
    }
    memset(used,0,sizeof(used));
    diam(0);
    cout<<(ans/2);
    return 0;
}

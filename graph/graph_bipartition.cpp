/*
http://codeforces.com/problemset/problem/687/A
user : alquarizm/ sunny08
*/

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
typedef long long int ll;
typedef pair<int,int> PII;
const ll mod = 1000000007;
const int N=100005;

const int clr = 2;
vector<VI > gp(N);
vector<VI > clset(clr);
VI mark(N);
int dfs(int u, int c = clr){
    mark[u]=c;
    clset[c-1].pb(u);
    bool ret=1;
    for(auto v:gp[u]){
        if(!mark[v]){
            ret = ret && dfs(v, 3 - c);
        }
        if(mark[v]==c){
            ret = 0;
        }
    }
    return ret;
}

int main(){
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        gp[u].pb(v);
        gp[v].pb(u);
    }
    rep(i,1,n+1){
        if(!mark[i]){
            if(!dfs(i)){
                cout<<-1;
                return 0;
            }
        }
    }
    rep(i,0,clr){
        cout<<clset[i].size()<<"\n";
        rep(j,0,sz(clset[i])){
            cout<<clset[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

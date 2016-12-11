/*
http://www.spoj.com/problems/BOTTOM/
user : photonit
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
#include<stack>

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
const int N=5005;
VI cnt(N);
void dfs1(int u, vector<VI > &gp, VI &stk,bool *visited){
    if(!visited[u]){
        visited[u]=1;
        for(int v:gp[u]){
            dfs1(v,gp,stk,visited);
        }
        stk.pb(u);
    }
}
void dfs2(int u, vector<VI > &ngp, bool *visited,int cmp){
    if(visited[u]){
        visited[u]=0;
        cnt[u]=cmp;
        for(int v:ngp[u]){
            dfs2(v,ngp,visited,cmp);
        }
    }
}
int main(){
    while(1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        int m;
        cin>>m;
        vector<VI > gp(n+1);
        VI stk;
        vector<VI > ngp(n+1);
        int v,w;
        rep(i,0,m){
            cin>>v>>w;
            gp[v].pb(w);
            ngp[w].pb(v);
        }
        bool visited[n+1];
        memset(visited,0,sizeof(visited));
        rep(i,1,n+1){
            if(!visited[i])
                dfs1(i,gp,stk,visited);
        }
        int cmp=0;
        rrep(i,0,sz(stk)){
            if(visited[stk[i]])
                dfs2(stk[i],ngp,visited,cmp++);
        }
        VI sol(cmp,1);
        rep(i,1,n+1){
            rep(j,0,sz(gp[i])){
            if(cnt[i]!=cnt[gp[i][j]]){
                sol[cnt[i]]=0;
                break;
            }
            }

        }
        rep(i,1,n+1)
        if(sol[cnt[i]])
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}

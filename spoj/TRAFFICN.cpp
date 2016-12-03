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
typedef unsigned long long int ll;
typedef pair<int,int> PII;

const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
struct edge{
    int v;
    int w;
};

bool operator<(edge a, edge b){
    return a.w>b.w;
}

void dijkstra(vector<edge> gp[], VI &dst, int s){
    dst[s]=0;
    priority_queue<edge> q;
    q.push((edge){s,0});
    while(!q.empty()){
        edge p=q.top();
        q.pop();
        rep(i,0,sz(gp[p.v])){
            edge k = gp[p.v][i];
            if(dst[k.v]>dst[p.v]+k.w){
                dst[k.v]=dst[p.v]+k.w;
                q.push(k);
            }
        }
    }
}
int main(){
    int T;
    cin>>T;
    int n,m,k,s,t,u,v,w;
    while(T--){
        scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
        VI fodst(n+1, INF),badst(n+1, INF);
        vector<edge> fo[n+1],ba[n+1];
        rep(i,0,m){
            scanf("%d %d %d",&u,&v,&w);
            fo[u].pb((edge){v,w});
            ba[v].pb((edge){u,w});
        }
        dijkstra(fo,fodst,s);
        dijkstra(ba,badst,t);
        int ans = min(fodst[t],badst[s]);
        while(k--){
            scanf("%d %d %d",&u,&v,&w);
            ans = min(ans, min(fodst[u]+w+badst[v],fodst[v]+w+badst[u]));
        }
        if(ans==INF){
            printf("-1\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}

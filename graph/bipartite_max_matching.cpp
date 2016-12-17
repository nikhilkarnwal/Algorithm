/*
http://codeforces.com/contest/498/problem/C
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
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef vector<int> VI;
typedef unsigned long long int ll;
typedef pair<int,int> PII;
static const int cap = 10105;
bool visited[cap];
int matchL[cap],matchR[cap];
VI graph[cap];
class MaxBM
{
private:
    bool bpm(int u)
    {
        int i;
        for(int v:graph[u]) if(visited[v] == false)
        {
            visited[v] = true;
            if(matchR[v] < 0 || bpm(matchR[v]))
            {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        return false;
    }
public:
    void add_edge(int u,int v)
    {
        graph[u].pb(v);
    }
    int match()
    {
        memset(matchL, -1, sizeof(matchL));
        memset(matchR, -1, sizeof(matchR));
        int i, ret = 0;
        bool done;
        do
        {
            done = true;
            memset(visited, 0, sizeof(visited));
            for(i=0; i<cap; i++)
            {
                if(matchL[i]==-1 && bpm(i))
                {
                    done = false;
                }
            }
        }
        while(!done);
        for(i=0; i<cap; i++) ret += (matchL[i]!=-1);
        return ret;
    }
};
int ar[110],a[110],b[110];
set<int> s;
int main()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,n)cin>>ar[i];
    rep(i,0,m)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
        if(a[i]%2)swap(a[i],b[i]);
    }
    rep(i,0,n)
    {
        int p = ar[i];
        for(int j=2; (j*j)<=p; j++)
        {
            if(p%j==0)
                s.insert(j);
            while(p%j==0)p/=j;
        }
        if(p>1)
            s.insert(p);
    }
    int ans=0;
    snuke(s,it)
    {
        int p=(*it);
        MaxBM bpm;
        rep(i,0,cap)graph[i].clear();
        rep(i,0,m)
        {
            int x=ar[a[i]];
            int y=ar[b[i]];
            int cnt=0;
            while(x%p==0)
            {
                int cnt2=0;
                y=ar[b[i]];
                while(y%p==0)
                {
                    bpm.add_edge((a[i]+1)*100+cnt,(b[i]+1)*100+cnt2);
                    cnt2++;
                    y/=p;
                }
                cnt++;
                x/=p;
            }
        }
        ans+=bpm.match();
    }
    cout<<ans;
    return 0;
}

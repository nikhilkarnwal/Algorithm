#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
map<short,short> mp;
const short elem=1100;
vector<vector<short> > graph(elem);
struct node{
        int state;
        int cost;
        };
bool operator>(node a,node b){
        return a.cost>b.cost;
        }
int diff(int a,int b)
{
    int cnt=0;
    while(a>0||b>0)
    {
        if((a%10)!=(b%10))
            cnt++;
        a/=10;
        b/=10;
    }
    return cnt;
}
void checkprime()
{
    map<short,short> rvmp;
    bool prime[10000];
    memset(prime,0,sizeof(prime));
    prime[1]=1;
    prime[2]=1;
    prime[3]=1;
    for(int i=5;i<10000;i+=2)
    {
        bool flag=false;
        for(int j=2;j<=sqrt(i);j++)
        {
            if((i%j)==0){
                flag=true;break;}
        }
        if(!flag)
        {
            prime[i]=1;
            //cout<<i<<"\n";
        }

    }
    int cnt=0;
    for(int i=1000;i<10000;i++)
    {
        if(prime[i])
        {
            mp[i]=cnt;
            rvmp[cnt]=i;
            cnt++;
        }
    }
    cout<<cnt;
    for(int i=0;i<cnt;i++)
    {
        for(int j=i+1;j<cnt;j++)
        {
            int dist=diff(rvmp[i],rvmp[j]);
            if(dist==1)
                graph[i].push_back(j),graph[j].push_back(i);
        }
    }
}
int getPathDist(int st,int ed)
{
    int temp= mp.size();
    priority_queue<node,vector<node>,greater<node> > qu;
        node a;
        a.state=st;
        a.cost=0;
        qu.push(a);
        short visited[temp+1];
        memset(visited,0,sizeof(visited));
        //visited[0]=true;
        //cout<<"hello";
        while(!qu.empty())
            {
            a=qu.top();
            qu.pop();
            if(visited[a.state]==-1)
                    continue;
            visited[a.state]=-1;
            //cout<<a.state<<" "<<a.cost<<"\n";
            if(a.state==ed)
                return a.cost;
            for(int i=0;i<graph[a.state].size();i++)
                {
                    int best=visited[graph[a.state][i]];
                    if(best==0)
                        best=10000;
                    if(a.cost+1<best)
                    {
                        best=a.cost+1;
                        visited[graph[a.state][i]]=best;
                        qu.push(node{graph[a.state][i],best});
                    }
                }
            }
    return visited[ed];
}
int main()
{
    int t;
    cin>>t;
    checkprime();
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans = getPathDist(mp[a],mp[b]);
        if(ans==0&&a!=b)
            cout<<"Impossible\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}

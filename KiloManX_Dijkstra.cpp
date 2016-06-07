//KiloManX -Topcoder
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string.h>
#include <sstream>
#include <vector>
#include<queue>
using namespace std;

class KiloManX
{
    public:
    struct node{
        int state;
        int cost;
        };
      static bool Compare(node a,node b){
        return a.cost<b.cost;
        }
    int leastShots(vector<string> ds,vector<int> bh){
        priority_queue<node,vector<node>,decltype(&Compare)> qu(&Compare);
        //priority_queue<node> qu;
        node a;
        a.state=0;
        a.cost=0;
        qu.push(a);
        bool visited[1<<ds.size()];
        memset(visited,0,sizeof(visited));
        //visited[0]=true;
        //cout<<"hello";
        int ret=1;
        ret=(ret<<31)-1;
        while(!qu.empty())
            {
            a=qu.top();
            qu.pop();
            if(visited[a.state])
                    continue;
            visited[a.state]=true;
            cout<<a.state<<" "<<a.cost<<"\n";
            if(a.state==(1<<ds.size())-1){
                ret=min(-1*a.cost,ret);continue;}
            for(int i=0;i<ds.size();i++)
                {
                if((a.state>>i)&1)
                    continue;
                int best=bh[i];
                for(int j=0;j<ds.size();j++)
                    {
                    if((i!=j)&&((a.state>>j)&1)&&(ds[j][i]!='0')){
                        int ans=bh[i]/(ds[j][i]-'0');
                        ans+=((bh[i]%(ds[j][i]-'0'))==0?0:1);
                        best=min(best,ans);
                        }
                    }
                qu.push(node{a.state|(1<<i),a.cost-best});
                }
            }
        return ret;
        }
};
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

class DisjointSet{
private:
    int cap;
    int* pr;
    int* rk;
public:
    DisjointSet(int cap){
        this->cap = cap;
        pr = new int[cap+1];
        rk = new int[cap+1];
    }
    void createSet(int x){
        pr[x] = x;
        rk[x] = 0;
    }
    int findSet(int x){
        if(pr[x]==x){
            return x;
        }
        return pr[x] = findSet(pr[x]);
    }
    void mergeSet(int x,int y){
        int rt_x = findSet(x);
        int rt_y = findSet(y);
        if(rt_x == rt_y){
            return;
        }
        if(rk[rt_x]<rk[rt_y]){
            pr[rt_x] = rt_y;
        }
        else{
            pr[rt_y] = rt_x;
        }
        if(rk[rt_x]==rk[rt_y])
            rk[rt_x]++;
    }
};
class RoadReconstruction
{
public:
    vector<string> split(string str, char delimiter)
    {
        vector<string> internal;
        stringstream ss(str); // Turn the string into a stream.
        string tok;

        while(getline(ss, tok, delimiter))
        {
            internal.push_back(tok);
        }
        return internal;
    }
    string selectReconstruction(vector<string> rd)
    {
        DisjointSet dset(50);
        for(int i=0; i<50; i++)
            dset.createSet(i);
        map<int,map<string,vector<int> > > roads;
        map<string,int> city;
        int cnt=0;
        for(int i=0; i<rd.size(); i++)
        {
            vector<string> cols=split(rd[i],' ');
            int c1,c2;
            if(city.count(cols[1])>0)
                c1=city[cols[1]];
            else
                cout<<(c1=(city[cols[1]]=cnt++))<<" ";
            if(city.count(cols[2])>0)
                c2=city[cols[2]];
            else
                cout<<(c2=(city[cols[2]]=cnt++))<<" ";
            if(cols.size()==3)
                dset.mergeSet(c1,c2);
            else
            {
                map<string,vector<int> > temp;
                vector<int> _temp(2);
                _temp[0]=c1;
                _temp[1]=c2;
                temp[cols[0]]=_temp;
                if(roads.count(stoi(cols[3]))>0)
                    roads[stoi(cols[3])][cols[0]]=_temp;
                else
                    roads[stoi(cols[3])]=temp;
            }
        }
        map<int,map<string,vector<int> > >::iterator it;
        string ret="";
        vector<string> _ret;
        for(it=roads.begin(); it!=roads.end(); it++)
        {
            map<string,vector<int> > temp=it->second;
            map<string,vector<int> >::iterator it_temp;
            for(it_temp=temp.begin(); it_temp!=temp.end(); it_temp++)
            {
                string id=it_temp->first;
                vector<int> vec=it_temp->second;
                if(dset.findSet(vec[0])==dset.findSet(vec[1]))
                    continue;
                dset.mergeSet(vec[0],vec[1]);
                _ret.push_back(id);

            }
        }
        for(int i=0; i<cnt; i++)
            if(dset.findSet(i)!=0)
                return "IMPOSSIBLE";
        sort(_ret.begin(),_ret.end());
        for(int i=0; i<_ret.size(); i++)
            if(ret=="")
                ret+=_ret[i];
            else
                ret+=" "+_ret[i];
        return ret;
    }
};

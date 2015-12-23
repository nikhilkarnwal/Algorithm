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

class RoadReconstruction
    {
    public:
    int p[50];
    int findset(int a){
        if(p[a]==a)
            return a;
        p[a]=findset(p[a]);
        return p[a];
    }
    void merge(int a,int b){
            int _hd_a=findset(a);
            int _hd_b=findset(b);
            if(_hd_a==_hd_b)
                return ;
            else if(_hd_a<_hd_b)
                {
                p[_hd_b]=_hd_a;
                }
            else
                p[_hd_a]=_hd_b;
        }
    vector<string> split(string str, char delimiter) {
          vector<string> internal;
          stringstream ss(str); // Turn the string into a stream.
          string tok;

          while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
          }
          return internal;
	}
    string selectReconstruction(vector<string> rd){
        for(int i=0;i<50;i++)
            p[i]=i;
        map<int,map<string,vector<int> > > roads;
        map<string,int> city;
        int cnt=0;
        for(int i=0;i<rd.size();i++){
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
                merge(c1,c2);
            else{
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
            for(it=roads.begin();it!=roads.end();it++){
                map<string,vector<int> > temp=it->second;
                map<string,vector<int> >::iterator it_temp;
                for(it_temp=temp.begin();it_temp!=temp.end();it_temp++){
                    string id=it_temp->first;
                    vector<int> vec=it_temp->second;
                    if(findset(vec[0])==findset(vec[1]))
                        continue;
                    merge(vec[0],vec[1]);
                    _ret.push_back(id);
                    
                }
            }
            for(int i=0;i<cnt;i++)
                if(p[i]!=0)
                findset(i);
            for(int i=0;i<cnt;i++)
                if(p[i]!=0)
                return "IMPOSSIBLE";
            sort(_ret.begin(),_ret.end());
            for(int i=0;i<_ret.size();i++)
                if(ret=="")
                    	ret+=_ret[i];
                    else
                        ret+=" "+_ret[i];
            return ret;
    }
    };
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

//Find partition in increasing then decreasing sequence
int bsFindPartition(VI ar){
    int i=0,j=sz(ar)-1;
    while(i<j){
        int mid= i+(j-i)/2;
        if(i==(j-1)){
            return ar[mid]<=ar[mid+1]?mid+1:mid;
        }
        if(ar[mid]>ar[mid+1]&&ar[mid]>=ar[mid-1]){
            return mid;
        }
        else if(ar[mid]>=ar[mid-1]&&ar[mid+1]>=ar[mid]){
            i=mid+1;
        }
        else{
            j=mid;
        }
    }
    return -1;
}

//find element in the rotated sorted sequence
int bsFindInRotated(VI ar,int k){
    int i=0,j=sz(ar)-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(ar[mid]==k){
            return mid;
        }
        if(ar[mid]<ar[i]&&ar[mid]<ar[j]){
            if(k>=ar[i]||k<ar[mid]){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        else if(ar[mid]>ar[i]&&ar[mid]>ar[j]){
            if(k>ar[mid]||k<=ar[j]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        else{
            if(k>ar[mid])
                i=mid+1;
            else{
                j=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    VI v;
    v.pb(6);
    v.pb(7);
    v.pb(3);
    v.pb(4);
    v.pb(5);
    cout<<bsFindInRotated(v,8);
}

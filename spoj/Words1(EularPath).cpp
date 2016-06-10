#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
 using namespace std;

 int main()
 {
     int t;
     cin>>t;
     int s[26],e[26];
     bool dp[26][26];
     while(t--)
     {

     memset(s,0,sizeof(s));
     memset(e,0,sizeof(e));
     memset(dp,0,sizeof(dp));
         int n;
         cin>>n;
         string text;
         for(int i=0;i<n;i++){
             cin>>text;
             int a=text[0]-'a';
             int b=text[text.length()-1]-'a';
             s[a]++;
             e[b]++;
             dp[a][b]=1;
         }
         for(int k=0;k<26;k++)
            for(int i=0;i<26;i++)
                for(int j=0;j<26;j++)
                    dp[i][j]=dp[i][j]||(dp[i][k]&&dp[k][j]);
        int last=-1;
        bool flag=true;
        for(int i=0;i<26;i++)
        {
            if(s[i]>0||e[i]>0)
            {
                if(last==-1)
                    last=i;
                else if(dp[last][i]==0&&dp[i][last]==0)
                {
                    flag=false;
                    break;
                }
            }
        }
        cout<<flag;
        int temp[3];
        temp[0]=temp[1]=temp[2]=0;
        if(flag)
        {
            for(int i=0;i<26;i++)
            {
                if(abs(s[i]-e[i])<=1)
                    temp[s[i]-e[i]+1]++;
                else
                {
                    flag=false;
                    break;
                }
            }
            if(!(temp[0]<=1&&temp[2]<=1))
                flag=false;
        }
        if(flag)
            cout<<"Ordering is possible.\n";
        else
            cout<<"The door cannot be opened.\n";
     }
     return 0;
 }

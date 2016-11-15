#include<iostream>
using namespace std;
const int sz=2;
class trie{
private:
    struct trieNode{
        trieNode* children[sz];
        trieNode(){
        for(int i=0;i<sz;i++){
            children[i]=NULL;
        }
        }
        ~trieNode(){
                for(int i=0;i<sz;i++){
                        delete children[i];
                        children[i]=NULL;
                }
        }
    };
    trieNode* root;
public:
        trie(){
                root = new trieNode();
        }
        void insert(unsigned int n){
                trieNode* temp = root;
                unsigned int one =1;int cnt=31;
                while(cnt>=0){
                        unsigned int n2=(n&(one<<cnt))>>cnt;
                        if(temp->children[n2]==NULL){
                                temp->children[n2] =  new trieNode();
                        }
                        temp=temp->children[n2];
                        cnt--;
                }
        }
        int getMax(int n){
                trieNode* temp = root;
                int curr=0;
                int cnt=31;
                unsigned int one =1;
                while(temp!=NULL){
                        unsigned int n3=(n&(one<<cnt))>>cnt;
                        if(temp->children[!n3]!=NULL){
                                curr=curr|((!n3)<<cnt);
                                temp = temp->children[!n3];
                        }
                        else if(temp->children[n3]!=NULL){
                                curr=curr|(n3<<cnt);
                                temp = temp->children[n3];
                        }
                        else{
                                break;
                        }
                        cnt--;
                }
                //cout<<curr<<"\n";
                return curr^n;
        }
};
int main(){
        int n;
        cin>>n;
        int mx=0;
        trie trieTree;
        for(int i=0;i<n;i++){
                int a;
                cin>>a;
                if(i>0)
                mx = max(mx,trieTree.getMax(a));
                trieTree.insert(a);
        }
        cout<<mx;
        return 0;
}

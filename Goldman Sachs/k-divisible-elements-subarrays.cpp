struct Node{
    unordered_map<int,Node*> links;
    bool flag=false;
    bool containsKey(int ch){
        return (links.find(ch)!=links.end());
    }
    void put(int ch,Node* node){
        links[ch]=node;
    }
    Node* get(int ch){
        return links[ch];
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    int count(vector<int>& v,int k,int p) {
        Node* node=root;
        int cnt=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            int div=0;
            node=root;
            for(int j=i;j<n;j++){
                if(v[j]%p==0){
                    if(div==k) break;
                    div++;
                }
                if(!node->containsKey(v[j])){
                    cnt++;
                    node->put(v[j],new Node());
                }
                node=node->get(v[j]);
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int countDistinct(vector<int>& v, int k, int p) {
        Trie t;
        return t.count(v,k,p);
    }
};

class Solution {
public:
    void help(int cur,int k,int n,vector<int>& v,vector<vector<int>>& ans){
        if(k==0 && n==0){
            ans.push_back(v);
            return;
        }
        if(k==0 || n==0){
            return;
        }
        for(int num=cur;num<=9;num++){
            if(num<=n){
                v.push_back(num);
                help(num+1,k-1,n-num,v,ans);
                v.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> ans;
        help(1,k,n,v,ans);
        return ans;
    }
};

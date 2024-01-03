class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>& v){
        int n=v.size();
        int m=v[0].size();
        return (i>=0 && j>=0 && i<n && j<m);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& v) {
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(v.size(),vector<int>(v[0].size(),0));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        vector<vector<int>> ans(v.size(),vector<int>(v[0].size(),0));
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int h=it.first;
            int i=it.second.first;
            int j=it.second.second;
            ans[i][j]=h;
            if(isValid(i+1,j,v) && vis[i+1][j]==0){
                q.push({h+1,{i+1,j}});
                vis[i+1][j]=1;
            }
            if(isValid(i-1,j,v) && vis[i-1][j]==0){
                q.push({h+1,{i-1,j}});
                vis[i-1][j]=1;
            }
            if(isValid(i,j+1,v) && vis[i][j+1]==0){
                q.push({h+1,{i,j+1}});
                vis[i][j+1]=1;
            }
            if(isValid(i,j-1,v) && vis[i][j-1]==0){
                q.push({h+1,{i,j-1}});
                vis[i][j-1]=1;
            }
        }
        return ans;
    }
};

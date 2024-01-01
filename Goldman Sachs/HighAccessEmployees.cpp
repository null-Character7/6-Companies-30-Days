class Solution {
public:
    #define ff first
    #define ss second
    bool withinOneHour(pair<int,int>& a,pair<int,int>& b){
        if(a.ff==b.ff || (a.ff+1==b.ff && b.ss<a.ss)){
            return true;
        }
        return false;
    }
    bool highAccess(vector<pair<int,int>>& v){
        int n=v.size();
        for(int i=0;i<n-2;i++){
            if(withinOneHour(v[i],v[i+1]) && withinOneHour(v[i],v[i+2])){
                return true;
            }
        }
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& v) {
        unordered_map<string,vector<pair<int,int>>> m;
        for(auto it:v){
            int hh=stoi(it[1].substr(0,2));
            int mm=stoi(it[1].substr(2,2));
            m[it[0]].push_back({hh,mm});
        }
        for(auto& arr:m){
            sort(arr.ss.begin(),arr.ss.end());
        }
        vector<string> ans;
        for(auto it:m){
            if(highAccess(it.ss)){
                ans.push_back(it.ff);
            }
        }
        return ans;
    }
};

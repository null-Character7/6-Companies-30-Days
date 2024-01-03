class Solution {
public:

    void help(string &s,string &x,map<int,string>& m,vector<string>& ans,int ind){
        if(ind==s.length()){
            ans.push_back(x);
            return;
        }
        for(int i=0;i<m[s[ind]-'0'].length();i++){
            x.push_back(m[s[ind]-'0'][i]);
            help(s,x,m,ans,ind+1);
            x.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        map<int,string> m;
        m[2]="abc",m[3]="def",m[4]="ghi",m[5]="jkl",m[6]="mno",m[7]="pqrs",m[8]="tuv",m[9]="wxyz";
        int ind=0;
        string x;
        help(digits,x,m,ans,ind);
        return ans;
    }

};

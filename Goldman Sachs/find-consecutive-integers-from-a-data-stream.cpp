class DataStream {
public:
stack<pair<int,int>> s;
int last,val;
    DataStream(int value, int k) {
        last=k;
        val=value;
    }
    
    bool consec(int num) {
        if(last==1 && num==val){
            return true;
        }
        if(s.empty()){
            s.push({num,1});
            if(last==1 && num==val){
                return true;
            }
            return false;
        }
        if(s.top().first==val && num==val){
            auto it=s.top();
            s.pop();
            cout<<it.second<<endl;
            if(it.second<last-1){
                it.second++;
                s.push(it);
                return false;
            }
            else {
                s.push(it);
                return true;
            }
        }
        s.push({num,1});
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

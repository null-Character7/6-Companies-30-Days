class Solution {
public:
    
    unordered_set<int> flipped;
    int m,n,total;
    Solution(int m, int n) {
        this->n=m;
        this->m=n;
        total=m*n;
    }
    
    vector<int> flip() {
        if(flipped.size()==total){
            return {};
        }
        int ind=rand()%total;
        while(flipped.find(ind)!=flipped.end()){
            ind++;
            ind%=total;
        }
        int i=(ind/m);
        int j=(ind%m);
        flipped.insert(ind);
        return {i,j};
    }
    
    void reset() {
        flipped.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

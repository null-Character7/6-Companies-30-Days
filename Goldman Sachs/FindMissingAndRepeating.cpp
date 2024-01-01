vector<int> findTwoElement(vector<int> v, int n) {
        // code here
        // 1 2 3 4 5 ... x x ....
        // 1 2 3 4 5 ... x y .... 
        int xxor=0; // x ^ y
        for(int i=0;i<n;i++){
            xxor ^= v[i];
            xxor ^= (i+1);
        }
        int bitNo=0;
        while(xxor){
            if((xxor & (1<<bitNo))!=0){
                break;
            }
            bitNo++;
        }
        int setBit=0; // x
        int unsetBit=0; // y
        for(int i=0;i<n;i++){
            if((v[i] & (1<<bitNo))!=0){
                setBit ^= v[i];
            }
            else{
                unsetBit ^= v[i];
            }
            if(((i+1) & (1<<bitNo))!=0){
                setBit ^=(i+1);
            }
            else{
                unsetBit ^= (i+1);
            }
        }
        for(int i=0;i<n;i++){
            if(v[i]==setBit){
                return {setBit,unsetBit};
            }
            if(v[i]==unsetBit){
                return {unsetBit,setBit};
            }
        }
        return {-1};
}

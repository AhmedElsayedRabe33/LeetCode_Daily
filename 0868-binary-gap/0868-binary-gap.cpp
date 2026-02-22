class Solution {
public:
    int binaryGap(int n) {
        vector<int>pos;
        for(int i = 0 ; i < 32 ; i ++){
            if((1<<i)&n){
                pos.push_back(i);
            }
        }
        if(pos.size()==1)
            return 0;
        int ans = 0 ;
        for(int i =1 ; i <pos.size();i++){
            ans =max(ans , abs(pos[i] - pos[i-1]));
        }
        return ans ;
    }
};
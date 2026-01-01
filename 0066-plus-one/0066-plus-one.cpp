class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int  n = digits.size();
        vector<int>ans;
        bool ok =false;
        for(int i = n-1 ; i >= 0 ; i--){
            if(digits[i]<9){
                digits[i]++;
                ok = true;
                break;
            }
            else{
                digits[i]=0;
            }
        }
        if(ok){
            for(auto it : digits)
            ans.push_back(it);
        }
        else{
            ans.push_back(1);
            for(auto it : digits)
            ans.push_back(it);
        }
        return ans ;
    }
};
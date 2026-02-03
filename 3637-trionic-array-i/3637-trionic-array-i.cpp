class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for(int i  = 1 ; i < n ; i++){
            for(int j = i+1 ; j <n-1 ;j++ ){
               // first must be increasing
               bool ok1 = true;
               int a = (i+1), b= j-i+1 , c = n-j ;
               for(int k = 0 ;k+1 <=i ;k++){
                    if(nums[k+1]<=nums[k]){
                        ok1 = false;
                        break;
                    }
               }
               bool ok2 = true;
               for(int k = i ;k+1 <=j ;k++){
                    if(nums[k+1]>=nums[k]){
                        ok2 = false;
                        break;
                    }
               }
               bool ok3 = true;
               for(int k = j ;k+1 < n ;k++){
                    if(nums[k+1]<=nums[k]){
                        ok3 = false;
                        break;
                    }
               }
               if(ok1 && ok2 && ok3 && (a>1) && (b>1) &&(c>1))
                 return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        for(int i = 0 ; i < arr.size() ;i++){
            int cnt =0  ;
            for(int j = 0 ; j<32 ;j++){
                if(arr[i]&(1<<j)){
                    cnt++;
                }
            }
            v.push_back({cnt,arr[i]});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto it : v)
            ans.push_back(it.second);
        return ans ;
    }
};
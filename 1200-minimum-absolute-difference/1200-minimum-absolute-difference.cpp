class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int mn = arr[1] - arr[0];
        for(int i = 1 ; i < arr.size() ;i++){
            mn = min(mn , arr[i] - arr[i-1]);
        }
        for(int i =1 ; i < arr.size(); i++){
            if((arr[i]-arr[i-1] )== mn ){
                vector<int>cur{arr[i-1],arr[i]};
                ans.push_back(cur);
            }
        }
        return ans ; 
    }
};
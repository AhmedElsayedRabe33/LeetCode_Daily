class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans ,tmp;
        int cur = 0 ;
        for(auto it : s){
            cur+=(it=='(');
            cur-=(it==')');
            tmp+=it;
            if(cur==0){
                tmp.pop_back();
                reverse(tmp.begin(),tmp.end());
                tmp.pop_back();
                reverse(tmp.begin(),tmp.end());
                ans+=tmp;
                tmp.clear();
            }
        }
        return ans;
    }
};
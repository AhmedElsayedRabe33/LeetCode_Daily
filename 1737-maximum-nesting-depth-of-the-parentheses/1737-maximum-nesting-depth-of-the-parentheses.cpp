class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int cnt = 0 ;
        for(auto it : s){
            if(it=='('){
                st.push(it);
            }
            else if(it==')'){
                st.pop();
            }
            cnt = max<int>(cnt ,st.size());
        }
        return cnt;
    }
};
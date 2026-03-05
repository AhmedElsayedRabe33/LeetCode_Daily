class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        int a = 0 ,b =0;
        for(int i =0,j=1 ; i <s.size();i++){
            if((s[i]-'0')!=j)
                a++;
            j^=1;
        }
         for(int i =0,j=0 ; i <s.size();i++){
            if((s[i]-'0')!=j)
                b++;
            j^=1;
        }
        ans = min(a,b);
        return ans;
    }
};
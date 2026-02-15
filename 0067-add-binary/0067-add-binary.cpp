class Solution {
public:
    string addBinary(string a, string b) {
        while (a.size() < b.size())
            a = '0' + a;
        while (a.size() > b.size())
            b = '0' + b;
        string ans(a.size(),'0');
        int carry = 0 ;
        for(int i =a.size()-1 ; i>=0 ;i--){
            if(a[i]=='1' && b[i]=='1' && carry){
                ans[i] = '1';
            }
            else if(a[i]=='1' && b[i]=='1' ){
                carry++;
            }
            else if(a[i]=='0' && b[i]=='0' && carry){
                ans[i]='1';
                carry--;
            }
            else if(a[i]=='1' && b[i]=='0' && !carry){
                ans[i]='1';
            }

            else if(a[i]=='0' && b[i]=='1' && !carry){
                ans[i]='1';
            }
        }
        if(carry>0)
            ans='1'+ans;
        return ans ;
    }
};
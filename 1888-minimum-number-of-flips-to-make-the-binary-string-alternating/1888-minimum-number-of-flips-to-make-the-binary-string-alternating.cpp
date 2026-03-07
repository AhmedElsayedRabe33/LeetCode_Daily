class Solution {
public:
    int minFlips(string s) {
        int ans = 1e9 , n =s.size();
        s += s;
        vector<int> e(s.size() + 1), o(s.size() + 1), ee(s.size() + 1),
            oo(s.size() + 1);

        for (int i = 1; i < s.size(); i++) {
            if (i & 1) {
                // o ==> 1
                // oo ==> 0
                if (s[i] == '1') {
                    o[i]++;
                } else {
                    oo[i]++;
                }
            } else {
                 // e ==> 0
                // oo ==> 1
                if (s[i] == '0') {
                    e[i]++;
                } else {
                    ee[i]++;
                }
            }
            if(i){
                o[i]+=o[i-1]; // 1 odds 
                e[i]+=e[i-1]; // 0 even
                oo[i]+=oo[i-1]; // 0 odds
                ee[i]+=ee[i-1];// 1 even
            }
        } /// 5 -----
        if(n&1){
            int a = ((n+1)/2) - e[n-1]; // 0 even
            a+=( n/2)-  o[n-1]; // 1 odd
            ans = min(ans ,a );
            int b = ((n+1)/2) - ee[n-1];   // 1 even
            b+= (n/2) - oo[n-1];       // 0 odds
            ans = min(ans , b);
        }
        else{
            int a = ((n)/2) - e[n-1]; // 0 even
            a+=( n/2)-  o[n-1]; // 1 odd
            ans = min(ans ,a );
            int b = ((n)/2) - ee[n-1];   // 1 even
            b+= (n/2) - oo[n-1];       // 0 odds
            ans = min(ans , b);
        }
        for(int i =n ;i<s.size();i++){
            
            int a = ((n+1)/2) -(e[i] - e[i-n]) ; // 0 even
            a+=( n/2)- (o[i] - o[i-n]) ; // 1 odd
            ans = min(ans ,a );
            int b = ((n+1)/2) -(ee[i] - ee[i-n]);   // 1 even
            b+= (n/2) -(oo[i] - oo[i-n]);       // 0 odds
            ans = min(ans , b);
        }
        return ans ;
    }
};
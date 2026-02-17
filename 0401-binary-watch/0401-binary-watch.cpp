class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int>val{1,2,4,8,1,2,4,8,16,32};
        vector<string>ans;
        int n =val.size();
        for(int mask =0  ; mask < (1ll<<n);mask++){
            int a = 0 ,b =0 ;
            int cnt = 0 ;
           for (int i = 0; i < 10; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    if (i < 4)
                        a += val[i];
                    else
                        b += val[i];
                }
            }
            if(cnt == turnedOn && a <12 && b<60){
                string aa = to_string(a);
                string bb = to_string(b);
                if(bb.size()==1)
                    bb = '0'+bb;
                    string res = aa+':'+bb;
                ans.push_back(res);
            }
        }
        return ans;
    }
};
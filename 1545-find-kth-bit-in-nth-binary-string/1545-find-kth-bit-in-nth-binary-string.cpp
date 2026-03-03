class Solution {
public:
    char findKthBit(int n, int k) {
        function<string(string)> calc=[&](string a)->string{
            string ret;
            for(int i =a.size()-1 ; i>=0;i--){
                char me = (a[i]=='1'?'0':'1');
                ret+=me;
            }
            return ret;
        };
        string me="0";
        while(me.size()<k){
            string tmp = calc(me);
            me = me + '1'+tmp;
        }   
        cout <<me<<endl; 
        return me[k-1];
    }
};
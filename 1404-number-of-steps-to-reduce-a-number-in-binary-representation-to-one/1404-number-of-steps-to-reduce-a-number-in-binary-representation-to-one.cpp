class Solution {
public:
    int numSteps(string s) {
        // now i want to check if a cur num is even or odd
        int ans = 0 ;
        while(s.size()>1){
            if(s[s.size()-1]=='0'){
                ans++;
                s.pop_back();
            }
            else{
                ans++;
                // u have to add one to this string !
                    // how u can add !!!
                    // just loop on this string from last with carry 
                    int carry = 1;
                    for(int i = s.size() -1 ; i>=0;i--){
                        if(s[i]=='1' && carry){
                            s[i] = '0';
                        }
                        else if(carry && s[i]=='0'){
                            s[i] ='1';
                            carry =  0;
                            break;
                        }
                    }
                    if(carry)
                        s = '1'+s;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '{';
        for(auto it : letters){
            if(it>target)
                ans = min(ans , it);
        }
        return (ans=='{'?letters[0]:ans) ;
    }
};
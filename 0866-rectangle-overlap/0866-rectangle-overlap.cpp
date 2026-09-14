class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a = rec1[0];
        int b = rec1[1];
        int c = rec1[2];
        int d = rec1[3];

        int e = rec2[0];
        int f = rec2[1];
        int g = rec2[2];
        int h = rec2[3];

        return (max(a,e) < min(c,g) and max(b,f) < min(d,h));
    }
};
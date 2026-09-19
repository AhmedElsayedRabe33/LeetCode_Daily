class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int X = xCenter , Y =yCenter;
        if(X<x1){
            X = x1;
        }
        if(X>x2){
            X=x2;
        }
        if(Y<y1){
            Y = y1;
        }
        if(Y>y2){
            Y=y2;
        }
        long long  dis = (abs(X-xCenter)*abs(X-xCenter)) + (abs(Y-yCenter)*abs(Y-yCenter));
        if(dis<=(radius*radius)){
            return true;
        }
        return false;
    }
};
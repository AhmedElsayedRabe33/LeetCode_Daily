class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        function<int(vector<int>)> calc = [&](vector<int> a) -> int {
            int mx = 1, cur = 1;
            sort(a.begin(), a.end());
            for (int i = 1; i < a.size(); i++) {
                if (a[i] == (a[i - 1] + 1)) {
                    cur++;
                } else {
                    cur = 1;
                }
                mx = max(mx, cur);
            }
            return mx;
        };
        int a = calc(hBars) + 1, b = calc(vBars) + 1;
        return min(a, b)*min(a,b);
    }
};
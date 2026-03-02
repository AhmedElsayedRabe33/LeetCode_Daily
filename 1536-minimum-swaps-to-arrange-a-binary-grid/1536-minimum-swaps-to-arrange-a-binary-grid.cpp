#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) cnt++;
                else break;
            }
            trailing[i] = cnt;
        }

        vector<int> used(n, 0);
        vector<int> target;
        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && trailing[j] >= need) {
                    used[j] = 1;
                    target.push_back(j);
                    found = true;
                    break;
                }
            }
            if (!found) return -1;
        }
        ordered_set<int> st;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int x = target[i];
            ans += st.size() - st.order_of_key(x);
            st.insert(x);
        }
        return ans;
    }
};
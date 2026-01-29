class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = changed.size();
        vector<pair<int , int >> adj[30];
        for(int i =0 ; i < n ; i++){
            int x = original[i] -'a';
            int y = changed[i] -'a';
            adj[x].push_back({y,cost[i]});
        }
               const long long INF = 1e18;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for(int s = 0; s < 26; s++){
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            dist[s][s] = 0;
            pq.push({0, s});

            while(!pq.empty()){
                auto [d, u] = pq.top(); pq.pop();
                if(d > dist[s][u]) continue;

                for(auto [v, w] : adj[u]){
                    if(dist[s][v] > d + w){
                        dist[s][v] = d + w;
                        pq.push({dist[s][v], v});
                    }
                }
            }
        }
         long long ans = 0;
         n = source.size();

        for(int i = 0; i < n; i++){
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if(a == b) continue;
            if(dist[a][b] == INF) return -1;
            ans += dist[a][b];
        }

        return ans ;
    }
};
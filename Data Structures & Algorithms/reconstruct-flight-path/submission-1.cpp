class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        sort(tickets.begin(), tickets.end());
        for (auto& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }
        vector<string> res;
        dfs("JFK", res, adj);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string src, vector<string>& res, unordered_map<string, deque<string>>& adj) {
        while (!adj[src].empty()) {
            string next = adj[src].front();
            adj[src].pop_front();
            dfs(next, res, adj);
        }
        res.push_back(src);
    }
};

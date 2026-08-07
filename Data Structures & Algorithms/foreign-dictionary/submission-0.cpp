class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;  
    string ans;

    bool dfs(int node) {
        if (vis[node] == 1) return true;  
        if (vis[node] == 2) return false;  

        vis[node] = 1;

        for (int nxt : adj[node]) {
            if (dfs(nxt))
                return true;
        }

        vis[node] = 2;
        ans.push_back(node + 'a');
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        adj.assign(26, {});
        vis.assign(26, 0);
        vector<int> present(26, 0);
        for (auto &word : words) {
            for (char ch : word)
                present[ch - 'a'] = 1;
        }

        int n = words.size();

        for (int i = 0; i < n - 1; i++) {

            if (words[i].size() > words[i + 1].size() &&
                words[i].substr(0, words[i + 1].size()) == words[i + 1])
                return "";

            int len = min(words[i].size(), words[i + 1].size());

            for (int j = 0; j < len; j++) {
                if (words[i][j] != words[i + 1][j]) {
                    adj[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
                    break;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (present[i] && vis[i] == 0) {
                if (dfs(i))
                    return "";
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
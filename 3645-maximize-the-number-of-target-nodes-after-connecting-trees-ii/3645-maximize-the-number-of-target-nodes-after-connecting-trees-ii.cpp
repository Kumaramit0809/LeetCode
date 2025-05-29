class Solution {
public:
    unordered_map<int, vector<int>>
    getAdjacenyList(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent,
             vector<int>& mark, int& oneMarkedCount, int& zeroMarkedCount) {
        if (mark[curr] == 0) {
            zeroMarkedCount++;
        } else {
            oneMarkedCount++;
        }

        for (auto& ngbr : adj[curr]) {
            if (ngbr != parent) {
                mark[ngbr] =
                    (mark[curr] == 0) ? 1 : 0; 
                dfs(ngbr, adj, curr, mark, oneMarkedCount, zeroMarkedCount);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        unordered_map<int, vector<int>> adjA = getAdjacenyList(edges1);
        unordered_map<int, vector<int>> adjB = getAdjacenyList(edges2);

        vector<int> markA(N, -1);
        int oneMarkedCountA = 0;
        int zeroMarkedCountA = 0;
        markA[0] = 0; 
        dfs(0, adjA, -1, markA, oneMarkedCountA, zeroMarkedCountA);

       
        vector<int> markB(M, -1);
        int oneMarkedCountB = 0;
        int zeroMarkedCountB = 0;

        markB[0] = 0; 
        dfs(0, adjB, -1, markB, oneMarkedCountB, zeroMarkedCountB);

        int maxEleFromTree2 = max(oneMarkedCountB, zeroMarkedCountB);

        vector<int> res(N);
        for (int i = 0; i < N; i++) {
            
            res[i] = (markA[i] == 0 ? zeroMarkedCountA : oneMarkedCountA) +
                     maxEleFromTree2;
        }
        return res;
    }
};
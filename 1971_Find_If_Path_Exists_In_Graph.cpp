class Solution {
public:
    
    /**
     * @brief 
     * 
     * From Breadth First Search
     * Runtime: O(V+E)
     * Space: O(V) 
     * 
     * Assumptions: No Duplicate Edges, Nodes, No Self Edgesx
     * Optimizations
     */
    void DFS(const vector<vector<int>> & adj_list,
             vector<bool> &visited,
             int curr,
             const int & end,
             bool & path_exists){
        
        visited[curr] = true;
        if(curr == end){
            path_exists = true;
            return;
        }
        
        for(auto adj_node: adj_list[curr]){
            if(visited[adj_node] == false){
                DFS(adj_list, visited, adj_node, end, path_exists);
            }
        }

        return;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        if(start == end) return true;
        if(n == 0 || edges.size() == 0) return false;

        /* Create Adjacency List */
        vector<vector<int>> adj_list(n, vector<int>{});
        for(auto edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        
        /* Perform DFS */
        vector<bool> visited(n,false);
        bool path_exists = false;
        DFS(adj_list, visited, start, end, path_exists);
        return path_exists;
    }
};
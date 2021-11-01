class Solution {
public:
    
    bool DFS(unordered_map<int, vector<int>> &adj_list, int source, int dest, vector<bool>& visited){
        
        /* IF there is any vertex with 0 out going edges, it must be destination */
        if(!adj_list[source].size()){
            return source == dest;            
        }
        
        /* If cycle is found in that recursion stack return false */
        if(visited[source]){
            return false;
        }
        
        /* Set as visited to identify infinite loop over current node */
        visited[source] = true;
        
        for(auto next_source: adj_list[source]){
            
           bool result = DFS(adj_list, next_source, dest, visited);
           if (result == false){
                return result;
           }
        }
        
        /* Reset the visited before backtracking */
        visited[source] = false;
        return true;
        
        
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, vector<int>> adj_list;
        for(auto edge : edges){
            adj_list[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(n, false);
        bool result = DFS(adj_list, source, destination, visited);
        return result;
    }
};
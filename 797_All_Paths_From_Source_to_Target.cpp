class Solution {
public:

    /**
     * @brief 
     * 
     * From All Paths From Source to Target - Using Backtracking
     * Runtime: O(2^N * N) - At most 2^N Paths in which there is N elements that we must fill each path with.
     * Space: O(N) - Number of Nodes can be the longest amount of recursive calls on stack
     * 
     * Assumptions: No Self Loops, Duplicates
     * Optimizations
     */
    
    void DFS(const vector<vector<int>>& graph, 
             vector<vector<int>> &possible_paths,
             vector<int> current_path,
             int curr_node){
        current_path.push_back(curr_node);
        if(curr_node == graph.size()-1){
            possible_paths.push_back(current_path);
            return;
        }
        
        for(auto path: graph[curr_node]){
            DFS(graph, possible_paths, current_path, path);
        }
        
        return;
        
    }

    void DFS_backtrack(const vector<vector<int>>& graph, 
             vector<vector<int>> &possible_paths,
             vector<int> &current_path,
             int curr_node){
        current_path.push_back(curr_node);
        if(curr_node == graph.size()-1){
            possible_paths.push_back(current_path);
            return;
        }
        
        for(auto path: graph[curr_node]){
            DFS(graph, possible_paths, current_path, path);
            current_path.pop_back();
        }
        
        return;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vectoraint>> possible_paths;
        vector<int> path;
        DFS_backtrack(graph, possible_paths, path, 0);
        // DFS_no_bt(graph, possible_paths, {}, 0);
        return possible_paths;
    }
};
class Solution {
public:
    
    void DFS(const vector<int>& arr, 
            unordered_map<int, vector<int>> & adj_list, 
            vector<int> &visited, int path_len,
            int curr_idx){
        
        if(visited[curr_idx] > path_len){
            visited[curr_idx] = path_len;
        }else{
            return;
        }
        if(curr_idx == arr.size()-1){
            return;
        }
        path_len++;
        
        int cur_val = arr[curr_idx];
        int l_idx = curr_idx-1;
        int r_idx = curr_idx+1;
        if(l_idx > 0){
            DFS(arr, adj_list, visited, path_len, l_idx);
        }
        if(r_idx < arr.size()){
            DFS(arr, adj_list, visited, path_len, r_idx);
        }
        for(auto shrt_cut: adj_list[cur_val]){
            DFS(arr, adj_list, visited, path_len, shrt_cut);
        } 
        
        return;

    }
    
    int minJumps(vector<int>& arr) {
        
        if(arr.size()==1){
            return 0;
        }
        vector<bool> visited(arr.size(), false);
        unordered_map<int, vector<int>> adj_list;
        
        for(int i=arr.size()-1; i >= 0; i--){
            adj_list[arr[i]].push_back(i);
        }
        
        queue<pair<int,int>>q; // idx, path_len
        q.emplace(0,0);
        /* BFS */
        while(!q.empty()){
            
            pair<int, int> node = q.front();
            q.pop();
            
            int cur_idx = node.first;
            int cur_val = arr[cur_idx];
            visited[cur_idx] = true;
            
            if(cur_idx == arr.size()-1){
                return node.second;
            }
            int l_idx = cur_idx-1;
            int r_idx = cur_idx+1;
            if(l_idx > 0 && !visited[l_idx]){
                q.emplace(l_idx, node.second+1);
            }
            if(r_idx < arr.size() && !visited[r_idx]){
                q.emplace(r_idx, node.second+1);
            }
            for(auto shrt_cut: adj_list[cur_val]){
                if(visited[shrt_cut] != true){
                    q.emplace(shrt_cut, node.second+1);
                }
            } 
            
            
        }

        return -1;
    }
};
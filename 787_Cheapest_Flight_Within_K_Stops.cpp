class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        /**
            O(V^2 * log(V)) time - O(V^2) for going through each neighbour for a node, and log(v) for min-heap sort
            O(V^2) - from adjacency matrix
        
        **/
        if(src == dst){
            return 0;
        }
        
        /* Form Adjacency List */
        vector<vector<pair<int,int>>> adj_list(n);
        for(auto flight: flights){
            adj_list[flight[0]].push_back({flight[1],flight[2]});
        }
        
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0,src,0}); // (Cost, node_id, stops);
        
        while(!pq.empty()){
            int cost = pq.top()[0];
            int node_id = pq.top()[1];
            int stops = pq.top()[2];
            pq.pop();
            
            if(node_id == dst){
                return cost;
            }  

            if(stops > k){
                continue;
            }


            for(auto flights : adj_list[node_id]){
                int new_cost = cost+flights.second;
                int new_node_id = flights.first;
                int new_stop_count = stops+1;
                pq.push({new_cost, new_node_id, new_stop_count});

                
            }
            
        }
        

        return -1;
        
        
    }
};
class Solution {
public:
    
    /*
        Time: O(ElogE + E) for sort and dfs. 
        Space O(V + E) for dfs stack and adj_list. 

    */
    
    void DFS(unordered_map<string, deque<string>> & mappings, 
             vector<string> & itinerary,
             string curr_loc){

        while(mappings[curr_loc].size() != 0){
            string next_loc = mappings[curr_loc].front();
            mappings[curr_loc].pop_front();
            DFS(mappings, itinerary, next_loc);
        }
        
        itinerary.push_back(curr_loc);    
        return;
    
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, deque<string>> mappings;
        string starting_location = "JFK";
        
        /* Populate the mappings into adjacency list using queue to order lexically*/
        sort(tickets.begin(), tickets.end());
        for(auto ticket: tickets){
            mappings[ticket[0]].push_back(ticket[1]);
            
        }
        
        /* Perform DFS and Populate the Itinerary */
        vector<string> itinerary;
        DFS(mappings, itinerary, starting_location);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
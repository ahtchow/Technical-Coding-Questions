class Solution {
public:
    
    /**
    
    Runtime: O(n) - by adding to visit set, we only need to perform DFS until we see all the nodes once.
    Space: O(n) - set used to store maximum n visited nodes.
    
    **/
    
    void DFS(const int city, unordered_set<int> &visitedCities, const vector<vector<int>> &isConnected ){
        visitedCities.insert(city);
        for(int path = 0; path < isConnected[city].size(); path++){
            if(isConnected[city][path] == 1 && visitedCities.find(path) == visitedCities.end()){
                DFS(path, visitedCities, isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfProvinces = 0;
        unordered_set<int> visitedCities = {}; 
        
        /* Loop through each city */
        for(int startCity = 0; startCity < isConnected.size();  startCity++){
            
            /* Haven't seen this city before */
            if(visitedCities.find(startCity) == visitedCities.end()){
                numOfProvinces++;
                DFS(startCity, visitedCities, isConnected);
            }
        }
        
        return numOfProvinces;
        
        
    }
};
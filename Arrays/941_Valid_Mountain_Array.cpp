class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3){
            return false;
        }
        
        int i = 1;
        // Increasing only
        while(i < arr.size() && arr[i] > arr[i-1]){
            i++;
        }
        
        // Must not be first element or past last element
        if(i == 1 || i == arr.size()){
            return false;
        }
        
        // Decreasing Only
        while(i < arr.size() && arr[i] < arr[i-1]){
            i++;
        }
        
        // Must be passed last element
        return i == arr.size();
        
    }
};
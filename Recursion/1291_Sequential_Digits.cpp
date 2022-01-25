class Solution {
public:
    
    void dfs(const int & low, const int & high, vector<int> & ans, int num, int digit){

        if(num >= low && num <= high){
            ans.push_back(num);
        } 
        
        if(digit < 9 && num <= high){
            dfs(low, high, ans, num*10 + (digit+1) , digit+1);
        }
        
        return;
        
        
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++){
            dfs(low, high, ans, i, i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
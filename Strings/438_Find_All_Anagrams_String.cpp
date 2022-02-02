class Solution {
public:
    
    /*
    
    Using Sliding window approach
    O(n) - space
    O(1) - space
    
    
    
    */
    
    vector<int> findAnagrams(string s, string p) {
        
        int N = s.size();
        int M = p.size();
        vector<int> ans;
        if(N<M) return ans;

        vector<int> p_map(26), s_map(26);
        
        for(char ch: p){
            p_map[ch-'a']++;
        }
        
        int left = 0;
        int right = M-1;
        for(int i = left; i < p.size(); i++){
            s_map[s[i]-'a']++;
        }
        s_map[s[right]-'a']--;
        
        while(right < N){
            
            s_map[s[right]-'a']++;

            if(s_map == p_map){
                ans.push_back(left);
            }
            
            s_map[s[left]-'a']--;
            left++;
            right++;
            
        }
        
        return ans;
        
        
    }
};
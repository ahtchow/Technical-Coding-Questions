class Solution {
public:
    
    /**
    
        ["eat","tea","tan","ate","nat","bat"]
        
        {
            "aet": ["eat","tea"],
            "ant": ["tan", "nat", "bat"],
        }
        
        O(nklog(k)) - sort (klog(k)) , list iteration n words
        O(n*k) - k is max length of string, n is length of the strs array (Hashmap)
        Alternative Solution: dont sort letter fors nlog(n), go through and count asci sums for n.
    **/
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams;
        for(auto str: strs){
            string str_srtd = str;
            sort(str_srtd.begin(), str_srtd.end());
            anagrams[str_srtd].push_back(str);
        }
        
        vector<vector<string>> anagram_list;
        for(auto anagram: anagrams){
            anagram_list.push_back(anagram.second);
        }
        return anagram_list;
    }
};
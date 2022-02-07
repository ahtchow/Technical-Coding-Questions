class Solution {
public:
    char findTheDifferenceHM(string s, string t) {
        /*
        O(n), O(n);
        
        */
        unordered_map<char, int> hm;
        char diff;
        
        for(char c: s){
            hm[c]++;
        }
        for(char c: t){
            hm[c]++;
        }
        for(auto c: hm){
            if (c.second % 2 != 0){
                diff = c.first;
                break;
            }
        }
        return diff;
        
    }
    
    char findTheDifference(string s, string t) {
        /*
        O(n), O(1);
        
        */
        
        int count_s = 0;
        int count_t = 0;
        for(int i = 0; i < s.size(); i++){
            count_s += s[i] - 'a';
        }
        for(int i = 0; i < t.size(); i++){
            count_t += t[i] - 'a';
        }
        
        char diff = 'a' + char(abs(count_s-count_t));
        return diff;
    }
};
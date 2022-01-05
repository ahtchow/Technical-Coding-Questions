class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        /* For there to be judge 

            - everyone must trust the judge: n-1 people must trust the judge
            - judge can not trust anyone. (consider this case by decrementing)

        */

        vector<int> trust_counter(n, 0);

        for(auto t: trust){
            trust_counter[t[0]-1]--;;
            trust_counter[t[1]-1]++;
        }

        for(int i = 0; i < trust_counter.size(); i++){
            if(trust_counter[i] == n-1){
                return i+1;    
            }

        }

        return -1;

    }
};
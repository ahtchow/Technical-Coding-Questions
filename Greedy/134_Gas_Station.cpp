class Solution {
public:
    /*
    
    - There are n gas stations along a circular route 
    - Amount of gas at the ith station is gas[i]
    - You have a car with an unlimited gas tank (start with no gas, but size if unlimited)
    - Costs cost[i] of gas to travel from the ith station to its next (i + 1)th
    - You begin the journey with an empty tank at one of the gas stations.
    
    
    
    */
    int canCompleteCircuitBruteForce(vector<int>& gas, vector<int>& cost) {
        /* Brute Force - try every gas station */
        int gas_tank;
        int counter;
        int len_track = gas.size();
        for(int i = 0; i < gas.size(); i++){
            gas_tank = 0;
            counter = 0;
            for(int j = 0; j < gas.size(); j++){
                int idx = (i+j) % len_track;
                /* Fill gas at station and pay to go to next */
                gas_tank += gas[idx] - cost[idx];
                if(gas_tank < 0){
                    break;
                }
                counter++;
            }
            if(counter == gas.size()){
                return i;
            }
        }
        
        return -1;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        /* Greedy - If we fail at a gas station, start over at that gas station 
            This method will always reult in the starting location with largest build up of gas.
        
        */
        int start = 0;
        int gas_tank = 0;
        int net_gas = 0;

        for(int i = start; i < gas.size(); i++){
            gas_tank += gas[i] - cost[i];
            net_gas += gas[i] - cost[i];
            if(gas_tank < 0){
                start = i + 1;
                gas_tank = 0;
            }
        }
        
        /* If trip is not even possible */
        if(net_gas < 0) return -1;
        
        return start;
    }
    
    
};
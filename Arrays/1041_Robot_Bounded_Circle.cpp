class Solution {
public:

    /*
    O(n) - runntime
    O(1) - space

    */
    struct direction{
        int x;
        int y;
    };
        
    unordered_map<int, direction> moves{{90,{0,1}}, 
                                        {180, {-1, 0}}, 
                                        {270, {0,-1}}, 
                                        {0, {1,0}} 
                                       };
    
    bool isRobotBounded(string instructions) {

        direction curr = {0,0};
        int heading = 90;
        for(auto instr: instructions){
            
            if(instr == 'G'){
                curr.x += moves[heading].x;
                curr.y += moves[heading].y;
            } else if(instr == 'L'){
                heading  = (heading + 90) % 360;
            } else{
                heading  = (heading + 270) % 360;
            }
                        
            
        }
        cout << heading << endl;
        /* Inutition: If we are at orgin or not facing North , we are in a loop */
        if ((curr.x == 0 && curr.y == 0) || heading != 90){
            return true;
        }
        
        
        return false;
        
    }
};
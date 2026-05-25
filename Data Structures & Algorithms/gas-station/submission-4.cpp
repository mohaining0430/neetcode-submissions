class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < 
                accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        
        // Otherwise, there must be an answer.
        int start = 0;
        int total_gas = 0, total_cost = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            if (total_gas < total_cost) {
                start = i + 1;
                total_gas = total_cost = 0;
            }
        }
        return start;
    }
};

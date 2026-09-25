class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < 
                accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int start = 0, gasTotal = 0, costTotal = 0;
        for (int i = 0; i < gas.size(); ++i) {
            gasTotal += gas[i];
            costTotal += cost[i];
            if (gasTotal < costTotal) {
                start = i + 1;
                gasTotal = 0;
                costTotal = 0;
            }
        }
        return start;
    }
};
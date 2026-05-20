// Can skip
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<car> cars;
        for (int i = 0; i < position.size(); ++i) 
            cars.push_back(car(position[i], speed[i]));
        sort(cars.begin(), cars.end(), std::greater<car>());
        stack<car> res;
        for (const auto car : cars) {
            if (!res.empty() && 
                (float)(target - res.top().position) / (float)res.top().speed >=
                (float)(target - car.position) / (float)car.speed)
                continue;
            res.push(car);
        }
        return res.size();
    }

private:
    struct car {
        int position;
        int speed;
        car(int p, int s) : position(p), speed(s) {}
        bool operator > (const car& c) const {
            return position > c.position;
        }
    };
};

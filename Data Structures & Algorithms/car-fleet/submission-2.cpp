class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<car> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.push_back(car(position[i], speed[i]));
        }
        sort(cars.begin(), cars.end(), std::greater<car>());

        stack<car> s;
        for (const auto car : cars) {
            if (!s.empty() && (float)(target - car.position) / (float)car.speed <= 
                (float)(target - s.top().position) / (float)s.top().speed)
                continue;
            s.push(car);
        }
        return s.size();
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

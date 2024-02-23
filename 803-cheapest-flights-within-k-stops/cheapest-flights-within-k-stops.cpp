class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize distance array with maximum possible values
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    // Relax edges for k stops
    for (int i = 0; i <= k; ++i) {
        vector<int> temp(distance);
        for (const auto& flight : flights) {
            if (distance[flight[0]] != INT_MAX && distance[flight[0]] + flight[2] < temp[flight[1]]) {
                temp[flight[1]] = distance[flight[0]] + flight[2];
            }
        }
        distance = temp;
    }

    // Check if destination is reachable
    if (distance[dst] == INT_MAX) {
        return -1;
    } else {
        return distance[dst];
    }
    }
};
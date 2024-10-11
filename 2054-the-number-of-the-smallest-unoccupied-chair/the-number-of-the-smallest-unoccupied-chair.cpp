
struct friendList{
    int number ; 
    int start ; 
    int end ; 
    int ans ; 

    // we have overload the bracket operator and than apply the sorting logic 
     // You can define the "less than" operator instead of using operator()
    bool operator<(const friendList& other) const {
        if (start < other.start) return true;
        else if (start == other.start) {
            return end < other.end;
        }
        return false;
    }
};
class Solution {
public:
    void print(friendList arr[], int n ){
        for (int i=0 ;i<n ;i++){
            cout<<"("<<arr[i].start <<","<<arr[i].end<<")"<<arr[i].number <<arr[i].ans ;
        }
        cout<<endl;
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // step create your own custom data structure 
        int n = times.size();
        friendList arr [n];

        for (int i=0 ;i<n;i++ ){
            arr[i].number = i;
            arr[i].start = times[i][0];
            arr[i].end = times[i][1];
            arr[i].ans = -1;
        }

        // step 2 : sort the friends timing according to their starting time 
        sort(arr, arr + n);
        print(arr,n);
// Min-heap for available chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; i++) availableChairs.push(i);  // Initially, all chairs are available

        // Min-heap to track friends leaving: (leave time, chair number)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingEvents;

        // Step 4: Process each friend in sorted order and assign chairs
        for (int i = 0; i < n; i++) {
            int currentTime = arr[i].start;

            // Free up chairs for friends who have already left by this time
            while (!leavingEvents.empty() && leavingEvents.top().first <= currentTime) {
                availableChairs.push(leavingEvents.top().second);  // Free the chair
                leavingEvents.pop();
            }

            // Assign the smallest available chair
            int assignedChair = availableChairs.top();
            availableChairs.pop();

            // Store the result in the arr structure
            arr[i].ans = assignedChair;

            // Add the leaving event for this friend (when they leave, free the chair)
            leavingEvents.push({arr[i].end, assignedChair});

            // If this is the target friend, return the assigned chair
            if (arr[i].number == targetFriend) {
                return assignedChair;
            }
        }

        // Default return (shouldn't happen for valid input)
        return -1;
    }
};
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        // If the current numeral is smaller than the next one, subtract it
        if (i < s.length() - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
            result -= romanMap[s[i]];
        }
        // Otherwise, add the value of the current numeral
        else {
            result += romanMap[s[i]];
        }
    }

    return result;
    }
};
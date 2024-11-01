class Solution {
public:
  

bool toNumCheck(string s) {
    // Leading zeroes are not allowed unless the number is zero
    if (s.empty() || (s.size() > 1 && s[0] == '0')) return false;
    
    int num = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (!isdigit(s[i])) return false;
        num = num * 10 + (s[i] - '0');
        if (num > 255) return false; // Exceeds IPv4 range
    }
    return true;
}

bool isValidIPv4(string ipAddress) {
    string temp;
    int n = ipAddress.size();
    if (ipAddress[0] == '.' || ipAddress[n - 1] == '.') return false;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        char ch = ipAddress[i];
        if (ch == '.') {
            if (temp.empty() || !toNumCheck(temp)) return false;
            count++;
            temp.clear();
        } else if (isdigit(ch)) {
            temp.push_back(ch);
            if (temp.size() > 3) return false; // Exceeds segment length for IPv4
        } else {
            return false;
        }
    }
    return (count == 3 && !temp.empty() && toNumCheck(temp));
}

bool toNumCheck2(string s) {
    int n = s.size();
    if (n < 1 || n > 4) return false;
    
    for (char ch : s) {
        if (!isxdigit(ch)) return false; // Check for valid hex digit
    }
    return true;
}

bool isValidIPv6(string ipAddress) {
    string temp;
    int n = ipAddress.size();
    if (ipAddress[0] == ':' || ipAddress[n - 1] == ':') return false;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        char ch = ipAddress[i];
        if (ch == ':') {
            if (temp.empty() || !toNumCheck2(temp)) return false;
            count++;
            temp.clear();
        } else if (isxdigit(ch)) {
            temp.push_back(ch);
            if (temp.size() > 4) return false; // Exceeds segment length for IPv6
        } else {
            return false;
        }
    }
    return (count == 7 && !temp.empty() && toNumCheck2(temp));
}

string validIPAddress(string queryIP) {
    int n = queryIP.size() ; 
    if (n==0 )return "Neither";
    if (isValidIPv4(queryIP)) {
        return "IPv4";
    } else if (isValidIPv6(queryIP)) {
        return "IPv6";
    } else {
        return "Neither";
    }
}

};
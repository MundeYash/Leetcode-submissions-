class Solution {
public:
    bool isValid(string str ) {

        stack<char> s;

	for (int i = 0; str [i] != '\0'; ++i)
	{
		char ch = str [i];
		switch (ch) {
		case '{':
		case '(':
		case '[':
			s.push(ch);
			break;
		case ')':
			if (s.empty() || s.top() != '(') {
				return false;
			}
			s.pop();
			break;
		case '}':
			if (s.empty() || s.top() != '{') {
				return false;
			}
			s.pop();
			break;
		case ']':
			if (s.empty() || s.top() != '[') {
				return false;
			}
			s.pop();
		}
	}

	if (s.empty()) return true;
	else return false;
        
    }
};
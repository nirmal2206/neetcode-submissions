class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                else if (st.top() != getPair(ch)) return false;
                else st.pop();
            }
        }
        return st.empty();

    }
    char getPair(char ch){
        if(ch == ')') return '(';
        else if(ch == '}') return '{';
        else if(ch == ']') return '[';
        return '\0';
    }
};

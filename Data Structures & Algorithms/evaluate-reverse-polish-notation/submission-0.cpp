class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s: tokens){
            if(s!="+" && s!="-" && s!="*" && s!="/"){
                st.push(stoi(s));
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ans = operate(b, a, s);
                st.push(ans);
            }
        }
        return st.top();
    }

    int operate(int a, int b, string op){
        if(op == "+"){
            return a+b;
        } else if(op == "-"){
            return a-b;
        } else if(op == "*"){
            return a*b;
        } else if(op == "/"){
            return a/b;
        }
    }
};

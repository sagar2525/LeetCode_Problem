class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char ch;
        for(int i =0;i<s.length();i++){
            ch = s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char chtop= st.top();
                    if(chtop=='(' && ch==')'){
                        st.pop();
                    }
                    else if(chtop=='{' && ch=='}'){
                        st.pop();
                    }
                    else if(chtop=='[' && ch==']'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
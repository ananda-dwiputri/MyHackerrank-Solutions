bool IsPair(char a, char b)
{
    if(a == '[' and b == ']') return 1;
    if(a == '{' and b == '}') return 1;
    if(a == '(' and b == ')') return 1;
    return 0;
}
// Complete the isBalanced function below.
string isBalanced(string s) {
    int len = s.length();
    stack<char> S;

    if(len == 0){
        return "YES";
    }

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' or s[i] == '{' or s[i] == '[')
            S.push(s[i]);
        else{
            if(S.empty() or !IsPair(S.top(), s[i]))
                return "NO";
            else
                S.pop();
        }
    }

    return S.empty() ? "YES" : "NO";
}

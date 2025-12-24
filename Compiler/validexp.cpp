#include<vector>
#include<iostream>
#include<string>
#include<cctype>
#include<stack>
using namespace std;

bool checkparen(const string &s){
    stack<char> st;

    for(char m:s){
        if(m=='('){
            st.push(m);
        }else if(m==')'){
            if(st.empty()) return false;
            st.pop();
        }
    } 
    return st.empty();
}
bool checkvalid(const string &s){
    if(s.empty()) return false;
    if(!checkparen(s)) return false;

    for(size_t i=0;i<s.length();i++){
        char c=s[i];

        if(isalpha(c) && i+1<s.size() && isalpha(s[i+1])){
            return false;
        }
        if(!isalnum(c) && c!='=' && c!='+' && c!='-' && c!='(' && c!=')' && c!='/' && c!='*' && c!=' '){
            return false;
        }

        if((c=='*' || c=='/' || c=='+' || c=='-')&& i+1<s.size()){
            if(s[i+1]=='*' || s[i+1]=='/' || s[i+1]=='+' || s[i+1]=='-'){
                if(!(s[i]=='=' && s[i+1]=='-')){
                    return false;
                }
            }
        }
    }
    return true;
}
bool isValidExpression(const string &expr) {
   if (expr.empty()) return false;
   if (!checkparen(expr)) return false;
   for (size_t i = 0; i < expr.size(); i++) {
       char c = expr[i];
       if (!isalnum(c) && c != '=' && c != '+' && c != '-' &&
           c != '*' && c != '/' && c != '(' && c != ')' && c != ' ')
           return false;
       if (isalpha(c) && i + 1 < expr.size() && isalpha(expr[i + 1]))
           return false;
       if ((c == '*' || c == '/' || c == '+' || c == '-') && i + 1 < expr.size()) {
           if (expr[i + 1] == '*' || expr[i + 1] == '/' || expr[i + 1] == '+' || expr[i + 1] == '-') {
               // allow "-a" (unary minus)
               if (!(expr[i] == '=' && expr[i + 1] == '-'))
                   return false;
           }
       }
   }
   return true;
}

int main(){
    string s;
    getline(cin,s);

    if(checkvalid(s)){
        cout<<"Valid Expression";
    }else{
        cout<<"Invalid Expression";
    }
}
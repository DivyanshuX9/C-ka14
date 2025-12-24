#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
using namespace std;

bool key(const string &s){
    vector<string> ar={"int","float","double","short","long","if","else","for","while","do","switch","case","return","void","char","bool"};
    for(auto i:ar){
        if(i==s) return true;
    }
    return false;
}
int main(){
    string n;
    getline(cin,n);

    stringstream ss(n);
    string token;

    regex identifier("^[a-zA-Z0-9][a-zA-Z0-9_]*$");
    regex number("^[0-9]+(\\.[0-9]+)?$");

    vector<string> op={"+","*","%","-","/","=","==","<",">","<=",">=","!=","&&","||","!","++","--"};
    vector<char> punct={',','(',')','{','}',';'};

    while(ss >> token){
        if(key(token)){
            cout<<token<<" : Keyword"<<endl;
        }
        else if(regex_match(token,identifier)){
            cout<<token<<" : Identifier"<<endl;
        }
        else if(regex_match(token,number)){
            cout<<token<<" : Number"<<endl;
        }
        else if(find(op.begin(),op.end(),token)!=op.end()){
            cout<<token<<" : Operator"<<endl;
        }
        else if(token.length()==1 && find(punct.begin(),punct.end(),token[0])!=punct.end()){
            cout<<token<<" : Punctuation"<<endl;
        }
        else{
            cout<<token<<" : Not a valid identifier"<<endl;
        }
    } 
    return 0;
}
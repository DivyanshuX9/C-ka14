#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include<regex>

using namespace std;

bool identi(string s){
    string ar[]={"int","float","double","short","long","if","else","for","while","do","switch","case","return","void","char","bool"};
    for(auto i:ar){
        if(i==s) return true;
    }
    return false;
}

int main(){
    string s;
    cin>>s;

    regex identifier("^[a-zA-Z0-9][a-zA-Z0-9_]*$");

    regex number("^[0-9]+(\\.[0-9]+)?$");

    if(identi(s)){
        cout<<"Keyword";
    }
    else if(regex_match(s,identifier)){
        cout<<"Identifier";
    }
    else if(regex_match(s,number)){
        cout<<"Number";
    }
    else{
        cout<<"Not a valid identifier";
    }

    return 0;
}
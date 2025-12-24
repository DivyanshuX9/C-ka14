#include <iostream>

using namespace std;
class uni{
    public:
    void inp1(){
    char name[50];
    char uniID[50];}
};
class faculty : public uni{
    public:
    void inp(){
    char rank[50];}
};
class undergrad : public uni{
    public:
    void inp(){
    int year;}
};
class grad : public uni{
    public:
    void inp(){
    char supID[50];}
};
//class info : virtual public uni,public faculty,public undergrad,public grad{};
int main(){
    cout<<"Enter the number of people to add"<<endl;
    int n;
    cin>>n;
    faculty f[n];int s1=0;
    undergrad u[n];int s2=0;
    grad g[n];int s3=0;
    for(int i=0;i<n;i++){
        cout<<"ENTER THE POSITON"<<endl;
        int nm;
        cin>>nm;
        if(nm==1){
            f[s1].inp1();
            f[s1].inp();
            s1++;
        }
        else if(nm==2){
            u[s2].inp1();
            u[s2].inp();
            s2++;
        }
         else{
            g[s3].inp1();
            g[s3].inp();
            s3++;
        }
    }
    return 0;
}
#include<stdio.h>
#include<string.h>


void check(char arr[n][m],char m,int n,int m){
     int largest=0;
    int day=0;
    int Pdays[n];
    int conseday[n];
    int pre=0;
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0;j<m;j++){
             if(arr[i][j]==m){
                s++;
            }
        }
        if(s==m){
            day+=1;
            Pdays[pre]=i+1;pre++;
        }
        else{
            if(largest<day){
                largest=day;
                for(int a=0;a<pre;a++){
                    conseday[a]=Pdays[a];}
                pre=0;
            }
            day=0;
            }
        }
    printf("%d",largest);
       for(int a=0;a<pre;a++){
            printf("%d ",conseday[a]);
            }
}
int main(){
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    char arr[n][m];
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
    }
    check(arr[n][m],'P',n,m);
    check(arr[n][m],'A',n,m);
    return 0;
        }
    
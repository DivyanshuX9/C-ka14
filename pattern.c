#include<stdio.h>
int main(){
    int s=11;
    for(int i=1;i<=5;i++){s=11;
        for(int j=1;j<=i;j++){
            s*=11;
        }printf("%d/n",s);
    }return 0;
}
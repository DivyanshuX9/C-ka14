#include <stdio.h>
#include <string.h>

static char arr[100][100];
void www(int n,int m){
    int Pcount=0;
    int Acount=0;
    int equal=0;
    int Pgreat[100];int pre=0;int prex=0;
    int Agreat[100];int abt=0;int abtx=0;
    int PAequal[100];int eq=0;int eqx=0;
     for (int i = 0; i < n; i++) {
        int s = 0; 
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'P') {
                Pcount++;
            }else if(arr[i][j] == 'A'){
                Acount++;
            }else{
                equal++;
            }
    }
        if(Pcount>Acount)
        {
            Pgreat[pre]=i+1;pre++;
        }
        else if(Acount>Pcount){
            Agreat[abt]=i+1;abt++;
        }else{
            PAequal[eq]=i+1;eq++;
        }
     }
     for(int i=0;i<pre;i++){
         printf("%d ",Pgreat[i]);
     }printf("\n");
     for(int i=0;i<abt;i++){
         printf("%d ",Agreat[i]);
     }printf("\n");
     for(int i=0;i<eq;i++){
         printf("%d ",PAequal[i]);
     }printf("\n");
}
void check(char x, int n, int m) {
    int largest = 0;
    int day = 0;
    int Pdays[n];
    int conseday[n];
    int pre = 0;
    
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == x) {
                s++;
            }
        }
        if (s == m) {
            day += 1;
            Pdays[pre] = i + 1;
            pre++;
        } else {
            if (day>largest) {
                largest = day;
                for (int a = 0; a < pre; a++) {
                    conseday[a] = Pdays[a];
                }
                pre = 0;
            }
            day = 0;
        }
    }
    
    printf("%d\n", largest);
    for (int a = 0; a < pre; a++) {
        printf("%d ", conseday[a]);
    }
}

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    
    check('P', n, m);
    check('A', n, m);
    www(n,m);
    return 0;
}

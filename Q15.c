#include<stdio.h>
#include<string.h>
int main(){
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    char arr[n][m+1];
    for(int i=0;i<n;i++){
        char arr2[m+1];
        scanf("%s",arr2);
        strcpy(arr[i],arr2);
    }
    // part 1 - all present
    char arr2[m];
    for(int i=0;i<m;i++){
        arr2[i]='P';
    }
    arr2[m]='\0';
    int max=0,count;
    int pdays[n];int s=0;
    for(int i=0;i<n;){
        if(strcmp(arr[i],arr2)==0){
            count=1;
            for(int j=i+1;j<n;j++){
                if(strcmp(arr[j],arr2)==0){
                    count+=1;
                    pdays[s]=i+1;s++;
                }else{
                    break;
                }
            }
            
            if(count>max){
                max=count;
            }
            i+=count;
        }else{
            i+=1;
        }
    }
    printf("no of continuous days all are present %d\n",max);
    for(int i=0;i<s;i++){
        printf("%d",pdays[i]);
    }printf("\n");
    // part 2 - all absent
    for(int i=0;i<m;i++){
        arr2[i]='A';
    }
    arr2[m]='\0';
    for(int i=0;i<n;){
        if(strcmp(arr[i],arr2)==0){
            count=1;
            for(int j=i+1;j<n;j++){
                if(strcmp(arr[j],arr2)==0){
                    count+=1;
                }else{
                    break;
                }
            }
            if(count>max){
                max=count;
            }
            i+=count;
        }else{
            i+=1;
        }
    }
    printf("\nno of continuous days all are absent%d",max);
    // part 3 - number of student present > number of student absent
    int i=0;
    int count_p=0;
    int count_a=0;
    int no_of_days_more_present[n];
    int more_present=0,more_absent=0,equal=0;
    int no_of_days_more_absent[n];
    int no_of_days_equal[n];
    while(i<n){
        count_p=0;
        count_a=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]=='P'){
                count_p+=1;
            }else if(arr[i][j]=='A'){
                count_a+=1;
            }
        }
        if(count_p>count_a){
            no_of_days_more_present[more_present]=i;
            more_present+=1;
        }else if (count_a>count_p){
            no_of_days_more_absent[more_absent]=i;
            more_absent+=1;
        }else{
            no_of_days_equal[equal]=i;
            equal+=1;
        }
        i++;
    }
    printf("\n");
    for(int a=0;a<more_present;a++){
        printf("%d ",no_of_days_more_present[a]);
    }
    printf("\n");
    for(int x=0;x<more_absent;x++){
        printf("%d ",no_of_days_more_absent[x]);
    }
    printf("\n");
    for(int y=0;y<equal;y++){
        printf("%d ",no_of_days_equal[y]);
    }
    return 0;
}
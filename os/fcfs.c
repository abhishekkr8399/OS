#include <stdio.h>
struct process{
    int pid,bt,wt,tt;
};
int main(){
    int i,n,totwt=0,tottt=0;
    float avgwt,avgtt;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    struct process p[n]; 
    for(i=0; i<n; i++){
        p[i].pid=i+1;
        printf("Enter burst time for process-%d : ", (i+1));
        scanf("%d",&p[i].bt);
    }
    p[0].wt=0; 
    p[0].tt=p[0].bt+p[0].wt; 
    for(i=1; i<n; i++) {
        p[i].wt=p[i-1].bt+p[i-1].wt; 
        p[i].tt=p[i].wt+p[i].bt;
    }
    for(i=0; i<n; i++){
        totwt=totwt+p[i].wt;
        tottt=tottt+p[i].tt;
    }
    avgwt=(float)totwt/n;
    avgtt=(float)tottt/n;
    printf("\nTotal Waiting Time : %dms\nAverage Waiting Time : %.2fms",totwt,avgwt);
    printf("\nTotal turn-around time : %dms\nAverage turn-around time : %.2fms",tottt,avgtt);
return 0;
}
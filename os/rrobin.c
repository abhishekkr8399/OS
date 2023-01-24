#include <stdio.h>
struct process {
int pid,bt,wt,tt;
};
int main(){
    int i,n,tq,time=0,totwt=0,tottt=0,flag=0;
    float avgwt,avgtt;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    struct process p[n];
    int remBT[n];
    for(i=0; i<n; i++){
        p[i].pid=i+1;
        printf("Enter burst time for process-%d : ",i+1);
        scanf("%d",&p[i].bt);
        remBT[i]=p[i].bt;
    }
    printf("\nEnter the time quantum : ");
    scanf("%d",&tq);
    while(flag==0){
        flag=1; 
        for(i=0; i<n; i++){
            if(remBT[i]>0){
                flag=0;
                if(remBT[i]>tq) {
                    time=time+tq;
                    remBT[i]=remBT[i]-tq;
                }
                else {
                    time=time+remBT[i];
                    remBT[i]=0;
                    p[i].tt=time;
                    p[i].wt=p[i].tt-p[i].bt;
                }
            }
        }
    }
    for(i=0; i<n; i++) {
        totwt=totwt+p[i].wt;
        tottt=tottt+p[i].tt;
    }
    avgwt=(float)totwt/n;
    avgtt=(float)tottt/n;
    printf("\nTotal Waiting Time : %dms\nAverage Waiting Time : %.2fms",totwt,avgwt);
    printf("\nTotal turn-around time : %dms\nAverage turn-around time : %.2fms",tottt,avgtt);
    return 0;
}

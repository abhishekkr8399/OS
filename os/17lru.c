#include<stdio.h>
void main() {
    int n,f,i,j,free,min,index,found,pos=0,time=0,pf=0;
    printf("Enter the number of pages : ");
    scanf("%d",&n);
    int ref[n];
    printf("Enter number of frames : ");
    scanf("%d",&f);
    free=f;
    int frame[f],count[f];
    for(j=0; j<f; j++) {
        frame[j]=-1;
        count[j]=0;
    }
    printf("Enter the reference string : ");
    for(i=0; i<n; i++)
    scanf("%d",&ref[i]);
    for(i=0;i<n;i++) {
        found=0;  
        for(j=0;j<f;j++) {
            if(frame[j]==ref[i]) {
                count[j]=time;
                found=1; 
                break;
            }
        }
        if(!found) {
            if(free) {
                frame[pos]=ref[i];
                pf++;
                free--;
                count[pos]=time;
                pos++;
            }
            else {
                min=count[0];
                index=0; 
                for(j=1;j<f;j++) 
                    if(count[j]<min) {
                        min=count[j];
                        index=j;
                    }
                    frame[index]=ref[i];
                    count[index]=time;
                    pf++;
            }
        }
         time++;
         printf("%d -> ",ref[i]);
         for(j=0; j<f; j++)
           printf(" %d ",frame[j]);
        if(found==0) printf("\tPage miss\n");
        else printf("\tPage hit\n");
    }
    printf("\nNo of page faults:%d\n",pf);
}

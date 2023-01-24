#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,f,i,j,found,victim=-1,pf=0;
    printf("Enter the number of pages : ");
    scanf("%d",&n);
    int ref[n];
    printf("Enter number of frames : ");
    scanf("%d",&f);
    int frame[f];
    for(j=0; j<f; j++)
        frame[j]=-1;
    printf("Enter the reference string : ");
    for(i=0; i<n; i++)
        scanf("%d",&ref[i]);
    printf("\nFIFO Page Replacement\n");
    for(i=0; i<n; i++){
        found=0; 
        for(j=0; j<f; j++) 
            if(frame[j]==ref[i]){
                found=1; 
                break;
            }
            if(!found){
                pf++;
                victim=(victim+1)%f;
                frame[victim]=ref[i];
            }
            printf("%d -> ",ref[i]);
            for(j=0; j<f; j++)
            	printf(" %d ",frame[j]);
            if(found==0) printf("\tPage miss\n");
		 else printf("\tPage hit\n");
    }
    printf("\nTotal number of page faults : %d\n",pf);
    return 0;
}

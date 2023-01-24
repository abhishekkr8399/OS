#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int n, f;
int optimal(int ref[], int frame[], int optindex[], int index){
    int pos, found, max, i, j;
    for (i = 0; i < f; i++){
        found = 0;
        for (j = index + 1; j < n; j++){
            if (frame[i] == ref[j]){
                found = 1;
                optindex[i] = j;
                break;
            }
        }
        if (!found)
            return i;
    }
    max = optindex[0];
    pos = 0;
    for (i = 1; i < f; i++){
        if (max < optindex[i]){
            max = optindex[i];
            pos = i;
        }
    }
    return pos;
}
int main(){
    int i, j, found, count = 0, pf = 0, victim = -1;
    printf("Enter the number of pages : ");
    scanf("%d", &n);
    int ref[n];
    printf("Enter number of frames : ");
    scanf("%d", &f);
    int frame[f], optindex[f];
    for (j = 0; j < f; j++){
        frame[j] = -1;
        optindex[j] = -1;
    }
    printf("Enter the reference string : ");
    for (i = 0; i < n; i++)
        scanf("%d", &ref[i]);
    for (i = 0; i < n; i++){
        found = 0;
        for (j = 0; j < f; j++){
            if (ref[i] == frame[j]){
                found = 1;
                break;
            }
        }
        if (!found){
            count++;
            if (count <= f)
                victim++;
            else
                victim = optimal(ref, frame, optindex, i);
            pf++;
            frame[victim] = ref[i];
        }
        printf("%d -> ", ref[i]);
        for (j = 0; j < f; j++)
            printf(" %d ", frame[j]);
        if (found == 0)
            printf("\tPage miss\n");
        else
            printf("\tPage hit\n");
    }
    printf("\nNumber of page fault:%d\n", pf);
}
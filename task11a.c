#include<stdio.h> 
/* FCFS DISK SCHEDULING ALGORITHM  */
void main() 
{ 
    int t[20], n, i, j, tohm[20], tot=0; 
    float avhm; 
    printf("enter the no.of tracks: "); 
    scanf("%d",&n); 
    printf("enter the tracks to be traversed: "); 
    for(i=0;i<n;i++) 
        scanf("%d",&t[i]); 
    // tohm[0] = t[0]-10;
    for(i=1;i<n+1;i++) 
    { 
        tohm[i]=t[i]-t[i-1]; 

        if(tohm[i]<0) 
            tohm[i]=tohm[i]*(-1); 
        tot += tohm[i];
    } 
    avhm=(float)tot/n; 
    printf("Tracks traversed\tDifference between tracks\n"); 
    for(i=0;i<n;i++) 
        printf("%d\t\t\t%d\n",t[i],tohm[i]); 
    // printf("")
    printf("\nAverage header movements:%f", avhm); 
} 
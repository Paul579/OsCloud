#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int main() 
{ 
    int mx[10][10], req[10][10], allc[10][10], avl[10], cmplt[10], sfseq[10]; 
    int p, r, i, j, pro, ct; 
    ct = 0; 
    p=5;//process count
    for(i = 0; i< p; i++) 
        cmplt[i] = 0; 
    r=4;//resource count 
	printf("\nEnter the max values for all processes: "); 
    for(i = 0; i < p; i++) 
    { 
        printf("\nFor process no.%d : ", i + 1); 
        for(j = 0; j < r; j++) 
            scanf("%d", &mx[i][j]); 
    } 
 
    printf("\nEnter the allocation values for all processes: "); 
    for(i = 0; i < p; i++) 
    { 
        printf("\nFor process no.%d : ",i + 1); 
        for(j = 0; j < r; j++) 
            scanf("%d", &allc[i][j]); 
    } 
 
    printf("\n\nEnter the available number of resources: "); 
    for(i = 0; i < r; i++) 
        scanf("%d", &avl[i]); 
 
    for(i = 0; i < p; i++) 
 
        for(j = 0; j < r; j++) 
            req[i][j] = mx[i][j] - allc[i][j]; 
 
        do 
        { 
            printf("\n Max matrix:\tAllocation matrix:\n"); 
 
            for(i = 0; i < p; i++) 
            { 
                for( j = 0; j < r; j++) 
                    printf("%d ", mx[i][j]); 
                printf("\t\t"); 
                for( j = 0; j < r; j++) 
                    printf("%d ", allc[i][j]); 
                printf("\n"); 
            } 
 
            pro = -1; 
 
            for(i = 0; i < p; i++) 
            { 
                if(cmplt[i] == 0)//if not cmplt 
                { 
                    pro = i ; 
                    for(j = 0; j < r; j++) 
                    { 
                        if(avl[j] < req[i][j]) 
                        { 
                            pro = -1; 
                            break; 
                        } 
                    } 
                } 
                if(pro != -1) 
                    break; 
            } 
 
            if(pro != -1) 
            { 
                printf("\nProcess no.%d gets finished.", pro + 1); 
                sfseq[ct] = pro + 1; 
                ct++; 
                for(j = 0; j < r; j++) 
                { 
                    avl[j] += allc[pro][j]; 
                    allc[pro][j] = 0; 
                    mx[pro][j] = 0; 
                    cmplt[pro] = 1; 
                } 
            } 
        } 
        while(ct!=p && pro!=-1); 
 
        if(ct==p) 
        { 
            printf("\nThe system is in safe state.\n"); 
            printf("Safe Sequence : < "); 
            for( i = 0; i < p; i++) 
                printf("P%d ", sfseq[i]); 
            printf(">\n"); 
        } 
        else 
            printf("\nThe system is in unsafe state."); 
}



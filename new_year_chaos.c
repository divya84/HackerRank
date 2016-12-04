#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int min_bribes(int *q, int n) {
        int sum = 0, curr_diff=0;
        int j;
        for(int i = n-1; i >= 0 ; i--) {
                curr_diff = q[i] - (i+1);
                if(curr_diff > 2) {
                        return -1;
                }
                j = q[i] - 2;
                if(j < 0) j=0;
                while(j < i){
                        if(q[j] > q[i]) sum++;
                        j ++;
                }
        }
        return sum;
}

int main(){
    int T;
    scanf("%d",&T);
    int * bribes_list = malloc(sizeof(int) * T);
    for(int a0 = 0; a0 < T; a0++){
        int n;
        scanf("%d",&n);
        int *q = malloc(sizeof(int) * n);
        for(int q_i = 0; q_i < n; q_i++){
           scanf("%d",&q[q_i]);
        }
        bribes_list[a0] = min_bribes(q, n);
        free(q);
    }

    for(int a0 = 0; a0 < T; a0++){
        if(bribes_list[a0] == -1)
                printf("Too chaotic\n");
        else
                printf("%d\n", bribes_list[a0]);
    }

    return 0;
}

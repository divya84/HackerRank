/* Given a n k find lexicographically smallest absolute permuation of value k */


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t;
    scanf("%d",&t); /* Number of inputs */ 
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        scanf("%d %d",&n,&k);


        if(k == 0) {
            int i;
            for(i=0; i<n; i++)
                printf("%d ", i+1);
            printf("\n");
            continue;
        }

        int index = 0;
        int count = 1;
        if(((n%k) == 0) && ((n/k)%2 == 0)) {
            int * perm = malloc(sizeof(int) * (n+1));
            for(int j = 0; j < n/(k*2); j++) {
                for(int m = 0; m < k; m++) {
                    int curr_index = index + m;
                    int curr_count = count + m;
                    perm[curr_index] = curr_count+k;
                    perm[curr_index+k] = curr_count;
                }
                index+=k*2; count+=k*2;
            }
            for (int j = 0; j < n; j++)
                printf("%d ", perm[j]);
            printf("\n");
            free(perm);
        }
        else  printf("-1\n");
    }

    return 0;
}

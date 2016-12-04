

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b

int comp(const void * int_A, const void * int_B) {
        int a = *((int*)int_A);
        int b = *((int*)int_B);
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
}

/* Returns the distance to the nearest space station */
unsigned int bin_search_for_ss(int *c, int x,  size_t left, size_t right) {
        size_t mid = left + ((right - left)/2);
//      printf("x = %d, mid = %d\n", x, mid);
        if(left == right)
                return abs(c[mid] - x);

        if(x == c[mid]) return 0;

        if(x < c[mid]) {
                if(x >= c[mid-1])
                        return min(c[mid] - x, x - c[mid-1]);
                return bin_search_for_ss(c, x, left, mid-1);
        }

        if (x <= c[mid+1])
                return min(c[mid+1] - x, x - c[mid]);
        return bin_search_for_ss(c, x, mid + 1, right);
}

int main(){
    int n;
    int m;
    scanf("%d %d",&n,&m);
    int *c = malloc(sizeof(int) * m);
    for(int c_i = 0; c_i < m; c_i++){
       scanf("%d",&c[c_i]);
    }
    qsort(c, m, sizeof(int), &comp);
    int max_dist = 0;

    for(int i = 0; i < n; i++) {
        int dist = bin_search_for_ss(c, i, 0, m-1);
        max_dist = max(max_dist, dist);
    }
    printf("%d\n", max_dist);
    return 0;
}


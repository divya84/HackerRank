
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int FindMedian(int * arr, int f, int l, int m) { 
    if(m==1)
        return arr[0]; 
    if(f==l)
        return arr[f]; 
    int j = f;
    int p = arr[l]; 
    for(int i = f; i <= l; i++) { 
        if(arr[i] <= p) { 
            int temp = arr[j]; 
            arr[j] = arr[i]; 
            arr[i] = temp;
            j++; 
        }
    }
    
    if((j-1) == m)
        return arr[j-1]; 
    if(m < j) 
        return FindMedian(arr, f, j-2, m); 
    else 
        return FindMedian(arr ,j , l, m); 
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; 
    cin >> n; 
    int * arr = new int[n]; 
    for(int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    }
    cout << FindMedian(arr, 0, n-1, n/2); 
    return 0;
}

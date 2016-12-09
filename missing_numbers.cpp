#include <cmath>                                                                                                                                                                                                                                                 
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map> 

using namespace std;

map<int, int> count_map; 

#define incr_count(m, e) m.find(e) == m.end() ? (m[e] = 1) : (m[e] + 1 == 0 ? m.erase(e) : (m[e] = m[e] + 1))
#define decr_count(m, e) m.find(e) == m.end() ? (m[e] = -1) : (m[e] = m[e] - 1)

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int ac, bc;  
    cin >> ac; 
    for(int i = 0; i < ac; i++) { 
        int elem; 
        cin >> elem; 
        decr_count(count_map, elem);  
    }   
    
    cin >> bc; 
    for(int i = 0; i < bc; i++) { 
        int elem; 
        cin >> elem; 
        incr_count(count_map, elem); 
    }   
   
    for(auto it = count_map.begin(); it != count_map.end(); it++) { 
        int count = 0;
        if(it != count_map.begin()) 
          cout << " ";  
        cout << it->first; 
    }   
    
    return 0;
}
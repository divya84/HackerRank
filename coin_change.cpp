                                                                                   
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map> 

using namespace std;

map<pair<long long,long long>, long long> mem; 
vector<long long> coin_denoms;

long long count_ways(long long sum, int num_items) { 
    if(sum == 0)
        return 1; 
    if((sum < 0) || ((sum > 0) && (num_items <= 0)))
        return 0; 
    auto p = pair<long long, long long>(sum,num_items); 
    auto it = mem.find(p);
    if(it != mem.end())
        return it->second;  
    long long coin = coin_denoms[num_items - 1]; 
    long long count = count_ways(sum,num_items - 1) + count_ways(sum-coin,num_items);     
    mem[p] = count; 
    return count; 
} 

int main() {
    long long m, n;
    cin >> n;  
    cin >> m;
    
    long long coin_item;
    for (long long i=0; i<m; i++) {
       cin >> coin_item;
        coin_denoms.push_back(coin_item);
    }   
    
    cout << count_ways(n,m); 
    return 0;
}
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
class Node; 

class Node { 
    public: 
    char charVal;
    int size; 
    Node ** children; 
 
    Node(char c): charVal(c), size(0) { 
        children = new Node*[26](); 
		}
    

    int getIndexOf(char c) {
        return c - 'a'; 
    }
    
    Node * getNodeAt(char c) {
        /* assert: (index >= 0) && (index < 26)  */ 
        return children[getIndexOf(c)];
    }
    
 
    void AddCharAtIndex(string s, int index) {
			//	cout << charVal << " : AddCharAtIndex " << s[index] << endl;   
        if(index >= s.size())
            return; 
        size++;
        Node * n = getNodeAt(s[index]); 
        if(n == 0) { 
					// 	cout << "New Node " << endl; 
            Node * newNode = new Node(s[index]); 
            newNode->AddCharAtIndex(s, index + 1); 
            int nodeIndex = getIndexOf(s[index]); 
            children[nodeIndex] = newNode; 
        } else { 
					// 	cout << "Existing Node " << endl; 
            n->AddCharAtIndex(s, index + 1); 
        }
        return;
    }
    
   void add(string s) { 
       //  cout << "Add " << s << endl; 
				return AddCharAtIndex(s, 1); 
    }
 
    int FindCountAtIndex(string s, int index) {
        if(index == s.size()) { 
            return size; 
        } 
        Node * n = getNodeAt(s[index]); 
        if(n == 0) {
            return 0; 
        } 
        return n->FindCountAtIndex(s, index + 1); 
    }
    
    int FindCount(string s) { 
       return FindCountAtIndex(s,1); 
    }
   
}; 



int main(){
    int n;
    cin >> n;
    Node ** characters = new Node*[26]; 
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
         if(op.compare("add") == 0) { 
           char c = contact[0]; 
           if(characters[c - 'a'] == 0) {
                Node * n = new Node(c); 
                n->add(contact); 
                characters[c - 'a'] = n;
           } else { 
                Node * n = characters[c - 'a']; 
                n->add(contact); 
           }
        } else if(op.compare("find") == 0) { 
           char c = contact[0];
           if(characters[c - 'a'] == 0) { 
                cout << "0" << endl;    
           } else { 
                Node * n = characters[c - 'a']; 
                cout << n->FindCount(contact) << endl; 
           }
        }
    }
    return 0;
}

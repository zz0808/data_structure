#include <iostream>
#include <memory>
#include <vector>
using namespace std;

#define SIZE 1000

int main () {
    
    bool check[SIZE + 1];
    int prime[SIZE + 1];
    int idx = 0;
    memset(check, true, sizeof(check));
    
    for (int i = 2; i <= SIZE; i++) {
        if (check[i]) {
            prime[idx++] = i;
        }
        for (int k = 0; k < idx && i * prime[k] <= SIZE; k++) {
            check[i * prime[k]] = false;
            if (i % prime[k] == 0)
                break;
        }
    }
    
    for (int i = 0; i < idx; i++) {
        cout << prime[i] << " ";
    }
    
    return 0;
}
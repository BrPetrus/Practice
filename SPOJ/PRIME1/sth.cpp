#include <iostream>
#include <cmath>

using namespace std;

void print_al_primes(int min, int max) {
    // allocate
    //
    bool* options = new bool[max-min];

    

    delete[] options;
}

void sieve_of_eratosthenes(int n) {
    bool* is_prime = new bool[n];
    // default values
    is_prime[0] = false;
    for(int i = 1; i < n; i++)
        is_prime[i] = true;
    
    double sqr = sqrt(n);
    for(int i = 2; i <= sqr; i++) {
        if(is_prime[i] == true) {
            for(int j = i*i; j <= n; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i = 0; i < n; i++)
        if(is_prime[i] == true)
            cout << i << endl;

    delete[] is_prime;
    //return is_prime;
}

int main() {
    // get number of questions
    //int t;
    //cin >> t;

    // for every question
   // bool* options = nullptr;
   // for(int i = 0; i < t; i++) {
   //     int min;
   //     int max;
   //     cin >> min >> max;
   // }
    

    return 0;
}

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void better_sieve(const int min, const int n) {
    // first create an array of all primes from 1 to sqrt(n)
    double sqr = sqrt(n);
    bool* is_prime = new bool[(int)sqr+1];
    is_prime[0] = false; // 0
    is_prime[1] = false; // 1
    for (int i = 2; i <= sqr; i++)
        is_prime[i] = true;

    // sieve
    for (int i = 2; i <= sqr; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= sqr; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // now we have all primes from 0 to sqrt(n)
    // we can now go through the specified range and filter out composite numbers
    // [min, n]
    bool* range = new bool[n-min+1];
    for (int i = 0; i <= n-min; i++)
        range[i] = true;
    if (min == 1)
        range[0] = false;

    for (int p = 2; p <= sqr; p++) {
        if (is_prime[p]) { 
            int j = (min/p)*p;
            if (j < min)
                j += p;
            for (; j <= n; j += p) {
                if (j != p)
                    range[j-min] = false;
            }
        }
    }

    for (int i = 0; i <= n-min; i++)
        if (range[i])
            cout << i+min << endl;

    delete[] is_prime;
    delete[] range;
}

int main()
{
    // get number of questions
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int min;
        int max;
        cin >> min >> max;
        better_sieve(min, max);
        cout << endl;
    }

    return 0;
}

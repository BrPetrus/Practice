#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkDistance (int C, const vector<long long>& positions, int min_distance) {
    // first cow is put in the first available stall
    int cows_inserted = 1;
    vector<long long>::const_iterator it = positions.begin();
    auto last_position = *it;
    it++;
    for (; it != positions.end(); ++it) {
        if ((*it - last_position) >= min_distance) {
            cows_inserted++;
            last_position = *it;
        }
        if (cows_inserted == C)
            return true;
    }
    return false;

}

void binarySearch(long long low, long long high, const vector<long long>& positions, int C) {
    long long pos = 0;
    while(high >= low) {
        int mid = (high + low) / 2;
        if(checkDistance(C, positions, mid)) {
            low = mid + 1;
            pos = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << pos << endl;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, c;
        cin >> n >> c;

        vector<long long> pos;
        pos.reserve(n);
        for(int j = 0; j < n; j++) {
            long long tmp;
            cin >> tmp;
            pos.push_back(tmp);
        }

        sort(pos.begin(), pos.end());
        
        binarySearch(0, 1000000000, pos, c); 
    }
     
    return 0;
}

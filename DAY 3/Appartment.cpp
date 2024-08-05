#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> desired_sizes(n);
    vector<int> apartment_sizes(m);

    for (int i = 0; i < n; ++i) {
        cin >> desired_sizes[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> apartment_sizes[i];
    }
    
    sort(desired_sizes.begin(), desired_sizes.end());
    sort(apartment_sizes.begin(), apartment_sizes.end());
    
    int matched = 0;
    int applicant_index = 0;
    int apartment_index = 0;
    
    while (applicant_index < n && apartment_index < m) {
        int desired = desired_sizes[applicant_index];
        int apartment = apartment_sizes[apartment_index];
        
        if (apartment < desired - k) {
            // Apartment too small, move to next apartment
            ++apartment_index;
        } else if (apartment > desired + k) {
            // Apartment too large, move to next applicant
            ++applicant_index;
        } else {
            // Found a match
            ++matched;
            ++applicant_index;
            ++apartment_index;
        }
    }
    
    cout << matched << endl;
    return 0;
}

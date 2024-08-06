#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> songs(n);
    
    // Read song IDs
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    unordered_set<long long> unique_songs;
    int start = 0;
    int max_length = 0;

    for (int end = 0; end < n; ++end) {
        // Remove elements from the start of the window until the current song is unique
        while (unique_songs.find(songs[end]) != unique_songs.end()) {
            unique_songs.erase(songs[start]);
            ++start;
        }
        // Insert the current song into the set
        unique_songs.insert(songs[end]);
        // Update the maximum length
        max_length = max(max_length, end - start + 1);
    }

    cout << max_length << endl;

    return 0;
}

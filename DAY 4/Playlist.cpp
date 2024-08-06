#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> songs(n);
    
    // Read the song IDs
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    unordered_map<long long, int> last_seen;
    int start = 0;
    int max_length = 0;

    for (int end = 0; end < n; ++end) {
        long long current_song = songs[end];
        
        // If the song was seen before and is in the current window, move start
        if (last_seen.find(current_song) != last_seen.end() && last_seen[current_song] >= start) {
            start = last_seen[current_song] + 1;
        }

        // Update the last seen index of the current song
        last_seen[current_song] = end;
        
        // Calculate the length of the current window and update max_length
        max_length = max(max_length, end - start + 1);
    }

    cout << max_length << endl;

    return 0;
}

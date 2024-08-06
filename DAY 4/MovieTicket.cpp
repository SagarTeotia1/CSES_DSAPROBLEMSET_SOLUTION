#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store movie times
struct Movie {
    long long start;
    long long end;
};

// Comparator function to sort movies by their end time
bool compareMovies(const Movie& a, const Movie& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Movie> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
    }

    // Sort movies by their end time
    sort(movies.begin(), movies.end(), compareMovies);

    int count = 0;
    long long lastEndTime = 0;

    for (const auto& movie : movies) {
        if (movie.start >= lastEndTime) {
            count++;
            lastEndTime = movie.end;
        }
    }

    cout << count << endl;
    return 0;
}

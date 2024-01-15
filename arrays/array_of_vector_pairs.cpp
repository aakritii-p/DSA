#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n = 5;  // Replace with the desired size
    vector<pair<int, int>> vect[n + 1];

    // Adding elements to the vectors
    vect[1].push_back(make_pair(1, 2));
    vect[2].push_back(make_pair(3, 4));
    vect[2].push_back(make_pair(5, 6));

    // Accessing elements
    cout << "Elements in vect[1]: ";
    for (auto p : vect[1]) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    cout << "\nElements in vect[2]: ";
    for (auto p : vect[2]) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

void findAllFlights(map<char, vector<char>>& graph, char startNode, char endNode) {
    vector<string> results;
    vector<pair<char, string>> flights;
    flights.push_back({ startNode, string(1, startNode) });
    set<char> visited;

    while (!flights.empty()) {
        pair<char, string> flight = flights.back();
        cout << "flight nachalo while: " << endl; 
        cout << "       flight first: " << flight.first << endl;
        cout << "       flight second: " << flight.second << endl;
        flights.pop_back();

        if (flight.first == endNode) {
            results.push_back(flight.second);
            cout << "results: " << flight.second << endl;
        }

        for (char neighbor : graph[flight.first]) {
            if (visited.find(neighbor) == visited.end()) {
                flights.push_back({ neighbor, flight.second + " -> " + neighbor });
                visited.insert(neighbor);
                cout << "neighbor: " << neighbor << ", flight.second: " << flight.second << "  -> neighbor: " << neighbor << endl;
            }
        }
    }

    cout << "All flights from " << startNode << " to " << endNode << ":" << endl;
    for (string result : results) {
        cout << result << endl;
    }
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'D', 'E'}},
        {'B', {'C', 'N', 'Z'}},
        {'D', {'E', 'F'}},
        {'F', {'S', 'E', 'D'}}
    };

    findAllFlights(graph, 'A', 'S');

    return 0;
}
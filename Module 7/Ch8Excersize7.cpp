#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Candidate {
    string lastName;
    int votes;
    float percentage;
};

int main() {
    // Initialize vector to store candidates
    vector<Candidate> candidates(5);

    // Input candidate names and votes
    for (int i = 0; i < 5; ++i) {
        cout << "Enter candidate's last name: ";



            
        cin >> candidates[i].lastName;
        cout << "Enter number of votes received by " << candidates[i].lastName << ": ";
        cin >> candidates[i].votes;
    }

    // Calculate total number of votes
    int totalVotes = 0;
    for (const auto& candidate : candidates) {
        totalVotes += candidate.votes;
    }

    // Calculate percentage of votes for each candidate
    for (auto& candidate : candidates) {
        candidate.percentage = (static_cast<float>(candidate.votes) / totalVotes) * 100;
    }

    // Output results
    cout << "\nResults:\n";
    for (const auto& candidate : candidates) {
        cout << candidate.lastName << ": " << candidate.votes << " votes, "
             << fixed << setprecision(2) << candidate.percentage << "% of total votes\n";
    }

    return 0;
}

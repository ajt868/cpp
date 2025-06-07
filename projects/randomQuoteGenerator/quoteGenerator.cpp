#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time

using namespace std;

// pass in actual vector to modify values at actual memory address
void loadVectors(vector<string>& v) {
    std::ifstream inputFile("randomQuotes.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        v.push_back(line);
    }

    inputFile.close();
}

int main() {
    vector<string> quotes;
    loadVectors(quotes);

    if (quotes.empty()) {
        std::cerr << "No quotes loaded." << std::endl;
        return 1;
    }

    srand(time(0));
    int randomIndex = rand() % quotes.size();

    std::cout << quotes[randomIndex] << std::endl;

    return 0;
}

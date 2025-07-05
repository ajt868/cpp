#include <map>
#include <iostream>

using namespace std;

template <typename T>
void printMap(const T& myMap) {
    for (const auto& [key, value] : myMap) {
        cout << key << " -> " << value << endl;
    }
}

void populateMap(const T& myMap) {
    cout << "Enter the number of values you want to insert into the map." << endl;
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        
    }
}


int main() {
    map<string, int> people;
    people.insert({"John", 25});

    map<float, int> numbers;
    numbers.insert({3.14159, 2});

    cout << people.size() << endl;
    printMap(people);

    printMap(numbers);
}
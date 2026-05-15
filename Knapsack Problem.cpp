#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value, weight;

    // Constructor
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Comparator function to sort items based on profit/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve fractional knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    // 1. Sort items by ratio in descending order
    sort(items.begin(), items.end(), compare);

    double finalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < items.size(); i++) {
        // 2. If the entire item fits, add it
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } 
        // 3. Otherwise, add the fractional part and break
        else {
            int remain = W - currentWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W = 50; 
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items) << endl;

    return 0;
}

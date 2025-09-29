#include <iostream>
using namespace std;

int main() {
    int numProducts;
    float total = 0;

    cout << "Enter number of products in your cart: ";
    cin >> numProducts;

    // Dynamically allocate memory for product prices
    float* prices = new float[numProducts];

    // Take prices from the user
    for (int i = 0; i < numProducts; i++) {
        cout << "Enter price of product " << i + 1 << ": ";
        cin >> prices[i];
        total += prices[i];
    }

    // Display the total
    cout << "\nTotal amount to be paid: ₹" << total << endl;

    // Free the allocated memory
    delete[] prices;

    return 0;
}

// COMSC-210 | Lab 20 | Mamadou Sissoko
// IDE used: Visual Studio Code
// Adds random default constructor, two-parameter constructor, and numbered output progressively from starter code

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
    static int count; // chair numbering
    int id;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        srand(static_cast<unsigned int>(time(0)));
        legs = rand() % 2 + 3; // random 3 or 4 legs
        const int MIN = 10000, MAX = 99999;
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0; // random price
        id = ++count;
    }

    Chair(int l, double p1, double p2, double p3) { // two-parameter constructor added
        prices = new double[SIZE];
        legs = l;
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
        id = ++count;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }
    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA " << id << " - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int Chair::count = 0;

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print(); // random default chair

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3, 525.25, 434.34, 252.52);
    livingChair->print(); // fixed price chair
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print(); // random default chairs

    delete[] collection;
    delete chairPtr;
    return 0;
}
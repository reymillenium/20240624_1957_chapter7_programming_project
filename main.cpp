/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                   *
 *   Name: Rainfall                                                  *
 *                                                                   *
 *   Purpose:                                                        *
 *   Receives 12 rainfall values provided by the user from the       *
 *   console & and stores them in an array. And then based on them,  *
 *   it calculates the total rainfall, the average rainfall,         *
 *   the least rainfall month, and the most rainfall month.          *
 *                                                                   *
 *   More Details:                                                   *
 *   https://github.com/reymillenium/20240621_0127_arrays_intro      *
 *                                                                   *
 *                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;
using std::vector;
using std::find;

// Receives and validates a double number from the console
double getDouble(const string &, double, double, bool = false, const string & = "Invalid input. Please try again.");

// Calculates the sum of all the elements inside an array of doubles
template<int N>
double sumOfDoublesWithRangeOverReference(double (&)[N]);

template<int N>
double averageAmongDoublesWithRangeOverReference(double (&)[N]);

// Determines the lower number among an array of doubles
double simpleLowerDoubleInArray(const double [], int);

// Determines the higher number among an array of doubles
double simpleHigherDoubleInArray(const double [], int);


// CUSTOM FUNCTIONS

template<int N>
void loadRainfalls(const vector<string> &, double (&)[N]);

string getLeastRainfallMonth(const vector<string> &, double [], int);

string getMostRainfallMonth(const vector<string> &, double [], int);

void displayResults(double, double, const string &, const string &);

// Main Function
int main() {
    constexpr int MONTHS_AMOUNT = 12;
    const vector<string> months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double rainfalls[MONTHS_AMOUNT]; // An array with all the rainfall values across the whole year, month by month
    double totalRainfall {0}; // The total rainfall
    double averageRainfall {0.0}; // The average rainfall

    // Loads all the rainfall double values into the reference of the array
    loadRainfalls(months, rainfalls);

    // Calculates the total rainfall, the average rainfall, the least rainfall month, and the most rainfall month:
    totalRainfall = sumOfDoublesWithRangeOverReference(rainfalls);
    averageRainfall = averageAmongDoublesWithRangeOverReference(rainfalls);
    const string leastRainfallMonth = getLeastRainfallMonth(months, rainfalls, MONTHS_AMOUNT);
    const string mostRainfallMonth = getMostRainfallMonth(months, rainfalls, MONTHS_AMOUNT);

    // Displays the results on the console:
    displayResults(totalRainfall, averageRainfall, leastRainfallMonth, mostRainfallMonth);

    return 0;
}

// Receives and validates a double number from the console
double getDouble(const string &message, const double minValue, const double maxValue, const bool showRange, const string &errorMessage) {
    double number = 0; // Number typed by the user
    bool invalidInput; // If the input is valid

    do {
        cout << message << (showRange ? (" (" + to_string(minValue) + " - " + to_string(maxValue) + ")") : "") << ": ";
        cin >> number;
        cin.ignore();

        invalidInput = number < minValue || maxValue < number;
        if (invalidInput) cout << errorMessage << endl;
    } while (invalidInput);

    return number;
}

// Calculates the sum of all the elements inside an array of integers
template<int N>
double sumOfDoublesWithRangeOverReference(double (&doublesArray)[N]) {
    double sum = 0.0;
    for (auto number: doublesArray) {
        sum += number;
    }
    return sum;
}

// Calculates the average among all the numbers inside an array of doubles
template<int N>
double averageAmongDoublesWithRangeOverReference(double (&doublesArray)[N]) {
    const int length = sizeof(doublesArray) / sizeof(doublesArray[0]);
    return sumOfDoublesWithRangeOverReference(doublesArray) / length;
}

// Determines the lower number among an array of doubles
double simpleLowerDoubleInArray(const double doublesArray[], const int length) {
    double lower = doublesArray[0];
    if (length == 1) return lower;

    for (int i = 1; i < length; i++) {
        if (doublesArray[i] < lower)
            lower = doublesArray[i];
    }

    return lower;
}

// Determines the higher number among an array of doubles
double simpleHigherDoubleInArray(const double doublesArray[], const int length) {
    double higher = doublesArray[0];
    if (length == 1) return higher;

    for (int i = 1; i < length; i++) {
        if (doublesArray[i] > higher)
            higher = doublesArray[i];
    }

    return higher;
}


// CUSTOM FUNCTIONS


template<int N>
void loadRainfalls(const vector<string> &months, double (&rainfalls)[N]) {
    const int arraySize = sizeof(rainfalls) / sizeof(rainfalls[0]);
    for (int i = 0; i < arraySize; i++) {
        rainfalls[i] = getDouble("Enter rainfall for " + months[i], 0, INT_MAX, false, "invalid data (negative rainfall) -- retry");
    }
}

string getLeastRainfallMonth(const vector<string> &months, double rainfalls[], const int arraySize) {
    const double *targetPointer = find(&rainfalls[0], rainfalls + arraySize, simpleLowerDoubleInArray(rainfalls, arraySize));
    const int targetIndex = targetPointer - rainfalls;
    string leastRainfallMonth = months[targetIndex];
    return leastRainfallMonth;
}

string getMostRainfallMonth(const vector<string> &months, double rainfalls[], const int arraySize) {
    const double *targetPointer = find(&rainfalls[0], rainfalls + arraySize, simpleHigherDoubleInArray(rainfalls, arraySize));
    const int targetIndex = targetPointer - rainfalls;
    string mostRainfallMonth = months[targetIndex];
    return mostRainfallMonth;
}

void displayResults(const double totalRainfal, const double averageRainfall, const string &leastRainfallMonth, const string &mostRainfallMonth) {
    cout << "Total rainfall " << totalRainfal << endl;
    cout << "Average rainfall " << averageRainfall << endl;
    cout << "Least rainfall in: " << leastRainfallMonth << endl;
    cout << "Most rainfall in: " << mostRainfallMonth << endl;
}

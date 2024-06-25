/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                       *
 *       Created by: Reinier Garcia Ramos                *
 *       reymillenium@gmail.com                          *
 *                                                       *
 *       https://www.linkedin.com/in/reiniergarcia       *
 *       https://github.com/reymillenium                 *
 *       https://www.reiniergarcia.dev                   *
 *                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 *   Name: 07-Arrays-intro                                             *
 *                                                                     *
 *   Purpose:                                                          *
 *   Receives 10 integers provided by the user from the console,       *
 *   and stores them in an array. And then based on them, it           *
 *   calculates the sum, the average and the largest element.          *
 *                                                                     *
 *   More Details:                                                     *
 *   https://github.com/reymillenium/20240621_0127_arrays_intro        *
 *                                                                     *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>  // for string, to_string, etc
#include <cmath> // for sqrt, sin, pow
#include <limits> // For SHRT_MAX, SHRT_MIN, etc
#include <iomanip> // for setprecision, setw, fixed
#include<array>  // for array
#include<random> // for random_device
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <sstream> // for stringstream (used in humanizeInteger, humanizeDouble, etc)
#include <vector> // to use vectors
#include <fstream> // For ifstream, ofstrea, fstream
#include <numeric> // For accumulate, transform_reduce (in the vectors)
#include <algorithm> // For max_element, min_element, transform (to use in vectors), or for max()

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::string;
using std::to_string;
using std::stringstream;
using std::accumulate;
using std::vector;
using std::find;

// Prints a given value, of almost any kind, once in the terminal
template<typename T>
void print(const T &);

// Prints a given value, of almost any kind, N given times in the terminal
template<typename T>
void printNTimes(const T &, int);

// Prints a given value, of almost any kind, once in the terminal, and then breaks the line
template<typename T>
void printLine(const T &);

// Prints a given value, of almost any kind, N given times in the terminal, and then breaks the line
template<typename T>
void prinLineNTimes(const T &, int);

// Gets several types of values from the console (except strings with spaces, objects, etc, among others), as a response of a given question
template<typename T>
auto getValue(const string &) -> T;

// Receives and validates an integer number from the console
int getInteger(const string &, int, int, bool = false, const string & = "Invalid input. Please try again.");

// Receives and validates a double number from the console
double getDouble(const string &, double, double, bool = false, const string & = "Invalid input. Please try again.");

// Gets a string with or without spaces, from the terminal, as a response of a given question
string getStringFromMessage(const string &);

// Gets a string with or without spaces, from the terminal
string getString();

// Formats a given negative or positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeInteger(long long int);

// Formats a given negative or positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeDouble(long double, int = 2);

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(unsigned long long int);

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(long double, int = 2);

// Formats a given int by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeInteger(unsigned long int, bool = true, const string & = "$");

// Formats a given double by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeDouble(long double, int = 2, bool = true, const string & = "$");

// Rounds up a given double number, with a given amount of decimal places
double roundUp(double, int);

// Calculates the Recursive Sum of a given int number. Example: recursiveSum(5) == 5 + 4 + 3 + 2 + 1 = 15
int recursiveSum(unsigned long long int);

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(long long int);

// Determines is a given int number is prime or not
bool isPrime(unsigned long long int);

// Calculates the sum of all the elements inside an array of integers
int neatSumOfIntegers(const int [], int);

// Calculates the sum of all the elements inside an array of integers
int simpleSumOfIntegers(const int [], int);

// Calculates the sum of all the elements inside an array of integers
template<int N>
int sumOfIntegersWithRangeOverReference(int (&)[N]);

// Calculates the sum of all the elements inside an array of doubles
double neatSumOfDoubles(const double [], int);

// Calculates the sum of all the elements inside an array of doubles
double simpleSumOfDoubles(const double [], int);

// Calculates the sum of all the elements inside an array of doubles
template<int N>
double sumOfDoublesWithRangeOverReference(double (&)[N]);

// Calculates the average among all the numbers inside an array of integers
double simpleAverageAmongIntegers(const int [], int);

// Calculates the average among all the numbers inside an array of integers
double neatAverageAmongIntegers(const int [], int);

// Calculates the average among all the numbers inside an array of doubles
double simpleAverageAmongDoubles(const double [], int);

// Calculates the average among all the numbers inside an array of doubles
double neatAverageAmongDoubles(const double [], int);

template<int N>
double averageAmongDoublesWithRangeOverReference(double (&)[N]);

// Determines the highest number among an array of integers
int simpleHighestIntegerInArray(const int [], int);

// Determines the lower number among an array of integers
int simpleLowerIntegerInArray(const int [], int);

// Determines the lower number among an array of doubles
double simpleLowerDoubleInArray(const double [], int);

// Determines the higher number among an array of doubles
double simpleHigherDoubleInArray(const double [], int);

// Determines if the given value is lower than the also given minimum value
bool isInvalid(long double value, double);

// Prints on the terminal a text if the given value is lower than the also given minimum value
void scoldUserIfInvalidInput(long double, double);

// CUSTOM FUNCTIONS

string getLeastRainfallMonth(const vector<string> &, double [], int);

string getMostRainfallMonth(const vector<string> &, double [], int);

void displayResults(double, double, const string &, const string &);

// class MonthlyRainLog {
// public:
//     string monthName;
//     double rainAmount;
//
//     // dummy constructor
//     MonthlyRainLog() {
//     }
//
//     // Parameterized constructor
//     MonthlyRainLog(const string &aMonthName, const double &aRainAmount) {
//         monthName = aMonthName;
//         rainAmount = aRainAmount;
//     }
// };

// Main Function
int main() {
    constexpr int MONTHS_AMOUNT = 12;
    const vector<string> months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double rainfalls[MONTHS_AMOUNT];
    double totalRainfall {0};
    double averageRainfall {0.0};

    for (int i = 0; i < MONTHS_AMOUNT; i++) {
        rainfalls[i] = getDouble("Enter rainfall for " + months[i], 0, INT_MAX, false, "invalid data (negative rainfall) -- retry");
    }

    totalRainfall = neatSumOfDoubles(rainfalls, MONTHS_AMOUNT);
    averageRainfall = neatAverageAmongDoubles(rainfalls, MONTHS_AMOUNT);
    const string leastRainfallMonth = getLeastRainfallMonth(months, rainfalls, MONTHS_AMOUNT);
    const string mostRainfallMonth = getMostRainfallMonth(months, rainfalls, MONTHS_AMOUNT);

    const double temp = sumOfDoublesWithRangeOverReference(rainfalls);
    printLine(temp);
    printLine(averageAmongDoublesWithRangeOverReference(rainfalls));


    displayResults(totalRainfall, averageRainfall, leastRainfallMonth, mostRainfallMonth);
    return 0;
}

// Prints a given value, of almost any kind, once in the terminal
template<typename T>
void print(const T &item) {
    cout << item;
}

// Prints a given value, of almost any kind, N given times in the terminal
template<typename T>
void printNTimes(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        print(item);
    }
}

// Prints a given value, of almost any kind, once in the terminal, and then breaks the line
template<typename T>
void printLine(const T &item) {
    cout << item << endl;
}

// Prints a given value, of almost any kind, N given times in the terminal, and then breaks the line
template<typename T>
void prinLineNTimes(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        printl(item);
    }
}

// Gets several types of values from the console (except strings with spaces, objects, etc, among others), as a response of a given question
template<typename T>
auto getValue(const string &message) -> T {
    cout << message;
    T value;
    cin >> value;
    cin.ignore();
    return value;
}

// Receives and validates an integer number from the console
int getInteger(const string &message, const int minValue, const int maxValue, const bool showRange, const string &errorMessage) {
    int number = 0; // Number typed by the user
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

// Gets a string with or without spaces, from the terminal, as a response of a given question
string getStringFromMessage(const string &message) {
    cout << message;
    string value;
    getline(cin, value);
    return value;
}

// Gets a string with or without spaces, from the terminal
string getString() {
    string value;
    getline(cin, value);
    return value;
}

// Formats a given negative or positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeInteger(const long long int integerValue) {
    const bool isNegative = integerValue < 0;
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > (isNegative ? 1 : 0); j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Formats a given negative or positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    const bool hasNegativeDecimals = decimals < 0;

    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the zero & the dot. Ex: 0.34, -0.34 (the zero, and possibly also a negative sign, must be removed next)
    return humanizeInteger(integerValue) + decimalsAsString.substr(hasNegativeDecimals ? 2 : 1, precision + 1);
}

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(const unsigned long long int integerValue) {
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > 0; j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<unsigned long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the zero & the dot. Ex: 0.34 (the dot must be removed next)
    return humanizeUnsignedInteger(integerValue) + decimalsAsString.substr(1, precision + 1);
}

// Formats a given int by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeInteger(const unsigned long int integerValue, const bool prepend, const string &symbol) {
    return static_cast<string>(prepend ? (symbol + " ") : "") + humanizeUnsignedInteger(integerValue) + static_cast<string>(prepend ? "" : " " + symbol);
}

// Formats a given double by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeDouble(const long double doubleValue, const int precision, const bool prepend, const string &symbol) {
    return static_cast<string>(prepend ? (symbol + " ") : "") + humanizeUnsignedDouble(doubleValue, precision) + static_cast<string>(prepend ? "" : " " + symbol);
}

// Rounds up a given double number, with a given amount of decimal places
double roundUp(const double value, const int decimalPlaces) {
    const double multiplier = pow(10.0, decimalPlaces);
    return ceil(value * multiplier) / multiplier;
}

// Calculates the Recursive Sum of a given int number. Example: recursiveSum(5) == 5 + 4 + 3 + 2 + 1 = 15
int recursiveSum(const unsigned long long int number) {
    if (number != 0)
        return number + recursiveSum(number - 1);
    return 0;
}

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(const long long int number) {
    const long long int lastDigit = number % 10;
    string additive;

    switch (number) {
        case 11:
        case 12:
            additive = "th";
            break;
        default:
            switch (lastDigit) {
                case 1:
                    additive = "st";
                    break;
                case 2:
                    additive = "nd";
                    break;
                case 3:
                    additive = "rd";
                    break;
                default:
                    additive = "th";
                    break;
            }
            break;
    }

    return to_string(number) + additive;
}

// Determines is a given int number is prime or not
bool isPrime(const unsigned long long int value) {
    if (value <= 1)
        return false;
    for (unsigned long long int i = 2; i <= value / 2; i++) {
        if (value % i == 0)
            return false;
    }
    return true;
}

// Calculates the sum of all the elements inside an array of integers
int simpleSumOfIntegers(const int integersArray[], const int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += integersArray[i];
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of integers
int neatSumOfIntegers(const int integersArray[], const int length) {
    return accumulate(integersArray, integersArray + length, 0);
}

// Calculates the sum of all the elements inside an array of integers
template<int N>
int sumOfIntegersWithRangeOverReference(int (&integersArray)[N]) {
    int sum = 0;
    for (auto number: integersArray) {
        sum += number;
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of integers
double simpleSumOfDoubles(const double doublesArray[], const int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += doublesArray[i];
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of integers
double neatSumOfDoubles(const double doublesArray[], const int length) {
    return accumulate(doublesArray, doublesArray + length, 0.0);
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

// Calculates the average among all the numbers inside an array of integers
double simpleAverageAmongIntegers(const int array[], const int length) {
    return simpleSumOfIntegers(array, length) / static_cast<double>(length);
}

// Calculates the average among all the numbers inside an array of integers
double neatAverageAmongIntegers(const int array[], const int length) {
    return neatSumOfIntegers(array, length) / static_cast<double>(length);
}


// Calculates the average among all the numbers inside an array of integers
double simpleAverageAmongDoubles(const double array[], const int length) {
    return simpleSumOfDoubles(array, length) / length;
}

// Calculates the average among all the numbers inside an array of integers
double neatAverageAmongDoubles(const double array[], const int length) {
    return neatSumOfDoubles(array, length) / length;
}

// Calculates the average among all the numbers inside an array of integers
template<int N>
double averageAmongDoublesWithRangeOverReference(double (&doublesArray)[N]) {
    const int length = sizeof(doublesArray) / sizeof(doublesArray[0]);
    return sumOfDoublesWithRangeOverReference(doublesArray) / length;
}

// Determines the highest number among an array of integers
int simpleHighestIntegerInArray(const int integersArray[], const int length) {
    int highestInteger = integersArray[0];
    if (length == 1) return highestInteger;

    for (int i = 1; i < length; i++) {
        if (integersArray[i] > highestInteger)
            highestInteger = integersArray[i];
    }

    return highestInteger;
}

// Determines the lower number among an array of integers
int simpleLowerIntegerInArray(const int integersArray[], const int length) {
    int lower = integersArray[0];
    if (length == 1) return lower;

    for (int i = 1; i < length; i++) {
        if (integersArray[i] < lower)
            lower = integersArray[i];
    }

    return lower;
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

// Determines if the given value is lower than the also given minimum value
bool isInvalid(const long double value, const double minValue) {
    return value < minValue;
}

// Prints on the terminal a text if the given value is lower than the also given minimum value
void scoldUserIfInvalidInput(const long double value, const double minValue) {
    if (isInvalid(value, minValue))
        cout << "You must type a number greater or equal than " << minValue << ". Try again!" << endl;
}


// CUSTOM FUNCTIONS

void loadRainfalls() {
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

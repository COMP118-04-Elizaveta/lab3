/** \file lab3.cpp
 *  \brief     A shopping program that calculates the total price for an array of items
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then Check In
 *                   the code with a comment on the fix you did
 *                3) There are a three functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      28/01/2025
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constant
const int VAT = 21;
const int WITH_VAT = 1;
const int WITHOUT_VAT = 0;
const int VAT_DIM = 2;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const double[], int[], const int);
void displayArray(const double[][VAT_DIM], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[], const int, int&);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
    int choice;
    const int SIZE = 10;

    // Initialize array price
    int price[SIZE] = {12, 4, 8, 1, 17, 2, 4, 2, 9, 1};
    // Declare array quantity and total
    int quantity[SIZE] = {};
    double total[9][VAT_DIM] = {};

    // Interactive menu
    do {
        choice = printMenu();

        switch (choice){
            // Enter quantity
            case 1:
                fillInArray(quantity, SIZE);
                break;
            // Calculate total
            case 2:
                //multArrays(quantity, total, price, SIZE);
                break;
            // Print total
            case 3:
                displayArray(total, SIZE);
                break;
            // Exit
            case 4:
                // No code needed
                break;
            case 5:
                cout << "\nAll positive:" << isAllPositive(quantity, SIZE);
            default:
                assert(true);
        }
    } while (choice != 4);

    cout << "\nHave a nice day:)" << endl;
    return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu(){
    int choice;

    do {
        cout << "\n == MENU ==";
        cout << "\n1) Enter quantity";
        cout << "\n2) Calculate total";
        cout << "\n3) Print total";
        cout << "\n4) Exit";
        cout << "\n5) All positive";

        cout << "\nEnter the choice: ";
        cin >> choice;

        if (choice < 1 || choice > 5){
            cout << "\nWrong choice, try again.";
        }
    } while (choice < 1 || choice > 5);
    return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size){
    assert (size > 1);

    for (int i = 0; i < size; ++i){
        cout << "\nEnter an element for the array at " << i << ": ";
        cin >> arr[i];
    }
}

/**
 * <code>multArrays</code> multiplies the value of elements of the source array
 * to the corresponding value at the destination array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrSource The array containing the destination elements.
 * @param arrDest The array containing the source elements.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size){
    assert (size > 0);

    for (int i = 0; i <= size; ++i){
        arrTotal[i] = arrQuantity[i] * arrPrice[i];
    }
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 */
void displayArray(const double arr[][VAT_DIM], const int size){
    double sum = 0;

    for (int i = 0; i < size - 1; ++i){
        cout << "\nValue without VAT at " << i << ": " << arr[i][WITHOUT_VAT];
        sum += arr[i][WITHOUT_VAT];
    }

    cout << "\nThe total without VAT is: " << sum;
}

/**
 * <code>sumOddArray</code> Sums the odd numbers in the array and returns the result
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 */
int sumOddArray(const int arr[], const int size){
//@TODO: You will need to complete this. Including makeing the appropriate comment header
    int count = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 1) {
            count++;
        }
    }
    
    return count;
}

/**
 * <code>isAllPositive</code> If all the values in the array are greater than 0 return true
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 */
bool isAllPositive(const int arr[], const int size){
    
    for (int i = 0; i < size; i++){
        if (arr[i] <= 0) {
            return false;
        }
    }
  return true;
}

// Finds the average of all the odd numbers in the array and stores this in the last argument
void avgOddArray(const int arr[], const int size, int& avgOdd){
    //@TODO: You will need to complete this. Including makeing the appropriate comment header
}

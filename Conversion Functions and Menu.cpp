/*
Unani
Zweni
08/12/2026
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// FUNCTION 1: Decimal to Binary
// Receives an integer and returns its binary equivalent
string decimalToBinary(int decimal)
{
    if (decimal == 0)
    {
        return "0";
    }

    string binary = "";

    while (decimal > 0)
    {
        int remainder = decimal % 2;

        if (remainder == 0)
        {
            binary = "0" + binary;
        }
        else
        {
            binary = "1" + binary;
        }

        decimal = decimal / 2;
    }

    return binary;
}


// FUNCTION 2: Binary to Decimal
// Receives a binary string and returns its decimal value
int binaryToDecimal(string binary)
{
    int decimal = 0;

    for (int i = 0; i < binary.length(); i++)
    {
        decimal = decimal * 2 + (binary[i] - '0');
    }

    return decimal;
}


// FUNCTION 3: Decimal to Hexadecimal
// Receives an integer and returns its hexadecimal value
string decimalToHexadecimal(int decimal)
{
    if (decimal == 0)
    {
        return "0";
    }

    string hexadecimal = "";
    string hexDigits = "0123456789ABCDEF";

    while (decimal > 0)
    {
        int remainder = decimal % 16;

        hexadecimal = hexDigits[remainder] + hexadecimal;

        decimal = decimal / 16;
    }

    return hexadecimal;
}


// FUNCTION 4: Hexadecimal to Decimal
// Receives a hexadecimal string and returns its decimal value
int hexadecimalToDecimal(string hexadecimal)
{
    int decimal = 0;

    for (int i = 0; i < hexadecimal.length(); i++)
    {
        char digit = toupper(hexadecimal[i]);
        int value;

        if (digit >= '0' && digit <= '9')
        {
            value = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            value = digit - 'A' + 10;
        }
        else
        {
            return -1;
        }

        decimal = decimal * 16 + value;
    }

    return decimal;
}


// FUNCTION: Check whether binary input is valid
bool isValidBinary(string binary)
{
    if (binary.empty())
    {
        return false;
    }

    for (int i = 0; i < binary.length(); i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            return false;
        }
    }

    return true;
}



// FUNCTION: Check whether hexadecimal input is valid
bool isValidHexadecimal(string hexadecimal)
{
    if (hexadecimal.empty())
    {
        return false;
    }

    for (int i = 0; i < hexadecimal.length(); i++)
    {
        char digit = toupper(hexadecimal[i]);

        if (!((digit >= '0' && digit <= '9') ||
            (digit >= 'A' && digit <= 'F')))
        {
            return false;
        }
    }

    return true;
}


// FUNCTION: Display the conversion menu
void displayMenu()
{
    cout << "\n========================================\n";
    cout << "           CONVERSION MENU\n";
    cout << "========================================\n";
    cout << "1. Convert Decimal to Binary\n";
    cout << "2. Convert Binary to Decimal\n";
    cout << "3. Convert Hexadecimal to Decimal\n";
    cout << "4. Convert Decimal to Hexadecimal\n";
    cout << "5. Demo (Generate and convert random integer)\n";
    cout << "6. Exit\n";
    cout << "========================================\n";
}


// FUNCTION: Decimal to Binary option
void decimalToBinaryOption()
{
    int decimal;

    cout << "\nEnter a decimal number: ";
    cin >> decimal;

    if (decimal < 0)
    {
        cout << "Please enter a positive integer.\n";
        return;
    }

    cout << "Binary representation: "
        << decimalToBinary(decimal) << endl;
}


// FUNCTION: Binary to Decimal option
void binaryToDecimalOption()
{
    string binary;

    cout << "\nEnter a binary number: ";
    cin >> binary;

    if (!isValidBinary(binary))
    {
        cout << "Invalid binary number.\n";
        cout << "Only 0 and 1 are allowed.\n";
        return;
    }

    cout << "Decimal representation: "
        << binaryToDecimal(binary) << endl;
}


// FUNCTION: Decimal to Hexadecimal option
void decimalToHexadecimalOption()
{
    int decimal;

    cout << "\nEnter a decimal number: ";
    cin >> decimal;

    if (decimal < 0)
    {
        cout << "Please enter a positive integer.\n";
        return;
    }

    cout << "Hexadecimal representation: "
        << decimalToHexadecimal(decimal) << endl;
}


// FUNCTION: Hexadecimal to Decimal option
void hexadecimalToDecimalOption()
{
    string hexadecimal;

    cout << "\nEnter a hexadecimal number: ";
    cin >> hexadecimal;

    if (!isValidHexadecimal(hexadecimal))
    {
        cout << "Invalid hexadecimal number.\n";
        cout << "Use digits 0-9 and letters A-F.\n";
        return;
    }

    cout << "Decimal representation: "
        << hexadecimalToDecimal(hexadecimal) << endl;
}


// FUNCTION: Demo
// Generates a random number between 0 and 99
// and converts it to binary
void runDemo()
{
    int randomNumber = rand() % 100;

    string binary = decimalToBinary(randomNumber);

    cout << "\n========== DEMO ==========\n";
    cout << "Generated random integer: " << randomNumber << endl;
    cout << "Binary representation: " << binary << endl;
    cout << "===========================\n";
}


// MAIN PROGRAM
int main()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    int choice;

    do
    {
        displayMenu();

        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Check if the user entered something other than a number
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\nInvalid input. Please enter a number from 1 to 6.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            decimalToBinaryOption();
            break;

        case 2:
            binaryToDecimalOption();
            break;

        case 3:
            hexadecimalToDecimalOption();
            break;

        case 4:
            decimalToHexadecimalOption();
            break;

        case 5:
            runDemo();
            break;

        case 6:
            cout << "\nExiting the program.\n";
            break;

        default:
            cout << "\nInvalid choice. Please select an option from 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}
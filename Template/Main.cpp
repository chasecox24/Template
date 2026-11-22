
#include <iostream>
#include <fstream>
#include <string>
#include "thing.h"

using namespace std;

// Bubble Sort
template <typename T>
void bubbleSort(RawDynamicGenericArray<T>& array)
{
    for (int i = 0; i < array.getSize() - 1; i++)
    {
        for (int j = 0; j < array.getSize() - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Sequential Search
template <typename T>
int sequentialSearch(const RawDynamicGenericArray<T>& array, const T& target)
{
    for (int i = 0; i < array.getSize(); i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    // =====================================
    // PART 1: STRINGS
    // =====================================

    RawDynamicGenericArray<string> names;

    ifstream nameFile("names.txt");

    if (!nameFile)
    {
        cout << "Could not open names.txt" << endl;
        return 1;
    }

    string name;

    while (getline(nameFile, name))
    {
        if (!name.empty())
        {
            names.pushBack(name);
        }
    }

    nameFile.close();

    cout << "Original Names:" << endl;
    names.print();

    bubbleSort(names);

    cout << "\nSorted Names:" << endl;
    names.print();

    string searchName;

    cout << "\nEnter a name to search for: ";
    getline(cin, searchName);

    int namePosition = sequentialSearch(names, searchName);

    if (namePosition != -1)
    {
        cout << searchName << " found at index " << namePosition << endl;
    }
    else
    {
        cout << searchName << " was not found." << endl;
    }


    // =====================================
    // PART 2: INTEGERS
    // =====================================

    RawDynamicGenericArray<int> numbers;

    ifstream numberFile("numbers.txt");

    if (!numberFile)
    {
        cout << "Could not open numbers.txt" << endl;
        return 1;
    }

    int number;

    while (numberFile >> number)
    {
        numbers.pushBack(number);
    }

    numberFile.close();

    cout << "\nOriginal Numbers:" << endl;
    numbers.print();

    bubbleSort(numbers);

    cout << "\nSorted Numbers:" << endl;
    numbers.print();

    int searchNumber;

    cout << "\nEnter an integer to search for: ";
    cin >> searchNumber;

    int numberPosition = sequentialSearch(numbers, searchNumber);

    if (numberPosition != -1)
    {
        cout << searchNumber << " found at index " << numberPosition << endl;
    }
    else
    {
        cout << searchNumber << " was not found." << endl;
    }

    return 0;
}


#pragma once
#include <iostream>
#include <memory>
using namespace std;

// Templated Abstract Base Class
template <typename SomeDataType>
class DynamicGenericArrayADT
{
public:
    virtual void pushBack(const SomeDataType& dataToPush) = 0;

    virtual ~DynamicGenericArrayADT() = default;
};

// Raw pointer implementation
template <typename SomeDataType>
class RawDynamicGenericArray : public DynamicGenericArrayADT<SomeDataType>
{
private:
    int max_capacity = 5;
    int current_size = 0;

    SomeDataType* rawPtrToDynamicList =
        new SomeDataType[max_capacity];

    // Increase capacity when array becomes full
    void resize()
    {
        max_capacity *= 2;

        SomeDataType* newArray =
            new SomeDataType[max_capacity];

        for (int i = 0; i < current_size; i++)
        {
            newArray[i] = rawPtrToDynamicList[i];
        }

        delete[] rawPtrToDynamicList;

        rawPtrToDynamicList = newArray;
    }

public:

    RawDynamicGenericArray() = default;

    // Add an item to the back of the array
    void pushBack(const SomeDataType& dataToPush) override
    {
        if (current_size == max_capacity)
        {
            resize();
        }

        rawPtrToDynamicList[current_size] = dataToPush;
        current_size++;
    }

    // Return current number of items
    int getSize() const
    {
        return current_size;
    }

    // Access an item by index
    SomeDataType& operator[](int index)
    {
        return rawPtrToDynamicList[index];
    }

    const SomeDataType& operator[](int index) const
    {
        return rawPtrToDynamicList[index];
    }

    // Print the contents
    void print() const
    {
        for (int i = 0; i < current_size; i++)
        {
            cout << rawPtrToDynamicList[i] << endl;
        }
    }

    // Destructor
    ~RawDynamicGenericArray()
    {
        delete[] rawPtrToDynamicList;
    }

    // Prevent accidental shallow copies of the raw pointer
    RawDynamicGenericArray(const RawDynamicGenericArray&) = delete;
    RawDynamicGenericArray& operator=(const RawDynamicGenericArray&) = delete;
};

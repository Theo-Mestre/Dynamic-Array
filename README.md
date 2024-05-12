# Dynamic Array

This solution provides a dynamic array implementation in C++ that I made during my first year of programming studies.
The solution also contains unit test.

## DynamicArray.h

The `DynamicArray.h` file contains the implementation of the `DynamicArray` class, which represents a dynamic array that can grow and shrink as elements are added or removed.

### Class Members

- `DynamicArray()`: Default constructor that initializes an empty dynamic array.
- `~DynamicArray()`: Destructor that cleans up the dynamic array by deleting the allocated memory.
- `DynamicArray(const DynamicArray& _other)`: Copy constructor that creates a deep copy of another dynamic array.
- `DynamicArray(DynamicArray&& _other) noexcept`: Move constructor that moves the contents of another dynamic array.
- `operator=(const DynamicArray& _other)`: Copy assignment operator that assigns a deep copy of another dynamic array.
- `operator=(DynamicArray&& _other) noexcept`: Move assignment operator that moves the contents of another dynamic array.
- - `PushBack(const T& _newElement)`: Adds a new element to the end of the array.
- `PushBack(T&& _newElement)`: Adds a new element to the end of the array using move semantics.
- `PopBack()`: Removes the last element from the array.
- `Clear()`: Removes all elements from the array.
- `Reserve(size_t _newCapacity)`: Reserves memory for the specified number of elements.
- `EmplaceBack(Args&&... _args)`: Constructs a new element in-place at the end of the array.
- `operator[](size_t _index) const`: Accesses the element at the specified index in the array (const version).
- `operator[](size_t _index)`: Accesses the element at the specified index in the array.
- `Size() const`: Gets the size of the array.
- `Capacity() const`: Gets the capacity of the array.

### Usage

To use the `DynamicArray` class, include the `DynamicArray.h` header file in your C++ program:
Then, you can create 

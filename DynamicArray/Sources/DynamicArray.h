#pragma once
#include <iostream>
#include <cassert>

template<typename T>
class DynamicArray
{
public:
	/**
	* @brief Default constructor.
	*
	* Initializes an empty dynamic array.
	*/
	DynamicArray()
		: m_data(nullptr), m_size(0), m_capacity(0)
	{
	}

	/**
	* @breif Constructor with initial capacity.
	*/
	DynamicArray(size_t _capacity)
		: m_data(new T[_capacity]), m_size(0), m_capacity(_capacity)
	{
	}

	/**
	 * @brief Copy constructor.
	 */
	DynamicArray(const DynamicArray<T>& _other)
	{
		if (this == &_other)
		{
			return;
		}

		delete[] m_data;

		if (_other.m_capacity == 0)
		{
			m_data = nullptr;
			m_size = 0;
			m_capacity = 0;
			return;
		}

		m_size = _other.m_size;
		m_capacity = _other.m_capacity;

		if (m_capacity < m_size)
		{
			m_capacity = m_size;
		}
		m_data = new T[m_capacity];

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = _other.m_data[i];
		}
	}

	/**
	* @brief Move constructor.
	*/
	DynamicArray(DynamicArray<T>&& _other) noexcept
	{
		if (this == &_other)
		{
			return;
		}

		delete[] m_data;

		m_size = _other.m_size;
		m_capacity = _other.m_capacity;
		m_data = _other.m_data;

		_other.m_size = 0;
		_other.m_capacity = 0;
		_other.m_data = nullptr;
	}

	/**
	* @brief Destructor.
	*
	* Cleans up the dynamic array by deleting the allocated memory.
	*/
	~DynamicArray()
	{
		delete[] m_data;
	}

	/**
	* @brief Copy constructor.
	*  *
	* Initializes a new dynamic array as a copy of another dynamic array.
	*  *
	* @param _other The dynamic array to copy.
	*  */
	void operator=(const DynamicArray<T>& _other)
	{
		if (this == &_other)
		{
			return;
		}

		delete[] m_data;

		m_size = _other.m_size;
		m_capacity = _other.m_capacity;
		m_data = new T[m_capacity];

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = _other.m_data[i];
		}
	}

	/**
	* @brief Move constructor.
	*  *
	* Initializes a new dynamic array by taking ownership of the data from another dynamic array.
	*  *
	* @param _other The dynamic array to move.
	*  */
	void operator=(DynamicArray<T>&& _other) noexcept
	{
		if (this == &_other)
		{
			return;
		}

		delete[] m_data;

		m_size = _other.m_size;
		m_capacity = _other.m_capacity;
		m_data = _other.m_data;

		_other.m_size = 0;
		_other.m_capacity = 0;
		_other.m_data = nullptr;
	}

	/**
	* @brief Adds a new element to the end of the array.
	*
	* If the array is full, it will be resized to twice its current capacity.
	*
	* @param _newElement The new element to be added.
	*/
	void PushBack(const T& _newElement)
	{
		if (m_size >= m_capacity)
		{
			ReAlloc(m_capacity + 1);
		}

		m_data[m_size++] = _newElement;
	}

	/**
	* @brief Adds a new element to the end of the array using move semantics.
	*
	* If the array is full, it will be resized to twice its current capacity.
	*
	* @param _newElement The new element to be added.
	*/
	void PushBack(T&& _newElement)
	{
		if (m_size >= m_capacity)
		{
			ReAlloc(m_capacity + 1);
		}

		m_data[m_size++] = std::move(_newElement);
	}

	/**
	* @brief Removes the last element from the array.
	*
	* The element is destructed and the size of the array is decreased by one.
	*/
	void PopBack(void)
	{
		m_data[--m_size].~T();
	}

	/**
	* @brief Removes all elements from the array.
	*
	* All elements are destructed and the size of the array is set to zero.
	*/
	void Clear()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i].~T();
		}
		m_size = 0;
	}

	/**
	 * @brief Reserves memory for the array to prevent reallocation.
	 *
	 * @param _newCapacity The new capacity of the array.
	 */
	void Reserve(size_t _newCapacity)
	{
		if (_newCapacity > m_capacity)
		{
			ReAlloc(_newCapacity);
			m_size = _newCapacity;
		}
	}

	/**
	* @brief Constructs a new element in-place at the end of the array.
	*
	* If the array is full, it will be resized to accommodate the new element.
	*
	* @tparam Args The types of the arguments used to construct the new element.
	* @param _args The arguments used to construct the new element.
	* @return T& A reference to the newly constructed element.
	*/
	template<typename... Args>
	T& EmplaceBack(Args&&... _args)
	{
		if (m_size >= m_capacity)
		{
			ReAlloc(m_capacity + 1);
		}

		new(&m_data[m_size]) T(std::forward<Args>(_args)...);
		return m_data[m_size++];
	}

	/**
	* @brief Removes the element at the specified index from the array.
	*  *
	* The element is destructed and all subsequent elements are shifted to fill the gap.
	*  *
	* @param _index The index of the element to remove.
	*  * @throws std::out_of_range If the index is out of range.
	*  */
	void RemoveAt(size_t _index)
	{
		if (_index >= m_size || _index < 0)
		{
			assert(false && "Index out of range");
		}

		m_data[_index].~T();

		for (size_t i = _index; i < m_size - 1; i++)
		{
			m_data[i] = std::move(m_data[i + 1]);
		}

		m_size--;
	}

	/**
	* @brief Resizes the array to its current size.
	* *
	* @param _newSize The new size of the array.
	*  */
	void ShrinkToFit()
	{
		ReAlloc(m_size);
	}

	/**
	* @brief Accesses the element at the specified index in the array.
	*
	* @param _index The index of the element to access.
	* @return const T& A reference to the element at the specified index.
	* @throws std::out_of_range If the index is out of range.
	*/
	const T& operator[](size_t _index) const
	{
		if (_index >= m_size || _index < 0)
		{
			assert(false && "Index out of range");
		}
		return m_data[_index];
	}

	/**
	* @brief Accesses the element at the specified index in the array.
	*
	* @param _index The index of the element to access.
	* @return T& A reference to the element at the specified index.
	* @throws std::out_of_range If the index is out of range.
	*/
	T& operator[](size_t _index)
	{
		if (_index >= m_size || _index < 0)
		{
			assert(false && "Index out of range");
		}
		return m_data[_index];
	}

	/**
	* @brief Gets the size of the array.
	*
	* @return size_t The number of elements in the array.
	*/
	size_t Size(void) const
	{
		return m_size;
	}

	/**
	* @brief Gets the capacity of the array.
	*
	* @return size_t The capacity of the array.
	*/
	size_t Capacity(void) const
	{
		return m_capacity;
	}

private:
	/**
	* @brief Reallocates the memory for the array with a new capacity.
	*
	* @param _newCapacity The new capacity of the array.
	*/
	void ReAlloc(size_t _newCapacity)
	{
		// Allocate new block of memory
		T* newBlock = new T[_newCapacity];

		if (_newCapacity < m_size)
		{
			m_size = _newCapacity;
		}

		// Move old elements to new block
		for (size_t i = 0; i < m_size; i++)
		{
			newBlock[i] = std::move(m_data[i]);
		}

		// Delete old elements
		delete[] m_data;
		m_data = newBlock;
		m_capacity = _newCapacity;
	}

private:
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;
};

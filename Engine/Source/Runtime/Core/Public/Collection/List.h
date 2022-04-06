#include "Platform/Platform.h"
#include "Platform/PlatformTypes.h"

template <class T>
class List
{
public:
    List();

    List(int32 capacity);

public:
    ~List();

public:
    FORCEINLINE size_t Size() const;

    FORCEINLINE size_t Capacity() const;

    FORCEINLINE void Add(T element);

    FORCEINLINE bool Remove(T element);

    FORCEINLINE bool RemoveAt(size_t index);

    FORCEINLINE bool Contains(T element) const;

    FORCEINLINE size_t Find(T element) const;

public:
    FORCEINLINE T operator[](size_t index);

private:
    FORCEINLINE void AddElement(T element);

    FORCEINLINE void GrowContainer();

public:
    static const int32 DefaultCapacity;

    static const int32 DefaultGrowFactor;

    static const int32 InvalidIndex;

private:
    T *container;

    int32 size;

    int32 capacity;
};

template <class T>
const int32 List<T>::DefaultCapacity = 10;

template <class T>
const int32 List<T>::DefaultGrowFactor = 2;

template <class T>
const int32 List<T>::InvalidIndex = -1;

template <class T>
List<T>::List() : capacity(DefaultCapacity), size(0), container(new T[capacity])
{
}

template <class T>
List<T>::List(int32 capacity) : capacity(capacity), size(0), container(new T[capacity])
{
}

template <class T>
List<T>::~List()
{
    delete[] container;
}

template <class T>
FORCEINLINE size_t List<T>::Size() const
{
    return size;
}

template <class T>
FORCEINLINE size_t List<T>::Capacity() const
{
    return capacity;
}

template <class T>
FORCEINLINE void List<T>::Add(T element)
{
    if (size < capacity == false)
    {
        GrowContainer();
    }

    AddElement(element);
}

template <class T>
FORCEINLINE void List<T>::GrowContainer()
{
    capacity *= DefaultGrowFactor;
    T *newContainer = new T[capacity];
    for (size_t i = 0; i < size; ++i)
    {
        newContainer[i] = container[i];
    }

    delete[] container;

    container = newContainer;
}

template <class T>
FORCEINLINE void List<T>::AddElement(T element)
{
    container[size++] = element;
}

template <class T>
FORCEINLINE bool List<T>::Remove(T element)
{
    int elementIndex = Find(element);
    if (elementIndex != InvalidIndex)
    {
        return RemoveAt(elementIndex);
    }

    return false;
}

template <class T>
FORCEINLINE bool List<T>::RemoveAt(size_t index)
{
    if (index < size)
    {
        for (int i = index; i < size - 1; ++i)
        {
            container[i] = container[i + 1];
        }

        size -= 1;

        return true;
    }

    return false;
}

template <class T>
FORCEINLINE bool List<T>::Contains(T element) const
{
    for (int i = 0; i < size; ++i)
    {
        if (container[i] == element)
        {
            return true;
        }
    }

    return false;
}

template <class T>
FORCEINLINE size_t List<T>::Find(T element) const
{
    for (int i = 0; i < size; ++i)
    {
        if (container[i] == element)
        {
            return i;
        }
    }

    return InvalidIndex;
}

template <class T>
FORCEINLINE T List<T>::operator[](size_t index)
{
    return container[index];
}

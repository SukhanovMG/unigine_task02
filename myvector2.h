#include <limits>
#include <algorithm>

template<typename T> class myvector
{
public:
	myvector()
		: m_data(nullptr), m_capacity(0), m_size(0)
	{

	}
	~myvector()
	{
		for (int i = 0; i < m_size; i++)
			destroy_elem(i);
		delete[] m_data;
	}

	myvector(const myvector<T>& rhs)
		: m_data(nullptr), m_capacity(0), m_size(0)
	{
		realloc(rhs.capacity());
		for(int i = 0; i < rhs.size(); i++)
		{
			(*this)[i] = rhs[i];
			m_size++;
		}
	}

	myvector<T>& operator=(const myvector<T>& rhs)
	{
		realloc(rhs.capacity());
		for(int i = 0; i < rhs.size(); i++)
		{
			(*this)[i] = rhs[i];
			m_size++;
		}
		return *this;
	}

	int capacity() const { return m_capacity; }
	int size()     const { return m_size; }

	void add(const T& value)
	{
		push_back(value);
	}
	T& add()
	{
		push_back(T());
		return *(begin() + m_size - 1);
	}
	void erase(int index)
	{
		if (m_size <= 0 || index < 0)
			return;
		for (int i = index + 1; i < m_size; i++)
		{
			(*this)[i-1] = (*this)[i];
		}
		m_size--;
		destroy_elem(m_size);
	}

	void push_back(const T& value)
	{
		if (m_size == 0)
			realloc(1);
		if (m_size == m_capacity)
			realloc(m_capacity * 2);
		new(m_data + m_size * sizeof(T)) T(value);
		m_size++;
	}
	
	void erase(const T * item)
	{
		if (item < begin() && item >= end())
			return;
		std::ptrdiff_t diff = std::distance((const T*)begin(), item);
		if (diff > 0)
			erase((int) diff);
	}

	T & operator[](int index)
	{
		return *(begin() + index);
	}

	const T & operator[](int index) const
	{
		return *(begin() + index);
	}

	T * begin() const { return (T*)m_data; }
	T * end() const { return (T*)m_data + m_size; }

	void clear()
	{
		for (int i = 0; i < m_size; i++)
			destroy_elem(i);
		m_size = 0;
	}

	void resize(int new_size)
	{
		realloc(new_size);
	}

	void reserve(int min_capacity)
	{
		if (min_capacity < m_capacity)
			return;
		int new_capacity = m_capacity == 0 ? 1 : m_capacity;
		do
		{
			new_capacity *= 2;
			if (new_capacity <= 0)
				new_capacity = std::numeric_limits<int>::max();
		} while(new_capacity < min_capacity && new_capacity <= std::numeric_limits<int>::max());
		realloc(new_capacity);
	}

private:
	void destroy_elem(int index)
	{
		T* elem = begin() + index;
		elem->~T();
	}

	void realloc(int new_capacity)
	{
		if (new_capacity <= 0)
			return;
		char* new_data = new char[new_capacity * sizeof(T)];
		int element_to_copy = std::min(m_size, new_capacity);
		for (int i = 0; i < element_to_copy; i++)
		{
			T* _new_data = (T*) new_data;
			new (_new_data + i) T((*this)[i]);
		}
		m_capacity = new_capacity;
		for (int i = 0; i < m_size; i++)
			destroy_elem(i);
		delete[] m_data;
		m_data = new_data;
	}

	char *m_data;
	int m_capacity;
	int m_size;
};
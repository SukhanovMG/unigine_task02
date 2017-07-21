#include <limits>
#include <algorithm>

template<typename T> class myvector
{
public:
	myvector()
		: m_data(nullptr), m_capacity(0), m_size(0)
	{
		realloc(8);
	}
	~myvector()
	{
		delete[] m_data;
	}

	myvector(const myvector<T>& rhs)
		: m_data(nullptr), m_capacity(0), m_size(0)
	{
		realloc(rhs.capacity());
		for(int i = 0; i < rhs.size(); i++)
		{
			m_data[i] = rhs[i];
			m_size++;
		}
	}

	myvector<T>& operator=(const myvector<T>& rhs)
	{
		realloc(rhs.capacity());
		for(int i = 0; i < rhs.size(); i++)
		{
			m_data[i] = rhs[i];
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
		return m_data[m_size-1];
	}
	void erase(int index)
	{
		if (m_size <= 0 || index < 0)
			return;

		for (int i = index + 1; i < m_size; i++)
		{
			m_data[i-1] = m_data[i];
		}
		m_size--;
		m_data[m_size] = T();
	}

	void push_back(const T& value)
	{
		if (m_size == m_capacity)
			realloc(m_capacity * 2);
		m_data[m_size++] = value;
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
		return m_data[index];
	}

	const T & operator[](int index) const
	{
		return m_data[index];
	}

	T * begin() { return m_data; }
	T * end() { return m_data + m_size; }

	void clear()
	{
		for (int i = 0; i < m_size; i++)
			m_data[i] = T();
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
		int new_capacity = m_capacity;
		do
		{
			new_capacity *= 2;
			if (new_capacity <= 0)
				new_capacity = std::numeric_limits<int>::max();
		} while(new_capacity < m_capacity && new_capacity <= std::numeric_limits<int>::max());
		realloc(new_capacity);
	}
private:
	void realloc(int new_capacity)
	{
		if (new_capacity <= 0)
			return;
		T* new_data = new T[new_capacity];
		int elements_to_copy = std::min(m_size, new_capacity);
		try
		{
			for (int i = 0; i < elements_to_copy; i++)
			{
				new_data[i] = m_data[i];
			}
		}
		catch(...)
		{
			delete[] new_data;
			throw;
		}
		m_capacity = new_capacity;
		try
		{
			delete[] m_data;
		}
		catch(...)
		{
		}
		m_data = new_data;
	}

	T* m_data;
	int m_capacity;
	int m_size;
};
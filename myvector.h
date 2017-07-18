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

	int capacity() const { return m_capacity; }
	int size()     const { return m_size; }

	void push_back(const T& value)
	{
		if (m_size == m_capacity)
			realloc(m_capacity * 2);
		m_data[m_size++] = value;
	}

	T & operator[](int index)
	{
		return m_data[index];
	}

	T * begin() { return m_data; }
	T * end() { return m_data + m_size; }
private:
	void realloc(int new_capacity)
	{
		if (new_capacity <= 0 || new_capacity < m_capacity)
			return;
		T* new_data = new T[new_capacity];
		try
		{
			for (int i = 0; i < size(); i++)
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
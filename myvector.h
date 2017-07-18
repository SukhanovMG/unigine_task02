template<typename T> class myvector
{
public:
	myvector()
		: m_data(nullptr), m_capacity(0), m_size(0)
	{
		m_data = new T[8];
		m_capacity = 8;
	}
	~myvector()
	{
	}

	int capacity() const { return m_capacity; }
	int size()     const { return m_size; }

	void push_back(const T& value)
	{
		m_data[m_size++] = value;
	}

	T & operator[](int index)
	{
		return m_data[index];
	}

	T * begin() { return m_data; }
	T * end() { return m_data + m_size; }
private:
	T* m_data;
	int m_capacity;
	int m_size;
};
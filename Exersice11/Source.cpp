#include <iostream>

class SampleVector
{
private:
	int* data;
	int size;
	int capacity;
public:
	SampleVector()
	{
		this->size = 0;
		capacity = 0;
	}

	SampleVector(int capacity)
	{
		data = new int[capacity];
		this->size = 0;
		this->capacity = capacity;
	}

	SampleVector(int capacity, int value)
	{
		data = new int[capacity];
		for (int i = 0; i < capacity; i++)
		{
			data[i] = value;
		}
		this->size = capacity;
		this->capacity = capacity;
	}

	~SampleVector()
	{
		delete[] data;
		data = nullptr;
	}

	int get_size()
	{
		return this->size;
	}

	int get_capacity()
	{
		return this->capacity;
	}

	int get(int index)
	{
		if (index >= this->size)
		{
			std::cout << "Index out of a range!" << std::endl;
			return 0;
		}
		else
		{
			return data[index];
		}
	}

	void set(int index, int value)
	{
		if (index >= this->size)
		{
			std::cout << "Index out of a range!" << std::endl;
		}
		else
		{
			data[index] = value;
		}
	}

	void push_back(int value)
	{
		if (capacity == 0)
		{
			data = new int[1];
			size = 1;
			capacity = 1;

			data[0] = value;
		}
		else
		{
			if (size < capacity)
			{
				data[size] = value;
				size++;
			}
			else
			{
				capacity = int(capacity * 1.5) + 1;
				int* new_data = new int[capacity];
				for (int i = 0; i < size; i++)
					new_data[i] = data[i];

				new_data[size] = value;
				size++;

				delete[] data;
				data = new_data;
			}
		}
	}
};


using namespace std;
int main()
{
	SampleVector v = SampleVector();
	cout << "Size: " << v.get_size() << " || Capacity: " << v.get_capacity() << endl;
	for (int i = 1; i <= 17; i++)
	{
		v.push_back(i);
		cout << "Size: " << v.get_size() << " || Capacity: " << v.get_capacity() << endl;
	}

	return 0;
}
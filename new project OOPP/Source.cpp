#include <iostream>
#include <vector>

class MyClass {
public:
	explicit MyClass(int a) // explicit - Это, нужно для того чтобы ограничить для неявных появлений данных. 
	{
		if (a >= 0)
		{
			data.reserve(a);
			this->intit();
		}
	}

	int operator + (const MyClass obj)const
	{
		int result{};
		for (size_t i = 0; i < obj.data.size(); i++)
		{
			result += obj.data[i];
		}

		for (size_t i = 0; i < this->data.size(); i++)
		{
			result += this->data[i];
		}
		return result;
	}

private:
	void intit()
	{
		for (size_t i = 0; i < data.capacity(); i++)
		{
			data.push_back(i + 1);
		}
	}

	std::vector <int> data;
};

class integer
{
public:
	int units;
	integer operator ++()
	{
		units += 1;
		return *this;
	}

	integer operator ++(int)
	{
		integer result;
		result.units = units;
		units += 1;
		return *this;
	}

	// Постфиксные операторы, всегда используют дополнтиленые объём памяти и тратят процессорное время.

	integer operator --()
	{
		units -= 1;
		return *this;
	}
};

int main() 
{
	/*MyClass a(4);
	MyClass b(4);
	std::cout << a + MyClass(1);
	std::cout << std::endl;*/
	
	int num;
	num = 9;
	int r1 = num++;
	int r2 = num--;
	
	integer a;
	a.units = 9;
	integer r3(a++);
	integer r4(--a);

	return {};
}
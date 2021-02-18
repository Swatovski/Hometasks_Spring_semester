#include <iostream>
#include <vector>

int main()
{
	std::vector < int > vec;

	std::cout << vec.capacity() << std::endl; // Ёмкость такого 0

	for (auto i = 0; i < 40; i++)
	{
		vec.push_back(i);
	}

	std::cout << vec.capacity() << std::endl;

	for (auto i = 40; i < 60; i++)
	{
		vec.push_back(i);
	}

	std::cout << vec.capacity() << std::endl;

	for (auto i = 60; i < 90; i++)
	{
		vec.push_back(i);
	}

	std::cout << vec.capacity() << std::endl;

	// Видно, что вектор увеличивается в 1,5 раза каждый раз, как память заканчивается

	vec.reserve(100);

	std::cout << vec.capacity() << std::endl; // Будет 100

	for (auto i = 90; i < 102; i++)
	{
		vec.push_back(i);

		if (i == 99)
		{
			std::cout << vec.capacity() << std::endl; // До увеличения размера - будет 100
		}

		if (i == 100)
		{
			std::cout << vec.capacity() << std::endl; // После увеличения размера - будет 150 (в полтора раза растёт, как обычно)
		}
	}

	int cap = vec.capacity();

	for (auto i = 100; i < 1000000000; i++) // В какой-то момент уже не хватает памяти системе, и выбрасывается исключение bad_alloc
	{										// а до этого выделение памяти такое же - повышение в 1,5 раза
		vec.push_back(i);
		if (cap != vec.capacity())
		{
			cap = vec.capacity();
			std::cout << cap << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
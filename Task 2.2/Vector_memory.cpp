#include <iostream>
#include <vector>

int main()
{
	std::vector < int > vec;

	std::cout << vec.capacity() << std::endl; // ������� ������ 0

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

	// �����, ��� ������ ������������� � 1,5 ���� ������ ���, ��� ������ �������������

	vec.reserve(100);

	std::cout << vec.capacity() << std::endl; // ����� 100

	for (auto i = 90; i < 102; i++)
	{
		vec.push_back(i);

		if (i == 99)
		{
			std::cout << vec.capacity() << std::endl; // �� ���������� ������� - ����� 100
		}

		if (i == 100)
		{
			std::cout << vec.capacity() << std::endl; // ����� ���������� ������� - ����� 150 (� ������� ���� �����, ��� ������)
		}
	}

	int cap = vec.capacity();

	for (auto i = 100; i < 1000000000; i++) // � �����-�� ������ ��� �� ������� ������ �������, � ������������� ���������� bad_alloc
	{										// � �� ����� ��������� ������ ����� �� - ��������� � 1,5 ����
		vec.push_back(i);
		if (cap != vec.capacity())
		{
			cap = vec.capacity();
			std::cout << cap << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
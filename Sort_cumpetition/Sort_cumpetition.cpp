#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

#include <algorithm>

#include "C:\Users\berna\source\repos\Timer\Timer\Timer.cpp"

int main()
{
	Timer my_timer;
	int num;

	std::array < int, 1000 > a_1;
	std::vector < int > a_2;
	std::deque < int > a_3;
	std::list < int > a_4;
	std::forward_list < int > a_5;

	// ���������� ��������

	for (auto i = 0; i < 1000; i++)
	{
		num = std::rand();

		a_1[i] = num;
		a_2.push_back(num);
		a_3.push_back(num);
		a_4.push_back(num);
		a_5.push_front(num);
	}

	a_5.reverse(); // ��� ��� ������� ������������ - ��������� ��������� � �����, � ���� � ������, ��� ��� ���� ����������

	// ������ ���������� - std::array

	std::cout << "array" << std::endl;
	my_timer.start_new_timer();
	std::sort(a_1.begin(), a_1.end());
	my_timer.elapsed();

	// ������ ���������� - std::vector

	std::cout << "vector" << std::endl;
	my_timer.start_new_timer();
	std::sort(a_2.begin(), a_2.end());
	my_timer.elapsed();

	// ������ ���������� - std::deque
	
	std::cout << "deque" << std::endl;
	my_timer.start_new_timer();
	std::sort(a_3.begin(), a_3.end());
	my_timer.elapsed();

	// �������� ���������� - std::list

	std::cout << "list" << std::endl;
	my_timer.start_new_timer();
	a_4.sort();
	my_timer.elapsed();

	// ����� ���������� - std::forward_list

	std::cout << "forward_list" << std::endl;
	my_timer.start_new_timer();
	a_5.sort();
	my_timer.elapsed();

	// �����
	// ������� ���� ����������� list � forward_list ������ ������������, ������� � ������� ����
	// ����� ���� �������� � 1,5-2 ���� ��������� array � vector � ������� std::sort (� ��� ��� �����)
	// � � �����, � ����������� ��� ���� � 3, ������� deque, �.�. �� �������� ����������� ���������� ������� ��������� ������, ������� ������� ��� ������ �� ��������� � ��������� �������

	return EXIT_SUCCESS;
}
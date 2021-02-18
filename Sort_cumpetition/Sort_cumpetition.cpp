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

	// Заполнение массивов

	for (auto i = 0; i < 1000; i++)
	{
		num = std::rand();

		a_1[i] = num;
		a_2.push_back(num);
		a_3.push_back(num);
		a_4.push_back(num);
		a_5.push_front(num);
	}

	a_5.reverse(); // это для чистоты эксперимента - остальные добавляли в конец, а этот в начало, так что надо развернуть

	// Первый претендент - std::array

	std::cout << "array" << std::endl;
	my_timer.start_new_timer();
	std::sort(a_1.begin(), a_1.end());
	my_timer.elapsed();

	// Второй претендент - std::vector

	std::cout << "vector" << std::endl;
	my_timer.start_new_timer();
	std::sort(a_2.begin(), a_2.end());
	my_timer.elapsed();

	// Третий претендент - std::deque
	
	std::cout << "deque" << std::endl;
	my_timer.start_new_timer();
	std::sort(a_3.begin(), a_3.end());
	my_timer.elapsed();

	// Четвёртый претендент - std::list

	std::cout << "list" << std::endl;
	my_timer.start_new_timer();
	a_4.sort();
	my_timer.elapsed();

	// Пятый претендент - std::forward_list

	std::cout << "forward_list" << std::endl;
	my_timer.start_new_timer();
	a_5.sort();
	my_timer.elapsed();

	// ИТОГО
	// Быстрее всех сортируются list и forward_list своими сортировками, времена в среднем одни
	// Затем идут примерно в 1,5-2 раза медленнее array и vector с помощью std::sort (у них нет своих)
	// И в конце, с отставанием ещё раза в 3, плетётся deque, т.к. он обладает специфичной страничной моделью выделения памяти, поэтому требует доп затрат на обращения к элементам массива

	return EXIT_SUCCESS;
}
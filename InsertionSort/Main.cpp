#include <iostream>
#include <Windows.h>

// 삽입 정렬 구현
void InsertionSort(int* array, int length)
{
	if (length <= 1) return;

	
	// 배열 순회
	for (int i = 1; i < length; i++)
	{
		// 현재 삽입할 값.
		int key = array[i];
		int j = i - 1;

		// key보다 큰 값은 오른쪽으로 배치.
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}

		// 적절한 위치에 키 삽입.
		array[j + 1] = key;

	}
}



// 배열 항목 출력
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i];
		if (i < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

void InsertionSort2(int* array, int length)
{
	for (int i = 1; i < length; i++)
	{
		int current = i - 1;
		int key = array[i];

		while (current >= 0 && key < array[current])
		{
			array[current + 1] = array[current];
			--current;
		}

		array[current + 1] = key;
	}
}


int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };
	int length = ARRAYSIZE(array);

	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	InsertionSort2(array, length);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);

	std::cin.get();
}
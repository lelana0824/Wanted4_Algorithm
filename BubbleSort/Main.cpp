#include <iostream>
// 함수 포인터 타입 지정

using Comparer = bool (*)(int, int);

// 함수 포인터 활용
bool IsGreater(int left, int right)
{
	return left > right;
}

bool IsLess(int left, int right)
{
	return left < right;
}

// 버블 정렬 함수
// 비교 조건 확인 로직을 위임. 델리게이트
// c++ 일반 함수 - Function
// 객체의 멤버 함수 - Method
void BubbleSort(int* array, int length, Comparer comparer)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			// 비교
			if (comparer(array[j], array[j + 1]))
			{
				// 교체
				std::swap<int>(array[j], array[j + 1]);
			}
		}
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


void BubbleSort2(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap<int>(array[j], array[j + 1]);
			}
		}
	}
}

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	int length = sizeof(array) / sizeof(array[0]);

	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	BubbleSort2(array, length);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);
	std::cin.get();
}
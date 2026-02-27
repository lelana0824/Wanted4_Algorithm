#include <iostream>

// 병합 함수. 구현 난이도 어려움.
void Merge(
	int* array,
	int* leftArray, int leftArrayLength,
	int* rightArray, int rightArrayLength
)
{
	// 인덱스.
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	// 왼쪽/오른쪽 배열 요소를 비교해 더 작은 배열의 요소를
	// array에 복사.
	while (leftIndex < leftArrayLength &&
		rightIndex < rightArrayLength)
	{
		// 왼쪽 배열의 항목이 더 작으면 array에 설정.
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		// 오른쪽 배열의 항목이 더 작으면 array에 설정.
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		// 병합된 배열의 인덱스 증가 처리.
		mergedIndex++;
	}

	// 위의 과정에서 왼쪽 배열의 남은 요소를 최종 배열에 복사.
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		leftIndex++;
		mergedIndex++;
	}

	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		rightIndex++;
		mergedIndex++;
	}
}

// 병합 정렬 함수 (재귀).
void MergeSort(int* array, int length)
{
	// 종료 조건.
	if (length <= 1) return;

	// 배열 나누기.
	int mid = length / 2;
	int rightArrayLength = length - mid;
	// 나눠서 저장할 배열 선언 (공간 사용)
	int* leftArray = new int[mid];
	int* rightArray = new int[rightArrayLength];

	// 배열 복사. memcpy 함수로 메모리 통 복사.
	memcpy(leftArray, array, sizeof(array[0]) * mid);
	memcpy(rightArray, array + mid, sizeof(array[0]) * (rightArrayLength));

	// 왼쪽 배열 병합 정렬 (재귀)
	MergeSort(leftArray, mid);
	// 오른쪽 배열 병합 정렬 (재귀)
	MergeSort(rightArray, rightArrayLength);

	// 병합
	Merge(array, leftArray, mid, rightArray, rightArrayLength);

	// 동적 메모리 해제.
	delete[] leftArray;
	delete[] rightArray;
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

void Merge2(int* array,
	int* leftArray, int leftArrayLength,
	int* rightArray, int rightArrayLength)
{
	int index = 0;
	int leftIndex = 0;
	int rightIndex = 0;

	while (leftIndex < leftArrayLength
		&& rightIndex < rightArrayLength)
	{
		if (leftArray[leftIndex] < rightArray[rightIndex])
		{
			array[index] = leftArray[leftIndex++];
		}
		else
		{
			array[index] = rightArray[rightIndex++];
		}
		index++;
	}


	if (leftIndex < leftArrayLength)
	{
		for (int i = leftIndex; i < leftArrayLength; i++)
		{
			array[index++] = leftArray[i];
		}
	}

	if (rightIndex < rightArrayLength)
	{
		for (int i = rightIndex; i < rightArrayLength; i++)
		{
			array[index++] = rightArray[i];
		}
	}
}

void MergeSort2(int* array, int length)
{
	if (length <= 1) return;

	int mid = length / 2;
	int leftArrayLength = mid;
	int rightArrayLength = length - mid;

	int* leftArray = new int[leftArrayLength];
	int* rightArray = new int[rightArrayLength];

	memcpy(leftArray, array, (leftArrayLength * sizeof(array[0])));
	memcpy(rightArray, array + mid, (rightArrayLength * sizeof(array[0])));

	MergeSort2(leftArray, leftArrayLength);
	MergeSort2(rightArray, rightArrayLength);

	Merge2(array,
		leftArray, leftArrayLength,
		rightArray, rightArrayLength
	);

	delete[] leftArray;
	delete[] rightArray;
}

int main()
{
	// 자료 집합 1.
	//int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };
	int array[] =
	{
		1, 58, 10, 20, 56, 63, 73, 5, 28, 37,
		80, 61, 82, 45, 11, 66, 83, 59, 22, 64,
		52, 89, 94, 76, 44, 40, 75, 2, 23, 57,
		92, 8, 41, 96, 15, 84, 35, 69, 54, 47,
		90, 24, 43, 74, 34, 85, 72, 95, 18, 17,
		98, 9, 29, 53, 27, 79, 39, 51, 31, 16,
		6, 97, 26, 100, 21, 48, 33, 60, 91, 19,
		30, 13, 71, 78, 87, 25, 81, 4, 42, 93,
		49, 12, 14, 7, 62, 77, 38, 99, 88, 50,
		32, 46, 70, 3, 86, 68, 36, 67, 55, 65
	};
	int length = sizeof(array) / sizeof(array[0]);

	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	MergeSort2(array, length);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);

	std::cin.get();
}
// sortTest.cpp: 定义应用程序的入口点。
//

#include <chrono>

#include "impl/selectionSort.h"
#include "impl/bubbleSort.h"
#include "impl/insertSort.h"
#include "impl/shellSort.h"
#include "impl/quickSort.h"
#include "impl/heapSort.h"


#include "benchmark.h"

using namespace std;

int main()
{
	{
		std::vector<int> testData{ 5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6,5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6 };

		BubbleSort qst(testData);
		BenchMark mark(&qst);
		mark.measure();
	}
	{
		std::vector<int> testData{ 5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6,5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6 };

		SelectionSort qst(testData);
		BenchMark mark(&qst);
		mark.measure();
	}
	{
		std::vector<int> testData{ 5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6,5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6 };

		InsertSort qst(testData);
		BenchMark mark(&qst);
		mark.measure();
	}
	{
		std::vector<int> testData{ 5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6,5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6 };

		ShellSort qst(testData);
		BenchMark mark(&qst);
		mark.measure();
	}
	
	{
		std::vector<int> testData{ 5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6,5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6 };

		QuickSort qst(testData);
		BenchMark mark(&qst);
		mark.measure();
	}

	{
		std::vector<int> testData{ 5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6,5,6,8,4,2,3,1,2,5,3,7,8,9,5,6,8,4,2,3,1,2,5,3,7,8,9,6 };

		HeapSort hst(testData);
		BenchMark mark(&hst);

		mark.measure();
	}

	return 0;
}

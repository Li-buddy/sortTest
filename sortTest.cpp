// sortTest.cpp: 定义应用程序的入口点。
//

#include "sortTest.h"
#include "impl/selectionSort.h"
#include "impl/bubbleSort.h"
#include "impl/insertSort.h"

using namespace std;

int main()
{
	std::vector<int> data{7,5,9,8,6,1};
	SelectionSort sls(data);

	sls.show();
	sls.sort();

	std::vector<int> data2{ 7,5,9,8,6,1 };
	BubbleSort bb(data2);

	bb.show();
	bb.sort();

	std::vector<int> data3{ 7,5,9,8,6,1 };
	InsertSort ins(data3);

	ins.show();
	ins.sort();

	return 0;
}

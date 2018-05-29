// you can use includes, for example:
#include <algorithm>
#include <cmath>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
double maximum = -987654321;

int solution(int A, int B, int C, int D) {
	// write your code in C++14 (g++ 6.2.0)
	//int arr[4] = {A, B, C, D};
	double abcd = ((A - C)*(A - C) + (B - D)*(B - D));//(A,B) (C,D) == (B,A) (D,C)
	double acbd = ((A - B)*(A - B) + (C - D)*(C - D));//(A,C) (B,D) == (C,A) (D,B)
	double abdc = ((A - D)*(A - D) + (B - C)*(B - C));//(A,B) (D,C) == (B,A) (C,D)

	if (abcd > maximum) maximum = abcd;
	if (acbd > maximum) maximum = acbd;
	if (abdc > maximum) maximum = abdc;
	return maximum;
}
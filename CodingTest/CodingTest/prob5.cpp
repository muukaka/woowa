// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int maxA = -987654321;
int maxB = -987654321;
int maxSum = -987654321;
int solution(vector<int> &A, int K, int L) {
	// write your code in C++14 (g++ 6.2.0)
	int sz = (int)A.size();
	if (K + L > sz)// base case
		return -1;

	for (int i = 0; i + K + L - 1 < sz; i++)// K���� ��ġ
	{
		int sumA = 0;
		for (int k = 0; k < K; k++)// K�� ����
		{
			sumA += A[i + k];
		}

		for (int j = i + K; j + L - 1 < sz; j++)//���� ĭ
		{
			int sumB = 0;
			for (int l = 0; l<L; l++)//L�� ����
			{
				sumB += A[j + l];
			}
			if (sumA + sumB > maxSum)
				maxSum = sumA + sumB;
		}
	}

	for (int i = 0; i + K + L - 1 < sz; i++)// L���� ��ġ
	{
		int sumA = 0;
		for (int l = 0; l < L; l++)// L�� ����
		{
			sumA += A[i + l];
		}

		for (int j = i + L; j + K - 1 < sz; j++)//���� ĭ
		{
			int sumB = 0;
			for (int k = 0; k<K; k++)//K�� ����
			{
				sumB += A[j + k];
			}
			if (sumA + sumB > maxSum)
				maxSum = sumA + sumB;
		}
	}

	return maxSum;
}
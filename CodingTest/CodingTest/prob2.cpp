// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &A, string &B) {
	// write your code in C++14 (g++ 6.2.0)
	int cnt = 0;
	int a, b;
	for (int i = 0; A[i]; i++)
	{
		if (A[i] == 'T') a = 10;
		else if (A[i] == 'J') a = 11;
		else if (A[i] == 'Q') a = 12;
		else if (A[i] == 'K') a = 13;
		else if (A[i] == 'A') a = 14;
		else
			a = A[i] - '0';

		if (B[i] == 'T') b = 10;
		else if (B[i] == 'J') b = 11;
		else if (B[i] == 'Q') b = 12;
		else if (B[i] == 'K') b = 13;
		else if (B[i] == 'A') b = 14;
		else
			b = B[i] - '0';

		if (a > b) cnt++;

	}
	return cnt;
}
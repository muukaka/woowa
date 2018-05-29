#include <iostream>
using namespace std;

int N;//1~10*1000*1000
int D;//1 or 0
int K, J;//1~1000*1000
int ret;

int survive[10000000];

void solve()
{
	int p = N;//처음에 사람 몇명인지, 1명 남을 때까지 반복
	int idx = 0;//1번에서 출발, 0번인덱스
	int mov = K;//처음에 K만큼 움직임, +J
	int rem;
	while (1)
	{
		int cnt = 0;//mov만큼 움직였는지 세기
		rem = mov % p;
		while (1)//한명 탈락자 걸러내는 과정
		{
			if (cnt == mov)// 현위치 탈락
			{
				if (survive[idx] == 1)
				{
					survive[idx] = 0;
					break;
				}
				else
					idx = (idx + N + 1 * D) % N;
			}
			else
			{
				idx = (idx + N + 1 * D) % N;
				if (survive[idx] == 1)
					cnt++;
			}
		}
		p--;
		if (p == 1) break;
		mov = (mov + J);
	}
}

int main() {
	// input
	cin >> N >> D >> K >> J;

	// initial
	for (int i = 0; i < N; i++)
		survive[i] = 1;
	if (D == 0) D = -1;

	// algo
	ret = 0;
	solve();

	// output
	for (int i = 0; i<N; i++)
		if (survive[i] == 1) ret = i + 1;
	cout << ret << endl;

	return 0;
}
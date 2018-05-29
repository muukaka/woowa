#include <iostream>
#include <vector>

using namespace std;

#define LIMIT 1*1000*1000*1000;
int N;
int mini = LIMIT;
int maxi = -LIMIT;

int main() {
	// input
	cin >> N;

	int stt, end;
	vector< vector<int> > cover(N);// int cover[N][2];
	for (int i = 0; i < N; i++)
	{
		cin >> stt >> end;
		cover[i].push_back(stt);
		cover[i].push_back(end);
		if (stt < mini) mini = stt;
		if (end > maxi) maxi = end;
	}
	// 구간이 몇번 나왔는지 카운트 하는 배열, 0과 max+1 위치 추가
	vector<int> range(maxi + 2, 0);
	vector<int> spot(maxi + 2, 0);
	for (int i = 0; i < N; i++)
	{
		int s = cover[i][0];
		int e = cover[i][1];
		for (int j = s; j < e; j++)
		{
			range[j]++;
			spot[j]++;
		}
		spot[e]++;
	}

	// output
	int open = 0;
	for (int i = 0; i <= maxi; i++)
	{
		if (i == 0)
		{
			cout << "(-,";
			if ((range[i] % 2) != (range[i + 1] % 2))
			{
				cout << i + 1 << ")" << endl;
				open = 1;
			}
		}
		else if (i == maxi)
		{
			if (open == 1)
			{
				if (spot[i] % 2 == 0)
					cout << "[" << i << ",";
				else
					cout << "(" << i << ",";
			}
			else
			{
				cout << "+)" << endl;
			}
			/*if (range[maxi] % 2 == 0)
				cout << "[" << maxi << ",";
			else
				cout << "(" << maxi << ",";*/
		}
		else
		{
			if ((range[i] % 2) != (range[i + 1] % 2))
			{
				if (open == 1 && spot[i + 1] % 2 == 0)
				{
					cout << "[" << i + 1 << ",";
					open = 0;
				}
				else if (open == 1 && spot[i + 1] % 2 != 0)
				{
					cout << "(" << i + 1 << ",";
					open = 0;
				}
				else if (open != 1 && spot[i + 1] % 2 == 0)
				{
					cout << i + 1 << "]" << endl;
					open = 1;
				}

				else if (open != 1 && spot[i + 1] % 2 != 0)
				{
					cout << i + 1 << ")" << endl;
					open = 1;
				}
			}
		}
		
	}
	return 0;
}
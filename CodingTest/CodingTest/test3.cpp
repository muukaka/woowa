#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
	int x1, x2;// ���� �Ʒ�
	int y1, y2;// ������ ��
};

Rect rect[3];
int ret;
int cover[3];//1�� �簢���� ��ġ���� ����, 0:2-3, 1:1-2, 2:1-3

void solve()
{
	// 1�� �簢���� 2,3�� �簢���� ��ġ�� �κ��� ����
	for (int i = 1; i < 3; i++)
	{
		Rect temp;
		temp.x1 = max(rect[0].x1, rect[i].x1);
		temp.y1 = max(rect[0].y1, rect[i].y1);
		temp.x2 = min(rect[0].x2, rect[i].x2);
		temp.y2 = min(rect[0].y2, rect[i].y2);

		if (temp.x2 > temp.x1 && temp.y2 > temp.y1)
			ret -= (temp.x2 - temp.x1) * (temp.y2 - temp.y1);
	}
	
	// 1,2,3�� �簢���� ��ġ�� �κ��� ���ϱ�
	Rect temp;
	temp.x1 = max(max(rect[0].x1, rect[1].x1), rect[2].x1);
	temp.y1 = max(max(rect[0].y1, rect[1].y1), rect[2].y1);
	temp.x2 = min(min(rect[0].x2, rect[1].x2), rect[2].x2);
	temp.y2 = min(min(rect[0].y2, rect[1].y2), rect[2].y2);
	if (temp.x2 > temp.x1 && temp.y2 > temp.y1)
		ret += (temp.x2 - temp.x1) * (temp.y2 - temp.y1);
}

int main() {
	// input
	for (int i = 0; i<3; i++)
	{
		cin >> rect[i].x1 >> rect[i].y1;
		cin >> rect[i].x2 >> rect[i].y2;
	}

	// algo
	ret = (rect[0].x2 - rect[0].x1) * (rect[0].y2 - rect[0].y1);// �ʱ� 1���� ���� ���
	solve();

	// output
	cout << ret << endl;

	return 0;
}
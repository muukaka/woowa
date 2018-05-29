// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <sstream>
#include <string>

vector<int> num;

int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	int sp = -1;//stack pointer
	istringstream iss(S);
	string sub;
	iss >> sub;
	//getline(iss, sub, ' ');
	while (iss)
	{
		//cout << "*" << sub << endl;
		if (!sub.compare("DUP"))
		{
			if (sp < 0)
				return -1;
			num.push_back(num[sp]);
			sp++;
		}
		else if (!sub.compare("POP"))
		{
			if (sp < 0)
				return -1;
			num.pop_back();
			sp--;
		}
		else if (sub == "+")
		{
			if (sp < 0)
				return -1;
			int top = num[sp];
			num.pop_back();
			sp--;

			if (sp < 0)
				return -1;
			num[sp] += top;
		}
		else if (sub == "-")
		{
			if (sp < 0)
				return -1;
			int top = num[sp--];
			num.pop_back();

			if (sp < 0)
				return -1;
			int down = num[sp];
			num.pop_back();

			top = top - down;
			num.push_back(top);
		}
		else// number
		{
			int temp = stoi(sub);
			sp++;
			num.push_back(temp);
		}
		//getline(iss, sub, ' ');
		iss >> sub;

		// vector<int>::iterator it;
		// for(int it=num.begin(); it != num.end(); it++)
		//     cout << *it << " ";

	}
	return num[sp];
}
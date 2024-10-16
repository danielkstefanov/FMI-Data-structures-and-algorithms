#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int simple_strcmp(const char* str1, const char* str2) {
	while (*str1 && (*str1 == *str2)) {
		++str1;
		++str2;
	}
	return *(unsigned char*)str1 - *(unsigned char*)str2;
}

bool toSwap(pair<string, unsigned>& firstStudent, pair<string, unsigned>& secondStudent) 
{
	return firstStudent.second < secondStudent.second || (firstStudent.second == secondStudent.second && simple_strcmp(firstStudent.first.c_str(), secondStudent.first.c_str()) > 0);
}

int main() {
	unsigned n;
	cin >> n;

	vector<pair<string, unsigned>> students;

	for (size_t i = 0; i < n; i++)
	{
		pair<string, unsigned> currentStudent;
		cin >> currentStudent.first;
		students.push_back(currentStudent);
	}

	for (size_t i = 0; i < n; i++)
		cin >> students[i].second;

	for (size_t i = 1; i < students.size(); i++)
	{
		pair<string, unsigned> currentStudent = students[i];
		int indexToPut = i-1;
		
		while (indexToPut >=0 && toSwap(students[indexToPut], currentStudent))
		{
			students[indexToPut+1] = students[indexToPut];
			indexToPut--;
		}

		students[indexToPut+1] = currentStudent;
	}

	for (size_t i = 0; i < n; i++)
		cout << students[i].first << ' ' << students[i].second << endl;
}
// Create.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std; //ACM 好坑啊
int main() {
	char str[100] = "#include<iostream>\n#include<stdio.h>\nusing namespace std;\nint main(){\n\n}";
	FILE *p;
	char  month[10], day[10];
	char file[100] = "C:\\Users\\xulez\\Desktop\\Coding\\2015-";
	cout << "Enter the Month: ";
	cin >> month;
	system("cls");
	strcat(file, month);
	strcat(file, "-");
	cout << "Enter the Day: ";
	cin >> day;
	system("cls");
	strcat(file, day);
	strcat(file, "-");
	char things[20];
	cout << "Enter the Things: ";
	cin >> things;
	system("cls");
	strcat(file, things);
	strcat(file, ".cpp");
	//	cout<<file<<endl;
	p = fopen(file, "w");
	fputs(str, p);
	cout << "Created!" << endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#pragma warning(disable:4996)
#include "String.h"

int main()
{
	Li::wString fas = L"adfdsf";
	Li::String one = "a";
	one = "";
	int k = one.empty();
	k == 1 ? std::cout << "��" << std::endl : std::cout << "����" << std::endl;
	one.append("~!@#$%^&*()_+-=");
	k = one.empty();
	k == 1 ? std::cout << "��" << std::endl : std::cout << "����" << std::endl;
	std::cout << "1: " << one << std::endl;
	one.append(L'U');
	std::cout << "2: " << one << std::endl;
	Li::String two(one);
	//two = "\\";
	//two.append(one);
	two == one ? std::cout << "һ��" << std::endl : std::cout << "��ͬ" << std::endl;
	std::cout << "3: " << two << std::endl;
	std::cin >> two;
	std::cout << "4: " << two << std::endl;
	two += one;
	std::cout << "5: " << two << std::endl;
	two += "+=";
	std::cout << "6: " << two << std::endl;
	two += L'*';
	std::cout << "7: " << two << std::endl;
	//const char *p = two.c_str();	// ����
	//char p[50];
	//strcpy(p, two.c_str());	// ���
	//std::cout << "8: " << p << std::endl;
	two == one ? std::cout << "һ��" << std::endl : std::cout << "��ͬ" << std::endl;
	two = two + L'a';
	std::cout << "9: " << two << std::endl;
	two = two + "aaa";
	std::cout << "10: " << two << std::endl;
	two = two + two;
	std::cout << "11: " << two << std::endl;


	//size_t a = one.size();
	//std::cout << one;
	//std::cout << "���ȣ� " << a << std::endl;
	//std::cin >> one;
	//a = one.size();
	//std::cout << one;
	//std::cout << "���ȣ� " << a << std::endl;

	//wchar_t b = L'��';
	//std::wcout.imbue(std::locale("chs"));
	//std::wcout << b << std::endl;

	system("pause");
	return 0;
}
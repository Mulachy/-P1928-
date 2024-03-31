#include <iostream>
#include <string>
using namespace std;

// 递归解压缩函数
string decompress(const string &compressed, int &index)
{
	string result;
	while (index < compressed.length())
	{
		char c = compressed[index];
		if(c == '[')
			index++;
		else if (isdigit(c))
		{
			// 提取数字
			int num = c - '0';
			while (isdigit(compressed[index + 1]))
			{
				num = num * 10 + (compressed[++index] - '0');
			}
			// 跳到下一个字符
			index++;
			// 递归解压缩子串
			string subResult = decompress(compressed, index);
			// 重复子串
			while (num--)
			{
				result += subResult;
			}
			// 跳过右括号
			index++;
		}
		else if (c == ']')
		{
			// 遇到右括号，返回当前结果
			return result;
		}
		else
		{
			// 普通字符，直接添加到结果
			result += c;
			index++;
		}
	}
	return result;
}

int main()
{
	string compressed;
	cin >> compressed;
	int index = 0;
	cout << decompress(compressed, index) << endl;
	return 0;
}

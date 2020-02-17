#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class SHA1
{
	// 循环左移,处理32位的数据块
	unsigned circleShift(const unsigned &word, const int &bits)
	{
		return (word << bits) | ((word) >> (32 - bits));
	}
	// 非线性函数
	unsigned sha1Function(const unsigned &B, const unsigned &C, const unsigned &D, const unsigned &t)
	{

		switch (t / 20)
		{
		case 0:
			return (B & C) | ((~B) & D);
		case 2:
			return (B & C) | (B & D) | (C & D);
		case 1:
		case 3:
			return B ^ C ^ D;
		}

		return t;
	}

public:
	string getSHAcode(const string &strRaw)
	{

		string str(strRaw);
		// 补一个1后面填0
		str += (unsigned char)(0x80);
		// 每个字节8位,所以要乘8,左移3位
		while (str.size() << 3 % 512 != 448)
		{
			str += (char)0;
		}
		//把输入字符串的长度转化为64位，然后8位8位取出来，按大端方式存储
		for (int i(56); i >= 0; i -= 8)
		{
			str += (unsigned char)((((unsigned __int64)strRaw.size()) << 3) >> i);
		}
		// 定义5个加法常量，每一轮的20步迭代都要用到
		const unsigned K[4] = {0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6};
		// 初始化5个32位寄存器
		unsigned A(0x67452301), B(0xefcdab89), C(0x98badcfe), D(0x10325476), E(0xc3d2e1f0), T(0);
		unsigned W[80] = {0}; //缓冲区

		// 每次处理str中的512位，即64字节
		for (unsigned i(0); i != str.size(); i += 64)
		{
			// 记录上一次循环寄存器的值
			unsigned A_(A), B_(B), C_(C), D_(D), E_(E);
			// 512位，分为16份子明文，每个子明文32位，即4个字节
			for (unsigned t(0); t != 16; t++)
			{
				// 将4个字节放到一个子明文中
				W[t] = ((unsigned)str[i + 4 * t] & 0xff) << 24 |
							 ((unsigned)str[i + 4 * t + 1] & 0xff) << 16 |
							 ((unsigned)str[i + 4 * t + 2] & 0xff) << 8 |
							 ((unsigned)str[i + 4 * t + 3] & 0xff);
			}
			// 将16分子明文扩展成80份，利用W[t] = CLS1(W[t-16]^W[t-14]^W[t-8]^W[t-3]),前16个W[t] = M[t],即等与子明文
			for (unsigned t(16); t != 80; ++t)
			{
				W[t] = circleShift(W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16], 1);
			}
			// 进行80轮迭代,利用A,B,C,D,E←[(A<<<5)+ ft(B,C,D)+E+Wt+Kt],A,(B<<<30),C,D
			for (unsigned t(0); t != 80; ++t)
			{
				T = circleShift(A, 5) + sha1Function(B, C, D, t) + E + W[t] + K[t / 20];
				E = D;
				D = C;
				C = circleShift(B, 30);
				B = A;
				A = T;
			}
			// 迭代完成后，新的寄存器中的值与老的寄存器的值相加,得到的结果作为下一次512明文的ABCDE寄存器的初始值
			A += A_;
			B += B_;
			C += C_;
			D += D_;
			E += E_;
		}
		//5个寄存器的值连接一起，输出结果
		stringstream ss;
		ss << setw(8) << setfill('0') << hex << A << B << C << D << E;
		ss >> str;
		return str;
	}
};
class t{
};
int main(int argc, char *argv[])
{

	string str("");

	cout << "输入一个串 :" << endl;
	getline(cin, str);
	SHA1 exam;
	string res = exam.getSHAcode(str);
	cout << "原来的: " << str << endl
			 << "sha1处理之后摘要: " << res << endl;

	return 0;
}
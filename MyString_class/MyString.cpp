#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<string>
/*
 - ����� ������, �����, �����������
 - ���������
 - ������� ���������, ������ ��������
 - ����������� �����������
 - ���� ����� ������
*/
class MyString
{
public:

	//����������� ��� ����������
	MyString()
	{
		str = nullptr;
		length = 0;
	}
	//����������� � �����������, ��� �������� ������� ������ ���������� ��������
	// ������ ������� �� ����� �������.
	MyString(const char* str)
	{
		//�������� ���������� �������� � ������ ������� �� �������� � ������(length),
		// ���� �� ��������� �� \0
		length = strlen(str);

		//+1 - ��������� 1 ����� � ������� ��� ������������� ����!
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{

			//�������� ������� �� private char*str(87 ������)
			this->str[i] = str[i];
		}
		//����������� � ����� ������ ������������� ����
		this->str[length] = '\0';
	}
	//������� � ������������ ������ ��� ������ ������
	~MyString()
	{
		delete[] this->str;
	}
	//����������� �����������, ����� ��� �������� ������ ����� ������� ������
	// �� � ������ ������� ������
	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}
	//������������� �������� ������������, ���������� ����� ����������
	// ��������� �������� ������ ������� �������
	MyString& operator =(const MyString& other)
	{
		//������ ���������� ��� � ������������, ���������� � ���, ��� �����
		// ����������� �� ������������ ������� �������
		// ���� �� ����������� � ���� ����� ������ �� ��� �������� ��� + ����������� 
		// ��������� ���������� ��������� =
		if (this->str != nullptr)
		{
			delete[]str;
		}
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
		return *this;
	}
	//������������� �������� ��������, � ������� ���������� ������ String
	// ��������� ��� ������������ �����
	MyString operator +(const MyString& other)
	{
		//������� ����� ������ ������ ��� ����� ������� ��������� ������������ ����� 
		// � ������� ����� ����������� ������ �������������� ��������� +
		MyString newStr;

		//�������� ���������� �������� � ����� ������� ��� ������������
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		//this � other - ������ ������� ������������ � � ������� ������������. ������� ���-��.
		newStr.length = thisLength + otherLength;

		//�������� ����� � ������������ ������ ��� ����� ������
		newStr.str = new char[thisLength + otherLength + 1];

		//����������� ������ �� 2-� ��������������� ����� � ����� ������
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[thisLength + otherLength] = '\0';

		//���������� ��������� ������������
		return newStr;
	}
	//������� ������ �� �����, � ������ ��� ����� ���������� ���������� ��������� <<
	void Print()
	{
		std::cout << str;
	}
	//���������� ����� ����� ������.
	int Length()
	{
		return length;
	}
	//���������� ��������� == (����� �� ������)
	bool operator==(const MyString& other)
	{
		//�������� ����� �����
		if (this->length != other.length)
		{
			return false;
		}
		//�������� �������� �����
		for (int i = 0; i < this->length; i++)
		{
			//��������� �� �������  
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		//������ ��������� �� true
		return true;
	}
	//���������� ��������� !=
	bool operator !=(const MyString& other)
	{
		//����������� ����� ���������
		return !(this->operator==(other));
	}

	//���������� �������� [ ] � ���������� ���������� ������� �� ������� ������ 
	// � ����� ����������� ������� � ������

	char& operator [](int index)
	{
		return this->str[index];
	}
	//����������� �����������, ������ �� ������ �� ������
	MyString(MyString&& other)
	{
		//�������� �������� ���� length
		this->length = other.length;
		//�������� ����� �������
		this->str = other.str;
		//��������� �������� ��� ������ �������
		other.str = nullptr;
	}
private:
	// ��������� �� ������ char, ������ ������� ������� �������� � ������
	char* str;
	int length;
};

int main()
{
	MyString str("Hello");
	MyString str2("World");
	MyString result;
	result = str + str2;
	std::cout << str.Length() << std::endl;
	std::cout << str2.Length() << std::endl;
	std::cout << result.Length() << std::endl;
	//	str.Print();
	//	std::cout << std::endl;
	////������ ������ � ������ str
	//	str[0] = 'q';
	//	str.Print();

	//�������� ������� �������
		//std::cout << str[0] << std::endl;

		std::cout<<(str!=str2)<<"\n"; //str.operator==(str2)
	return 0;
}
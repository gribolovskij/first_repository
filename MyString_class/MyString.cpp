#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<string>
/*
 - Длина строки, метод, оптимизация
 - Равенство
 - Перебор элементов, замена символов
 - Конструктор перемещения
 - Ввод вывод строки
*/
class MyString
{
public:

	//Конструктор без параметров
	MyString()
	{
		str = nullptr;
		length = 0;
	}
	//Конструктор с параметрами, при создание объекта класса необходимо передать
	// строку которую он будет хранить.
	MyString(const char* str)
	{
		//Получает количество символов в строке которую мы передаем в объект(length),
		// пока не наткнется на \0
		length = strlen(str);

		//+1 - Оставляем 1 место в массиве под терминирующий нуль!
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{

			//Копирует строчку из private char*str(87 строка)
			this->str[i] = str[i];
		}
		//Присваиваем в конец строки терминирующий нуль
		this->str[length] = '\0';
	}
	//Удаляем с динамической памяти наш объект класса
	~MyString()
	{
		delete[] this->str;
	}
	//Конструктор копирования, нужен для создания точной копии объекта класса
	// но в другой области памяти
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
	//Перегруженный оператор присваивания, вызывается когда необходимо
	// присвоить значение одного объекта другому
	MyString& operator =(const MyString& other)
	{
		//Логика реализации как в конструкторе, исключение в том, что нужно
		// позаботится об освобождение ресуров объекта
		// если до копирования в него новой строки он уже содержал код + стандартный 
		// синтаксис перегрузки оператора =
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
	//Перегруженный оператор сложения, в текущей реализации класса String
	// необходим для конкатенации строк
	MyString operator +(const MyString& other)
	{
		//Создаем новый пустой объект где будем хранить результат конкатенации строк 
		// и который будет результатом работы перегруженного оператора +
		MyString newStr;

		//Получаем количество символов в обеих строках для конкатенации
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		//this и other - строки которую присоединяем и к которой присоединяем. Считаем кол-во.
		newStr.length = thisLength + otherLength;

		//Выделяем место в динамической памяти под новую строку
		newStr.str = new char[thisLength + otherLength + 1];

		//Копирование данных из 2-х конкатенируемых строк в новую строку
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

		//Возвращаем результат конкатенации
		return newStr;
	}
	//Функция вывода на экран, в идеале для этого необходима перегрузка оператора <<
	void Print()
	{
		std::cout << str;
	}
	//Возвращаем длину нашей строки.
	int Length()
	{
		return length;
	}
	//Перегрузка оператора == (Равны ли строки)
	bool operator==(const MyString& other)
	{
		//Проверка длины строк
		if (this->length != other.length)
		{
			return false;
		}
		//Проверка символов строк
		for (int i = 0; i < this->length; i++)
		{
			//Иттерация по массиву  
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		//Строки одинаковы то true
		return true;
	}
	//Перегрузка оператора !=
	bool operator !=(const MyString& other)
	{
		//Рекурсивный вызов оператора
		return !(this->operator==(other));
	}

	//Перегрузка оператор [ ] и возвращаем конкретный элемент из массива класса 
	// и можем присваивать элемнты в массив

	char& operator [](int index)
	{
		return this->str[index];
	}
	//Конструктор перемещения, Ссылка на ссылку на объект
	MyString(MyString&& other)
	{
		//Копируем значение поля length
		this->length = other.length;
		//Копируем адрес объекта
		this->str = other.str;
		//Запрещаем удаление для нового объекта
		other.str = nullptr;
	}
private:
	// Указатель на массив char, хранит символы которые передали в объект
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
	////Меняем символ в строке str
	//	str[0] = 'q';
	//	str.Print();

	//Получаем элемент массива
		//std::cout << str[0] << std::endl;

		std::cout<<(str!=str2)<<"\n"; //str.operator==(str2)
	return 0;
}
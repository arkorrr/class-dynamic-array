#include <iostream>

using namespace std;

class Point
{
	int x;
	int y;
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point()
	{
		x = 0;
		y = 0;
	}

	int getX() { return x; }
	int getY() { return y; }
};

template<typename T>
class DynArray
{
	T* arr;
	T size;
public:
	DynArray(T sizeP) : arr{ new T[sizeP] {} }, size{ sizeP }
	{
		cout << "DynArr constructed for " << size << " elements, for " << this << '\n';
	}
	int getElem(T idx) { return arr[idx]; }
	void setElem(T idx, T val) { arr[idx] = val; }
	void print();
	void randomize();
	void sum(); 
	~DynArray()
	{
		delete[] arr;
	}
	int& operator[] (const int index);
};



template<typename T>
void DynArray<T>::sum()
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	cout << "Sum of array = " << sum << endl;
}

template<typename T>
int& DynArray<T>::operator[](const int index)
{
	return arr[index];
}

template<typename T>
void DynArray<T>::print()
{
	for (int i{ 0 }; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

template<typename T>
void DynArray<T>::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}

ostream& operator<<(ostream& os, Point& obj) // перегрузка вывода в консоль
{
	os << "x: " << obj.getX() << "   y: " << obj.getY() << endl;
	return os;
}
	
int main()
{
	DynArray<int> ar1{ 10 };
	ar1.randomize();
	cout << "ar1 elements: ";
	ar1.print();
	ar1.sum();

	DynArray<double> ar2{ 10 };
	cout << "ar2 elements: ";
	ar2.randomize();
	ar2.print();
	ar2.sum();


	DynArray<char> ar3{ 10 };
	cout << "ar3 elements: ";
	ar3.randomize();
	ar3.print();
	ar3.sum();

	/*Point p(2, 2);
	DynArray<Point> ar4{ p };
	ar4.randomize();
	cout << "ar4 elements: ";
	ar4.print();
	ar4.sum();*/

	return 0;
}



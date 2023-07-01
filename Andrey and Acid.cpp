#include iostream
#include vector

using namespace std;

int main() {
	 вводим количество резервуаров
	int n;
	cin  n;
	vectorint v(n);
	 вводим значения для каждого резервуара
	for (int i = 0; i  n; i++)
	{
		cin  v[i];
	}
	int result = v[n - 1] - v[0];
	 проверка можно ли вообще разлить
	for (int i = 0; i  n-1; i++)
	{
		if (v[i]  v[i + 1])
		{
			cout  -1  endl;
			return 0;
		}
	}
	
	cout  result  endl;

	return 0;
}

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class optimal {
public:
	short int point;
	short int use = 0;
};

int main()
{

	int32_t n, k;
	cin >> n >> k;
	vector<int32_t> arr(n);
	for (int32_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<optimal> opt(n);
	for (int32_t i = 0; i < n; i++)
	{
		opt[i].point = arr[i];
	}

	int32_t temp;
	int64_t result=NULL;
	int64_t resultfinal=0;



	int32_t countinarray=0;
	for (int32_t nt = 0; nt < n; nt++)
	{
		for (int32_t i = 0; i < k; i++)
		{
			for (int32_t j = 0; j < n; j++)
			{
				if (j != nt && opt[j].use != 1) {
					if (countinarray == 0)
					{
						result = abs(opt[nt].point - opt[j].point);
						opt[j].use = 1;
						temp = j;
						countinarray++;
					}
					if (result > abs(opt[nt].point - opt[j].point))
					{
						result = abs(opt[nt].point - opt[j].point);
						opt[temp].use = 0;
						temp = j;
						opt[temp].use = 1;
						
					}
				}
			}
			resultfinal += result;
			result = 0;
			countinarray = 0;
		}
		cout << resultfinal << ' ';
		resultfinal = 0;
		for (short int s = 0; s < n; s++)
		{
			opt[s].use = 0;
		}
	}

	return 0;
}
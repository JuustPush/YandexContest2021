#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Desire {
public:
	int num;
	string position;
    string side;
    int used=0;
};

char letter[7] = { 'A', 'B', 'C', '_', 'D', 'E', 'F' };

int main() {

	int Count_Rows;
	cin >> Count_Rows;
	// add seats
	vector<string> Rows(Count_Rows);
	for (int i = 0; i < Count_Rows; i++)
	{
		cin >> Rows[i];
	}



	// desired location
    int k, Count_Desired;
    cin >> k;
    Count_Desired = k;
    k *= 3;
    int count = 0;
    vector<string> input1(k);
    vector<Desire> des(Count_Desired);
    for (int i = 0; i < k; i++)
    {
        cin >> input1[i];
    }

    for (int i = 0; i < Count_Desired;)
    {
        for (int j = 0; j < k; j++)
        {
            switch (count)
            {
            case 0:
                des[i].num = atoi(input1[j].c_str());
                count++;
                break;
            case 1:
                des[i].side = input1[j];
                count++;
                break;

            case 2:
                des[i].position = input1[j];
                i++;
                count = 0;
                break;
            default:
                break;
            }
        }
    }

    string result;

    for (int i = 0; i < Count_Desired; i++)
    {
        if (des[i].side == "left")
        {
            for (int j = 0; j < Count_Rows; j++)
            {
                int FromAisleLeft = 2, FromWindowLeft = 0;
                if (des[i].position=="aisle")
                {
                    for (int k = 0; k < des[i].num; k++)
                    {
                        if (Rows[j][FromAisleLeft]=='#')
                        {
                            FromAisleLeft = 2;
                            break;
                        }
                        else
                        {
                            FromAisleLeft--;
                        }
                        if (k+1 == des[i].num)
                        {
                            for (int r = 0; r < des[i].num; r++)
                            {
                                Rows[j][FromAisleLeft + 1] = 'X';
                                
                                result += ' '+to_string(j + 1) + letter[FromAisleLeft + 1];
                                FromAisleLeft++;
                            }
                            cout << "Passengers can take seats:" << result << endl;
                            result = "";
                            for (int nt = 0; nt < Count_Rows; nt++) cout << Rows[nt] << endl;
                            for (int nt = 0; nt < 7; nt++) if (Rows[j][nt] == 'X') Rows[j][nt] = '#';
                            des[i].used = 1;
                            break;
                            /*cout << endl;
                            for (int nt = 0; nt < Count_Rows; nt++) cout << Rows[nt] << endl;*/
                        }
                    }
                }
                else
                {
                    for (int k = 0; k < des[i].num; k++)
                    {
                        if (Rows[j][FromWindowLeft] == '#')
                        {
                            FromWindowLeft = 0;
                            break;
                        }
                        else
                        {
                            FromWindowLeft++;
                        }
                        if (k + 1 == des[i].num)
                        {
                            FromWindowLeft = 0;
                            for (int r = 0; r < des[i].num; r++)
                            {
                                Rows[j][FromWindowLeft] = 'X';
                                result += ' ' + to_string(j + 1) + letter[FromWindowLeft];
                                FromWindowLeft++;
                            }
                            /*for (int r = 0; r < des[i].num; r++)
                            {

                            }*/
                            cout << "Passengers can take seats:" << result << endl;
                            result = "";
                            for (int nt = 0; nt < Count_Rows; nt++) cout << Rows[nt] << endl;
                            for (int nt = 0; nt < 7; nt++) if (Rows[j][nt] == 'X') Rows[j][nt] = '#';
                            des[i].used = 1;
                            /*cout << endl;
                            for (int nt = 0; nt < Count_Rows; nt++) cout << Rows[nt] << endl;*/
                        }
                    }
                }
                if (des[i].used == 1)
                {
                    break;
                }                
            }
        }
        // Правая сторона
        if (des[i].side == "right")
        {
            for (int j = 0; j < Count_Rows; j++)
            {
                int FromAisleRight = 4, FromWindowRight = 6;
                if (des[i].position == "aisle")
                {
                    for (int k = 0; k < des[i].num; k++)
                    {
                        if (Rows[j][FromAisleRight] == '#')
                        {
                            FromAisleRight = 4;
                            break;
                        }
                        else
                        {
                            FromAisleRight++;
                        }
                        if (k + 1 == des[i].num)
                        {
                            FromAisleRight = 4;
                            for (int r = 0; r < des[i].num; r++)
                            {
                                Rows[j][FromAisleRight] = 'X';
                                result += ' ' + to_string(j + 1) + letter[FromAisleRight];
                                FromAisleRight++;
                            }
                            cout << "Passengers can take seats:" << result  << endl;
                            result = "";
                            for (int nt = 0; nt < Count_Rows; nt++) cout << Rows[nt] << endl;
                            for (int nt = 0; nt < 7; nt++) if (Rows[j][nt] == 'X') Rows[j][nt] = '#';
                            des[i].used = 1;
                            break;
                            /*cout << endl;
                            for (int nt = 0; nt < Count_Rows; nt++) cout << Rows[nt] << endl;*/
                        }
                    }
                }
                else
                {
                    for (int k = 0; k < des[i].num; k++)
                    {
                        if (Rows[j][FromWindowRight] == '#')
                        {
                            FromWindowRight = 6;
                            break;
                        }
                        else
                        {
                            FromWindowRight--;
                        }
                        if (k + 1 == des[i].num)
                        {
                            FromWindowRight = 6;
                            for (int r = 0; r < des[i].num; r++)
                            {
                                Rows[j][FromWindowRight] = 'X';
                                //result += to_string(j + 1) + letter[FromWindowRight] + ' ';
                                FromWindowRight--;
                            }
                            int FromWindowRightTemp = FromWindowRight;
                            
                            for (int nr = 0; nr < des[i].num; nr++)
                            {
                                result += ' ' + to_string(j + 1) + letter[FromWindowRight+1];
                                FromWindowRight++;
                            }

                            /*for (int r = 0; r < des[i].num; r++)
                            {

                            }*/
                            cout << "Passengers can take seats:" << result  << endl;
                            result = "";
                            for (int nt = 0; nt < Count_Rows; nt++) cout << Rows[nt] << endl;
                                
                            for (int nt = 0; nt < 7; nt++) if (Rows[j][nt] == 'X') Rows[j][nt] = '#';
                            des[i].used = 1;
                            /*cout << endl;
                            for (int nt = 0; nt < Count_Rows; nt++) cout << Rows[nt] << endl;*/
                        }
                    }
                }
                if (des[i].used == 1)
                {
                    break;
                }
            }
        }
        if (des[i].used!=1) cout << "Cannot fulfill passengers requirements" << endl;
    }
	

	return 0;
}

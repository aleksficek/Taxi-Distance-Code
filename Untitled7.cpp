// Taxi Code
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream fin ("taxi.txt");
	cout << fixed << setprecision(2);
	
	if (!fin)
	{
		cout << "No file.";
		return EXIT_FAILURE;
	}
	
	bool returns = 0;
	double distance_c = 0, cost_c = 0, cost_base = 1000000, distance_base = 0;
	int days = 0;
	
	cout << "Trip" << setw(8) << "Return" << setw(8) << "Stops"; 
	cout << setw(12) << "Distance" << setw(8) << "Cost"<< setw(25); 
	cout << "Culminative Distance" << setw(20) << "Culminative Cost" << endl;
	
	while (fin >> returns)
	{
		int stops = 0;
		double distance = 0, distance_previous = 0, cost = 0;
		double x_value = 0, y_value = 0,  x_base = 0, y_base = 0;
		days ++;
			
		if (returns == false)
		{
			fin >> stops;
			for (int tripnum = 1; tripnum <= stops; tripnum++)
			{
				fin >> x_value >> y_value;
				distance = sqrt(pow(x_value,2.0) + pow(y_value,2.0));
				distance_previous += distance;
			}
		}
		
		else if (returns == true)
		{
			fin >> stops;
			for (int tripnum = 1; tripnum <= stops; tripnum++)
			{
				fin >> x_value >> y_value;
				distance = sqrt(pow(x_value,2.0) + pow(y_value,2.0));
				distance_previous += distance;
				
				x_base += x_value;
				y_base += y_value;
			}
			distance_previous += sqrt(pow(x_base,2.0) + pow(y_base,2.0));
		}
		
		cost = (11.0 * stops + 2.7 * distance_previous);
		cost_c += cost;
		distance_c += distance_previous;
		
		if ((days >= 1 && days <=5 ) || (days % 10 == 5))
		{
			cout << setw(3) << days  << setw (6) << returns << setw(9) << stops; 
			cout << setw(12) << distance_previous << setw(11) << cost; 
			cout << setw(16) << distance_c << setw(23) << cost_c << endl;
		}
		
		if(distance_previous > distance_base)
		distance_base = distance_previous;
	
		if (cost < cost_base)
		cost_base = cost;
	}

	cout << "The longest trip was: " << distance_base << " km" << endl;
	cout << "The least expensive trip was: $" << cost_base << endl;

	fin.close();
	return EXIT_SUCCESS;
}

/*

Trip  Return   Stops    Distance    Cost     Culminative Distance    Culminative Cost
1     0        1        10.20       38.54           10.20                  38.54
2     1        2        15.21       63.07           25.41                 101.61
3     0        4        23.81      108.29           49.22                 209.90
4     0        3        17.35       79.85           66.58                 289.76
5     0        5        33.61      145.76          100.19                 435.52
15     0        3        22.77       94.47          408.39                1663.66
25     1        3        24.45       99.03          701.89                2830.10
35     0        1        10.08       38.21          977.21                3903.45
45     0        4        31.34      128.61         1211.38                4832.72
55     0        4        26.85      116.50         1523.18                6004.59
65     0        2        11.72       53.65         1769.24                6954.94
75     1        3        42.12      146.72         2011.43                7883.86
The longest trip was: 70.00 km
The least expensive trip was: $23.44

--------------------------------
Process exited after 0.1371 seconds with return value 0
Press any key to continue . . .

*/


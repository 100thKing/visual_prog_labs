#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


class Some_object
{

protected:
public:
	int pos_x;
	int pos_y;

	double way = 0;
	Some_object(int x, int y)
	{
		pos_x = x;
		pos_y = y;
	}


	void output(int x, int y)
	{
		cout << "\t" << "x: " << pos_x << endl;
		cout << "\t" << "y: " << pos_y << endl;
		cout << "\t" << "way: " << way << endl;
	//	cout << "\t" << "diff: " << sqrt(x * x + y * y) << endl;
		cout << "\t" << endl << endl;
	}
	void random_walk()
	{
		int diff_x = rand() % 3 - 1;
		pos_x += diff_x;
		int diff_y = rand() % 3 - 1;
		pos_y += diff_y;
		if ((pos_x < 0) || (pos_y < 0))
		{
			random_walk();
		}
		way += (sqrt(diff_x * diff_x + diff_y * diff_y));
		output(diff_x, diff_y);
		
		
	}

	void Random_Waypoint()
	{
		int new_x = rand() % 1000;
		int new_y = rand() % 1000;

		int diff_x = pos_x - new_x;
		int diff_y = pos_y - new_y;

		int speed_x = rand() % 5;

		int step_count = diff_x / speed_x;
		if (diff_x % speed_x != 0)
		{
			step_count++;
		}

		int speed_y = diff_y / step_count;
	}

};

double get_distance(Some_object a, Some_object b)
{
	double distance;
	int x = abs(a.pos_x - b.pos_x);
	int y = abs(a.pos_y - b.pos_y);
	distance = sqrt(x * x + y * y);

	return distance;
}


void menu()
{
	int choice;
	cout << endl << endl;
	cout << "Enter the method of moving:" << endl;
	cout << "1. Random Walk" << endl;
	cout << "2. Random Waypoint" << endl;
	cout << "3. Gaussian-Markov" << endl;
	cout << "4. Markov Chains" << endl;
	cout << "5. Get distance between 2 object" << endl;
	cout << "6. Show placement of objects" << endl;
	cout << "0. Exit" << endl << endl;
}

void functions(Some_object x, int choice, Some_object first, Some_object second)
{
	int count;
	switch (choice)
	{
	case 1:
		cout << "Enter the number of repetitions: ";
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			x.random_walk();
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		cout << endl << endl << "Distance: " << get_distance(first, second) << endl;
		break;
	case 6:
		cout << "First object: " << endl;
		first.output(first.pos_x, first.pos_y);
		cout << endl;
		cout << "Second object: " << endl;
		second.output(second.pos_x, second.pos_y);
		cout << endl;
		break;
	case 0:
		break;
	default:
		system("cls");
		cout << "invalid value entered, try again";
		menu();
	}
}

int main()
{
	srand(time(NULL));
	int k = rand() % 1000;
	int l = rand() % 1000;
	int count;
	int choice;
	int choice_obj;
	Some_object	first = Some_object(k,l);

	k = rand() % 1000;
	l = rand() % 1000;
	Some_object second = Some_object(k, l);

	setlocale(LC_ALL, "en");
	while (1)
	{
		cout << "Choice first or second object by number: ";
		cin >> choice_obj;
		cout << endl;

		switch (choice_obj)
		{
		case 1:

			menu();
			cout << "Your choice: ";
			cin >> choice;
			cout << endl;
			functions(first, choice, first, second);
			break;
		case 2:
			menu();
			cout << "Your choice: ";
			cin >> choice;
			cout << endl;
			functions(second, choice, first, second);
			break;
		default:
			system("cls");
			cout << "invalid value entered, try again";
			menu();
		}
	}
}

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	struct NOTE
	{
		char name[30];
		char tel[15];
		char data[3];
	};

	int n = 3;
	NOTE *mas = new NOTE[n];

	for (int i = 0; i<n; i++)
	{
		cout << "Имя: ";
		cin >>  mas[i].name;

		cout << "Телефон: ";
		cin >> mas[i].tel;

		cout << "Месяц рождения : ";
		cin >> mas[i].data;
			
		cout << endl;
	}

	NOTE temp;
	for (int i = 0; i < 3 - 1; i++)
	{
		for (int j = 0; j < 3 - i - 1; j++)
		{
			if (mas[j].name[0] > mas[j + 1].name[0])
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}

	char data_ [3];
	cout << "Введите месяц рождения \n";
	cin >> data_;
	for (int i = 0; i<8; i++)
	 {
		if ( strcmp(mas[i].data, data_) == 0 )
		  {
		      cout << "Информация о человеке, который родился в этот месяц \n";
		      cout << " Имя : " << mas[i].name << endl << "Телфон: " << mas[i].tel << endl;
		  }
 	 }



	return 0;
}

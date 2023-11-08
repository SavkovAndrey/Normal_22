#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
//---------------------Функции и Прототипы---------------------------------------

class matrix
{
private:
public:
	int row;
	int column;
	int value;
	int n_row = 0, n_column = 0;

	matrix(int i, int j, bool x)      // конструктор для создания ( вручную или автоматом)
	{
		
		row = i;
		column = j;
		if (x)
		{
			cout << "Введите значение:";
			cin >> value;
		}
		else
		{
			int temp = rand() % 10;
			if (temp < 3)
			{
			value = temp;
			}
			else
			{
				value = 0;
			}
			
			
		}
	}

	matrix(matrix a, matrix b)         // перегрузка конструктора для сложения
	{
		value = a.value + b.value;
		row = a.row;
		column = a.column;
	}

	matrix()                           // перегрузка конструктора для умножения
	{

	}
	
};

void Enter(vector<matrix>&element)
{
	int n_row, n_column;
	bool x;
	cout << "Введите размерность матрицы: \n";
	cout << "число строк: ";
	cin >> n_row;
	cout << "Число столбцов: ";
	cin >> n_column;

	cout << "Выберите способ заполнения (1 - вручную, 0 - автоматически)";
	cin >> x;



	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_column; j++)
		{
			element.push_back(matrix(i, j, x));
		}
	}
	element[0].n_row = n_row;
	element[0].n_column = n_column;
}




void Print(vector<matrix> element, string str)
{
	int n_row, n_column, k = 0;
	n_row = element[k].n_row;
	n_column = element[k].n_column;

	cout << endl;
	cout << str << endl;

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_column; j++)
		{
			if (element[k].value != 0)
			{
				cout << element[k].value;
			}
			else
			{
				cout << "0";
			}
			cout << "\t";
			k++;
		}
		cout << "\n";
	}
}

void Print_R(vector<matrix>element, string str)
{
	cout << endl << str << endl;
	cout << "\nrow\tcolumn\tvalue\n";
	for (int i = 0; i < element.size(); i++)
	{
		if (element[i].value != 0)
		{
			cout << element[i].row << "\t" << element[i].column << "\t" << element[i].value << endl;
		}
	}
}

void Sum(vector<matrix>a, vector<matrix>b, vector<matrix> &result)
{

	if (a[0].n_row == b[0].n_row && a[0].n_column == b[0].n_column)
	{
		

		for (int i = 0; i < a.size(); i++)
		{
			result.push_back(matrix(a[i], b[i]));
		}
		result[0].n_row = a[0].n_row;
		result[0].n_column = a[0].n_column;
	}
	else
	{
		cout << "\nERROR ADDITION!!\n";
	}

}

void Multiplication(vector<matrix>a, vector<matrix>b, vector<matrix>& result)
{

	if (a[0].n_column == b[0].n_row)
	{
		int row_a = a[0].n_row;
		int column_a = a[0].n_column;
		int row_b = b[0].n_row;
		int column_b = b[0].n_column;
		int z = 0;


		for (int i = 0; i < row_a; i++)
		{
			for (int k = 0; k < column_b; k++)
			{

		        result.push_back(matrix());
				result[z].row = i;
				result[z].column = k;
				
				
				for (int j = 0; j < column_a; j++)        // одинаковый итератор
				{
					result[z].value += a[i * column_a + j].value * b[column_b * j + k].value;
				}
				z++;
			}
		}





		result[0].n_row = a[0].n_row;
		result[0].n_column = b[0].n_column;
	}
	else
	{
		cout << "\nERROR MULTIPLICATION!!\n";
	}
}

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------САМА ПРОГА-------------------------------------
	
	int choice = 1;
	vector<matrix> element;
	vector<matrix> element_a;
	vector<matrix> element_b;



	while (choice != 0)
	{

		cout << "Menu:\n";
		cout << "1 - Enter the matrixs A\n";
		cout << "2 - Enter the matrixs B\n";
		cout << "3 - Print the matrixs\n";
		cout << "4 - Printing a discharged matrixs\n";
		cout << "5 - Sum the matrixs\n";
		cout << "6 - Multiplication the matrixs\n";
		cout << "0 - Exit\n";
		cout << "Make a choice:  ";
		cin >> choice;


		switch (choice)
		{
		case 1:
		{
			element_a.clear();
	        Enter(element_a);         // ввод вручную ( или автомат )

		}
		    break;
		case 2:
		{
			element_b.clear();
			Enter(element_b);
		}
		    break;
		case 3:
		{
			Print(element_a, "Print A:");
			Print(element_b, "Print B:");
	        Print(element, "Print RESULT:");         // печать в стандартном виде
		}
		    break;
		case 4:
		{
			Print_R(element_a, "Print A:");
			Print_R(element_b, "Print B:");
	        Print_R(element, "Print RESULT:");       // печать в разряженном виде
		}
		break;
		case 5:
		{
			element.clear();
			Sum(element_a, element_b, element);      // сумма elem = a + b
		}
		break;
		case 6:
		{
			element.clear();
			Multiplication(element_a, element_b, element);
		}
		break;
		case 0:
		{
			cout << "\nExiting the program\n";
		}
		break;

		default:
			cout << "Error!!\n";
			break;
		}
	}





	system("pause");
	return 0;
}

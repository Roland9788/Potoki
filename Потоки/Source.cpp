#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>

////Максимальная длина пути к файлу
//#define MAX_PATH 260
////Количество столбцов на экране
//#define NUM_COLS 18
////Количество строк на экране
//#define NUM_ROWS 24



using namespace std;

void main()
{

	char Answer;
	const int MessageCount = 8;
	int i, j;
	//Подсказки
	enum { CHOICE = 3, INPUT_FILENAME, INPUT_DIMENSIONS, INPUT_ELEMENT, FILE_ERROR };
	//Сообщение 
	char Msg[MessageCount][50] =
	{
		"1. Вывести данные из текстового файла\n",
		"2. Записать данные в текстовый файл\n",
		"3. Выход из программы\n",
		"\n Ваш выбор: ",
		"Введите имя обрабатываемого файла: ",
		"Введите размерность матрицы: ",
		"Введите элементы матрицы: ",
		"Невозможно открыть файл"
	};
	//Руссификация сообщений и вывод меню на экран
	for (i = 0; i < MessageCount; i++)
	{
		CharToOemA(Msg[i], Msg[i]);
	}
	do
	{
		for (int i = 0; i < 4; i++)
		{
			cout << Msg[i];
		}
		cin >> Answer;

	} while (Answer < '1' || Answer>'3');
	if (Answer == '3')
	{
		return;
	}
	//Переменная для имени файла
	char FileName[80];
	//Размерность матрицы
	int M, N;
	int num;
	cout << "\n" << Msg[INPUT_FILENAME];
	cin >> FileName;
	//Если выбран первый пункт меню, то выводим данные из текстового файла экран
	if (Answer == '1')
	{
		//Если файл с указанным именем уже существует выводим сообщение об ошибке
		ifstream inF(FileName, ios::in | ios::_Nocreate);
		if(!inF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//Считываем размерность массива
		inF >> M;
		inF >> N;
		//Считываем элементы массива из файла и выводим их сразу на экран
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				inF >> num;
				cout << setw(6) << num;
			}
			cout << "\n";
		}
		inF.close();
	}

	//Если выбран второй пункт меню, то выводим данные из текстового файла экран
	if (Answer == '2')
	{
		//Открываем файл для записи.
		// Если файла не существует то программа создает его
		ofstream outF(FileName, ios::out);
		if (!outF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//Запрашиваем размерность матрицы и записываем данные в файл
		cout << Msg[INPUT_DIMENSIONS];
		cout << "\nM: ";
		cin >> M;
		cout << "\nN: ";
		cin >> N;

		outF << M << " " << N << "\n";
		cout << Msg[INPUT_ELEMENT];
		//Запрашиваем элементы массива и записываем их в файл
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				cout << "Array[" << i << "]" << "[" << j << "] = ";
				cin >> num;
				outF << num << " ";
			}
			outF << "\n";
		}
		outF.close();
	}


	//char path[MAX_PATH];
	////Запрашиваем путь к файлу
	//cout << "Введите путь к файлу:\n";
	//cin.getline(path, MAX_PATH);
	//int counter = 0, i = 0, j = 0;
	//char text[NUM_COLS];
	////Открытие файла в двоичном режиме
	//ifstream input(path, ios::in | ios::binary);
	//if (!input)
	//{
	//	cout << "Невозможно открыть файл\n";
	//	return;
	//}
	////Режим отображения в верхнем регистре для шестнадцатичного вывода
	//cout.setf(ios::uppercase);
	////Пока не конец файла, читаем из него данные и производим форматированный вывод
	//while (!input.eof())
	//{
	//	//Посимвольное чтение файла
	//	for (i = 0; (i < NUM_COLS && !input.eof()); i++)
	//	{
	//		input.get(text[i]);
	//	}
	//	if (i < NUM_COLS)
	//	{
	//		i--;
	//	}
	//	for (j = 0; j < i; j++)
	//		if ((unsigned)text[i] < 0x10)
	//		{
	//			//Количество символов для отображения числа меньше двух?
	//			cout << setw(2) << 0 << hex << (unsigned)text[j];
	//		}
	//		else
	//		{
	//			cout << setw(3) << 0 << hex << (unsigned)text[j];
	//		}
	//	//Выравнивание для не завершенной строки
	//	for (; j < NUM_COLS; j++)
	//	{
	//		cout << "    ";
	//	}
	//	cout << " ";
	//	for (j = 0; j < i; j++)
	//		//символ не является управляющим?
	//		if (text[j] > 31 && text[j] <= 255)
	//		{
	//			cout << text[j];
	//		}
	//		else
	//		{
	//			cout << " ";
	//		}
	//		cout << "\n";
	//	//Если экран уже заполнен производим остановку
	//		if (++counter == NUM_COLS)
	//		{
	//			counter = 0;
	//			cout << "Нажмите любую кнопку что бы закончить \n";
	//			//Ожидаем нажатия любой кнопки
	//			_getch();
	//			cout << "\n";
	//		}
	//}
	////Закрываем файл
	//input.close();
	
	//fstream()-создаёт поток, не открывая файла
	//fstream(const char* name имя файла
	//int omode режим открытия файла
	//int= fikebuf::openport защита файла
	//)-создаёт поток, открывает файл и связывает его с потоком
	//fstream(int f дескриптор файла)-создаёт поток и связывает его с уже открытым файлом
	//fstream(int f дескриптор файла char* buf буфер int len размер буфер)-тоже что предыдущий конструктор но по пот оку назначенается буфер
	// enum_Openmode(in =  0x01-открыть только для чтения out=0x02,-открыть для записи, ate=0x04-установить указатель на конец файла, app=0x08-дописать данныйе в конец файла,trunc=0x10-усечь файл до нулевой длины,_Nocreate =0x40-если файл не существует,ошибка открытия,_Noreplace=0x80-если файл уже существует,ошибка открытия, binary=0x20-отрыть файл для двоичного обмена)
	//void open(const char* fileName,int mode=значение по умолчанию,int protection=значение по умолчению);
	//istream&amp; istream::read(unsigned char* buf, int len);
	//istream&amp; istream::read(signed char* buf, int len);
	//ostream&amp;
	//ostream::write(const usigned char* buf, int n);
	//ostream&amp;
	//ostream::write(const signed char* buf, int n);
	// int istream::get();
	//istream& istream::get(unsigned char&);-извлечение из потока
	//istream& istream::get(signed char&);
	//ostream& ostream::put(char);- добавление в поток
	//istream& istream::get(unsingned char* buf,int n,char c='\n');-извлечение элемента до определенного момента
	//istream& istream::get(singned char* buf,int n,char c='\n');
	//istream& istream::getline(unsigned char* buf,int n,char c='\n')-тоже что и гет но ограничитель вытаскивается с потоком 
	//istream& istream::getline(signed char* buf,int n,char c='\n') 
	//istream& istream::ignore(int n=1,int d=EOF);-извлекает до ограничителя
	//int istream::gcount();-возвращает кол-во символов из последного форматного ввода
	//int istream::peek();-Просмотр следющего символа в потоке
	//istream& istream::putback(char cc);-Помещает символ в поток (и становится текущим)и первым для извлечения
	//istream& istream::seekg(long pos);-Устанавливает позицию потока для ввода
	//istream& istream::seekg(long off,ios::seek_dir dir)enum seek_dir{beg,cur,end};-Перемещение позиции чтения в доль потока
	//ostream& ostream::seekp(long pos);-Устанавливает обсалютную позицию записи потока
	//osteam& ostream::seekp(long off,ios::seek_dir dir)-Перемещение обсалютной позиции чтения в доль потока
	//long istream::tellg()-Определяет текущую позицию в потоке
	//long ostream::tellp()-Устанавливает позицию чтения потока
	






}

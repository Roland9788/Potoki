#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>

////������������ ����� ���� � �����
//#define MAX_PATH 260
////���������� �������� �� ������
//#define NUM_COLS 18
////���������� ����� �� ������
//#define NUM_ROWS 24



using namespace std;

void main()
{

	char Answer;
	const int MessageCount = 8;
	int i, j;
	//���������
	enum { CHOICE = 3, INPUT_FILENAME, INPUT_DIMENSIONS, INPUT_ELEMENT, FILE_ERROR };
	//��������� 
	char Msg[MessageCount][50] =
	{
		"1. ������� ������ �� ���������� �����\n",
		"2. �������� ������ � ��������� ����\n",
		"3. ����� �� ���������\n",
		"\n ��� �����: ",
		"������� ��� ��������������� �����: ",
		"������� ����������� �������: ",
		"������� �������� �������: ",
		"���������� ������� ����"
	};
	//������������ ��������� � ����� ���� �� �����
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
	//���������� ��� ����� �����
	char FileName[80];
	//����������� �������
	int M, N;
	int num;
	cout << "\n" << Msg[INPUT_FILENAME];
	cin >> FileName;
	//���� ������ ������ ����� ����, �� ������� ������ �� ���������� ����� �����
	if (Answer == '1')
	{
		//���� ���� � ��������� ������ ��� ���������� ������� ��������� �� ������
		ifstream inF(FileName, ios::in | ios::_Nocreate);
		if(!inF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//��������� ����������� �������
		inF >> M;
		inF >> N;
		//��������� �������� ������� �� ����� � ������� �� ����� �� �����
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

	//���� ������ ������ ����� ����, �� ������� ������ �� ���������� ����� �����
	if (Answer == '2')
	{
		//��������� ���� ��� ������.
		// ���� ����� �� ���������� �� ��������� ������� ���
		ofstream outF(FileName, ios::out);
		if (!outF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//����������� ����������� ������� � ���������� ������ � ����
		cout << Msg[INPUT_DIMENSIONS];
		cout << "\nM: ";
		cin >> M;
		cout << "\nN: ";
		cin >> N;

		outF << M << " " << N << "\n";
		cout << Msg[INPUT_ELEMENT];
		//����������� �������� ������� � ���������� �� � ����
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
	////����������� ���� � �����
	//cout << "������� ���� � �����:\n";
	//cin.getline(path, MAX_PATH);
	//int counter = 0, i = 0, j = 0;
	//char text[NUM_COLS];
	////�������� ����� � �������� ������
	//ifstream input(path, ios::in | ios::binary);
	//if (!input)
	//{
	//	cout << "���������� ������� ����\n";
	//	return;
	//}
	////����� ����������� � ������� �������� ��� ���������������� ������
	//cout.setf(ios::uppercase);
	////���� �� ����� �����, ������ �� ���� ������ � ���������� ��������������� �����
	//while (!input.eof())
	//{
	//	//������������ ������ �����
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
	//			//���������� �������� ��� ����������� ����� ������ ����?
	//			cout << setw(2) << 0 << hex << (unsigned)text[j];
	//		}
	//		else
	//		{
	//			cout << setw(3) << 0 << hex << (unsigned)text[j];
	//		}
	//	//������������ ��� �� ����������� ������
	//	for (; j < NUM_COLS; j++)
	//	{
	//		cout << "    ";
	//	}
	//	cout << " ";
	//	for (j = 0; j < i; j++)
	//		//������ �� �������� �����������?
	//		if (text[j] > 31 && text[j] <= 255)
	//		{
	//			cout << text[j];
	//		}
	//		else
	//		{
	//			cout << " ";
	//		}
	//		cout << "\n";
	//	//���� ����� ��� �������� ���������� ���������
	//		if (++counter == NUM_COLS)
	//		{
	//			counter = 0;
	//			cout << "������� ����� ������ ��� �� ��������� \n";
	//			//������� ������� ����� ������
	//			_getch();
	//			cout << "\n";
	//		}
	//}
	////��������� ����
	//input.close();
	
	//fstream()-������ �����, �� �������� �����
	//fstream(const char* name ��� �����
	//int omode ����� �������� �����
	//int= fikebuf::openport ������ �����
	//)-������ �����, ��������� ���� � ��������� ��� � �������
	//fstream(int f ���������� �����)-������ ����� � ��������� ��� � ��� �������� ������
	//fstream(int f ���������� ����� char* buf ����� int len ������ �����)-���� ��� ���������� ����������� �� �� ��� ��� ������������� �����
	// enum_Openmode(in =  0x01-������� ������ ��� ������ out=0x02,-������� ��� ������, ate=0x04-���������� ��������� �� ����� �����, app=0x08-�������� ������� � ����� �����,trunc=0x10-����� ���� �� ������� �����,_Nocreate =0x40-���� ���� �� ����������,������ ��������,_Noreplace=0x80-���� ���� ��� ����������,������ ��������, binary=0x20-������ ���� ��� ��������� ������)
	//void open(const char* fileName,int mode=�������� �� ���������,int protection=�������� �� ���������);
	//istream&amp; istream::read(unsigned char* buf, int len);
	//istream&amp; istream::read(signed char* buf, int len);
	//ostream&amp;
	//ostream::write(const usigned char* buf, int n);
	//ostream&amp;
	//ostream::write(const signed char* buf, int n);
	// int istream::get();
	//istream& istream::get(unsigned char&);-���������� �� ������
	//istream& istream::get(signed char&);
	//ostream& ostream::put(char);- ���������� � �����
	//istream& istream::get(unsingned char* buf,int n,char c='\n');-���������� �������� �� ������������� �������
	//istream& istream::get(singned char* buf,int n,char c='\n');
	//istream& istream::getline(unsigned char* buf,int n,char c='\n')-���� ��� � ��� �� ������������ ������������� � ������� 
	//istream& istream::getline(signed char* buf,int n,char c='\n') 
	//istream& istream::ignore(int n=1,int d=EOF);-��������� �� ������������
	//int istream::gcount();-���������� ���-�� �������� �� ���������� ���������� �����
	//int istream::peek();-�������� ��������� ������� � ������
	//istream& istream::putback(char cc);-�������� ������ � ����� (� ���������� �������)� ������ ��� ����������
	//istream& istream::seekg(long pos);-������������� ������� ������ ��� �����
	//istream& istream::seekg(long off,ios::seek_dir dir)enum seek_dir{beg,cur,end};-����������� ������� ������ � ���� ������
	//ostream& ostream::seekp(long pos);-������������� ���������� ������� ������ ������
	//osteam& ostream::seekp(long off,ios::seek_dir dir)-����������� ���������� ������� ������ � ���� ������
	//long istream::tellg()-���������� ������� ������� � ������
	//long ostream::tellp()-������������� ������� ������ ������
	






}

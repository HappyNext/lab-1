#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstring>

using namespace std;

const int maxlen = 255;

#pragma pack(push, 1)
struct students
{
    char surname[maxlen];
    int groupnumber;
    char adress[maxlen];
    int phonenumber;
};
#pragma pack(pop)

students arr[maxlen];

int students_index = 0;

int menu();
void readFromFile(const char* fileName);
void saveToFile(const char* fileName);
void addNew();
void del();
void change();
void sortirovka();

int main()
{
    setlocale(LC_ALL,"Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    for(;;)
    {
        switch(menu())
        {
        case 1:
            readFromFile("file.dat");
            break;
        case 2:
            saveToFile("file.dat");
            break;
        case 3:
            addNew();
            break;
        case 4:
            del();
            break;
        case 5:
            change();
            break;
        case 6:
            sortirovka();
            break;
        case 7:
            return 0;
        default:
            cout << "������������ �����" << endl;
        }
    }
}

int menu()
{
    cout << "\n";
    int ans;
    cout << "��������\n";
    cout << "1-��� ����������� � �����\n";
    cout << "2-��� ������ � ����\n";
    cout << "3-��� ���������� ������\n";
    cout << "4-��� �������� ������\n";
    cout << "5-��� ��������� ������\n";
    cout << "6-��� ���������� �������\n";
    cout << "7-��� ������ �� ���������\n";
    cout << "\n";
    cout << "��� �����:  ";
    cin >> ans;
    return ans;
}
void saveToFile(const char* fileName) //�������, �� ������ ��� � ������� ����
{
    ofstream f;
    f.open(fileName, ios::binary);
    f.write((char*)arr, sizeof(students) * students_index);
    f.close();
    cout << "�������� ������ ��������� � ����\n";
}
void readFromFile(const char* fileName) //�������, �� ����� ��� � �������� �����
{
    ifstream f;
    f.open(fileName, ios::binary);
    if (!f) {
        cout << "����� �� ����������";
    }
    else {
        students student;
        students_index = 0;
        while (1) {
            f.read((char*)&student, sizeof(student));
            if (f.eof())
                break;
            arr[students_index] = student;
            students_index++;
        }
        f.close();
        cout << "������ ������� � �����\n";
        for (int i = 0; i < students_index; i++) {
            cout << i + 1 << "\t" << arr[i].surname << "\t" << arr[i].groupnumber << "\t" << arr[i].adress << "\t" << arr[i].phonenumber << endl;
        }
    }
}
void addNew()//�������, �� ����(�������) ����� �����
{
    cout << "���������� ����� ������\n\n";
    cout << "������ ����� " << students_index + 1 << "\n";
    cin.ignore();
    cout << "������� �������  ";
    cin.getline(arr[students_index].surname, maxlen);
    cout << "������� ����� ������  ";
    cin >> arr[students_index].groupnumber;
    cin.ignore();
    cout << "������� ������  ";
    cin.getline(arr[students_index].adress, maxlen);
    cout << "������� ����� �������� ";
    cin >> arr[students_index].phonenumber;
    students_index++;
    cout << "\n";
    for (int i = 0; i < students_index; i++)
    {
        cout << i + 1 << "\t" << arr[i].surname << "\t" << arr[i].groupnumber << "\t" << arr[i].adress << "\t" << arr[i].phonenumber << endl;
    }
    cout << "\n";
}

void del()//�������, �� ������� �����
{
    int d;
    cout << "�������� ����� ������, ������� ����� ������� ";
    cin >> d;
    for (int i = d - 1; i < students_index; i++)
       { arr[i] = arr[i + 1];}
    students_index--;

    cout << "\n";
    for (int i = 0; i < students_index; i++)
    {
        cout << i + 1 << "\t" << arr[i].surname << "\t" << arr[i].groupnumber << "\t" << arr[i].adress << "\t" << arr[i].phonenumber << endl;
    }
    cout << "\n";
}

void change()
{
    int g;
    cout << "�������� ����� ������, ������� ����� �������� ";
    cin >> g;
    cout << "������� ����� �������  ";
    cin.ignore();
    cin.getline(arr[g-1].surname, maxlen);
    cout << "������� ����� ����� ������  ";
    cin >> arr[g-1].groupnumber;
    cout << "������� ����� ������  ";
    cin.ignore();
    cin.getline(arr[g-1].adress, maxlen);
    cout << "������� ����� ����� �������� ";
    cin >> arr[g-1].phonenumber;
    cout << "\n";


    for (int i = 0; i < students_index; i++)
    {
        cout << i + 1 << "\t" << arr[i].surname << "\t" << arr[i].groupnumber << "\t" << arr[i].adress << "\t" << arr[i].phonenumber << endl;
    }
    cout << "\n";
}

void sortirovka()
{
    int i, j, i1;
    for (i = 0; i < students_index; i++)
    {
        i1 = i;
        for (j = i+1; j < students_index; j++)
        if (arr[j].surname[0] < arr[i1].surname[0]){
            i1 = j;
        }
        students temp = arr[i1];
        arr[i1] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < students_index; i++)
    {
        cout << i + 1 << "\t" << arr[i].surname << "\t" << arr[i].groupnumber << "\t" << arr[i].adress << "\t" << arr[i].phonenumber << endl;
    }
    cout << "\n";
}

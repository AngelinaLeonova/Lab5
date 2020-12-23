// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <regex>
#include <string>
using namespace std;
class Admin
{
public:
    virtual int getKolstr() = 0;
    virtual string getDirector() = 0;
    virtual string getNazvanie() = 0;

    virtual void setKolstr(int) = 0;
    virtual void setDirector(string) = 0;
    virtual void setNazvanie(string) = 0;

    virtual string Print() = 0;
    ~Admin() {}
};

class Bizness : public Admin
{
private:
    int kolstr;
    string direc;
    string naz;
public:
    Bizness(int c = 0, string n = "", string a = "")
    {
        this->kolstr = c;
        this->direc = n;
        this->naz = a;
    }
    
   


    void setDirector(string temDirector)override
    {
        this->direc = temDirector;
    }

    void setNazvanie(string tempnaz)override
    {
        this->naz = tempnaz;
    }

    void setKolstr(int nKol)override
    {
        this->kolstr = nKol;
    }

    int getKolstr()override//методы класса
    {
        return kolstr;
    }

    string getDirector()override //указ что ф-ция должна переопределять виртуальную
    {
        return direc;
    }

    string getNazvanie()override
    {
        return naz;
    }

    string Print()override
    {
        return "\tБизнесс-администрирование: \n Руководитель: " + getDirector() +
            "\n Наименование отдела: " + getNazvanie() +
            "\n Количество сотрудников: " + to_string(getKolstr());
    }

    ~Bizness() {}
};

class Komp : public Admin
{
private:
    int kolstr;
    string direc;
    string naz;
public:
    Komp (int c = 0, string n = "", string a = "") : kolstr(c), direc(n), naz(a) //Конструктор класса принимающий аргументы
    {}

    void setKolstr(int nKol)override
    {
        this->kolstr = nKol;
    }

    void setDirector(string tempDirector)override
    {
        this->direc = tempDirector;
    }

    void setNazvanie(string tempnaz)override
    {
        this->naz = tempnaz;
    }

    int getKolstr()override
    {
        return kolstr;
    }
    string getDirector()override
    {
        return direc;
    }
    string getNazvanie()override
    {
        return naz;
    }

    string Print()override
    {
        return "\tАдминистрирование компьютеров: \n Руководитель: " + getDirector() +
            "\n Наименование отдела: " + getNazvanie() +
            "\n Количество сотрудников: " + to_string(getKolstr());
    }
    ~Komp() {}
};

class Site : public Admin
{
private:
    int kolstr;
    string direc;
    string naz;
public:
    Site(int c = 0, string n = "", string a = "") : kolstr(c), direc(n), naz(a) //Конструктор класса принимающий аргументы
    {}

    void setKolstr(int nKol)override
    {
        this->kolstr = nKol;
    }

    void setDirector(string tempDirector)override
    {
        this->direc = tempDirector;
    }

    void setNazvanie(string tempnaz)override
    {
        this->naz = tempnaz;
    }

    int getKolstr()override
    {
        return kolstr;
    }
    string getDirector()override
    {
        return direc;
    }
    string getNazvanie()override
    {
        return naz;
    }

    string Print()override
    {
        return "\tАдминистрирование сайта: \n Руководитель: " + getDirector() +
            "\n Наименование отдела: " + getNazvanie() +
            "\n Количество сотрудников: " + to_string(getKolstr());
    }
    ~Site() {}
};

int isIntTru()
{
    regex integers(R"(\d+)"); 
    char input[80];
    do
    {
        memset(input, 0, 80); //выделяем под массив память
        cin >> input;//вводит строку
        if (regex_match(input, input + strlen(input), integers))//проверяем условие содержит ли строка только цифры
        {
            return atoi(input);//если только цифры - возвращаем их, преобразовывая из char в int
        }
        else
        {
            cout << "Ошибка! Введите число!";
        }
    } while (1);//Бесконечный цикл, пока не будет число
}

int main()
{
    system("chcp 1251");
    system("cls");
    string a, b;
    int c = 0;
    Admin* admin[3];

    cout << "Бизнесс-администрирование" << endl;
    cout << "Введите руководителя отдела:" << endl;
    getline(cin, a);
    cout << "Введите название отдела:" << endl;
    getline(cin, b);
    cout << "Введите количество сотрудников:" << endl;
    c = isIntTru();
    Bizness n;

    n.setDirector(a);
    n.setNazvanie(b);
    n.setKolstr(c);
    admin[0] = &n;

    cout << "Компьютерное администрирование" << endl;
    cout << "Введите руководителя отдела:" << endl;
    std::cin.ignore(32767, '\n');
    getline(cin, a);
    cout << "Введите название отдела:" << endl;
    getline(cin, b);
    cout << "Введите количество сотрудников:" << endl;
    c = isIntTru();
    Komp k;
    k.setDirector(a);
    k.setNazvanie(b);
    k.setKolstr(c);
    admin[1] = &k;

    cout << "Администрирование сайта" << endl;
    cout << "Введите руководителя отдела:" << endl;
    std::cin.ignore(32767, '\n');
    getline(cin, a);
    cout << "Введите название отдела:" << endl;
    getline(cin, b);
    cout << "Введите количество сотрудников:" << endl;
    c = isIntTru();
    Site s(c, a, b);
    admin[2] = &s;

    for (int i = 0; i < 3; i++)
    {
        cout << admin[i]->Print() << endl;
    }
    return 0;

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

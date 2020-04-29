// Overloading.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <vector>
#include "windows.h"
#include <time.h>
using namespace std;
class Data
{
protected:
    vector<string> commands = { "Dynamo","Liverpool","Barcelona","Levante"};
    struct Result
    {
        int win;
        int defeat;
        int draw;
    };
    Result res[10];
    Data()
    {
        for (int i = 0; i < commands.size(); i++)
        {
            res[i].win = 0;
            res[i].defeat = 0;
            res[i].draw = 0;
        }
    }
    void add()
    {
        string name;
        cout << "Назва команди: ";
        cin >> name;
        commands.push_back(name);
        res[commands.size() - 1].win = 0;
        res[commands.size() - 1].defeat = 0;
        res[commands.size() - 1].draw = 0;
    }
    void show_commands()
    {
        for (int i = 0; i < commands.size(); i++)
        {
            cout << i << ". " << commands[i] << endl;
        }
    }
    void get_result()
    {
        cout << endl;
        for (int i = 0; i < commands.size(); i++)
        {
            cout << "--- " << commands[i] << " ---" << endl;
            cout << endl;
            cout <<"Перемог: "<<res[i].win << endl;
            cout <<"Поразок: "<<res[i].defeat << endl;
            cout <<"Нічиї:   "<<res[i].draw << endl;
            cout << endl;
        }
    }
    void help() 
    {
        cout << "   add   --- додати команду" << endl;
        cout << "   match --- розпочати гру" << endl;
        cout << "   table --- турнірна таблиця" << endl;
        cout << "   commands --- список футбольних команд" << endl;
    }
};
class Second;
class First
{
    friend ostream& operator<<(ostream& os, const First& f);
    friend bool operator > (const First&, const Second&);
    friend bool operator == (const First&, const Second&);
private:
    int i;
public:
    First()
    {
        i = 0;
    }
    First& operator ++ (int)
    {
        i++;
        return *this;
    }
    First& operator = (int)
    {
        i = 0;
        return *this;
    }
    void disp()
    {
        cout << "f= " << i << endl;
    }
};
class Second
{
    friend ostream& operator<<(ostream& os, const Second& s);
    friend bool operator > (const First&, const Second&);
    friend bool operator == (const First&, const Second&);
private:
    int i;
public:
    Second()
    {
        i = 0;
    }
    Second& operator ++ (int)
    {
        i++;
        return *this;
    }
    Second& operator = (int)
    {
        i = 0;
        return *this;
    }
    void disp()
    {
        cout << "s= " << i << endl;
    }
};
bool operator > (const First& f, const Second& s)
{
    return (f.i > s.i);
};
bool operator == (const First& f, const Second& s)
{
    return (f.i == s.i);
};

ostream& operator<<(ostream& os, const First& f)
{
    os << f.i;
    return os;
};

ostream& operator<<(ostream& os, const Second& s)
{
    os << s.i;
    return os;
};
class Init : public Data
{
public:
    Second s;
    First f;
    void match()
    {
        int first, second, info;
        cout << "Перша команда: ";
        cin >> first;
        cout << "Друга команда: ";
        cin >> second;
        int rand_goal, rand_command;
        rand_goal = (rand() % 6) + 2;
        cout << "START!!!" << endl;
        for (int i = 0; i < rand_goal; i++)
        {
            rand_command = rand() % 2;
            if (rand_command == 0)
            {
                f++;
                cout << commands[first] << " " << f << " : " << s << " " << commands[second] << endl;
                Sleep(1000);
            }
            else
            {
                s++;
                cout << commands[first] << " " << f << " : " << s << " " << commands[second] << endl;
                Sleep(1000);
            }
        }
        if (f > s)
        {
            cout << "Команда " << commands[first] << " перемогла з рахунком: " << f << " : " << s << endl;
            res[first].win++;
            res[second].defeat++;
        }
        else if (f == s)
        {
            res[first].draw++;
            res[second].draw++;
        }
        else
        {
            cout << "Команда " << commands[second] << " перемогла з рахунком: " << s << " : " << f << endl;
            res[second].win++;
            res[first].defeat++;
        }
        f = 0;
        s = 0;
    }
    Init()
    {
        string cmd;
        help();
        while (true)
        {
            cout << "football:>";
            cin >> cmd;
            if (cmd == "match")
            {
                show_commands();
                match();
            }
            if (cmd == "add")
            {
                add();
            }
            if (cmd == "commands")
            {
                show_commands();
            }
            if (cmd == "table")
            {
                get_result();
            }
        }
    }
};
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    cout<< "\tVIRTUAL FOOTBAL" <<endl;
    Init();
    system("pause");
    cout << "---------------" << endl;
    return 0;
}

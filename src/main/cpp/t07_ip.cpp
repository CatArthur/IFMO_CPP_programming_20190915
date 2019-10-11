//В сети интернет каждому компьютеру присваивается четырехбайтовый код, 
// который принято записывать в виде четырех чисел, 
// каждое из которых может принимать значения от 0 до 255, разделенных точками.
// Вот примеры правильных IP-адресов:
//127.0.0.0
//192.168.0.1
//255.0.255.255
//Напишите программу, которая определяет, является ли заданная строка правильным IP-адресом.
//
//Входные данные
//
//Программа получает на вход строку из произвольных символов.
//
//Выходные данные
//
//Если эта строка является корректной записью IP-адреса, выведите YES, иначе выведите NO.
//
//Примечание
//
//Для перевода из строки в число удобно пользоваться функцией stoi,
// которая принимает на вход строку, а возвращает число.
//
//Sample Input:
//
//127.0.0.1
//Sample Output:
//
//YES

#include "t07_ip.h"
#include <iostream>


using namespace std;

int t07_ip() {
    string s;
    cin>>s;
    bool b=1;
    int dot1,dot2,dot3,dot4;
    dot1=s.find('.');
    dot2=s.find('.',dot1+1);
    dot3=s.find('.',dot2+1);
    dot4=s.find('.',dot3+1);
    if(dot3==-1||dot4!=-1)
        b=0;
    else {
        string num1, num2,num3,num4;
        num1=s.substr(0,dot1);
        num2=s.substr(dot1+1,dot2-dot1);
        num3=s.substr(dot2+1,dot3-dot2);
        num4=s.substr(dot3+1);
        int i1,i2,i3,i4;
        i1=int(num1);
        i2=int(num2);
        i3=int(num3);
        i4=int(num4);
        if(i1>255||i2>255||i3>255||i4>255)
            b=0;
    }
    if(b)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
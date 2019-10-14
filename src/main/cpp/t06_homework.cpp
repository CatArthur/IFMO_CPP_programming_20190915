//Учительница задала Пете домашнее задание — в заданном тексте расставить ударения в словах, 
// после чего поручила Васе проверить это домашнее задание. 
// Вася очень плохо знаком с данной темой, поэтому он нашел словарь, 
// в котором указано, как ставятся ударения в словах. 
// К сожалению, в этом словаре присутствуют не все слова. 
// Вася решил, что в словах, которых нет в словаре, он будет считать, 
// что Петя поставил ударения правильно, если в этом слове Петей поставлено ровно одно ударение.
//
//Оказалось, что в некоторых словах ударение может быть поставлено больше, чем одним способом. 
// Вася решил, что в этом случае если то, как Петя поставил ударение, 
// соответствует одному из приведенных в словаре вариантов, 
// он будет засчитывать это как правильную расстановку ударения, 
// а если не соответствует, то как ошибку.
//
//Вам дан словарь, которым пользовался Вася и домашнее задание, сданное Петей. 
// Ваша задача — определить количество ошибок, которое в этом задании насчитает Вася.
//
//Входные данные
//
//Вводится сначала число N — количество слов в словаре (0 ≤ N ≤ 20000).
//
//Далее идет N строк со словами из словаря. Каждое слово состоит не более чем из 30 символов. 
// Все слова состоят из маленьких и заглавных латинских букв. 
// В каждом слове заглавная ровно одна буква — та, на которую попадает ударение. 
// Слова в словаре расположены в алфавитном порядке. 
// Если есть несколько возможностей расстановки ударения в одном и том же слове, 
// то эти варианты в словаре идут в произвольном порядке.
//
//Далее идет упражнение, выполненное Петей. Упражнение представляет собой строку текста, 
// суммарным объемом не более 300000 символов. Строка состоит из слов, 
// которые разделяются между собой ровно одним пробелом. 
// Длина каждого слова не превышает 30 символов. 
// Все слова состоят из маленьких и заглавных латинских букв 
// (заглавными обозначены те буквы, над которыми Петя поставил ударение). 
// Петя мог по ошибке в каком-то слове поставить более одного ударения или не поставить ударения вовсе.
//
//Выходные данные
//
//Выведите количество ошибок в Петином тексте, которые найдет Вася.
//
//Примечание к примеру
//
//
//1. В слове cannot, согласно словарю возможно два варианта расстановки ударения. 
// Эти варианты в словаре могут быть перечислены в любом порядке 
// (т.е. как сначала cAnnot, а потом cannOt, так и наоборот).
//Две ошибки, совершенные Петей — это слова be (ударение вообще не поставлено) 
// и fouNd (ударение поставлено неверно). Слово thE отсутствует в словаре, 
// но поскольку в нем Петя поставил ровно одно ударение, признается верным.
//
//2. Неверно расставлены ударения во всех словах, кроме The (оно отсутствует в словаре,
// в нем поставлено ровно одно ударение). В остальных словах либо ударные все буквы (в слове PAGE),
// либо не поставлено ни одного ударения.
//
//
//Sample Input 1:
//
/*4
cAnnot
cannOt
fOund
pAge
thE pAge cAnnot be fouNd
*/
//Sample Output 1:
//
//2
//
//Sample Input 2:
//
/*4
cAnnot
cannOt
fOund
pAge
The PAGE cannot be found
//Sample Output 2:
*/
//4

#include "t06_homework.h"
#include <iostream>
#include <map>
#include <set>

using namespace std;

int t06_homework() {
    map<string,set<int>> dict;
    string s,sres="";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int c=s.length();
        for(char let:s){
            sres+=tolower(let);
        }
        int j=0;
        for(;j<c;j++) {
            if (s[j] <= 'Z' && s[j] >= 'A')
                break;
        }
        dict[sres].emplace(j);
        sres="";
    }

    int sum=0;
    int lastspace=-1;
    getline(cin,s);
    getline(cin,s);
    s+=" ";
    n=s.size();
    set<int> wordud;
    for(int i=0;i<n;i++){
        if(s[i]==' ') {
            lastspace=i;
            bool b = false;
            if (wordud.size() == 1) {
                if (dict[sres].size() == 0)
                    b = true;
                else {
                    int ind;
                    for (int t:wordud) { ind = t; }
                    for (int t:dict[sres]) {
                        if (t == ind)
                            b = true;
                    }
                }
            }
            if(!b)
                sum++;
            sres="";
            wordud.clear();
        }
        else{
            if(s[i] <= 'Z' && s[i] >= 'A')
                wordud.emplace(i-1-lastspace);
            sres+=tolower(s[i]);
        }
    }
    cout<<sum;
    return 0;
}
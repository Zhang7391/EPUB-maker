#include"BigNumber.h"
#include<iostream>
#include<fstream>

using namespace std;
using namespace MyOddWeb;

ofstream ux("content.txt");

class control
{
private:
    int digits = 0;
    int* table = new int[20];
    bool fake = false, ten = true;
    BigNumber begin, end;

    void NumberConv(BigNumber);
    bool NumberToChinese(int, bool);
    int DigitsConv(bool);

public:
    void UserInput(void);
};

int main()
{
    control user;
    user.UserInput();
    ux.close();
    return 0;
}

void control::UserInput(void)
{
    char space[200];
    cout << "Please enter the beginning chapter: ";
    cin >> space;
    this->begin = space;
    while (this->begin.IsLess(0))
    {
        cout << "Error! Please enter a number greater than 0.\n\nPlease enter the beginning chapter: ";
        cin >> space;
        this->begin = space;
    }
    cout << "Please enter the ending chapter(>= " << this->begin.ToString() << "): ";
    cin >> space;
    this->end = space;
    while (this->begin.IsGreater(this->end))
    {
        cout << "Error! Please enter a number greater " << this->begin.ToString() << ".\n\n";
        cout << "Please enter the beginning chapter(>= " << this->begin.ToString() << "): ";
        cin >> space;
        this->end = space;
    }
    for (int a = 0, b = 1; 20 > a; a++, b += 4) this->table[a] = b;

    if (this->begin.IsEqual(0))
    {
        ux << "      <tr>\n        <td class=\"mbt05 w40 tdtop\"><a class=\"nodeco color1\" href=\"../Text/chapter0.xhtml\">序章</a></td>\n\n        <td class=\"mbt05 left\"><a class=\"nodeco color1\" href=\"../Text/chapter0.xhtml\">(章節標題)</a></td>\n      </tr>\n";
        this->begin = 1;
    }
   for (; this->end.IsGreaterEqual(this->begin); this->begin.Add(1))
   {
       cout << this->begin.ToString() << "\n";
       this->fake = false;
       ux << "      <tr>\n        <td class=\"mbt05 w40 tdtop\"><a class=\"nodeco color1\" href=\"../Text/chapter" << this->begin.ToString() << ".xhtml\">第";
       if (this->begin.Mod(10).ToInt() == 0)
       {
               this->begin.Add(1);
               this->fake = true;
       }
       this->NumberConv(this->begin);
       if (fake) this->begin.Sub(1);
       ux << "章</a></td>\n\n        <td class=\"mbt05 left\"><a class=\"nodeco color1\" href=\"../Text/chapter" << this->begin.ToString() << ".xhtml\">(章節標題)</a></td>\n      </tr>\n";
   }
}

void control::NumberConv(BigNumber now)
{
    int point, check;
    this->digits = 0;
    bool key = true, flag;
    string PointNumber, NextNumber, SecNumber;
    BigNumber reversal = 0;

    while (now.IsUnequal(0))
    {
        reversal.Mul(10);
        reversal.Add(now.Mod(10));
        now.Div(10).Integer();
        this->digits++;
    }
    check = this->digits;

    while (reversal.IsUnequal(0))
    {
        if (this->fake && check == 2)
        {
            reversal = reversal.Mod(10);
            this->ten = false;
        }
        if (this->fake && this->digits == 3)
        {
            reversal = reversal.Mod(100);
            if (reversal.ToInt() == 0) break;
        }
        if (this->fake && this->digits == 4) if (reversal.Mod(1000).ToInt() == 0) break;
        if(check == 2 && reversal.Mod(10).ToInt() == 1 && digits == 2) this->ten = false;

        key = this->NumberToChinese(reversal.Mod(10).ToInt(), key);
        flag = true;

        PointNumber = reversal.ToString();
        point = this->DigitsConv(false);

        if (this->table[point] == this->digits) key = true;
        if (this->digits % 4 == 3 || this->digits % 4 == 0) NextNumber = PointNumber[this->table[point]];
        if (this->digits % 4 == 0) SecNumber = PointNumber[this->table[point] + 1];

        PointNumber = PointNumber[this->table[point] - 1];
        if (this->digits % 4 == 2 && PointNumber == "0")
        {
            this->DigitsConv(key);
            this->digits--;
            this->DigitsConv(key);
            flag = false;
            reversal.Div(100).Integer();
            this->digits--;
        }
        if (this->digits % 4 == 3 && NextNumber == "0" && PointNumber == "0")
        {
            this->DigitsConv(key);
            this->digits -= 2;
            this->DigitsConv(key);
            flag = false;
            reversal.Div(1000).Integer();
            this->digits--;
        }
        if (this->digits % 4 == 0 && NextNumber == "0" && SecNumber == "0" && PointNumber == "0")
        {
            this->digits -= 3;
            if (reversal.Mod(10).ToInt() != 0) ux << "千";
            this->DigitsConv(key);
            flag = false;
            reversal.Div(10000).Integer();
            this->digits--;
        }
        if (flag)
        {
            this->DigitsConv(key);
            reversal.Div(10).Integer();
            this->digits--;
        }
        this->ten = true;
    }
}

bool control::NumberToChinese(int PointNumber, bool key)
{
    switch (PointNumber)
    {
    case 0:
        if (key) ux << "零";
        return false;
    case 1:
        if (this->ten) ux << "一";
        return true;
    case 2:
        ux << "二";
        return true;
    case 3:
        ux << "三";
        return true;
    case 4:
        ux << "四";
        return true;
    case 5:
        ux << "五";
        return true;
    case 6:
        ux << "六";
        return true;
    case 7:
        ux << "七";
        return true;
    case 8:
        ux << "八";
        return true;
    case 9:
        ux << "九";
        return true;
    }
}

int control::DigitsConv(bool ComeIn)
{
    int compare = 0;
    while (this->digits > this->table[compare]) compare++;
    if (this->table[compare] != this->digits) compare--;
    if (!ComeIn) return compare;

    if (this->digits - this->table[compare] == 1) ux << "十";
    else if (this->digits - this->table[compare] == 2) ux << "百";
    else if (this->digits - this->table[compare] == 3) ux << "千";
    if (this->digits % 4 == 1)
    {
        switch (this->table[compare])
        {
        case 5:
            ux << "萬";
            return compare;
        case 9:
            ux << "億";
            return compare;
        case 13:
            ux << "兆";
            return compare;
        case 17:
            ux << "京";
            return compare;
        case 21:
            ux << "垓";
            return compare;
        case 25:
            ux << "秭";
            return compare;
        case 29:
            ux << "穰";
            return compare;
        case 33:
            ux << "溝";
            return compare;
        case 37:
            ux << "澗";
            return compare;
        case 41:
            ux << "正";
            return compare;
        case 45:
            ux << "戴";
            return compare;
        case 49:
            ux << "極";
            return compare;
        case 53:
            ux << "恆河沙";
            return compare;
        case 57:
            ux << "阿僧祇";
            return compare;
        case 61:
            ux << "那由他";
            return compare;
        case 65:
            ux << "不可思議";
            return compare;
        case 69:
            ux << "無量";
            return compare;
        case 73:
            ux << "大數";
            return compare;
        }
    }
}
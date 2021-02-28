#include"BigNumber.h"
#include<iostream>
#include<fstream>

using namespace std;
using namespace MyOddWeb;

int main()
{
    ifstream ui;
    ui.open("chapter.txt");
    ofstream ux;

    char input[200];
    string filename, title;

    cout << "Please enter the beginning chapter: ";
    cin >> input;
    BigNumber number(input);
    while (getline(ui, title))
    {
        filename = "chapter" + number.ToString() + ".xhtml";
        ux.open(filename);

        ux << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"\n  \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">\n\n<html xmlns=\"http://www.w3.org/1999/xhtml\">\n\n<head>\n  <title>chapter";
        ux << number.ToString() << "</title>\n  <link href=\"../Styles/style.css\" rel=\"stylesheet\" type=\"text/css\" />\n</head>\n\n<body>\n  <h1>";
        ux << title << "</h1>\n\n  <p>(This article)</p>\n\n</body>\n</html>";

        number.Add(1);
        ux.close();
    }

    return 0;
}
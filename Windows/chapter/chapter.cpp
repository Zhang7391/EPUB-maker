#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Number
{
private:
	char* number;
public:	
	Number(char*);
	
	void PlusOne(void);
	string ConvString(void);
};

int main()
{
    ifstream ui;
    ui.open("chapter.txt");
    ofstream ux;

    char *input = new char[200];
    for(int a=0;200>a;a++) input[a] = '\0';
    string filename, title;
    

    cout << "Please enter the beginning chapter: ";
    cin >> input;
    Number chapter(input);
    while(getline(ui, title))
    {
        filename = "chapter" + chapter.ConvString() + ".xhtml";
        ux.open(filename);

        ux << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"\n  \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">\n\n<html xmlns=\"http://www.w3.org/1999/xhtml\">\n\n<head>\n  <title>chapter";
        ux << chapter.ConvString() << "</title>\n  <link href=\"../Styles/style.css\" rel=\"stylesheet\" type=\"text/css\" />\n</head>\n\n<body>\n  <h1>";
        ux << title << "</h1>\n\n  <p>(This article)</p>\n\n</body>\n</html>";

        chapter.PlusOne();
        ux.close();
    }

    return 0;
}

Number::Number(char *init)
{
	this->number = new char[200];
	this->number = init;
}

void Number::PlusOne(void)
{
	int length;
	for(length=0;;length++) if(this->number[length] == '\0') break;
	length--;
	
	if('9' > this->number[length] && this->number[length] >= '0')
	{
		int x = static_cast<int>(this->number[length]);
		x += 1;
		this->number[length] = static_cast<char>(x);
	}
	else if(this->number[length] == '9')
	{
		int none;
		bool key = false;
		for(none=length;none>=0;none--)
		{
			if(this->number[none] != '9')
			{
				key = true;
				break;
			}
		}
		if(key)
		{
			int x = static_cast<int>(this->number[none]);
			x += 1;
			this->number[none] = static_cast<char>(x);
			for(none++;length>=none;none++) this->number[none] = '0'; 
		}
		else
		{
			this->number[0] = '1';
			length++;
			for(none=1;length>=none;none++) this->number[none] = '0';
		}
	}
}

string Number::ConvString(void)
{
	string brige(this->number);
	return brige;
}
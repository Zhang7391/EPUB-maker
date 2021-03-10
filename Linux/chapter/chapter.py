class Number:
    # __number

    def __init__(self, init):
        self.__number = init

    def __iadd__(self, number):
        self.__number += number
        return self

    def AutoWrite(self, WriteLine):
        filename = "chapter" + str(self.__number) + ".xhtml"
        ux = open(filename, 'w+', encoding='utf-8')
        ux.write("<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"\n  \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">\n\n<html xmlns=\"http://www.w3.org/1999/xhtml\">\n\n<head>\n  <title>chapter")
        ux.write(str(self.__number))
        ux.write("</title>\n  <link href=\"../Styles/style.css\" rel=\"stylesheet\" type=\"text/css\" />\n</head>\n\n<body>\n  <h1>")
        ux.write(WriteLine)
        ux.write("</h1>\n\n  <p>(This article)</p>\n\n</body>\n</html>")
        self.__number += 1
        ux.close()
        del filename

ui = open("chapter.txt", 'r+', encoding='utf-8')
Input = int(input("Please enter the beginning chapter: "))
chapter = Number(Input)
for WriteIn in ui: chapter.AutoWrite(WriteIn)

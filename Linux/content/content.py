class control:
    __digits = 0
    __begin = 0
    __table = ()
    __fake = False
    __ten = True

    def UserInput(self):
        space = int(input("Please enter the beginning chapter: "))
        while 0 > space:
            print("Error! Please enter a number greater than 0.")
            space = int(input("Please enter the beginning chapter: "))
        self.__begin = space
        print("Please enter the ending chapter(>= ", space, sep="", end="")
        space = int(input("): "))
        while self.__begin > space:
            print("Error! Please enter a number greater ", self.__begin, ".\nPlease enter the ending chapter(>= ", space, sep="", end="")
            space = int(input("): "))
        self.__end = space + 1
        del space

        TableToTuple = [init for init in range(1, 78, 4)]
        self.__table = tuple(TableToTuple)
        del TableToTuple

        if self.__begin == 0:
            ux.write("      <tr>\n        <td class=\"mbt05 w50 tdtop\"><a class=\"nodeco color1 contbox\" href=\"../Text/chapter0.xhtml\">序章</a></td>\n\n        <td class=\"mbt05 left\"><a class=\"nodeco color1\" href=\"../Text/chapter0.xhtml\">(章節標題)</a></td>\n      </tr>\n")
            self.__begin = 1
        for self.__begin in range(self.__begin, self.__end):
            self.__fake = False
            ux.write("      <tr>\n        <td class=\"mbt05 w50 tdtop\"><a class=\"nodeco color1 contbox\" href=\"../Text/chapter")
            ux.write(str(self.__begin))
            ux.write("xhtml\">第")
            if self.__begin%10 == 0:
                self.__begin += 1
                self.__fake = True
            self.NumberConv(int(self.__begin))
            if self.__fake: self.__begin -= 1
            ux.write("章</a></td>\n\n        <td class=\"mbt05 left\"><a class=\"nodeco color1\" href=\"../Text/chapter")
            ux.write(str(self.__begin))
            ux.write(".xhtml\">(章節標題)</a></td>\n      </tr>\n")

    def NumberConv(self, now):
        point, check, reversal, self.__digits = 0, 0, 0, 0
        key, key2, flag, self.__ten = True, True, True, True

        while now != 0:
            reversal *= 10
            reversal += (now%10)
            now //= 10
            self.__digits += 1
        check = int(self.__digits)
        while self.__digits != 0:
            PointerNumber, NextNumber, SecNumber = "PG", "PG", "PG"
            if self.__fake and check == 2:
                reversal %= 10
                self.__ten = False
            if self.__fake and self.__digits == 3:
                reversal %= 100
                key2 = False
                if reversal == 0: break
            if self.__fake and self.__digits == 4 and reversal % 1000 == 0: break
            if check == 2 and reversal % 10 == 1 and self.__digits == 2: self.__ten = False

            key = self.NumberToChinese(reversal % 10, key)
            flag = True

            PointNumber = str(reversal)
            point = self.DigitsConv(False)

            if self.__table[point] == self.__digits: key = True
            if (self.__digits % 4 == 3 or self.__digits % 4 == 0) and key2: 
                NextNumber = str(PointNumber[self.__table[point]])
            if self.__digits % 4 == 0: SecNumber = str(PointNumber[self.__table[point]+1])

            PointNumber = str(PointNumber[self.__table[point] - 1])
            if self.__digits % 4 == 2 and PointNumber == "0":
                self.DigitsConv(key)
                self.__digits -= 1
                self.DigitsConv(key)
                flag = False
                reversal //= 100
                self.__digits -= 1
            if self.__digits % 4 == 3 and NextNumber == "0" and SecNumber == "0":
                self.DigitsConv(key)
                self.__digits -= 2
                self.DigitsConv(key)
                flag = False
                reversal //= 1000
                self.__digits -= 1
            if self.__digits % 4 == 0 and NextNumber == "0" and SecNumber == "0" and PointNumber == "0":
                self.__digits -= 3
                if reversal % 10 != 0: ux.write("千")
                self.DigitsConv(key)
                flag = False
                reversal //= 10000
                self.__digits -= 1
            if flag:
                self.DigitsConv(key)
                reversal //= 10
                self.__digits -= 1
            self.__ten = True

        del point, check, reversal, key, flag, PointerNumber, NextNumber, SecNumber

    def NumberToChinese(self, PointNumber, key):
        if PointNumber == 0:
            if key: ux.write("零")
            return False
        elif PointNumber == 1: 
            if self.__ten: 
                ux.write("一")
        elif PointNumber == 2: ux.write("二")
        elif PointNumber == 3: ux.write("三")
        elif PointNumber == 4: ux.write("四")
        elif PointNumber == 5: ux.write("五")
        elif PointNumber == 6: ux.write("六")
        elif PointNumber == 7: ux.write("七")
        elif PointNumber == 8: ux.write("八")
        elif PointNumber == 9: ux.write("九")
        return True

    def DigitsConv(self, ComeIn):
        compare = 0
        while self.__digits > self.__table[compare]: compare += 1
        if self.__table[compare] != self.__digits: compare -= 1
        if not ComeIn: return compare

        if self.__digits - self.__table[compare] == 1: ux.write("十")
        elif self.__digits - self.__table[compare] == 2: ux.write("百")
        elif self.__digits - self.__table[compare] == 3: ux.write("千")

        if self.__digits % 4 == 1:
            if self.__table[compare] == 5: ux.write("萬")
            elif self.__table[compare] == 9: ux.write("億")
            elif self.__table[compare] == 13: ux.write("兆")
            elif self.__table[compare] == 17: ux.write("京")
            elif self.__table[compare] == 21: ux.write("垓")
            elif self.__table[compare] == 25: ux.write("秭")
            elif self.__table[compare] == 29: ux.write("穰")
            elif self.__table[compare] == 33: ux.write("溝")
            elif self.__table[compare] == 37: ux.write("澗")
            elif self.__table[compare] == 41: ux.write("正")
            elif self.__table[compare] == 45: ux.write("戴")
            elif self.__table[compare] == 49: ux.write("極")
            elif self.__table[compare] == 53: ux.write("恆河沙")
            elif self.__table[compare] == 57: ux.write("阿僧祇")
            elif self.__table[compare] == 61: ux.write("那由他")
            elif self.__table[compare] == 65: ux.write("不可思議")
            elif self.__table[compare] == 69: ux.write("無量")
            elif self.__table[compare] == 73: ux.write("大數")
        return compare

ux = open("content.txt", 'w+')
user = control()
user.UserInput()
ux.close()

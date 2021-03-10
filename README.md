### **EPUB小工具(中文介紹)**

目前只有兩個小工具，因為本人目前還不知道缺啥。
總之就先寫了自己在製作EPUB上所需要的兩個工具，也就是目錄產生器(content)，和章節產生器(chapter)。
因為本人在製作的時候花最多時間在這兩部分。

若有任何想新增的EPUB小工具，歡迎Pull或是用Github Issues提出，本人會盡快merge或依據Issues上的建議撰寫程式或給予回饋。
目前還在猶豫要不要丟執行檔上來，都已經做好、打包好了且確認可以跨電腦運行，但沒有API介面實為硬傷

#### **EPUB小工具簡介**

chapter: 產生對應chpater.txt裡的chpater*.xhtml檔案
```html
<?xml version="1.0" encoding="utf-8" standalone="no"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN"
  "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">

<head>
  <title>chapter2</title>
  <link href="../Styles/style.css" rel="stylesheet" type="text/css" />
</head>

<body>
  <h1>第一章 略</h1>	
<!-- 這裡會對應記事本裡面的第一行，第二個產生出來的xhtml會對應記事本裡第二行，以此類推...... -->

  <p>(This article)</p>

</body>
</html>
```

content: 產生連結到chpater*的連結，最高支援到**10^77 - 1位數**的輸出；預設會導入一些CSS的語言，可依照自己的需求來更改程式碼來產生不同的組合。
```html
      <tr>
        <td class="mbt05 w40 tdtop"><a class="nodeco color1" href="../Text/chapter1000000.xhtml">第一百萬章</a></td>

        <td class="mbt05 left"><a class="nodeco color1" href="../Text/chapter1000000.xhtml">(章節標題)</a></td>
      </tr>
      <tr>
        <td class="mbt05 w40 tdtop"><a class="nodeco color1" href="../Text/chapter1000001.xhtml">第一百萬零一章</a></td>

        <td class="mbt05 left"><a class="nodeco color1" href="../Text/chapter1000001.xhtml">(章節標題)</a></td>
      </tr>
```

#### **如何使用**
本人使用設備：
* Windows系統為windows 10(64-bit)
* Linux系統為CentOS 8.3

編譯器版本至少須為C++11否則程式無法執行

本人撰寫時使用的python版本為3.6.8

##### **Windows**

* chapter
	* C++
		1. 進入Windows/chapter資料夾內，找到chapter.cpp這一個檔案。
		2. 開啟任意的編譯軟體(至少需有**C++11**)，編譯chapter.cpp。
		3. 在同個資料夾內的chapter.txt裡一行一行貼上所需的大標題
		4. 執行編譯完所產生的執行檔
		5. 輸入開始章節號碼(像上方的範例輸出程式碼是從2開始)。
		6. 等待程式執行結束，即可在同個資料夾內找到寫好的chapter*.xhtml檔

* contenit
	* C++
		1. 進入Windows/content資料夾內，找到content.cpp, BigNumber.cpp, and BigNumber.h這三個檔案
		2. 開啟任意的編譯軟體(至少需有**C++11**)，編譯chapter.cpp。
		3. 執行編譯完所產生的執行檔
		4. 先輸入開始章節、在輸入結束章節並等待程式執行結束
		5. 開啟content.txt，將產生結果貼至所需地方

##### **Linux**
```
git clone https://github.com/Zhang7391/EPUB-maker.git
cd EPUB-maker
```
* chapter
	* C++
		1. `cd Linux/chapter`
		2. `g++ -g -Wall chapter.cpp -o chapter.exe`
		3. `vi chapter.txt`
		4. 一行一行貼上所需的大標題，儲存離開
		5. `./chapter.exe`
		6. get some chpater*.xhtml

* content
	* C++
		1. `cd Linux/content`
		2. `g++ -g -Wall content.cpp BigNumber.cpp -o content.exe`
		3. `./content.exe`
		4. 先輸入開始章節、在輸入結束章節並等待程式執行結束
		5. `vi content.txt`
	* Python3
		1. `cd Linux/chapter`
		2. `python3 content.py`
		3. 先輸入開始章節、在輸入結束章節並等待程式執行結束
		4. `vi content.txt`

#### **部分程式碼引用原出處**

BigNumber.cpp & BigNumber.h
* 原作者: FFMG
* [Github頁面](https://github.com/FFMG/myoddweb.bignumber.cpp)



### **EPUB makers (English discription)**

At present, there are only two small tools, because I don't know what I lack.
In a word, I first wrote two tools I need to make EPUB, namely, content and chapter.
Because I spend the most time in these two parts when I make them.

If you want to add any EPUB tool(s), please pull or use GitHub issues. I will merge them as soon as possible.
Maybe, write programs or give feedback on issues.
At present, I'm still hesitating whether to drop the execution file. It's all done, packaged, and confirmed that it can run across computers, but it's hard to get rid of the API interface.

#### **EPUB maker discript**

chapter: Generate corresponding chpater*.xhtml files in chpater.txt
```html
<?xml version="1.0" encoding="utf-8" standalone="no"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN"
  "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">

<head>
  <title>chapter2</title>
  <link href="../Styles/style.css" rel="stylesheet" type="text/css" />
</head>

<body>
  <h1>第一章 略</h1>
<!-- This will correspond to the first line in Notepad, and the second generated XHTML will correspond to the second line in Notepad, and so on...... -->

  <p>(This article)</p>

</body>
</html>
```

content: Link generate a link to chpater*, the maximum support to the **10^77 - 1** digit output.
Defaults to import a few CSS, you can change the code according to their own needs to produce different combinations
```html
      <tr>
        <td class="mbt05 w40 tdtop"><a class="nodeco color1" href="../Text/chapter1000000.xhtml">第一百萬章</a></td>

        <td class="mbt05 left"><a class="nodeco color1" href="../Text/chapter1000000.xhtml">(chapter title)</a></td>
      </tr>
      <tr>
        <td class="mbt05 w40 tdtop"><a class="nodeco color1" href="../Text/chapter1000001.xhtml">第一百萬零一章</a></td>

        <td class="mbt05 left"><a class="nodeco color1" href="../Text/chapter1000001.xhtml">(chapter title)</a></td>
      </tr>

<!-- JUST CONVERT TO CHINESE NUMBER! -->
```

#### **How to use**
I use the device:
* The Windows system is windows 10(64 bit)
* The Linux system is CentOS 8.3

The G++ version must be at least C++11, otherwise the program can't be executed.

The python version I wrote was 3.6.8

##### **Windows**

* chapter
	* C++
	    1. Enter the Windows/chapter folder and find the chapter.cpp.
    	2. Open any compiler software (at least **C++11**) and compile the "chapter.cpp".
	    3. Paste the titles line by line in chapter.txt, which in the same folder.
    	4. Execute the .exe file.
	    5. Please enter the beginning chapter.
    	6. Wait for the program to finish running, and you can find the written chapter*.xhtml file in the same folder.

* content
	* C++
	    1. Enter the Windows/content folder and find the chapter.cpp, BigNumber.cpp, and BigNumber.h.
    	2. Open any compiler software (at least **C++11**) and compile the "chapter.cpp".
	    3. Execute the .exe file.
    	4. Please enter the beginning chapter, and then enter the ending chapter.
	    5. open content.txt, and post the results where you need them.

##### **Linux**
```
git clone https://github.com/Zhang7391/EPUB-maker.git
cd EPUB-maker
```
* chapter
	* C++
	    1. `cd Linux/chapter`
    	2. `g++ -g -Wall chapter.cpp -o chapter.exe`
	    3. `vi chapter.txt`
    	4. Paste the titles line by line.
	    5. `./chapter.exe`
    	6. get some chpater*.xhtml.

* content
	* C++
	    1. `cd Linux/content`
    	2. `g++ -g -Wall content.cpp BigNumber.cpp -o content.exe`
	    3. `./content.exe`
    	4. Please enter the beginning chapter, and then enter the ending chapter.
	    5. `vi content.txt`
	* Python3
		1. `cd Linux/chapter`
        2. `python3 content.py`
        3. Please enter the beginning chapter, and then enter the ending chapter.
        4. `vi content.txt`

#### **Source of some code references**

BigNumber.cpp & BigNumber.h
* Original author: FFMG
* [Github page](https://github.com/FFMG/myoddweb.bignumber.cpp)

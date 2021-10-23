# Assignment 1 - CS5008 (Zhuocai Li)

## 1. Program Description and General Summary
This program is mainly a basic practice for C, including 4 functions:
- WarmUp: print 3 "Hello Worlds";
(Using a for loop to repeatedly print)

- PrintRectangle: print out an unfilled rectangle with given width and height;
(Using a for loop to repeatedly print and if-else to diffrentiate the first/last line and the middle part)

- PrintFancyRectangle: print out either filled or unfilled rectangle with given width and height;
(Using a for loop to repeatedly print and if-else to diffrentiate the first/last line and the middle part;
Using an if-else to differentiate filled or unfilled)

- main

## 2. Compile/run Commands
- Compile: gcc assignment1.c
- Run: ./a.out

## 3. Example Input/output

```
Below is an example of WarmUp
Hello World!
Hello World!
Hello World!

Below is an example of PrintRectangle(5,4)
-----
-   -
-   -
-----

Below is an example of PrintFancyRectangle(5,4,'+',1)
+++++
+++++
+++++
+++++

Below is an example of PrintFancyRectangle(5,4,'+',0)
+++++
+   +
+   +
+++++
```

## 4. File Description
In a1, assignment1.c and README.md is included.

## 5. External Library Usage
stdio.h is used in this program.

## 6. Any Assumption Made
Words and rectangles will be printed out.

## 7. External References and Resources
### C:
https://cdn.preterhuman.net/texts/manuals/essential_c.pdf
https://gribblelab.org/teaching/CBootCamp/
https://zhidao.baidu.com/question/141947192956689125.html
https://stackoverflow.com/questions/22517148/passing-argument-1-of-printf-makes-pointer-from-integer
http://www.voidcn.com/article/p-vmvrjibm-bwe.html
https://stackoverflow.com/questions/9590839/passing-argument-1-of-printf-from-incompatible-pointer-type
http://c.biancheng.net/view/159.html
http://c.biancheng.net/cpp/html/33.html
https://stackoverflow.com/questions/27272525/what-does-collect2-error-ld-returned-1-exit-status-mean
https://github.ccs.neu.edu/CS-5001-SEA-Spring2021/student-ZhuocaiLi
https://blog.csdn.net/weixin_43641971/article/details/88284773

### Linux:
https://www.cnblogs.com/yadongliang/p/6100003.html
https://blog.csdn.net/lydong_/article/details/79812402

### Emacs:
http://www.jesshamrick.com/2012/09/10/absolute-beginners-guide-to-emacs/
https://blog.csdn.net/fareast_mzh/article/details/94720439

### gcc:
https://blog.csdn.net/u013998070/article/details/79633547

## 8. The Tricky or Hard Part I Spent Time On
Getting used to the commands of Emacs, like copying and pasting.
Also, it is kind of hard to correct the format of C on Emacs.
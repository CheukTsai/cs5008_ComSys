# Assignment 2 - CS5008 (Zhuocai Li)

## 1. Program Description and General Summary
This program is mainly a basic practice for struct and array, including 4 functions:

[Bonus] CapAndSmall: Capitalizes the first letter and make the rest into lower cases;
```
char *CapAndSmall(char *word)
{
    int wordLength = strlen(word);
    char *wordNew = (char *)malloc(sizeof(*wordNew) * (wordLength + 1));
    int i;
    wordNew[0] = toupper(word[0]);
    for (i = 1; i < wordLength; i++)
    {
        wordNew[i] = tolower(word[i]);
    }
    wordNew[wordLength + 1] = '\0';
    return wordNew;
}
```
 
1. Big: print (first name (middle name) last name);
- if(middle != NULL){sprintf(dest, "%s %s %s", first, middle, last);}
- else{sprintf(dest, "%s %s", first, last);}

2. Last: print (last name, first name);
- sprintf(dest, "%s, %s",last, first);

3. Reg: print (first last);
- sprintf(dest, "%s %s", first, last);

4. Mid: print (first (middle - innitial) last);
- if(middle != NULL){char init[2];
- snprintf(init, 2, "%s", middle);
- sprintf(dest, "%s %s. %s",first, init, last);}
- else{sprintf(dest, "%s %s", first, last);}

5. Small: print (first)
- sprintf(dest, "%s", first);

6. FormatName: Given a format char, print the given name in the format specified by char.

7. FillName: Given a name, a format and a destination array, put the properly formatted name in the destination array, not printing anything on the screen.


## 2. Compile/run Commands
- Compile: gcc a2.c a2_test.c -o a2
- Run: ./a2

## 3. Example Input/output (with bonus)

```
Test #1: Print Big

Alyssa Mary Antle
Ben Ivan Bitdiddle
Daniel Diamond

--------------------------------

Test #2: Print Last

Bitdiddle, Ben
Diamond, Daniel

--------------------------------

Test #3: Print Reg

Cassie Charstrup
Daniel Diamond

--------------------------------

Test #4: Print Mid

Daniel Diamond
Alyssa M. Antle

--------------------------------

Test #5: Print Small

Daniel
Ben

--------------------------------

Test #6: Print FormatName

Alyssa Mary Antle
Antle, Alyssa
Alyssa Antle
Alyssa M. Antle
Alyssa
Daniel Diamond
Diamond, Daniel
Daniel Diamond
Daniel Diamond
Daniel

--------------------------------

Test #7: Print FillName

Alyssa Mary Antle
Antle, Alyssa
Ben I. Bitdiddle
Anya


--------------------------------

feel free to add your own!

```

## 4. File Description
In a2, a2.c a2.h a2_test.c a.out Makefile pointers.c README.md is included.

## 5. External Library Usage
stdio.h, stdlib.h, time.h, string.h, a2.h is used in this program.

## 6. Any Assumption Made
Certain formated names will be printed out.

## 7. External References and Resources
- https://blog.csdn.net/qq_32365567/article/details/55045942 
- https://zhidao.baidu.com/question/30528378
- https://blog.csdn.net/creat2012/article/details/44224217
- https://blog.csdn.net/qq_21583681/article/details/78572009
- https://www.runoob.com/cprogramming/c-header-files.html
- http://m.biancheng.net/view/293.html
- https://www.runoob.com/cprogramming/c-function-snprintf.html
- http://c.biancheng.net/cpp/html/132.html
- http://c.biancheng.net/ref/tolower.html
- and many other resources(websites) that I failed to copy and paste.

## 8. The Tricky or Hard Part I Spent Time On
It takes over 5 hours because I stucked in how to get the tolower and toupper function worked.
Not yet working.

[New Updates]It works now!

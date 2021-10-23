# Assignment7 - CS5008 - Zhuocai Li

Details are in the write-up on Canvas. 

Provided files: 

* ```words.txt```: The word file you need to read in to find anagrams with. 
* ```Hashtable.h```: **IF** you want, you can use this to start structuring 
and building your hashtable. 
* ```Hashtable.c```: Stub file for your hashtable code, contains FNV Hash function. 
* ```Makefile```: Generic starting Makefile
* ```test_hashtable.cc```: A starting test file for you to use to test your hashtable implementation. 

# Resources: 

* https://medium.com/basecs/hashing-out-hash-functions-ea5dd8beb4dd (Hash Functions)
* https://medium.com/basecs/taking-hash-tables-off-the-shelf-139cbf4752f0?source=---------17----------------------- (Hash Tables, generally)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#hashTables (Hashtables in C)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#File_IO  (Reading a file in C)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#functionPointers (Function Pointers, for more challenge)


## 1. Program Description and General Summary
This program is mainly to build up a hashtable, which can stores words in particular format with certain value.


## 2. Compile/run Commands
Using Makefile to directly compile and run:

./Makefile includes:

all: run

run: Hashtable.c Hashtable.h Anagram.c Anagram.h Main.c Assert007.c Assert007.h
	gcc -g Hashtable.c Main.c Anagram.c Assert007.c -o main
	./main

test:
	./test_suite

valgrind:
	valgrind --leak-check=full ./test_suite

clean: 
	rm -rf *.o


## 3. Example Input/output

Threshold is set to 1, and small_words.txt is read:

Read 150 rows 
Looking for Anagrams...
key: aabc| values: abac caba ; num: 2
key: aam| values: ama maa aam ; num: 3
key: aab| values: baa aba ; num: 2
key: aaabcy| values: cayaba abacay ; num: 2
key: aabcs| values: abacs cabas ; num: 2

## 4. File Description
In a6, Anagram.c, Assert007.h, Hashtable.c, Hashtable.h, main.c,  Makefile are included.

## 5. External Library Usage
stdio.h, stdlib.h, time.h, unistd.h is used in this program.

## 6. Any Assumption Made
words will be collected with certain sorted keys.

## 7. External References and Resources
- https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list
- https://cs50.stackexchange.com/questions/9260/how-to-fix-the-conditional-jump-or-move-depends-on-uninitialized-value-valgrin/9261
- https://stackoverflow.com/questions/27594992/uninitialized-value-was-created-by-a-heap-allocation
- https://github.com/PaddlePaddle/Paddle/issues/7912
- https://stackoverflow.com/questions/9051600/why-constant-argument-of-function-used-as-array-size-gives-error
- https://softwareengineering.stackexchange.com/questions/201104/sizeof-style-sizeoftype-or-sizeof-variable
- and many other resources(websites) that I failed to copy and paste.

## 8. The Tricky or Hard Part I Spent Time On
It takes over 40 hours. It is really so hard... many memory problems... many conditional problems... endless segmentation fault... jesus...
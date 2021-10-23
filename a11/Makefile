all: mt_search

mt_search: mt_search.c
	gcc -pthread -o mt_search mt_search.c

run: mt_search
	./mt_search nums10000.txt 100 10 1001

valgrind: run
	valgrind --leak-check=full --show-leak-kinds=all ./mt_search nums10000.txt 100 10 1001

clean:
	rm -f mt_search

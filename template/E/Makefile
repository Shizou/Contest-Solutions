CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} E.cpp -o E && ./E < ${input} && rm E

py: clear
	python3 E.py < ${input}

java: clear
	javac E.java && java E < ${input} && rm E.class

clear:
	clear


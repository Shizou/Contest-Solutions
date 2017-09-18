CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} D.cpp -o D && ./D < ${input} && rm D

py: clear
	python3 D.py < ${input}

java: clear
	javac D.java && java D < ${input} && rm D.class

clear:
	clear


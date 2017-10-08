CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} G.cpp -o G && ./G < ${input} && rm G

py: clear
	python3 G.py < ${input}

java: clear
	javac G.java && java G < ${input} && rm G.class

clear:
	clear


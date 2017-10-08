CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} J.cpp -o J && ./J < ${input} && rm J

py: clear
	python3 J.py < ${input}

java: clear
	javac J.java && java J < ${input} && rm J.class

clear:
	clear


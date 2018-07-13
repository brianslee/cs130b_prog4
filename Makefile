CC = g++ -g
STDFLAGS = -std=c++11

all: prog4

prog4:
	$(CC) prog4.cc main.cc -o $@ $(STDFLAGS)

.PHONY: clean

clean:
	rm -rf prog4
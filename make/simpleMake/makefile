objects = main.o max.o

all: $(objects)
	cc -o my_max $(objects)

max.o: max.h

exec:
	cd ~/Documents/build; pwd

.PHONY: clean
clean:
	rm $(objects) my_max



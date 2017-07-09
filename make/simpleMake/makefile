objects = main.o max.o

all: $(objects)
	cc -o my_max $(objects)

max.o: max.h

exec:
	cd ~/Documents/build; pwd

#.PHONY  目标“.PHONY”的所有依赖被作为伪目标，伪目标是这样一个目标：
#当使用make命令制定此目标时，这个目标躲在规则中的命令无论目标文件是否
#存在都会被无条件执行
.PHONY: clean
clean:
	rm $(objects) my_max



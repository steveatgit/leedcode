C=gcc
CXX=g++
CFLAGS= -g -D_DEBUG -fPIC -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wsign-compare -Winvalid-pch -fms-extensions -Wall -MMD
CPPFLAGS=$(CFLAGS) -Woverloaded-virtual -Wsign-promo -fno-gnu-keywords -std=c++11

SRC_DIR=.
BUILD_DIR=./build

OBJS=csapp.o

LIBPATH=/usr/bin
LIB=-lpthread #-fpermissive

TARGET=echo_client echo_num_test

all : $(TARGET) 
check: $(TARGET)
	./$^

echo_client: $(OBJS) echo_client.o
	$(CXX) $(CPPFLAGS) -o $(BUILD_DIR)/$@ $(BUILD_DIR)/$(OBJS) $(BUILD_DIR)/echo_client.o -L$(LIBPATH) $(LIB)

echo_num_test: $(OBJS) echo_num_test.o
	$(CXX) $(CPPFLAGS) -o $(BUILD_DIR)/$@ $(BUILD_DIR)/$(OBJS) $(BUILD_DIR)/echo_num_test.o -L$(LIBPATH) $(LIB)


echo_client.o:
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/echo_client/echo_client.cpp -o $(BUILD_DIR)/$@ -L$(LIBPATH) $(LIB)

echo_num_test.o:
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/echo_num_test/echo_num_test.cpp -o $(BUILD_DIR)/$@ -L$(LIBPATH) $(LIB)

csapp.o:
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/Base/csapp.cpp -o $(BUILD_DIR)/$@ -L$(LIBPATH) $(LIB)

clean:
	cd $(BUILD_DIR) && rm *.o echo_client echo_num_test

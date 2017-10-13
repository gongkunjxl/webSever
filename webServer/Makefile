
#-L表示在链接时要链接库的路径，但是在生成的ELF文件中，并不包含库的路径，需要LD_LIBRARY_PATH中有这个库的路径
# the project makefile

#SRC = ./main.cpp
OBJ = main.o ClientResponse.o LogHandle.o FutuHandle.o SqlHandle.o 
EXEC = webSever
CC = g++
FLAGS = -c -std=c++11
LIB = -L/usr/local/lib/ -L/usr/local/opt/openssl/lib
LIB_WEB = -lPocoXML -lPocoUtil -lPocoNet -lPocoFoundation -lssl -lcrypto -lboost_system -lboost_thread -lboost_chrono -lcpprest
INCLUDE = -I/usr/local/include -I/usr/local/include

#webSever: main.o ClientResponse.o LogHandle.o FutuHandle.o SqlHandle.o
#	$(CC) $(LIB) $(LIB_WEB) $(FLAGS) main.o ClientResponse.o LogHandle.o FutuHandle.o SqlHandle.o

$(EXEC): $(OBJ)
	$(CC) $(LIB) $(LIB_WEB) -o $(EXEC) $(OBJ)
main.o: main.cpp ClientResponse.h LogHandle.h FutuHandle.h SqlHandle.h
	$(CC) $(LIB) $(LIB_WEB) $(INCLUDE) $(FLAGS) main.cpp
LogHandle.o: LogHandle.cpp LogHandle.h
	$(CC) $(LIB) $(LIB_WEB) $(INCLUDE) $(FLAGS) LogHandle.cpp
SqlHandle.o: SqlHandle.cpp SqlHandle.h
	$(CC) $(LIB) $(LIB_WEB) $(INCLUDE) $(FLAGS) SqlHandle.cpp
ClientResponse.o: ClientResponse.cpp ClientResponse.h
	$(CC) $(LIB) $(LIB_WEB) $(INCLUDE) $(FLAGS) ClientResponse.cpp
FutuHandle.o: FutuHandle.cpp FutuHandle.h
	$(CC) $(LIB) $(LIB_WEB) $(INCLUDE) $(FLAGS) FutuHandle.cpp

#webSever.o:$(OBJ)
#	    $(CC) $^ $(LIB) $(LIB_WEB) $(FLAGS) -o $(EXEC)

#%.o:%.cpp
#	    $(CC) $^ $(LIB) $(LIB_WEB) $(INCLUDE) $(FLAGS) $< -o $@

clean:
	    rm -f *.o

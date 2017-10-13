1.安装boost poco openssl cpprestsdk 
2.参数:
link other flag:
    -lPocoXML -lPocoUtil -lPocoNet -lPocoFoundation -lssl -lcrypto -lboost_system -lboost_thread -lboost_chrono -lcpprest
header include: 
    /usr/local/include  /usr/local/opt/openssl/include
header lib:
    /usr/local/lib /usr/local/opt/openssl/lib
3.Makefile文件的创建


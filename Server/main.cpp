#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "TcpServer.h"

#include "MyTest.h"
int main(int argc, char* argv[])
{
    setbuf(stdout,NULL);//puts到输出台上
#if 0
    if (argc < 3)
    {
        printf("./a.out port path\n");
        return -1;
    }
    unsigned short port = atoi(argv[1]);
    // 切换服务器的工作路径
    chdir(argv[2]);
#else
    unsigned short port = 9999;
    chdir("/home/buaichifanqie/network/aoqi");
#endif
    // 启动服务器
    TcpServer* server = new TcpServer(port, 4);
    printf("你好");
    server->run();

//    MyTest t;
//    t.test();
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

//创建一个守护进程
int main(int argc, char **argv)
{
    //1.第一次创建一个子进程，父进程退出
    pid_t pid = fork();
    if(pid > 0){
        exit(0);//父进程进程退出
    }else if(pid < 0){
        printf("fork child process is fail\n");
    }
    /* 2. 调用setsid函数
    pid_t setsid(void);
    进程调用setsid()可建立一个新对话期间。如果调用此函数的进程不是一个进程组的组长，则此函数创建一个新对话期，结果为：
    1、此进程变成该新对话期的对话期首进程（session leader，对话期首进程是创建该对话期的进程）。此进程是该新对话期中的唯一进程。
    2、此进程成为一个新进程组的组长进程。新进程组ID就是调用进程的进程ID。
    3、此进程没有控制终端。如果在调用setsid之前此进程有一个控制终端，那么这种联系也被解除。如果调用进程已经是一个进程组的组长，则此函数返回错误。为了保证不处于这种情况，通常先调用fork()，
    然后使其父进程终止，而子进程继续执行。因为子进程继承了父进程的进程组ID，而子进程的进程ID则是新分配的，两者不可能相等，所以这就保证了子进程不是一个进程组的组长。
    */
    if (setsid() == -1)
    {
        printf("setsid() failed\n");
        return false;
    }
    // 3. 如果daemon后面可能会打开一个终端设备，那么必须要采取措施来确保这个设备不会成为控制终端,再次fork一个子进程，然后再次让父进程退出并让孙子进程继续执行。
    //这样就确保了子进程不会称为会话组长，因此根据System V中获取终端的规则，进程永远不会重新请求一个控制终端
    pid = fork();
    if (pid > 0){
        exit(0); //父进程进程退出
    }else if (pid < 0){
        printf("fork child process is fail\n");
    }
    //4. 设置权限，让子进程可以拥有自己的所有权限，并便能工作目录
    umask(0);
    chdir("/");
    while (true)
    {
        sleep(1000);
        printf("111111\n");
    }
    return 0;
}
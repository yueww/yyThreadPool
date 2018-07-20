/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月20日 星期五 09时32分33秒
 ************************************************************************/

#include "yyThreadPool.h"

void *func(void *arg);

int main(){
    threadpool_t *tp=threadpool_init(4);
    int a[8];
    for(int i=0;i<8;i++){
        a[i]=i+1;
    }
    for(int i=0;i<8;i++){
        if(threadpool_add_task(tp,func,a+i)==-1){
            printf("error!\n");
            threadpool_destroy(tp);
            return 0;
        } 
    }
    sleep(1);
    threadpool_destroy(tp);
    tp=threadpool_init(8);
    for(int i=0;i<8;i++){
        if(threadpool_add_task(tp,func,a+i)==-1){
            printf("error!\n");
            threadpool_destroy(tp);
            return 0;
        } 
    }
    sleep(1);
    threadpool_destroy(tp);
}

void *func(void *arg){
    int *pNum=(int *)arg;
    printf("thread %lu is printing %d\n",(unsigned long)pthread_self(),*pNum);
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
// #include<sys/wait.h>

#define BUFFERSIZE 10
int mutex, n, empty, full = 0, item, item1;
int buffer[20];
int in = 0, out = 0, mutex = 1;

void wait(int s)
{
    while(s < 0)
    {
        printf("Cannot add an item\n");
        exit(0);
        s--;
    }
}
void signal(int s){ s++; }

void consumer()
{
    do{
        wait(full);
        wait(mutex);
        item1 = buffer[out];
        printf("\nConsumed item= %d\n", item1);
        out += 1;
        signal(mutex);
        signal(empty);
    }while(out < n);
}

void producer()
{
    do{
        wait(empty);
        wait(mutex);
        printf("\nEnter an item: ");
        scanf("%d", &item);
        buffer[in] = item;
        in += 1;
        signal(mutex);
        signal(full);
    }while(in < n);
}
int main()
{
    printf("\nEnter the value of n: ");
    scanf("%d", &n);
    empty = n;
    while(in < n)
        producer();
    while (in != out)
    {
        consumer();
    }
    return 0;
}
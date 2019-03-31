#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

void* salin(void *arg)
{
    int t;
    t = system("touch /home/hisam/latihanmodul3/soal1/salin1.txt");
    char ch;

    FILE *src = fopen("/home/hisam/latihanmodul3/soal1/baca.txt", "r");
    FILE *dst = fopen("/home/hisam/latihanmodul3/soal1/salin1.txt", "w");

    while((ch = fgetc(src))!=EOF){
       fputc(ch, dst);
    }
    fclose(src);
    fclose(dst);

}

void* salin2(void *arg)
{
     int t2;
     t2 = system("touch /home/hisam/latihanmodul3/soal1/salin2.txt");
     char ch2;

     FILE *src2 = fopen("/home/hisam/latihanmodul3/soal1/salin1.txt", "r");
     FILE *dst2 = fopen("/home/hisam/latihanmodul3/soal1/salin2.txt", "w");

     while((ch2 = fgetc(src2))!=EOF){
         fputc(ch2, dst2);
     }
     fclose(src2);
     fclose(dst2);
}

int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &salin, NULL);
    pthread_create(&thread2, NULL, &salin2, NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2, NULL);
    return 0;
}

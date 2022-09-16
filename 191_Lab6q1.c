#include<stdio.h>
#include<stdlib.h>
int csum;
//64050191 ภูมิรพี ศรีฟ้า
//Q2.5
/* 
        โดยจะพบ 2 case
        1. โดยเเม่เสร็จก่อน - ลูกเสร็จทีหลัง
        2. โดยลูกเสร็จก่อน เเต่เเม่พิมพ์ทีหลังจึงไม่มีของลูก
*/
void *runner(void *param);
int main(int argc, char *argv[]){
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, argv[1]);

        int upper = atoi(argv[1]); // Q2.1 รับเลขจำนวนเต็ม
        int i;
        int msum = 0;
        if(upper > 0){
                for(i = 0; i<=upper; i++) //Q2.3 คำนวณผลบวก msum จาก 1 ถึง เลขนั้น
                        msum += i;
        }
        // pthread_join(tid,NULL); ถ้าหากไม่มีjoinจะเกิดอะไรขึ้น(ตามโจทย์)
        printf("Parent = %d\n",msum);
        printf("csum - msum = %d\n",csum-msum); //Q2.4 ให้parentเเสดงผลค่าต่าง
        return 0;
}
void *runner(void *param){
        int upper = atoi(param);
        int i;
        csum = 0;
        if(upper > 0){
                for(i = 0; i<=upper*2 ; i++) // Q2.2 csum จาก 1 ถึง 2 เท่า
                        csum+=i;
        }
        printf("Child = %d\n",csum);
        pthread_exit(0);
}
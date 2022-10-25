#include <iostream>
using namespace std;
#define MaxNum 10
int Stack[MaxNum];
int Top=-1;
void Push(int);
int Pop(void);
int Transfer(char*);
char itemset[MaxNum];
int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
        cout<<Transfer(itemset);
        return 0;
    }
int Transfer(char postfix[])
{
    char *pt=postfix;
    int opd1,opd2;
    while(*pt){
        if(*pt>='0'&&*pt<='9')
        Push(*pt-'0');
        else{
            opd2=Pop();
            opd1=Pop();
            switch(*pt){
                case '+':Push(opd1+opd2);
                break;
                case '-':Push(opd1-opd2);
                break;
                case '*':Push(opd1*opd2);
                break;
                case '/':Push(opd1/opd2);
                break;
                default: return -1;
            }
        }
        pt++;
    }
    return Pop();
}
void Push(int n)
{
    if(Top==MaxNum-1){
        return;
    }
    Stack[++Top]=n;
}
int Pop(void)
{
    if(Top==-1){

	}
    return Stack[Top--];
}

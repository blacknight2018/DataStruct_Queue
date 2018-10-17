/*
数据结构 之队列 byHuaze 2018-10-27  vc6测试通过
*/
#include <STDIO.H>
#include <STDLIB.H>
typedef enum
{
	TRUE = 1,
	FALSE = 0,
}status;
typedef int Elemtype;
struct Ququq
{
	Elemtype *pBase;
	int font;
	int real;
	int max;
	int first;
};
status initQueue(struct Ququq *pQue,int Max)
{
	if(NULL==pQue)
		return FALSE;
	pQue->font = pQue->real = 0;
	pQue->pBase = (Elemtype*)malloc(Max*sizeof(Elemtype));
	pQue->max = Max;
	if(NULL==pQue->pBase)
		return FALSE;
	else
		return TRUE;
}
status destryQueue(struct Ququq *pQue)
{
	if(NULL!=pQue->pBase)
	{
		free(pQue->pBase);
		pQue->pBase = NULL;
		pQue->font = pQue->real = 0;
		return TRUE;
	}
	else
		return FALSE;
}
status isFullQueue(struct Ququq *pQue)
{
	if(NULL==pQue)
		return FALSE;
	if((pQue->real+1)%pQue->max == pQue->font)
	{
		return TRUE;
	}
	return FALSE;
}
status isEmyruQueue(struct Ququq *pQuq)
{
	if(pQuq->font == pQuq->real)
		return TRUE;
	return FALSE;
}
//Add a Elemtype to end
status insertQueue(struct Ququq *pQue,Elemtype Value)
{
    if(NULL==pQue || TRUE==isFullQueue(pQue))
		return FALSE;
    pQue->pBase[ pQue->real] = Value;

	pQue->real=(pQue->real+1)%pQue->max;
	
	return TRUE;
}
//Delete the first
status deleteQuquq(struct Ququq *pQue)
{
   if(NULL==pQue || TRUE == isEmyruQueue(pQue))
	   return FALSE;
   pQue->font = (((pQue->font)+1)%(pQue->max));
   return TRUE;
}
Elemtype getTheFirstQueue(struct Ququq *pQue)
{
	if(TRUE == isEmyruQueue(pQue))
		return FALSE;
	return pQue->pBase[pQue->font];
}
int getnumQueue(struct Ququq *pQueue)
{
	if(NULL==pQueue->pBase)
		return FALSE;
    return (pQueue->real)-(pQueue->font);
}
int main()
{
	char c=0;
	Elemtype result;
    struct Ququq str1;

	initQueue(&str1,8);//N个元素的队列需要分配N+1的空间 不然有问题
	
	while(c!='q')
	{
		c = getchar();
		switch(c)
		{
			case 'q':	//Exit this app
				return 0;
			case 'g':	//Del the first Get the first
				if(TRUE == isEmyruQueue(&str1))
				{
					printf("The Queue is Emytry!\n");
					break;
				}
				else
				{
					result = getTheFirstQueue(&str1);	//Get
					printf("The first Queue is %u",result);
					deleteQuquq(&str1);					//And delete
				}
				break;
			case 'i':   //insert to the last
				if(TRUE == isFullQueue(&str1))
				{
					printf("The Queue is Full!\n");
					break;
				}
				else
				{
					printf("Please input a num:");
					scanf("%d",&result);
					insertQueue(&str1,result);
				}
				 break;
			case 'c':
				printf("These are %d in the Queue\n",getnumQueue(&str1));
				break;

		}
	}
	return 0;
}

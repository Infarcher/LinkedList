﻿#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
	int value;
	char name;
	struct _node* next;
}Node;

Node* head; //헤드 포인터 생성
void init() {
	head = NULL;
}
void tale(Node* tale) {//꼬리 노드로 변경
	tale->next = tale;
}
void allocNode(Node* node, int val, char name) {
	node->value = val;//노드 값 입력
	node->name = name;//노드 이름 입력
	node->next = NULL;//당장 안 쓰니까 NULL로 초기화
}
//Æ÷ÀÎÅÍ º¯¼ö´Â ¼±¾ð Áï½Ã ¸Þ¸ð¸® ÇÒ´çÀÌ³ª ÃÊ±âÈ­ÇØ¾ß ÇÏ¹Ç·Î ÇÔ¼ö·Î´Â ¸Þ¸ð¸® ÇÒ´ç ºÒ°¡
void insertNode(Node* forwNode, Node* inserNode)
/*inserNode는 삽입할 노드,forwNode는 바로 앞에 오는 노드.*/
//¾Õ¿¡ ³ëµå°¡ ¾øÀ¸¸é forwNode´Â NULL·Î ÀÔ·Â
//head ÀÚ¸®¿¡´Â &head¶ó°í ÀÔ·Â
{
	Node** headPtr = &head;// head 포인터 값이 바뀌므로 이중 포인터 사용						
	if (*headPtr == NULL) {//head Æ÷ÀÎÅÍ°¡ ¾Æ¹«°Íµµ ¾È °¡¸®Å°¹Ç·Î ºó ¸®½ºÆ®
		*headPtr = inserNode;
		tale(inserNode);//¿©±â¼­ »õ·Î »ðÀÔµÈ ³ëµå´Â ¹«Á¶°Ç ²¿¸®
	}
	else if (forwNode == NULL) {//¾Õ¿¡ Çìµå Æ÷ÀÎÅÍ ¹Û¿¡ ¾øÀ¸¹Ç·Î Çìµå°¡ °¡¸®Å°´Â °÷¿¡ ³ëµå »ðÀÔ
		inserNode->next = *headPtr;
		*headPtr = inserNode;
	}
	else {
		if (forwNode->next == forwNode) {//²¿¸® ³ëµå µÚ¿¡ »ðÀÔÇÏ´Â °æ¿ì
			forwNode->next = inserNode;
			tale(inserNode);//»ðÀÔÇÏ´Â ³ëµå¸¦ ²¿¸® ³ëµå·Î ¹Ù²Ù±â
		}
		else {
			inserNode->next = forwNode->next; /*A - C ±¸Á¶¿¡¼­ B¸¦ »ðÀÔ, A³ëµå¿¡ ÀúÀåµÈ C³ëµå À§Ä¡¸¦ B·Î ÀÌµ¿*/
			forwNode->next = inserNode;//A³ëµåÀÇ ´ÙÀ½ ³ëµå´Â ÀÌÁ¦ B³ëµå À§Ä¡¶ó°í ÀúÀå
		}

	}

}
void deleteNode(Node* forwNode, Node* delNode) {//¾Õ ³ëµå°¡ ¾øÀ¸¸é NULL ÀÔ·Â
	Node** headPtr = &head;// head Æ÷ÀÎÅÍ °ª º¯°æÇÏ¹Ç·Î ÀÌÁß Æ÷ÀÎÅÍ »ç¿ë	
	if (forwNode == NULL) //¹Ù·Î ¾ÕÀÌ Çìµå Æ÷ÀÎÅÍ
		*headPtr = delNode->next;
	else if (delNode->next == delNode)//²¿¸® ³ëµå Á¦°Å ½Ã
		tale(forwNode);
	else
		forwNode->next = delNode->next;//¹Ù·Î ¾Õ ³ëµåÀÇ ´ÙÀ½ ³ëµå´Â ÀÌÁ¦ »èÁ¦ÇÒ ³ëµåÀÇ ´ÙÀ½ ³ëµå			
	free(delNode);//free ½ÇÇà ÀÌÈÄ¿¡´Â ÇØ´ç ³ëµå ÀÚ¸®¿¡ ¾²·¹±â °ª ÀúÀå
}

void printValue(Node* priNode) {//³ëµå ÇöÀç °ª Ãâ·Â
	printf("³ëµå %cÀÇ °ªÀº %d\n",priNode->name, priNode->value);
}
void printHead() {//Çìµå Æ÷ÀÎÅÍ°¡ °¡¸®Å°´Â °ª Ãâ·Â
	printf("Çìµå Æ÷ÀÎÅÍ°¡ °¡¸®Å°´Â °÷ÀÇ ÀÌ¸§Àº %c\n", head->name);
}
void printOrder() {//³ëµå ¼ø¼­ Ãâ·Â
	Node* nowNode = head->next;//ÇöÀç ³ëµå ÀúÀå, °è¼Ó ¹Ù²ñ. 
							   //Çìµå Æ÷ÀÎÅÍ°¡ °¡¸®Å°´Â °÷ÀÌ Ã³À½ Ç¥½ÃÇÒ ³ëµå ÁÖ¼Ò
	Node* nextNode = nowNode->next;//´ÙÀ½ ³ëµå ÀúÀå, °è¼Ó ¹Ù²ñ.
	printf("³ëµåÀÇ ¼ø¼­´Â:");
	printf("%c - ", head->name);//Çìµå Æ÷ÀÎÅÍ°¡ °¡¸®Å°´Â ³ëµå Ãâ·Â

	while (nowNode != nextNode){		
		printf("%c - ", nowNode->name);
		nowNode = nowNode->next;//´ÙÀ½ ³ëµå ÁÖ¼Ò¸¦ nowNode º¯¼ö¿¡ ÀúÀå
		nextNode = nowNode->next;//´Ù´ÙÀ½ ³ëµå ÁÖ¼Ò¸¦ nextNode º¯¼ö¿¡ ÀúÀå
	}
	printf("%c Á¾·á\n", nowNode->name);//¸¶Áö¸· ³ëµå ÀÌ¸§ Ãâ·Â
}

int main()
{
	//NULL ¾øÀÌ ¼±¾ðÇÏ¸é ÃÊ±âÈ­µÇÁö ¾ÊÀº Áö¿ªº¯¼ö ¿À·ù ¹ß»ý
	init();//Çìµå Æ÷ÀÎÅÍ »ý¼º
	Node* Aptr = (Node*)malloc(sizeof(Node));//mallocÀº voidÇü Æ÷ÀÎÅÍ¸¦ ¸®ÅÏÇÏ¹Ç·Î mallocÀÌ ¸®ÅÏÇÑ Æ÷ÀÎÅÍ¸¦ NodeÇü Æ÷ÀÎÅÍ·Î Ä³½ºÆÃ
	Node* Bptr = (Node*)malloc(sizeof(Node));//mallocÀ¸·Î ±¸Á¶Ã¼ ¸¸µé ½Ã ³»ºÎ¿¡ ¾²·¹±â°ª »ý¼º->¹Ù·Î ÃÊ±âÈ­ ÇÊ¿ä
	Node* Cptr = (Node*)malloc(sizeof(Node));
	Node* Dptr = (Node*)malloc(sizeof(Node));
	allocNode(Dptr, 31, 'D');
	Node* Eptr = (Node*)malloc(sizeof(Node));
	allocNode(Eptr, 53, 'E');
	Node* NodeList[3] = {Aptr, Bptr, Cptr};
	char nameList[3] = { 'A', 'B', 'C' };
	int valList[3] = { 5, 12, 13 };
	for (int i = 0; i < 3; i++)
		allocNode(NodeList[i], valList[i], nameList[i]);//³ëµå »ý¼º
	printValue(Aptr);
	printValue(Bptr);
	printValue(Cptr);
	insertNode(NULL, Aptr);//³ëµå »ðÀÔ
	for (int j = 0; j < sizeof(NodeList) / sizeof(Node*) - 1;j++)
		insertNode(NodeList[j], NodeList[j + 1]);
	printHead();
	printOrder();
	insertNode(Aptr, Dptr);
	insertNode(Cptr, Eptr);
	printValue(Eptr);
	printValue(Dptr);
	printOrder();
	deleteNode(Cptr, Eptr);
	printOrder();
	
}
�

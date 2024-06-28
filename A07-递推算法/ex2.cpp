#include<iostream>
#include<cstdio>
using namespace std;

char codeGroup[10][10] = {" ", " ", "ABC","DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}; // 转码表 
int groupLen[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4}; // 转码表中每一项组合的长度 

void transcode(int *teleNumber, int *codePos, int index, int n) {
	printf("START transcode(%p, %p, index:%d, n:%d)\n", teleNumber, codePos, index, n);
	if(index == n) { // 已处理到最后一位 
		for(int i = 0; i < n; i++) {
			printf("PRINT %d -> %c[%d][%d] ", teleNumber[i], codeGroup[teleNumber[i]][codePos[i]], teleNumber[i], codePos[i]);
		}
		printf("\n");
		printf("RETURN transcode(%p, %p, index:%d, n:%d)\n", teleNumber, codePos, index, n);
		return;
	}
	for(int i = 0; i < groupLen[teleNumber[index]]; i++) {
		printf("codePos[%d]=%d\n", index, i);
		codePos[index] = i;
		transcode(teleNumber, codePos, index + 1, n);
	}
	if(groupLen[teleNumber[index]] == 0) {
		printf("codePos[%d]=%d\n", index, 0);
		codePos[index] = 0;
		transcode(teleNumber, codePos, index + 1, n);
	}
	printf("RETURN transcode(%p, %p, index:%d, n:%d)\n", teleNumber, codePos, index, n);
}

int main() {
	int teleLen; //输入号码的长度 
	int teleNumber[11]; // 存储输入号码，长度不超过11位 
	/*
	//
		codePos即每一位输入号码在转码表中对应的字母索引，
		例如：teleNumber[0]=2，查字母表得到字母串ABC，那么codePos[0] = 0/1/2；
		同理，teleNumber[1]=3，查字母表得到字母串DEF，codePos[1] = 0/1/2。 
	*/
	int codePos[11] = {0};  
	scanf("%d", &teleLen);
	if (teleLen > 11) {
		printf("电话号码长度不能超过 11。\n");
		return 1;
	}
	for(int i = 0; i < teleLen; i++) {
		scanf("%d", teleNumber+i); // 原代码有误，scanf("%d", teleNumber[i]); 
	}
	transcode(teleNumber, codePos, 0, teleLen); //
	return 0;
}


/*
2 2 3

START transcode(000000000071fd90, 000000000071fdc0, index:0, n:2)
codePos[0]=0
    START transcode(000000000071fd90, 000000000071fdc0, index:1, n:2)
    codePos[1]=0
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> A[2][0] PRINT 3 -> D[3][0]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    codePos[1]=1
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> A[2][0] PRINT 3 -> E[3][1]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    codePos[1]=2
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> A[2][0] PRINT 3 -> F[3][2]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    RETURN transcode(000000000071fd90, 000000000071fdc0, index:1, n:2)
codePos[0]=1
    START transcode(000000000071fd90, 000000000071fdc0, index:1, n:2)
    codePos[1]=0
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> B[2][1] PRINT 3 -> D[3][0]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    codePos[1]=1
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> B[2][1] PRINT 3 -> E[3][1]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    codePos[1]=2
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> B[2][1] PRINT 3 -> F[3][2]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    RETURN transcode(000000000071fd90, 000000000071fdc0, index:1, n:2)
codePos[0]=2
    START transcode(000000000071fd90, 000000000071fdc0, index:1, n:2)
    codePos[1]=0
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> C[2][2] PRINT 3 -> D[3][0]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    codePos[1]=1
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> C[2][2] PRINT 3 -> E[3][1]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    codePos[1]=2
        START transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
        PRINT 2 -> C[2][2] PRINT 3 -> F[3][2]
        RETURN transcode(000000000071fd90, 000000000071fdc0, index:2, n:2)
    RETURN transcode(000000000071fd90, 000000000071fdc0, index:1, n:2)
RETURN transcode(000000000071fd90, 000000000071fdc0, index:0, n:2)
*/



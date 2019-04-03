/*
1518.蚂蚁下桥 (10分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
n只蚂蚁在长为L的桥上爬行，速度是1.  知道每只蚂蚁的初始xi坐标，不知道其朝向。 桥很细，只能容许一只蚂蚁通行，两只蚂蚁碰头后，会各自回头。问所有蚂蚁最早和最迟下桥的时间。
输入描述
第一行是桥的长度L和蚂蚁个数n
随后n行是n只蚂蚁的坐标

限制: 1<=L,n<=1000000,  0<=xi<=L

输出描述
一行输出，最早和最迟的下桥时间

输入样例
10 3
2
6
7

输出样例
4 8
*/ 

/*
开始的时候一直在 纠结 "不知其朝向"  和 “两只蚂蚁碰头后，会各自回头”
感觉这个题目好复杂啊  要是有很多很多的蚂蚁 这要是碰头得多麻烦

解答：
当A蚂蚁碰到B蚂蚁的时候 ，各自回头 ，A到回头走 B也到回头走 --> A B都不回头，还是按照原来的方向走下去
A 走了 B应该走的 ，B走了A应该走的路   根本没什么差别 ..... 
*/ 
#include <stdio.h>
#include <algorithm>
#define MAXN 1000001
using namespace std;

int d[MAXN];
int main(){
	int L, n;
	int minn = 0;
	int maxx = 0;
	scanf("%d%d", &L, &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &d[i]);
		minn = max(minn, min(d[i], L-d[i]));
		maxx = max(maxx, max(d[i], L-d[i]));
	}
	printf("%d %d\n", minn, maxx);
	
	return 0;
}

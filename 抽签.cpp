/*
 1517.抽签 (10分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：

 你的朋友提议玩一个游戏：将写有数字的n个纸片放入口袋中．你可以从口袋中抽取4次纸片，每次记下纸片上的数字后都将其放回口袋中如果这4个数字的和是m， 就是你赢，否则就是你的朋友赢。 你挑战了好几回，结果一次也没赢过，于是怒而撕破口袋，取出所有纸片，检查自己是否真的有赢的可能性。请你编写一个程序，判断当纸片上所写的数字是k1，k2，…，kn时，是否存在抽取4次和为m的方案。如果存在，输出YES；否则，输出NO.

输入描述

第一行输入两个整数n,m,
随后n行是n个整数 k1,k2,..kn

已知1≤n ≤ 1000;   1 ≤ m ≤ 10^8;   1 ≤ Ki ≤ 10^8


输出描述

根据题意输出YES或者NO


输入样例

3 10
1
3
5             

3 9
1
3
5

输出样例

YES


NO
*/ 
/*
就是感觉解法还是挺秒的    反正我最开始一看到就是想dfs....有毒 
*/ 
#include <stdio.h>
#include <algorithm>
#define MAXN 1001
using namespace std;

int k[MAXN], kk[MAXN*MAXN];
bool binarySearch(int *a, int n, int x){
	int r = n - 1, l = 0;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(a[mid] == x) return true;
		if(a[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	return false;
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &k[i]);
	}
	sort(k, k+n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			kk[i*n+j] = k[i] + k[j];  // (n-1)*n+n-1 = n*n - 1  最后一个数的下标 
		}
	}

	bool flag = false;
	for(int i = 0; i < n; i++){
		if(k[i] >= m) break;
		if(flag) break;
		for(int j = 0; j < n; j++){
			if(flag) break;
			if(k[i] + k[j] >= m) break;
			if(binarySearch(kk, n*n, (m-k[i]-k[j]))){
				flag = true;
				break;
			}
		}
	}
	if(flag){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}

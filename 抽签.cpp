/*
 1517.��ǩ (10��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�

 �������������һ����Ϸ����д�����ֵ�n��ֽƬ����ڴ��У�����Դӿڴ��г�ȡ4��ֽƬ��ÿ�μ���ֽƬ�ϵ����ֺ󶼽���Żؿڴ��������4�����ֵĺ���m�� ������Ӯ����������������Ӯ�� ����ս�˺ü��أ����һ��ҲûӮ��������ŭ��˺�ƿڴ���ȡ������ֽƬ������Լ��Ƿ������Ӯ�Ŀ����ԡ������дһ�������жϵ�ֽƬ����д��������k1��k2������knʱ���Ƿ���ڳ�ȡ4�κ�Ϊm�ķ�����������ڣ����YES���������NO.

��������

��һ��������������n,m,
���n����n������ k1,k2,..kn

��֪1��n �� 1000;   1 �� m �� 10^8;   1 �� Ki �� 10^8


�������

�����������YES����NO


��������

3 10
1
3
5             

3 9
1
3
5

�������

YES


NO
*/ 
/*
���Ǹо��ⷨ����ͦ���    �������ʼһ����������dfs....�ж� 
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
			kk[i*n+j] = k[i] + k[j];  // (n-1)*n+n-1 = n*n - 1  ���һ�������±� 
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

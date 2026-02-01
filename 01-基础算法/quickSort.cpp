第k个数
	#include<iostream>
	//给定一个长度为 n 的整数数列，以及一个整数 k ，请用快速选择算法求出数列从小到大排序后的第 k 个数。
	using namespace std;
	const int N =10010; 
	int n,k;//n是数组数量，k是要查询的数 
	int q[N];//需要排列的数组
	int quicksort(int q[],int l,int r,int k){
		if(l == r) return q[l]; //查找成功
		//临界点
		int x = q[l],i = l-1,j = r+1;
		//先排序
		while(i < j){
			do i++; while(q[i] < x);
			do j -- ; while(q[j] > x);
			if(i < j){
				//交换
				int temp = q[i];
				q[i] = q[j];
				q[j] = temp;
			}
		}
		//后递归 
		int sl = j - l + 1;
		if(k <= sl) return quicksort(q,l,j,k);
		else return quicksort(q,j+1,r,k - sl);
	} 
	int main(){
		cin>>n>>k;//输入 
		for(int i = 0; i < n; i++) cin>>q[i];
		
		cout << quicksort(q,0,n-1,k);
		return 0;
	}

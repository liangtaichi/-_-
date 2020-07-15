#include <stdlib.h> 
#include<stdio.h>
int num[20];
int n;
int nm[20]; 

void swap(int *nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void quickSort(int *nums, int len, int l, int r) {
	if (l >= r || l < 0 || r >= len) {
		return;
	}
	
	int start = l;
	int privot = nums[l++];
	int end = r;
	while (l < r){
		while (l < r && nums[l] <= privot) {
			l++;
		}
		while (l < r && nums[r] > privot) {
			r--;
		}
		swap(nums, l, r);
	}
	if (nums[l] > privot) {
		l--;
	}
	swap(nums, start, l);
	quickSort(nums, len, start, l - 1);
	quickSort(nums, len, l + 1, end);

}

void sort(int *nums, int len) {
	quickSort(nums, len, 0, len - 1);
}

double FCFS(){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += abs(num[i+1] - num[i]) ;
	}
	return (double)sum/(double)n;
}

int near(int a , int b , int target){
	if (abs(target - nm[a]) > (abs(target - nm[b]))){
		return b;
	}else{
		return a;
	}
}

double SSTF() {
	int p = 0;
	int temp;
	for(int i = 0; i <= n;i++){
		nm[i] = num[i];
	}
	sort(nm,n+1);
	int sum = 0, cnt = 1;
	int a = 100;
	int low,high;
	while(1){
	 	if(nm[p] == 100){
	 		break;
		}else{
		 	p++;
		}
	}
		if(p != 0){
		low = p - 1;
	}else{
		low = p;
	}
	if(p != 9){
		high = p + 1; 
	} else{
		high = p;
	}
	while(low!=0&&high!=9){
		if(low != 0 || high != 9){
			temp = near(high , low , p);
			sum += abs(nm[p] - nm[temp]);
			if(temp == low){
				p = temp;
				if(temp == 0){
					low = high; 
				}else{
					low = temp - 1;
				}
			}else{
				p = temp;
				if(temp == 9){
					high = low;
				}else{
					high = temp + 1;
				}
			}
		}else if(low == 0&&high != 9){
			if(p == low+1){
				temp = low;
				sum += abs(nm[p] - nm[temp]);
				high += 1;
				p = temp;
			}else{
				temp = high;
				sum += abs(nm[p] - nm[temp]);
				high += 1;
				p = temp;
			}
		}else if(high == 9 && low != 0){
			if(p == high - 1){
				temp = high;
				sum += abs(nm[p] - nm[temp]);
				low -= 1;
				p = temp;
			}else{
				temp = low;
				sum += abs(nm[p] - nm[temp]);
				low -= 1;
				p = temp;
			}
		}
	}
	return (double)sum/(double)n;
}
/*
*0-up ,1 -down
*/
double SCAN(int state){
	for(int i = 0; i <= n; i++){
		nm[i] = num[i];
	}
	sort(nm,n+1);
	int sum = 0;
	int p = 0;
	int temp;
	int low,high;
	while(1){
	 	if(nm[p] == 100){
	 		break;
		}else{
		 	p++;
		}
	}
	low = p - 1;
	high = p + 1;
	if(state = 0){
		while(1){
			if(high != 9){
				temp = high;
				sum += abs(nm[p] - nm[temp]);
				high += 1;
				p = temp;			
			}else{
				if(high == 9 && p == high -1){
					temp = high;
					sum += abs(nm[p] - nm[temp]);
					p = temp;
				}else{
					temp = low;
					sum += abs(nm[p] - nm[temp]);
					low -= 1;
					p = temp;
					if(p == 0){
						break;
					}
				}
			}
		}
	}else{
		while(1){
			if(low != 0){
				temp = low;
				sum += abs(nm[p] - nm[temp]);
				low -= 1;
				p = temp;			
			}else{
				if(low == 0 && p == low +1){
					temp = low;
					sum += abs(nm[p] - nm[temp]);
					p = temp;
				}else{
					temp = high;
					sum += abs(nm[p] - nm[temp]);
					high += 1;
					p = temp;
					if(p == 9){
						break;
					}
				}
			}
		}		
	}
	return (double)sum/(double)n;
}
 
double CSAN(){
	for(int i = 0; i <= n; i++){
		nm[i] = num[i];
	}
	sort(nm,n+1);
	int sum = 0;
	int p = 0;
	int temp;
	int low,high;
	while(1){
	 	if(nm[p] == 100){
	 		break;
		}else{
		 	p++;
		}
	}
	temp = p;
	while(1){
		sum += abs(nm[p] - nm[p+1]);
		p++;
		if(p == 9){
			break;
		}
	}
	sum += abs(nm[9] - nm[0]);
	p = 0;
	while(1){
		sum += abs(nm[p] - nm[p+1]);
		p++;
		if(p == temp){
			break;
		}
	}
	return (double)sum/(double)n;
} 



int main(){
	num[0] = 100;
	n = 9;
	printf("\t100,");
	for(int i = 1; i<= n; i++){
		num[i] = rand()%201;
		printf("\t%d,",num[i]);
	}
	printf("\n");
	double aveFCFS = FCFS();
	double aveSSTF = SSTF();
	double aveSCAN = SCAN(0);
	double aveCSCAN = CSAN();
	printf("FCFS:%f\n",aveFCFS);
	printf("SSTF:%f\n",aveSSTF);
	printf("SCAN:%f\n",aveSCAN);
	printf("CSCAN:%f\n",aveCSCAN);
    return 0;
}





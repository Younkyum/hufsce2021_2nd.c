#include <stdio.h>

int main() {
	int c;
	scanf("%d", &c); //개수 입력받기
	int num_arr[10000];
	int max_count = 1;
	int count = 1;
	short check = 0;
	for (int i = 0; i < c; i++) { //숫자 배열 입력받기
		scanf("%d", &num_arr[i]);
		if (num_arr[i] == 1) check = 1;
	}
	for (int i = 0; i < c; i++) {
		if (num_arr[i + 1] == 1 && num_arr[i] == 1) { //뒤의 숫자와 같을경우
			count++; //카운트 추가
			check = 1;
			if (count > max_count) {
				max_count = count; //카운트가 맥스카운트보다 클경우 카운트로 변경
			}
		}
		else {
			count = 1; //뒤의 숫자와 같지 않을 경우 카운트 1로 변경
		}
	}
	if (check == 0) max_count = 0;

	printf("%d", max_count);
}
#include <stdio.h>

int main() {
	int count;
	scanf("%d", &count);
	int num_arr[10000]; //입력받는 배열
	int count_arr[10000]; //원소를 각각 나누는 배열
	int counter_arr[10000]; //한 원소의 개수를 나타내는 배열
	int limit_num = (count+1) / 2; //과반수 체크 정수

	for (int i = 0; i < count; i++) { //배열 입력받기
		scanf("%d", &num_arr[i]);
	}

	int b = 0;
	for (int i = 0; i < count; i++) { //count배열에 있는 원소인지 파악하기
		int c = num_arr[i];
		int a = 0;
		int checker;
		for (int j = 0; j < count; j++) { //있는 경우 a에 값 1로 변환
			if (c == count_arr[j]) {
				a = 1;
				checker = j;
			}
		}
		if (a == 1) { //a == 1일경우 counter배열에 개수 1 추가
			counter_arr[checker]++;
		}
		else { //a == 0일경우 count배열에 원소 추가후 couter배열에 1 추가
			count_arr[b] = c;
			counter_arr[b] = 1;
			b++;
		}
	}

	int checker = 0;
	for (int i = 0; i < b; i++) { //counter배열에서 과반수가 넘을경우 같은 위치에 있는 count배열에 있는 원소 출력
		if (counter_arr[i] >= limit_num) {
			printf("%d ", count_arr[i]);
			checker = 1;
		}
	}
	if (checker == 0) { //출력이 이루어지지 않았을 때 -1 출력
		printf("-1");
	}
}
#include <stdio.h>
#include "func.h" 


// 카테고리별 예산을 입력받는 기능. 
void Input_budget(struct Expenditure* exp,char *category_names,int category_count) {
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) { // 음수 제외
			scanf_s("%d", exp->budget[i]);
			if (exp->budget[i] < 0) {
				printf("음수는 저장할 수 없습니다. 다시 입력해 주세요. ");
				continue;
			}
			else {
				break;
			}
		}
	}
	printf("\n");
	// 테스트 
	//for (int i = 0; i < category_count; i++) {
		//printf("%d %d ", i + 1, budget[i]);
	//}
}

void Input_essential_ex(struct Expenditure* exp, char* category_names, int category_count) {
	printf("발생할 필수 지출을 입력해주세요. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) {
			scanf_s("%d", exp->essential_ex[i]);
			if (exp->budget[i] < exp->essential_ex[i]) {
				printf("설정된 예산보다 지출이 더 큽니다. 다시 입력해 주세요. ");
				continue;
			}
			else if (exp->essential_ex[i] < 0) {
				printf("음수는 입력할 수 없습니다. 다시 입력해 주세요. ");
				continue;
			}
			else { // 범위 내의 필수 지출일 때만 저장. 
				exp->budget[i] = exp->budget[i] - exp->essential_ex[i];
				break;
			}
		}
	}
}


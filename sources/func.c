#include <stdio.h>
#include "func.h" 


// ī�װ��� ������ �Է¹޴� ���. 
void Input_budget(struct Expenditure* exp,char *category_names,int category_count) {
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) { // ���� ����
			scanf_s("%d", exp->budget[i]);
			if (exp->budget[i] < 0) {
				printf("������ ������ �� �����ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else {
				break;
			}
		}
	}
	printf("\n");
	// �׽�Ʈ 
	//for (int i = 0; i < category_count; i++) {
		//printf("%d %d ", i + 1, budget[i]);
	//}
}

void Input_essential_ex(struct Expenditure* exp, char* category_names, int category_count) {
	printf("�߻��� �ʼ� ������ �Է����ּ���. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) {
			scanf_s("%d", exp->essential_ex[i]);
			if (exp->budget[i] < exp->essential_ex[i]) {
				printf("������ ���꺸�� ������ �� Ů�ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else if (exp->essential_ex[i] < 0) {
				printf("������ �Է��� �� �����ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else { // ���� ���� �ʼ� ������ ���� ����. 
				exp->budget[i] = exp->budget[i] - exp->essential_ex[i];
				break;
			}
		}
	}
}


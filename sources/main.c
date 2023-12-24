#include <stdio.h>
#include <stdlib.h> // ���� �޸𸮿�
#include <string.h> // strcmp
#include "func.h" 
#include "choice_func.h"

// ���� ���� �ڵ�ȭ ������Ʈ // 


char category_names[50][10] = { "�ĺ�", "���", "�Ƿ�", "����", "����", "��Ȱ", "��ü", "��Ÿ" }; // ī�װ��� �̸��� ������ �迭
int category_count = 7; // ī�װ� ���� ����


int main() {
	// 1. ���� ����. 
	struct Expenditure* exp = (struct Expenditure*)malloc(category_count * sizeof(struct Expenditure));

	// ����� �ʼ� ���� �迭 ���� �Ҵ�. 
	exp->budget = (int*)malloc(category_count * sizeof(int));
	exp->cost = (int*)malloc(category_count * sizeof(int));
	exp->essential_ex = (int*)malloc(category_count * sizeof(int));
	
	// ī�װ��� ���� �߻� ��Ȳ, 
	exp->total_expenditure = (int*)malloc(category_count * sizeof(int));

	// �Ƴ� ������ ����. 
	exp->save_budget = (int*)malloc(category_count * sizeof(int));
	exp->save_percentage = (int*)malloc(category_count * sizeof(int));


	// �޸� �Ҵ� ���� ó�� 
	if (exp->budget == NULL || exp->cost == NULL || exp->essential_ex == NULL || exp->total_expenditure == NULL || exp->save_budget == NULL) {
		printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(EXIT_FAILURE); // ���� 
	}

	// �ʱ�ȭ
	for (int i = 0; i < category_count; i++) {
		exp->total_expenditure[i] = 0;
		exp->cost[i] = 0;
		exp->save_budget[i] = 0;
		exp->save_percentage[i] = 0;
	}
	

	// ī�װ��� ���� �Է¹ޱ�.
	printf("�� ī�װ��� ������ �Ҵ��� �ּ���. \n");
	InputBudget(exp, category_names, category_count);

	// �ʼ� ���� �ݾ� ����. 
	InputEssentialEx(exp, category_names, category_count);


	printf("\n���� �Ҵ��� �Ϸ�Ǿ����ϴ�. \n");
	// ���������ϱ� 
	memcpy(exp->cost, exp->budget, category_count * sizeof(int));

	// �Ҵ� �Ϸ� �׽�Ʈ�� ���
	//for (int i = 0; i < category_count; i++) {
		//printf("%s %d ", category_names[i], exp->cost[i]);
	//}


	// �� �� ���� 
	while (1) {
		int choice;
		printf("���ϴ� ����� ������ �ּ���. (1. ���� �߰�, 2. ī�װ� ����, 3. ����):");
		choice = InputIntOnly();

		if (choice == 1) {
			printf("\n���� �׸��� �߰��մϴ�. \n");
			SaveExpenditure(exp, &category_names, category_count);
		}


		else if (choice == 2) {
			printf("\n���� ī�װ��� �����մϴ�. \n");
			// ī�װ� ��� 
			for (int i = 0; i < category_count; i++) {
				printf("%d %s ", i + 1, category_names[i]);
			}
			EditCategory(exp, &category_names, category_count);
		}


		else if (choice == 3) {
			int save_on = 0; // �� ��� Ȱ��ȭ ���� 
			printf("\n���� �м��� �����ϰڽ��ϱ�? (1. Ȱ��ȭ / 0. ����): ");
			save_on = InputIntOnly();

			if (save_on == 1) {
				Evaludation(exp, &category_names, category_count);
				break;
			}
			else if (save_on == 0) {
				printf("���α׷��� �����մϴ�. \n");
				break;
			}
			else {
				printf("�������� ��� �ּ���. ");
				continue;
			}

			// �޸� �Ҵ� ����, 
			free(exp->budget);
			free(exp->cost);
			free(exp->essential_ex);
			free(exp->total_expenditure);
			free(exp->save_budget);
			free(exp->save_percentage);
			
			break;
		}


		else {
			printf("�־��� �������� ��� �ּ���. \n"); // ������ �̿� ���� ���� 
			continue;
		}
	}
}
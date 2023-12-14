#include <stdio.h>
#include <stdlib.h> // ���� �޸𸮿�
#include <string.h> // strcmp
#include "func.h" 
#include "choice_func.h"

// ���� ���� �ڵ�ȭ ������Ʈ // 


//����
//char category_names[50][10] = { "�ĺ�", "���", "�Ƿ�", "����", "����", "��Ȱ", "��ü", "��Ÿ" }; // ī�װ��� �̸��� ������ �迭
//int category_count = 7; // ī�װ� ���� ����
// �׽�Ʈ��
char category_names[50][10] = { "�ĺ�", "���" };
int category_count = 2;
// ī�װ� ���� �̸��� ���߿� ���� ����� ��� ���� ����ü�� �ִ� �� �õ��غ���

int main() {
	// 1. ���� ����. 
	// ���� ���� ���� �����صα� 
	struct Expenditure* exp = (struct Expenditure*)malloc(category_count * sizeof(struct Expenditure));

	// ����� �ʼ� ���� �迭 ���� �Ҵ�. 
	exp->budget = (int*)malloc(category_count * sizeof(int));
	exp->cost = (int*)malloc(category_count * sizeof(int));
	exp->essential_ex = (int*)malloc(category_count * sizeof(int));

	// ī�װ��� ���� �߻� ��Ȳ, 
	exp->total_expenditure = (int*)malloc(category_count * sizeof(int));


	// �޸� �Ҵ� ���� ó�� 
	if (exp->budget == NULL || exp->cost == NULL || exp->essential_ex == NULL || exp->total_expenditure == NULL) {
		printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(EXIT_FAILURE); // ���� 
	}

	// �ʱ�ȭ
	for (int i = 0; i < category_count; i++) {
		exp->total_expenditure[i] = 0;
		exp->cost[i] = 0;
	}
	

	// ī�װ��� ���� �Է¹ޱ�.
	printf("�� ī�װ��� ������ �Ҵ��� �ּ���. \n");
	Input_budget(exp, category_names, category_count);

	// �ʼ� ���� �ݾ� ����. 
	Input_essential_ex(exp, category_names, category_count);


	printf("���� �Ҵ��� �Ϸ�Ǿ����ϴ�. \n");
	// ���������ϱ� 
	memcpy(exp->cost, exp->budget, category_count * sizeof(int));



	// �Ҵ� �Ϸ� �׽�Ʈ�� ���
	//for (int i = 0; i < category_count; i++) {
		//printf("%s %d ", category_names[i], exp->cost[i]);
	//}


	// �� �� ���� 
	while (1) {
		int choice;
		printf("���ϴ� ����� ������ �ּ���. (1. ���� �߰�, 2. ī�װ� ����, 3. ����): ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			printf("���� �׸��� �߰��մϴ�. \n");
			SaveExpenditure(exp, &category_names, category_count);
		}


		else if (choice == 2) {
			printf("���� ī�װ��� �����մϴ�. \n");
			// ī�װ� ��� 
			for (int i = 0; i < category_count; i++) {
				printf("%d %s ", i + 1, category_names[i]);
			}
			EditCategory(exp, &category_names, category_count);
		}


		else if (choice == 3) {
			printf("���α׷��� �����մϴ�. \n");
			// ���� ��ư�� �����ϴ� ���� ���� ������ ����� �м� ����. 
			// ���� ���� ��� ���� �� ���� ���� ���Ḧ ������ �� �ְ�, �߰��߰��� ���̺��ϵ��� �����ϱ�. 
			Evaludation(exp, &category_names, category_count);



			// �޸� �Ҵ� ����, ���� Ȯ�� �ʿ�. 
			for (int i = 0; i < category_count; i++) {
				free(exp->budget[i]);
				free(exp->cost[i]);
				free(exp->essential_ex[i]);
				free(exp->total_expenditure[i]);
			}
			break;
		}


		else {
			printf("�־��� �������� ��� �ּ���. \n"); // ������ �̿� ���� ���� 
			continue;
		}
	}
}



// 12/15 �޼��� �� �ϼ��ϱ� 
// ������ �Ƴ� ������ ���� �޼��� ��. 


// 22�� ���� ���: ���� ���� ��õ ��� �����ϱ�. 
// �ð� ������ ���� ���(��й�ȣ �Է����� ����) ��� �߰��ϱ�. 
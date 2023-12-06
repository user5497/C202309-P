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
	struct Expenditure* exp = (struct Expenditure*)malloc(category_count * sizeof(struct Expenditure));

	exp->budget = (int*)malloc(category_count*sizeof(int));
	exp->essential_ex= (int*)malloc(category_count * sizeof(int));

	// ī�װ��� ���� �Է¹ޱ�.
	printf("�� ī�װ��� ������ �Ҵ��� �ּ���. \n");
	Input_budget(&exp,&category_names,category_count);

	// �ʼ� ���� �ݾ� ����. 
	Input_essential_ex(&exp, &category_names, category_count);

	printf("���� �Ҵ��� �Ϸ�Ǿ����ϴ�. \n");
	// �Ҵ� �Ϸ� �׽�Ʈ�� ���
	for (int i = 0; i < category_count; i++) {
		printf("%s %d ", category_names[i], exp->budget[i]);
	}

	// �� �� ���� 
	while (1) {
		int choice;
		// ���� ��ư�� �����ϴ� ���� ���� ������ ����� �м� ����. 
		// ���� ���� ��� ���� �� ���� ���� ���Ḧ ������ �� �ְ�, �߰��߰��� ���̺��ϵ��� �����ϱ�. 
		printf("���ϴ� ����� ������ �ּ���. (1. ���� �߰�, 2. ī�װ� ����, 3. ����): ");
		scanf_s("%d", &choice);
		
		if (choice == 1) {
			printf("���� �׸��� �߰��մϴ�. \n");
			SaveExpenditure(&exp, &category_names, category_count);
		}
		

		else if (choice == 2) {
			printf("���� ī�װ��� �����մϴ�. \n");
			// ī�װ� ��� 
			for (int i = 0; i < category_count; i++) {
				printf("%d %s ", i + 1, category_names[i]);
			}
			EditCategory(&exp, &category_names, category_count);
		}


		else if (choice == 3) {
			printf("���α׷��� �����մϴ�. \n");
			// �м��� �����մϴ�. 
			Evaludation(&exp, &category_names, category_count);



			// �޸� �Ҵ� ���� 
			for (int i=0;i<category_count;i++) {
				free(exp->budget[i]);
				free(exp->essential_ex[i]);
			}
			// free(total_expenditure);
			break;
		}


		else {
			printf("�־��� �������� ��� �ּ���. \n"); // ������ �̿� ���� ���� 
			continue;
		}
	}
}




// 12/15 �޼��� �� 
// ������ �Ƴ� ������ ���� �޼��� ��. 

// ���� ���� ��õ ��� �����ϱ�. 

// �̹��ֱ���: ���� �м� ��� - �Һ� �ݾ� ��� ���. 
// �� ���꺰 ��� �ݾװ� �� �Һ���� ����. (�Һ� �ݾ� �Է¹޴� ���. )

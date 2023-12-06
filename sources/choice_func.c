#include "func.h" 

// �ð��� �� ����Ʈ���̶� ����̶� �и��ؼ� �Լ� ���̴� �۾��ϱ�. 

// ī�װ� ���� ���. 
void EditCategory(struct Expenditure* exp, char* category_names, int category_count) {
	while (1) {
		int choice_category;
		printf("(1. ī�װ� ����, 2. ī�װ� ���� ����): ");
		scanf_s("%d", &choice_category);

		if (choice_category == 1) {
			if (category_count == 1) {
				printf("�ּ� �� �� �̻��� ī�װ��� �����ؾ� �մϴ�. "); // ī�װ� ���� ���� ���� 
			}
			else {
				int del_category;
				printf("������ ���ϴ� ī�װ��� ��ȣ�� �������ּ���.\n");
				scanf_s("%d", &del_category);

				// ������ �Ҵ�� ī�װ� ���� ����
				if (exp->budget[del_category] != 0) {
					printf("�ش� ī�װ��� �Ҵ�� ������ �����մϴ�. ");
					break;
				}

				// �迭�� �� ĭ�� ��� ����.
				for (int i = del_category - 1; i < category_count - 1; i++) {
					for (int j = 0; j < 10; j++) {
						// �̰Ź���
						category_names[i][j] = category_names[i + 1][j];
					}
				}
				category_count -= 1;
				printf("������ �Ϸ�Ǿ����ϴ�.\n");
				printf(category_names);
			}
		}
		else if (choice_category == 2) {
			printf("ī�װ� ������ �����մϴ�.\n");
			break;
		}
		else {
			printf("�߸��� �����Դϴ�.\n");
		}
	}
}



// ���� ���� ���. 
void SaveExpenditure(struct Expenditure* exp, char* category_names, int category_count) {
	char* input_cate = (char*)malloc(sizeof(char) * 100); // ���� �߻� ī�װ�
	int valid_cate = 0; // ī�װ� ���� Ȯ�� �뵵
	int input_index = 0; // �Է¹��� ī�װ� ���� ��ġ ����
	int input_expenditure; //�Ͻ��� ���� ����. 


	// ī�װ��� ���� �߻� ��Ȳ, 100������ ����. 
	exp->total_expenditure = (int*)malloc(sizeof(int) * 100);

	printf("������ �߻��� ī�װ��� �Է��� �ּ���. ");
	while (valid_cate != 1) {
		scanf_s("%s", input_cate, (int)sizeof(input_cate));
		for (int i = 0; i < category_count; i++) {
			if (strcmp(input_cate, category_names[i]) == 0) { // strcmp -> 0 ��ġ
				input_index = i; // ī�װ� ��ġ ����. 
				valid_cate = 1;
				break;
			}
		}
		if (valid_cate == 0) { // ���� ī�װ� �Է¹޴� ��� ���� 
			printf("�������� �ʴ� ī�װ��Դϴ�. �ٽ� �Է��� �ּ���.");
			continue;
		}
	}


	// ���� �ݾ� �Է¹ް� �ش� ī�װ� ���꿡�� ���̳ʽ�
	// �߻��ϰ� �ִ� ������ �Ѿ׵� �����ؾ� ��. 
	printf("�߻��� ���� �ݾ��� �Է����ּ���.");
	scanf_s("%d", &input_expenditure);

	exp->total_expenditure[input_index] += input_expenditure; // ī�װ������� �Ѿ� ����
	exp->budget[input_index] -= input_expenditure; // ���꿡�� ���̳ʽ�

	// �׽�Ʈ
	printf("input_expenditure: %d ", input_expenditure);
	printf("budget: %d ", exp->budget[input_index]);



	// �� ���꺰 ��� �ݾװ� �� �Һ���� ����. 
	// �ش� ī�װ� ��� �ݾ� / �� ����
	printf("�ش� ī�װ������� �� ��� �ݾ�:%d / ����: %d", exp->total_expenditure[input_index], exp->budget[input_index]);
	printf("%d�� ���ҽ��ϴ�. ", exp->total_expenditure[input_index] - exp->budget[input_index]);

	free(input_cate);
}



// �� ����� �� ���. 
void Evaludation(struct Expenditure* exp, char* category_names, int category_count) {
	// ������� ���� �Ѿ�� ������ֱ�
}
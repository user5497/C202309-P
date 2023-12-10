#include "func.h" 

// �ð��� �� ����Ʈ���̶� ����̶� �и��ؼ� �Լ� ���̴� �۾��ϱ�. 


// ���� ���� ���. 
void SaveExpenditure(struct Expenditure* exp, char(*category_names)[10], int category_count) {

	char input_cate[10]; // ī�װ� �ִ� ���ڼ� 10
	int valid_cate = 0; // ī�װ� ���� Ȯ�� �뵵
	int input_index = 0; // �Է¹��� ī�װ� ���� ��ġ ����
	int input_expenditure = 0; //�Ͻ��� ���� ����. 


	printf("������ �߻��� ī�װ��� �Է��� �ּ���. ");
	while (valid_cate != 1) {
		scanf_s("%s", &input_cate, (int)sizeof(input_cate));
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



	printf("�߻��� ���� �ݾ��� �Է����ּ���.");
	scanf_s("%d", &input_expenditure);

	// �׽�Ʈ
	printf("input_index %d\n", input_index);
	// ���� 
	// �̻��� ���� ����Ǿ�����. input_index�� ���� ����ǰ�? ��������� �����Ѱ�? 
	printf("total_expenditure %d\n", exp->total_expenditure[input_index]);
	


	// ���� �ʰ� ���, ���� ���� ���. 
	if (exp->total_expenditure[input_index] > exp->budget[input_index]) {
		printf("���� ������ �ʰ��߽��ϴ�. \n");
	}

	exp->total_expenditure[input_index] += input_expenditure; // ī�װ��� ���� �Ѿ� ����
	exp->cost[input_index] -= input_expenditure; // ���꿡�� ���̳ʽ�
	

	// �� ���꺰 ��� �ݾװ� �� �Һ���� ����. 
	// �ش� ī�װ� ��� �ݾ� / �� ����
	// ���� ���� ���� �ʿ伺. 
	printf("�ش� ī�װ������� �� ��� �ݾ�:%d / ����: %d\n", exp->total_expenditure[input_index], exp->budget[input_index]);
	printf("%d�� ���ҽ��ϴ�. ", exp->total_expenditure[input_index] - exp->budget[input_index]);
}


// ī�װ� ���� ���. 
void EditCategory(struct Expenditure* exp, char(*category_names)[10], int category_count) {

	int choice_category = 0; // ������ ����. 
	int del_category = 0; // ������ ī�װ� ����. 

	while (1) {
		printf("(1. ī�װ� ����, 2. ī�װ� ���� ����): ");
		scanf_s("%d", &choice_category);

		// ī�װ� ���� ����. 
		if (choice_category == 1) {

			if (category_count == 1) { // ī�װ� ���� ���� ���� 
				printf("�ּ� �� �� �̻��� ī�װ��� �����ؾ� �մϴ�. ");
				continue;
			}

			printf("������ ���ϴ� ī�װ��� ��ȣ�� �������ּ���.\n");
			scanf_s("%d", &del_category);



			//�׽�Ʈ , 1�� ���� �۵��ϴµ� 2�� �� �޾ƿ�. index ������ ��? 
			printf("budget %d",exp->budget[del_category]);

			// ������ �Ҵ�� ī�װ� ���� ����
			if (exp->budget[del_category] != 0) {
				printf("�ش� ī�װ��� �Ҵ�� ������ �����մϴ�. ");
				continue;
			}



			// ���� ����.
			for (int i = del_category - 1; i < category_count - 1; i++) {
				for (int j = 0; j < 10; j++) {
					category_names[i][j] = category_names[i + 1][j]; // �迭�� �� ĭ�� ��� ����.
				}
			}
			category_count -= 1;

			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			printf(category_names);
		
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




// �� ����� �� ���. 
void Evaludation(struct Expenditure* exp, char(*category_names)[10], int category_count) {
	// ������� ���� �Ѿ�� ������ֱ�
}
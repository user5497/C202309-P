#include <stdio.h>
#include "func.h" 


// �Һ� �ݾ� ���� ���. 
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
	while (1) {
		if ((input_expenditure = InputIntOnly()) < 0) {// ���� ���� 
			printf("������ ������ �� �����ϴ�. �ٽ� �Է��� �ּ���.\n");
		}
		else { // ���� �Է�. 
			break;
		}
	}

	exp->total_expenditure[input_index] += input_expenditure; // ī�װ��� ���� �Ѿ� ����
	exp->cost[input_index] -= input_expenditure; // ���꿡�� ���̳ʽ�

	// ���� �ʰ� ���, ���� ���� ���. 
	if (exp->total_expenditure[input_index] > exp->budget[input_index]) {
		printf("���� ������ �ʰ��߽��ϴ�. \n");
	}


	// �� ���꺰 ��� �ݾװ� �� �Һ�� ����. 
	// �ش� ī�װ� ��� �ݾ� / �� ���� 
	printf("�ش� ī�װ������� �� ��� �ݾ�:%d / ����: %d\n", exp->total_expenditure[input_index], exp->budget[input_index]);
	printf("%d�� ���ҽ��ϴ�. ", exp->cost[input_index]);

}


// ī�װ� ���� ���. 
void EditCategory(struct Expenditure* exp, char(*category_names)[10], int category_count) {

	int choice_category = 0; // ������ ����. 
	int del_category = 0; // ������ ī�װ� ����. 

	while (1) {
		printf("(1. ī�װ� ����, 2. ī�װ� ���� ����): ");
		choice_category = InputIntOnly();

		// ī�װ� ���� ����. 
		if (choice_category == 1) {

			if (category_count == 1) { // ī�װ� ���� ���� ���� 
				printf("�ּ� �� �� �̻��� ī�װ��� �����ؾ� �մϴ�. ");
				continue;
			}

			printf("������ ���ϴ� ī�װ��� ��ȣ�� �������ּ���.(������ �Ҵ���� ���� ī�װ��� ������ �� �ֽ��ϴ�)\n");
			
			del_category = InputIntOnly(); 
			del_category = del_category-1; // �ε��� ����� �� ����. 

			// ������ �Ҵ�� ī�װ� ���� ����
			if (exp->budget[del_category] != 0) {
				printf("�ش� ī�װ��� �Ҵ�� ������ �����մϴ�. \n");
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


// �޼��� ��(���� �м� ���)
void Evaludation(struct Expenditure* exp, char(*category_names)[10], int category_count) {
	
	FILE* file;
	fopen_s(&file,"expenditure.txt", "w"); // 1ȸ�� ���븸 ����.
	if (file == NULL) {
		printf("������ �ۼ��� �� �����ϴ�.\n"); 
		fclose(file);
	}
	

	for (int i = 0; i < category_count; i++) {
		exp->save_budget[i] = exp->budget[i] - exp->total_expenditure[i]; 
		printf("%s������ �� ��� �ݾ�:%d / ����: %d (�����ݾ�: %d)\n", category_names[i], exp->total_expenditure[i], exp->budget[i],exp->save_budget[i]);
		printf("���� �ʼ� ���� �ݾ�: %d\n", exp->essential_ex[i]);
		fprintf(file, "%s������ �� ��� �ݾ�:%d / ����: %d (�����ݾ�: %d)\n", category_names[i], exp->total_expenditure[i], exp->budget[i], exp->save_budget[i]);
		
	
		// percentage ��ġ ����. 
		if (exp->save_budget[i] == 0) { // ��� �ݾװ� ���� ������ ���� ���, 0���� ������ ��� ����. 
			exp->save_percentage[i] = 0;
		}
		else {
			exp->save_percentage[i] = ((float)exp->save_budget[i] / exp->budget[i])*100;
		}


		// ���� �ʰ�,�̸� ���� ���� �Ǵ�. 
		if (exp->save_budget[i] > 0) { // ���� �̸� ����
			printf("%f%% �Ʋ����ϴ�.\n", ((float)exp->save_percentage[i]));
		}
		else if (exp->save_budget[i] < 0) { // ���� �ʰ� ���� 
			printf("%f%% �ʰ��߽��ϴ�.\n", ((float)exp->save_percentage[i]));
		}
		else { // save_budget[i] == 0
			printf("��� ������ ����߽��ϴ�.\n");
		}

		
		// ���� ��õ. 
		if (exp->save_percentage[i] < 0) { // �ʰ�
			if (-150 <= exp->save_percentage[i] && exp->save_percentage[i] <= -100) {
				printf("������ �ʰ��Ͽ� ����ϼ̽��ϴ�.\n");
				printf("���� %f������ ������ �ø� ���� ��õ�մϴ�.\n ", (float)exp->budget[i] * 1.3);
				fprintf(file, "%s�� ������ %f������ �� ���� ��õ�մϴ�. ", category_names[i], (float)exp->budget[i] * 1.3);
			}
			else {
				printf("������ 150%%�ʰ��Ͽ� ����ϼ̽��ϴ�.\n");
				printf("���� %f������ ������ �ø� ���� ��õ�մϴ�.\n ", (float)exp->budget[i] * 1.5);
				fprintf(file, "%s�� ������ %f������ ������ ���� ��õ�մϴ�.\n ", category_names[i], (float)exp->budget[i] * 1.5);
			}
		}
		
		else if (exp->save_percentage[i] > 0) { // �̸� 
			if (exp->save_percentage[i] <= 30) {
				printf("������ 30%% ���ϸ� ����ϼ̽��ϴ�.\n"); // 20% Ȯ�� ��ġ�� ������ ������ ���� �ǰ� 
				printf("���� %f������ ������ ���� ���� ��õ�մϴ�.\n ", (float)exp->budget[i] * 0.5);
				fprintf(file, "%s�� ������ %f������ ������ ���� ��õ�մϴ�. ", category_names[i], (float)exp->budget[i] * 0.5);
			}
			else if (30 < exp->save_percentage[i] && exp->save_percentage[i] <= 60) {
				printf("������ 60%% ���ϸ� ����ϼ̽��ϴ�.\n");
				printf("���� %f������ ������ ���� ���� ��õ�մϴ�.\n ", (float)exp->budget[i] * 0.8);
				fprintf(file, "%s�� ������ %f������ ������ ���� ��õ�մϴ�.\n ", category_names[i], (float)exp->budget[i] * 0.8);
			}
			else if (60 < exp->save_percentage[i] && exp->save_percentage[i] <= 100) {
				printf("60~100%%�� ������ ����ϼ̽��ϴ�. \n");
				printf("���� ��ġ�Դϴ�.\n");
				fprintf(file, "%s�� ������ %f������ ������ ���� ��õ�մϴ�.\n ", category_names[i], (float)exp->budget[i]); // ����
			}
		}

		else { // (exp->total_expenditure[i] == 0)
			printf("������ ������� �����̽��ϴ�.\n");
			fprintf(file, "���� �޿� ������ ������� �����̽��ϴ�.\n");
		}

		printf("\n"); //������
	}
	fclose(file);
}


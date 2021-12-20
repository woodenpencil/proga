#include <stdio.h>
#include <iostream> 
#include <windows.h>
//#include "../StaticLibFunctionality/static_func.h";
#include "..\Functional\plugins_manager.h"

#pragma comment (lib, "functional.lib")//������ �� ����������

bool LANG = true;

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Choose the language\n");
	printf("%s\n", "\"0\", �������");
	printf("%s\n", "\"1\" english");
	scanf_s("%i", &LANG);

	bool menu, choosing;
	int choice;
	menu = true;
	while (menu)
	{
		if (!LANG)
		{
			printf("%s\n", "�������:");
			printf("%s\n", "1: ��������� �������");
			printf("%s\n", "2: ��������� �������");
			printf("%s\n", "3: �������� ���������� � ����������� ��������");
			printf("%s\n", "4: ��������� �������");
			printf("%s\n", "5: �������� �������");
			printf("%s\n", "6: �����");
		}
		else
		{
			//ShowMenu();
			printf("%s\n", "Usage:");
			printf("%s\n", "1: Load plugins");
			printf("%s\n", "2: Unload plugins");
			printf("%s\n", "3: Show info about loaded plugins");
			printf("%s\n", "4: Execute plugins");
			printf("%s\n", "5: Clean console");
			printf("%s\n", "6: Exit");
		}

		choosing = true;

		while (choosing)
		{
			if(!LANG)
			printf("%s", "��� �����: ");
			else
			printf("%s", "Your choice: ");
			scanf_s("%d", &choice);

			switch (choice)
			{
			case 1:
				LoadPlugins(LANG);
				choosing = false;
				break;
			case 2:
				UnloadPlugins(LANG);
				choosing = false;
				break;
			case 3:
				ShowInfo(LANG);
				choosing = false;
				break;
			case 4:
				RunPlugins(LANG);
				choosing = false;
				break;
			case 5:
				system("cls");
				choosing = false;
				break;
			case 6:
				Exit(LANG);
				choosing = false;
				menu = false;
				break;
			default:
				if (!LANG)
					printf("%s\n\n", "������������ �����.");
				else
					printf("%s\n\n", "Incorrect choose.");
				break;
			}
		}
	}

	system("pause>>NUL");
	return 0;
}
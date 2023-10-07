#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	FILE* pf = fopen("C:\\Users\\张艺兴的圈外女友\\source\\repos\\lianxi\\1007\\test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
////输出：空																			
////   fopen: No such file or directory

//int main()
//{
//	FILE* pf = fopen("M:\\myfile.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputs("fopen example", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int ret = fgetc(stdin);
//	printf("%c ", ret);
//	ret = fgetc(stdin);
//	printf("%c ", ret);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("M:\\myfile.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	fputs("hello world", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//int main()
//{
//	char arr[40] = { 0 };
//	FILE* pf = fopen("M:\\myfile.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct MyStruct
//{
//	char c[20];
//	int i;
//	double d;
//};
//int main()
//{
//	struct MyStruct s[2] = { { "abcd",4,9.1 }, {"efg",9,12.23} };
//	FILE* pf = fopen("M:\\myfile.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fwrite(&s, sizeof(struct MyStruct), 2, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct MyStruct
//{
//	char c[20];
//	int i;
//	double d;
//};
//int main()
//{
//	struct MyStruct s[2] = {0};
//	FILE* pf = fopen("M:\\myfile.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fread(&s, sizeof(struct MyStruct), 2, pf);
//	printf("%s,%d,%lf\n", s->c, s->i, s->d);
//	printf("%s,%d,%lf\n", s[1].c,s[1].i,s[1].d);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
////输出：abcd,4,9.100000
////      efg,9,12.230000

//int main()
//{
//	FILE* pf = fopen("M:\\test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	fputs("this     an apple", pf);
//	fseek(pf,6, SEEK_SET);
//	fputs("is", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	long size = 0;
//	FILE* pf = fopen("M:\\test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	fseek(pf, 0, SEEK_END);
//	size = ftell(pf);
//	printf("%ld\n", size);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
////输出：17（this__is_an_apple=4+2+2+5+4）

//int main()
//{
//	FILE* pf = fopen("M:\\test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//t
//	fseek(pf, 1, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//i
//	fseek(pf, 4, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//s
//
//	int ret = ftell(pf);
//	printf("%d\n", ret);//8
//	
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//t
//	fclose(pf);
//
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int c = 0;
//	FILE* pf = fopen("M:\\test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	while ((c = fgetc(pf)) != EOF)
//	{
//		putchar(c);
//	}
//	puts("");
//	if (ferror(pf))
//	{
//		puts("I/O error when reading\n");
//	}
//	else if (feof(pf))
//	{
//		puts("EOF(End Of File) reading successfully\n");
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main()
{
	FILE* pfread = fopen("M:\\test.txt", "r");
	if (pfread == NULL)
	{
		perror("fopen");
		return 1;
	}
	FILE* pfwrite = fopen("M:\\test1.txt", "w");
	if (pfwrite == NULL)
//如果第二个文件（即"M:\text1.txt"）无法打开（例如，由于权限问题或磁盘空间不足），fopen函数将返回NULL
//关闭已经打开的第一个文件,以防止后续代码错误地尝试使用一个已经关闭的文件
	{
		fclose(pfread);
		pfread = NULL;
	}
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF)
//使用fgetc函数从pfread指向的文件中读取一个字符，并将其存储在变量ch中
	{
		fputc(ch, pfwrite);
//将读取的字符写入到pfwrite指向的文件
	}
	if (feof(pfread))
	{
		printf("normal end\n");
	}
	else if (feof(pfread))
	{
		printf("error\n");
	}
	fclose(pfwrite);
	pfwrite = NULL;
	fclose(pfread);
	pfread = NULL;
	return 0;
}
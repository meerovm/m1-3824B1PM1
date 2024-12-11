#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <memory.h>

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void randpoint(int* aa, int n, int min, int max) {
	long long int q = min, w, e, r;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		w = rand();
		e = rand();
		r = rand();
		if (r%2 == 0) {q = abs(((w * e) % max)) + min;}
		else {q = w+min;}
		aa[i] = q;
	}
	qsort(aa, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++) {
		printf("%d ", aa[i]);
	}
	printf("\n");
}

void printtime(int k, double* tt, long long int* oo, int* aa, int v) {
	for (int j = 0; j < k; j++) {
		printf("%lf ", tt[j]);
	}
	printf("\n");
	for (int j = 0; j < k; j++) {
		if (v % 4 == 0) {
			printf("%lf ", (double)((10000 * tt[j]) / (aa[j]) / aa[j]));
		}
		if (v % 4 == 1 or v % 4 == 2) {
			printf("%lf ", (double)(10000 * tt[j]) / (aa[j] * log(aa[j])));
		}
		if (v % 4 == 3) {
			printf("%lf ", (double)(10000 * tt[j]) / (aa[j]));
		}
	}
	printf("\n");

	for (int j = 0; j < k; j++) {
		printf("%lld ", oo[j]);
	}
	printf("\n");
	for (int j = 0; j < k; j++) {
		if (v % 4 == 0) {
			printf("%lf ", (double)((10000 * oo[j]) / aa[j]) / aa[j]);
		}
		if (v % 4 == 1 or v % 4 == 2) {
			printf("%lf ", (double) (oo[j]) / ((aa[j]) * log(aa[j])));
		}
		if (v % 4 == 3) {
			printf("%lf ", (double)(oo[j]) / (aa[j]));
		}
	}
}

void proverka(int n, float* a) {
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) {
			printf("ошибка сортировки");
			break;
		}
	}
}

void randmas(int n, float *a) {
	int q, w, z;
	for (int i = 0; i < n; i++) {
		q = rand();
		w = rand() % 200 + 1;
		z = rand() % 2;
		z = z + z - 1;
		a[i] = z * q + (float) 1.0 / (float) (w);
	}
}

int bubble_sort(int n, float* a) {
	int flag;
	float s;
	for (int i = 1; i < n; i++) {
		flag = 0;
		for (int j = 0; j < (n - i); j++) {
			if (a[j] > a[j + 1]) { 
				s = a[j+1];
				a[j+1] = a[j];
				a[j] = s;
				flag = 1;
			}
		}
		if (flag == 0) {
			return 0;
		}
	}
	return 0;
}

long long int bubble_sort_o(int n, float* a, long long int o) {
	int flag;
	float s;
	for (int i = 1; i < n; i++) {
		flag = 0;
		for (int j = 0; j < (n - i); j++) {
			o += 1;
			if (a[j] > a[j + 1]) {
				s = a[j];
				a[j] = a[j + 1];
				a[j + 1] = s;
				flag = 1;
			}
		}
		o += 1;
		if (flag == 0) {
			return o;
		}
	}
}

int comb_sort(int n, float* a) {
	float s;
	for (int step = (int)(n / 1.27); step > 1; step = (int)(step / 1.27)) {
		for (int j = 0; j < n - step; j++) {
			if (a[j] > a[j + step]) {
				s = a[j + step];
				a[j + step] = a[j];
				a[j] = s;
			}
		}
	}
	buble_sort(n,a);
	return 0;
}

long long int comb_sort_o(int n, float* a, long long int o) {
	float s;
	for (int step = (int)(n / 1.27); step > 1; step = (int)(step / 1.27)) {
		for (int j = 0; j < n - step; j++) {
			o += 1;
			if (a[j] > a[j + step]) {
				s = a[j + step];
				a[j + step] = a[j];
				a[j] = s;
			}
		}
	}
	o = bubble_sort_o(n, a, o);
	return o;
}

void sl(float* a,float* b, int s_1, int s_2, int r) {
	int i = s_1, j = s_2, k = s_1;
	while (i < s_2 && j < s_2 + r) {
		if (a[i] < a[j]) {
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	while (i < s_2) {
		b[k] = a[i];
		k++;
		i++;
	}
	while (j < s_2 + r) {
		b[k] = a[j];
		j++;
		k++;
	}	
}

int merge_sort(int n, float* a) {
	float* b;
	float* c;
	int i, r, k = 0;
	b = (float*)malloc(n * sizeof(double));
	for (r = 1; r < n; r *= 2) {
		for (i = 0; i < n / r - 1; i = i + 2) {
			sl(a, b, i * r, (i + 1) * r, r);
		}
		if ((n - i * r - 1) / r == 1) {
			sl(a, b, n - n % r - r, n - n % r, n % r);
		}
		else {
			for (int j = 0; j < n - i * r; j++) {
				b[j + i * r] = a[j + i * r];
			}
		}
		c = a;
		a = b;
		b = c;
		k += 1;
	}
	if ((k % 2) == 1) {
		for (i = 0; i < n; i++) {
			b[i] = a[i];
		}
		free(a);
	}
	else {
		free(b);
	}
	return 0;
}

long long int sl_o(float* a, float* b, int s_1, int s_2, int r, long long int o) {
	int i = s_1, j = s_2, k = s_1;
	while (i < s_2 && j < s_2 + r) {
		o += 1;
		if (a[i] < a[j]) {
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	while (i < s_2) {
		b[k] = a[i];
		k++;
		i++;
	}
	while (j < s_2 + r) {
		b[k] = a[j];
		j++;
		k++;
	}
	return o;
}

long long int merge_sort_o(int n, float* a, long long int o) {
	float* b;
	float* c;
	int i, r, k = 0;
	b = (float*)malloc(n * sizeof(double));
	for (r = 1; r < n; r *= 2) {
		for (i = 0; i < n / r - 1; i = i + 2) {
			o = sl_o(a, b, i * r, (i + 1) * r, r, o);
		}
		if ((n - i * r - 1) / r == 1) {
			o = sl_o(a, b, n - n % r - r, n - n % r, n % r, o);
		}
		else {
			for (int j = 0; j < n - i * r; j++) {
				b[j + i * r] = a[j + i * r];
			}
		}
		c = a;
		a = b;
		b = c;
		k += 1;
	}
	if ((k % 2) == 1) {
		for (i = 0; i < n; i++) {
			b[i] = a[i];
		}
		free(a);
	}
	else {
		free(b);
	}
	return o;
}

void fcount(unsigned char* a, int strate, int offset, int* count, int n) {
	int t = 0, r = 0;
	memset(count, (int) 0, 256*sizeof(int));
	for (int i = 0; i < n; i++) {
		count[a[i * strate + offset]]++;
	}
	r = count[0];
	count[0] = 0;
	for (int i = 1; i < 256; i++) {
		t = count[i];
		count[i] = count[i - 1] + r;
		r = t;
	}
}

int radix_sort(int n, float* a) {
	float* b;
	float* c;
	int* count;
	int q = 0, f = 0;
	b = (float*)malloc(n * sizeof(float));
	memset(b, 0.0, n*sizeof(float));
	count = (int*)malloc(256 * sizeof(int));
	for (int i = 0; i < sizeof(unsigned int); i++) {
		fcount((unsigned char*)a, sizeof(unsigned int), i, count, n);
		for (int j = 0; j < n; j++) {
			b[count[*(((unsigned char*)a) + j * sizeof(float) + i)]++] = a[j];
		}
		c = a;
		a = b;
		b = c;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 0 && f == 0) {
			q = i;
			f = 1;
		}
		b[i] = a[i];
	}
	for (int i = 0; i < n - q; i++) {
		a[i] = b[n - i - 1];
	}
	for (int i = n - q; i < n; i++) {
		a[i] = b[i - (n - q)];
	}
	free(b);
	free(count);
	return 0;
}

void fcount_o(unsigned char* a, int strate, int offset, int* count, int n, int o) {
	int t = 0, r = 0;
	memset(count, 0, 256*sizeof(int));
	for (int i = 0; i < n; i++) {
		count[a[i * strate + offset]]++;
		o++;
	}
	r = count[0];
	count[0] = 0;
	for (int i = 1; i < 256; i++) {
		t = count[i];
		count[i] = count[i - 1] + r;
		r = t;
		o += 3;
	}
}

long long int radix_sort_o(int n, float* a, long long int o) {
	float* b;
	float* c;
	int* count;
	b = (float*)malloc(n * sizeof(float));
	memset(b, 0, n*sizeof(float));
	count = (int*)malloc(256 * sizeof(int));
	for (int i = 0; i < sizeof(unsigned int); i++) {
		fcount_o((unsigned char*)a, sizeof(unsigned int), i, count, n, o);
		for (int j = 0; j < n; j++) {
			b[count[*(((unsigned char*)a) + j * sizeof(float) + i)]++] = a[j];
			o++;
		}
		c = a;
		a = b;
		b = c;
	}
	free(b);
	free(count);
	return o;
}

clock_t start(int v, int vvvvv, int n, float* a) {
	clock_t s, f, t;
	s = clock();
	if (v % 4 == 0) {
		bubble_sort(n, a);
		if ((vvvvv) == 0) {
			proverka(n, a);
		}
	}
	if (v % 4 == 1) {
		comb_sort(n, a);
		if ((vvvvv) == 0) {
			proverka(n, a);
		}
	}
	if (v % 4 == 2) {
		merge_sort(n, a);
		if ((vvvvv) == 0) {
			proverka(n, a);
		}
	}
	if (v % 4 == 3) {
		radix_sort(n, a);
		if ((vvvvv) == 0) {
			proverka(n, a);
		}
	}
	f = clock();
	t = f - s;
	return t;
}

int main() {
	setlocale(LC_ALL, "RU");
	int n, i, v, vv, vvv, vvvv, vvvvv, vvvvvv, k, max=0, min=0;
	long long int o = 0;
	int* aa;
	long long int* oo;
	float* a;
	float* aaa;
	double* tt;
	clock_t s, f, t;
	printf("если хотите отсортировать пузырьком введите 0, расческой - 1, слиянием - 2, поразрядной - 3 \n");
	scanf_s("%d", &v);
	printf("если хотите получить зависимость сложности сортировки от размера массива, введите - 0, иначе - 1 \n");
	scanf_s("%d", &vvvv);
	if (vvvv != 0) {
		printf("если хотите отсортировать случайный массив введите 0, введенный с клавиатуры - 1 \n");
		scanf_s("%d", &vv);
		printf("если хотите проверить сортировку на корректность - введите 0, иначе - 1 \n");
		scanf_s("%d", &vvvvv);
		printf("если хотите замерить время не выводя массив, введите 0, иначе - 1 \n");
		scanf_s("%d", &vvv);
		printf("введите длину массива \n");
		scanf_s("%d", &n);
		a = (float*)malloc(n * sizeof(float));
		/*ввод массива*/
		if (vv == 0) {
			randmas(n, a);
			if (vvv != 0) {
				for (i = 0; i < n; i++) {
					printf("%f ", a[i]);
				}
				printf("\n");
			}
		}
		else {
			printf("введите массив \n");
			for (i = 0; i < n; i++) {
				scanf_s("%f", &a[i]);
			}
		}
		t = start(v, vvvvv, n, a);
		/*печать массива*/
		if (vvv != 0) {
			for (i = 0; i < n; i++) {
				printf("%f ", a[i]);
			}
			printf("\n");
		}
		printf("%lf", (double)t);
		free(a);
	}
	if (vvvv == 0) {
		printf("введите кол-во точек, для которых исследуется зависимость \n");
		scanf_s("%d", &k);
		aa = (int*)malloc(k * sizeof(int));
		tt = (double*) malloc(k * sizeof(double));
		oo = (long long int*) malloc(k * sizeof(long long int));
		printf("если хотите ввести точки с клавиатуры, введите 0, иначе - 1 \n");
		scanf_s("%d", &vvvvvv);
		if (vvvvvv == 0) {
			printf("введите эти точки \n");
			for (i = 0; i < k; i++) {
				scanf_s("%d", &aa[i]);
			}
		}
		else {
			printf("введите диапазон \n");
			scanf_s("%d %d", &min, &max);
			randpoint(aa, k, min, max);
		}
		/*запуск сортировки для каждой из точек*/
		for (int j = 0; j < k; j++) {
			o = 0;
			n = aa[j];
			a = (float*)malloc(n * sizeof(float));
			aaa = (float*)malloc(n * sizeof(float));
			randmas(n, a);
			memcpy(aaa, a, n*sizeof(float));
			/*запуск сортировки*/
			if (v % 4 == 0) {
				s = clock();
				bubble_sort(n, a);
				f = clock();
				o = bubble_sort_o(n, aaa, o);
			}
			if (v % 4 == 1) {
				s = clock();
				comb_sort(n, a);
				f = clock();
				o = comb_sort_o(n, aaa, o);
			}
			if (v % 4 == 2) {
				s = clock();
				merge_sort(n, a);
				f = clock();
				o = merge_sort_o(n, aaa, o);
			}
			if (v % 4 == 3) {
				s = clock();
				radix_sort(n, a);
				f = clock();
				o = radix_sort_o(n, aaa, o);
			}
			t = f - s;
			tt[j] = (double)t;
			oo[j] = o;
			free(a);
		}
		printtime(k, tt, oo, aa, v);
		free(oo);
		free(aa);
		free(tt);
	}
	return 0;
}

#include <stdio.h>

int main (void) {
	FILE* file = fopen("input", "r");
	int arr[200];
	for(int i = 0; i < 200;i++) {
		fscanf(file, "%d", &arr[i]);
	}

	int res = 0;
	for(int i = 0;i < 200; i++) {
		for(int j = i; j < 200; j++) {
			for(int k = j; k < 200;k++) {
				res = arr[i] + arr[j] + arr[k];
				if(res == 2020) {
					printf("Found a 2020!\n", res);				
					printf("%d, %d, %d\n", arr[i], arr[j], arr[k]);
					printf("Sum = %d\n", arr[i] * arr[j] * arr[k]);
				}
			}
		}
	}

	return 0;

}


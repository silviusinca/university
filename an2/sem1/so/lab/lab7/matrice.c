#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **matriceA, **matriceB;
struct matrice {
	int i, j, dim;
};

void *produs(void *v) {
    struct matrice *arg = v;
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;

    for (int k = 0; k < arg->dim; k++)
        *sum += matriceA[arg->i][k] * matriceB[k][arg->j];

	return sum;
}

int main() {
    int m, n, k=0, dim;
	void *result;

	printf("Matrice A: ");
	scanf("%d %d", &m, &dim);
	matriceA = (int**)malloc(sizeof(int*)*m);
	
    for (int i = 0; i < m; i++) {
		matriceA[i] = (int *)malloc(sizeof(int)*dim);

		for (int j = 0; j < dim; j++) {
			int x;
			scanf("%d", &x);
            matriceA[i][j]=x;
		}
	}

	printf("Matrice B : ");
	scanf("%d %d", &dim, &n);
    matriceB = (int**)malloc(sizeof(int*)*dim);
    
    for (int i=0; i < dim; i++) {
        matriceB[i] = (int *) malloc(sizeof(int)*n);
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            matriceB[i][j]=x;
        }
    }

    pthread_t thr[n*m];
	int rez[m][n];
	for (int i=0; i < m; i++) {
		for (int j = 0; j < n; j++) {
		    struct matrice *arg=(struct matrice*)malloc(sizeof(struct matrice));
            arg->i = i;
            arg->j = j;
            arg->dim = dim;
            // calculam cu cate un thread fiecare element
			if (pthread_create(&thr[k++], NULL, produs, arg)) { 
				perror(NULL);
                return errno;
			}
		}
	}

	k=0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
            // facem join si mai jos echivalam pozitia din matrice cu elementul calculat
            if (pthread_join(thr[k++], &result)) {
				perror(NULL);
				return errno;
			}
			rez[i][j]=*((int*)result);
        }
    }

    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            printf("%d ", rez[i][j]);
        printf("\n");
    }

    return 0;
}

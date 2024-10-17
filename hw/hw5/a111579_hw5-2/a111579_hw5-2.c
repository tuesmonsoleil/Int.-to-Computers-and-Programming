#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

void initVector(Vector* v) {
    v->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    v->size = 0;
    v->capacity = INITIAL_CAPACITY;
}

// increase capacity dynamically
void push_back(Vector* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void pop_back(Vector* v) {
    if (v->size > 0) {
        v->size--;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Vector* vectors = (Vector*)malloc(n * sizeof(Vector));
    for (int i = 0; i < n; i++) {
        initVector(&vectors[i]);
    }

    for (int i = 0; i < m; i++) {
        int op, a;
        scanf("%d %d", &op, &a);
        a--; // Convert to 0-based index

        if (op == 1) {
            int v;
            scanf("%d", &v);
            push_back(&vectors[a], v);
        } else if (op == 2) {
            pop_back(&vectors[a]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vectors[i].size; j++) {
            if (j > 0) printf(" ");
            printf("%d", vectors[i].data[j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(vectors[i].data);
    }
    free(vectors);

    return 0;
}
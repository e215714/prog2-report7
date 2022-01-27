#include <stdio.h>

void swap(int *a, int *b);
void print_array(int array[], int size);
int median(int a, int b, int c);
void quick_sort_descending(int array[], int left, int right);

// 値を交換する
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 値をスペース区切りで出力し最後に改行
void print_array(int array[], int size) {
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 3つの値の中央値を返す
int median(int a, int b, int c) {
    if ((a > b) ^ (a > c)) {
        return a;
    } else if ((b < a) ^ (b < c)) {
        return b;
    } else {
        return c;
    }
}

// intの配列をクイックソートでソートする
void quick_sort_descending(int array[], int left, int right) {
    if (left < right) { // 範囲に2つ以上要素があるか
        int i = left;
        int j = right;

        int pivot = median(array[left], array[(left + right) / 2], array[right]);

        while (1) {
            while (array[i] > pivot) { // pivotより小さいものを見つける
                i++;
            }
            while (pivot > array[j]) { // pivotより大きいものを見つける
                j--;
            }
            if (i >= j) { // インデックスが逆転したらbreak
                break;
            }
            swap(&array[i], &array[j]); // 見つかった要素同士を交換
            i++; // iから左にpivotより大きいものはない
            j--; // jから右にpivotより小さいものはない
        }

        quick_sort_descending(array, left, i - 1); // 左側を再帰的に
        quick_sort_descending(array, j + 1, right); // 右側を再帰的に
    }
}

int main() {
    const int SIZE = 6; //定数として配列のサイズを宣言                          
    int scores[SIZE] = {100, 60, 70, 100, 90, 80};
    printf("scores = ");
    print_array(scores, SIZE);
    quick_sort_descending(scores, 0, SIZE-1);
    printf("result = ");
    print_array(scores, SIZE);
    return 0;
}

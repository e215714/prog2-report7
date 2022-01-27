#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int *a, int *b);
void print_array(int array[], int size);
void selection_sort_descending(int array[], int size);
int median(int a, int b, int c);
void quick_sort_descending(int array[], int left, int right);
void gen_random_arr(int array[], int size);

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

// intの配列を選択ソートでソートする
void selection_sort_descending(int array[], int size) {
    for (int i=0; i<size-1; i++) { // 全要素確認
        int max_ind = i; // iから先での最大の値があるindex, 初期値は今のindex
        for (int j=i+1; j<size; j++) { // iから先を確認
            if (array[max_ind] < array[j]) { // いまの最大より大きいのを見つけたら
                max_ind = j; // 更新
            }
        }
        // ここで最大と今の位置をスワップ
        swap(&array[i], &array[max_ind]);
    }
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

// 配列にランダムな値を設定する
void gen_random_arr(int array[], int size) {
    int random;
    for (int i = 0; i < size; i++) {
        random = rand() % size;
        array[i] = random;
    }
}

int main() {
    int N = 100; // 要素数
    int base[N];
    int work[N];
    double q_time, s_time;
    int QUEUE = 100; // 何回行うか
    clock_t begin, end;
    srand((unsigned)time(NULL));

    for (int i = 0; i < QUEUE; i++) {
        gen_random_arr(base, N);

        printf("\nQUEUE: %d\n", i);
        printf("元の配列の先頭5要素:");
        print_array(base, 5);

        // quick sort
        memcpy(work, base, N*sizeof(base[N]));
        begin = clock();
        quick_sort_descending(work, 0, N-1);
        end = clock();
        q_time += (double)(end - begin);
        printf( "クイックソート: %.3f\n", (double)(end - begin));
        printf("クイックソート処理後:");
        print_array(work, 5);

        // selection sort
        memcpy(work, base, N*sizeof(base[N]));
        begin = clock();
        selection_sort_descending(work, N);
        end = clock();
        s_time += (double)(end - begin);
        printf( "選択ソート: %.3f\n", (double)(end - begin));
        printf("選択ソート処理後:");
        print_array(work, 5);
    }

    q_time = q_time / QUEUE;
    s_time = s_time / QUEUE;

    printf("\n\n");
    printf("キュー数: %d\n要素数: %d\n", QUEUE, N);
    printf("↓平均CPU時間↓\n");
    printf( "クイックソート: %.3f\n", q_time);
    printf( "選択ソート: %.3f\n", s_time);
}
#include <stdio.h>

void swap(int *a, int *b);
void print_array(int array[], int size);
void selection_sort_descending(int array[], int size);

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

int main() {
    const int SIZE = 6; //定数として配列のサイズを宣言                          
    int scores[SIZE] = {100, 60, 70, 100, 90, 80};
    printf("scores = ");
    print_array(scores, SIZE);
    selection_sort_descending(scores, SIZE);
    printf("result = ");
    print_array(scores, SIZE);
    return 0;
}

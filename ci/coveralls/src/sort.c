void _sort(int list[], int size)
{
    int i, j, temp, swap = 1;
    while (swap) {
        swap = 0;
        for (i = (size - 1); i >= 0; i--) {
            for (j = 1; j <= i; j++) {
                if (list[j - 1] > list[j]) {
                    temp = list[j - 1];
                    list[j - 1] = list[j];
                    list[j] = temp;
                    swap = 1;
                }
            }
        }
    }
}


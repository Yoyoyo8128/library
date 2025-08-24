clock_t st; // 計測開始時刻を保存する変数

void nowtime() {
    cout << ((double)(clock()) - (double)(st)) / CLOCKS_PER_SEC << " 秒" << endl;
}

double nowtimed() {
    return ((double)(clock()) - (double)(st)) / CLOCKS_PER_SEC;
}
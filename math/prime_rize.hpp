vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= N; ++p) {
        if (N % p != 0) {
            continue;
        }
        int e = 0;
        while (N % p == 0) {
            ++e;
            N /= p;
        }
        res.emplace_back(p, e);
    }
    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}
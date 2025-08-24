std::random_device seed_gen;
std::mt19937_64 engine(seed_gen());

/*
for (int i = 0; i < 10; ++i) {
    std::uint64_t result = engine();
    std::cout << result << std::endl;
}
*/
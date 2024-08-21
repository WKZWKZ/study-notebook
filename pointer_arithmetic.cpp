#include <iostream>

// 宏定义
#define PRINT_ARRAY(array, n)         \
    for (int idx = 0; idx < n; idx++) \
        std::cout << "array[" << idx << "] = " << array[idx] << std::endl;

int main()
{
    int numbers[4] = {0, 1, 2, 3};
    PRINT_ARRAY(numbers, 4)

    int *p = numbers + 1;
    p++;

    std::cout << "numbers = " << numbers << std::endl;
    std::cout << "p = " << p << std::endl;

    *p = 20;
    *(p - 1) = 10;
    p[1] = 30;

    PRINT_ARRAY(numbers, 4)

    return 0;
}
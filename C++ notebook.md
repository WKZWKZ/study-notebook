

### 未知长度数组

#### 未声明数组长度
根据初始化的值来确定数组长度
```cpp
int num_array[] = {1,2,3,4}
```

#### 数组作为函数参数
传数组地址
```cpp
float array_sum(float values[], size_t length);
float array_sum(float *values, size_t length);
```

### 多维数组

```cpp
int mat[2][3] = {{11, 12, 13}, {14, 15, 16}};

for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
        std::cout << mat[r][c] << " ";
    }
    std::cout << std::endl;
}
```
多维数组在内存中存放顺序为：mat[0][0] mat[0][1] mat[0][2] mat[1][0] mat[1][1] mat[1][2]
因此，二维数组作为函数参数传入是，需要指出列数，否则无法明确每行有多少个元素

#### 二维数组作为函数参数
正确示例
```cpp
void init_2d_array(int mat[][3], size_t rows, size_t cols);
```

错误示例
```cpp
void init_2d_array(int mat[][], size_t rows, size_t cols);
```

### const 数组
```cpp
const float p = 3.14;
p = 1.3;  // 错误，const修饰的变量不可被修改
const float values[4] = {1.1, 2.2, 3.3, 4.4};
values[0] = 5.5;  // 错误，const修饰的数组元素值不可被修改
```

#### const数组常用情况
函数中只需要对数组进行读操作而不需要写操作，防止误操作修改数组的值
```cpp
float array_sum(const float values[], size_t length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        sum += values[i];
        // values[0] = 0;  // error
    }
    return sum;
}

int main() {
    float values[4] = {1.1, 2.2, 3.3, 4.4};
    float sum = array_sum(values, 4);
}
```


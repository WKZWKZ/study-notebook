
## 数组
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

## 字符串
### 数组风格字符串
char类型数组
```cpp
char rabbit[16] = {'P', 'e', 't', 'e', 'r'};
```

求字符串长度函数
size_t strlen(const char *str);
注：字符串长度不等于数组长度
```cpp
#include <cstring>
char rabbit[16] = {'P', 'e', 't', 'e', 'r'};
std::cout << strlen(rabbit);
```

#### 常量字符串
```cpp
char name1[] = "ABCD";  // 字符串长度为4，数组长度为5（末位为0）
char str1[] = "Hello, \0CPP";  // 字符串str1申请内存长度为12

```

#### 其它常用字符串函数

##### copy
char* strcpy(char* dst, const char* src);
char* strncpy(char* dst, const char* src, size_t count);  // safer

##### concatenate
char* strcat(char* dst, const char* src);

##### compare
int strcmp(const char* lefts, const char* rights);


### string类
```cpp
#include <string>

std::string str1 = "Hello";  // 定义string对象
std::string str2 = "CPP";
std::string result = str1 + ", " + str2;  // 字符串连接

result.length();  // 返回字符串长度
str1 < str2;  // 字符串比较
```

## 结构体
```cpp
struct Student {
    char name[4];
    int born;
    bool male;
};
```

## union 联合体
成员共用同一片内存
```cpp
union ipv4address {
    std::uint32_t address32;
    std::uint8_t address8[4];
};
// sizeof(union ipv4address) is 4
```

## enum 枚举类型
```cpp
enum color {
    WHITE,
    BLACK,
    RED,
    GREEN
};

enum color pen_color = RED;
```

## typedef
用于创建类型的别名
```cpp
typedef int myint;
typedef unsigned char vec3b[3];
typedef struct _rgb_struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb_struct;

myint a = 3;

unsigned char color[3];
vec3b color = {255, 0, 255};  // 两者等价

rgb_struct rgb = {0, 255, 128};
```

## 指针



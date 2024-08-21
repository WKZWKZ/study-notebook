
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
指针变量中存的是一个整数，是一个地址

### 结构体指针
```cpp
struct Student
{
    char name[4];
    int born;
    bool male;
};

Student stu = {"Yu", 2000, true};
Student *pStu = &stu;

// 查看指针的值
printf("Address of stu: %p\n", pStu);
std::cout << "Address of stu: " << pStu << std::endl;
```

### 指针的指针
指针变量本质上是一个变量，也有地址，可以通过取地址运算符&，取其地址赋给一个指针变量

### 常指针 const指针
const修饰的指针变量，其指向的内容不能通过指针被修改
```cpp
int num = 1;
int another = 2;

const int *p1 = &num;
*p1 = 3;  // error，不能通过p1修改num的值
num = 3;  // 

int * const p2 = &num;
*p2 = 3;  // 
p2 = &another;  // error，不能修改指针p2的指向
```

#### const指针常用情况
const指针作为函数参数，在函数内部无法通过指针修改其指向的内容
```cpp
int foo(const char *p) {
    // 函数内只能访问p指向内容，而不能修改
    char *p2 = p;
    // 无法将一个const char *的指针赋值给char *类型指针
}
```

### 数组与指针
数组名是数组首元素的地址，可看成一个const指针
```cpp
Student students[128];
Student *p0 = &students[0];
Student *p1 = &students[1];
Student *p2 = &students[2];
Student *p3 = &students[3];
Student *p4 = &students[4];

printf("p0 = %p\n", p0);
printf("p1 = %p\n", p1);
printf("p2 = %p\n", p2);
printf("p3 = %p\n", p3);
printf("p4 = %p\n", p4);
printf("%d\n", sizeof(Student));

printf("&students = %p\n", &students);
printf("students = %p\n", students);
printf("&students[0] = %p\n", &students[0]);
```

### 指针的代数操作
指针加1是指针往后偏移一个元素的位置，而不是一个字节的位置
```cpp
int numbers[4] = {0, 1, 2, 3};
int *p = number + 1;  // p指向1
p++;  // p指向2
```



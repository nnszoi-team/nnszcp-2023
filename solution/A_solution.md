本题为签到题，考察选手基本的程序设计能力。

可以直接模拟，也可以使用下列解法：

- 对于 C/C++：

可使用头文件 `string.h`（对应 C++ 中的 `cstring`）中的 `strstr()` 函数，代码如下：

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char s[110];
    scanf("%s", s);

    if (strstr(s, "nnsz"))
        puts("yes");
    else
        puts("no");

    return 0;
}
```

- 对于 C++：

可使用 `std::string` 类的 `find()` 方法，代码如下：

```cpp
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    bool res = s.find("nnsz") != std::string::npos;
    std::cout << (res ? "yes\n" : "no\n");

    return 0;
}
```

- 对于 Python：

可使用 `in` 关键字，代码如下：

```python
print("yes" if "nnsz" in input() else "no")
```

感兴趣的选手可以向 [彭俊皓123](https://www.luogu.com.cn/user/353893) 了解本题的 KMP 解法，这里不再赘述。

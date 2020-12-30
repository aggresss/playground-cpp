# setjump/longjumps

## 说明

```c
jmp_buf env;
int setjmp(jmp_buf env)
void longjmp(jmp_buf env, int value)
```

C 库宏 int setjmp(jmp_buf environment) ：创建本地的 jmp_buf 缓冲区并且初始化，用于将来跳转回此处。这个子程序保存程序的调用环境于 env 参数所指的缓冲区，env 将被 longjmp 使用。

这个宏可能不只返回一次（通常会返回两次）。第一次，在直接调用它时，它总是返回零。当调用 longjmp 时带有设置的环境信息，这个宏会再次返回，此时它返回的值会传给 longjmp 作为第二个参数。

- 如果是从setjmp直接调用返回，setjmp 返回值为 0
- 如果是从longjmp恢复的程序调用环境返回，setjmp 返回非零值。

---

## C 风格的异常处理机制

与 abort()和exit()相比, goto语句看起来是处理异常的更可行方案。不幸的是，goto是本地的：它只能跳到所在函数内部的标号上，而不能将控制权转移到所在程序的任意地点。
为了解决这个限制，C函数库提供了 setjmp() 和 longjmp() 函数，它们分别承担非局部标号和 goto 作用。头文件 <setjmp.h> 申明了这些函数及同时所需的 jmp_buf 数据类型。

setjmp 被用于包住一个例外处理，类似 try。longjmp 调用类似于 throw 语句，允许一个异常返回给 setjmp 一个异常值。

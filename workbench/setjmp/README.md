# setjump/longjumps

```

```

C 库宏 int setjmp(jmp_buf environment) ：创建本地的 jmp_buf 缓冲区并且初始化，用于将来跳转回此处。这个子程序保存程序的调用环境于 env 参数所指的缓冲区，env 将被 longjmp 使用。

这个宏可能不只返回一次（通常会返回两次）。第一次，在直接调用它时，它总是返回零。当调用 longjmp 时带有设置的环境信息，这个宏会再次返回，此时它返回的值会传给 longjmp 作为第二个参数。

- 如果是从setjmp直接调用返回，setjmp 返回值为 0
- 如果是从longjmp恢复的程序调用环境返回，setjmp 返回非零值。

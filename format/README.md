# Clang-Format

## MRU

```
clang-format -style=llvm -dump-config > .clang-format
clang-format -style=google -dump-config > .clang-format
clang-format -style=chromium -dump-config > .clang-format
clang-format -style=mozilla -dump-config > .clang-format
clang-format -style=webkit -dump-config > .clang-format
clang-format -style=microsoft -dump-config > .clang-format
clang-format -style=gnu -dump-config > .clang-format

clang-format -style=file -fallback-style=llvm --Wno-error=unknown -i *.cpp
```

## Reference

- [https://clang.llvm.org/docs/ClangFormat.html](https://clang.llvm.org/docs/ClangFormat.html)
- [https://clang.llvm.org/docs/ClangFormatStyleOptions.html](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
- [https://code.visualstudio.com/docs/cpp/cpp-ide](https://code.visualstudio.com/docs/cpp/cpp-ide)

## BasedOnStyle

The style used for all options not specifically set in the configuration.

This option is supported only in the clang-format configuration (both within -style='{...}' and the .clang-format file).

Possible values:

- LLVM
- Google
- Chromium
- Mozilla
- WebKit
- Microsoft
- GNU
- InheritParentConfig Not a real style, but allows to use the .clang-format file from the parent directory (or its parent if there is none). If there is no parent file found it falls back to the fallback style, and applies the changes to that.

With this option you can overwrite some parts of your main style for your subdirectories. This is also possible through the command line, e.g.: --style={BasedOnStyle: InheritParentConfig, ColumnLimit: 20}

## Essential Options

- IndentWidth
- ColumnLimit

## GN

GN is a meta-build system that generates build files for Ninja.

You just run gn from the command line. For large projects, GN is versioned and distributed with the source checkout.
- For Chromium and Chromium-based projects, there is a script in depot_tools, which is presumably in your PATH, with this name. The script will find the binary in the source tree containing the current directory and run it.
- For Fuchsia in-tree development, run `fx gn ...` which will find the right GN binary and run it with the given arguments.
- For other projects, see your project's documentation.

## MRU command

```
gn args --list out/Release

ninja -t list

```

### Reference

- https://gn.googlesource.com/gn/
- https://ninja-build.org/
- https://gn.googlesource.com/gn/+/master/docs/language.md
- https://blog.csdn.net/foruok/article/details/70050342
- https://blog.csdn.net/zhangtracy/article/details/79045363

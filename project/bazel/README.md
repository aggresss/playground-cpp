
- [https://bazel.build/](https://bazel.build/)
- [https://bazel.build/start/cpp](https://bazel.build/start/cpp)

```
git_clone https://github.com/bazelbuild/examples
```

```
brew install bazel buildifer
```

```
bazel query //...
bazel build //main:hello-world
./bazel-bin/main/hello-world
bazel clean
```

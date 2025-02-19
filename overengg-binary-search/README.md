Over-engineering Binary Search

```
$ make run1
```

## Development

```
$ cd benchmark
$ mkdir build && cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON
$ make -j$(nproc)
$ sudo make install
```

### Linter and formatter

```
$ sudo apt update
$ sudo apt install -y clang-tidy clang-format
```

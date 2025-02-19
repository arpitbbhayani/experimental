Over-engineering Binary Search
===

Setting up locally requires you setup `google/benchmark` lib
and that can be done by running the following commands.

```
$ cd benchmark
$ mkdir build && cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON
$ make -j$(nproc)
$ sudo make install
```

Once that is run, you can execute the benchmarks across
all approaches using the following command

```
$ make run
```

To make it easy to understand and quantify, I plotted the benchmark
results in a [spreadsheet, take a look](https://docs.google.com/spreadsheets/d/1pczvPGXTjOK7_3qYwfVa0U5XakAdoixIo6IFXQ42oPc/edit?usp=sharing).

## Linter and formatter

```
$ sudo apt update
$ sudo apt install -y clang-tidy clang-format
```

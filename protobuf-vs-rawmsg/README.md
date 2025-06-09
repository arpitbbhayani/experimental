Protobuf vs Raw Message
===

```
$ make generate
$ make benchmark
go test -bench=. -benchmem
goos: linux
goarch: amd64
pkg: protobuf-vs-rawmsg
cpu: AMD Ryzen 9 7950X 16-Core Processor            
BenchmarkProtoMarshal-16        11157592               107.2 ns/op             8 B/op          1 allocs/op
BenchmarkProtoUnmarshal-16       6700785               179.5 ns/op           156 B/op          4 allocs/op
BenchmarkRawMsgMarshal-16       24577530                47.20 ns/op            8 B/op          2 allocs/op
BenchmarkRawMsgUnmarshal-16     15744808                75.76 ns/op           32 B/op          5 allocs/op
PASS
ok      protobuf-vs-rawmsg      5.177s
```

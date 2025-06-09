generate:
	protoc --go_out=. --go-grpc_out=. protos/*.proto

run:
	go test

test:
	go test

benchmark:
	go test -bench=. -benchmem

package main

import (
	"fmt"
	"protobuf-vs-rawmsg/p"
	"protobuf-vs-rawmsg/rawmsg"
	"testing"

	"google.golang.org/protobuf/proto"
)

var msg = &p.Result{
	Response: &p.Result_GETRes{
		GETRes: &p.GETRes{
			Value: "test",
		},
	},
}

var rmmsg = &rawmsg.GETRes{
	Value: "test",
}

func TestCorrectness(t *testing.T) {
	buf, _ := proto.Marshal(msg)
	var m2 p.Result
	proto.Unmarshal(buf, &m2)

	fmt.Println(msg.GetGETRes().GetValue(), m2.GetGETRes().GetValue())

	buf, _ = rawmsg.RMMarshal(rmmsg)
	m3, _ := rawmsg.RMUnmarshal(buf)

	fmt.Println(rmmsg.Value, m3.Value)
}

func BenchmarkProtoMarshal(b *testing.B) {
	for i := 0; i < b.N; i++ {
		proto.Marshal(msg)
	}
}

func BenchmarkProtoUnmarshal(b *testing.B) {
	buf, _ := proto.Marshal(msg)
	for i := 0; i < b.N; i++ {
		var m p.Result
		proto.Unmarshal(buf, &m)
	}
}

func BenchmarkRawMsgMarshal(b *testing.B) {
	for i := 0; i < b.N; i++ {
		rawmsg.RMMarshal(rmmsg)
	}
}

func BenchmarkRawMsgUnmarshal(b *testing.B) {
	buf, _ := rawmsg.RMMarshal(rmmsg)
	for i := 0; i < b.N; i++ {
		rawmsg.RMUnmarshal(buf)
	}
}

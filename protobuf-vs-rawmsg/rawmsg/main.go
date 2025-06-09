package rawmsg

import (
	"bytes"
	"encoding/binary"
	"sync"
)

type MsgType int8

const (
	MsgTypeGETRes MsgType = 1
)

var bufferPool = sync.Pool{
	New: func() interface{} {
		return bytes.NewBuffer(make([]byte, 0, 1024))
	},
}

type GETRes struct {
	Value string
}

func RMMarshal(msg *GETRes) ([]byte, error) {
	buf := bufferPool.Get().(*bytes.Buffer)
	defer bufferPool.Put(buf)

	buf.Reset()
	binary.Write(buf, binary.BigEndian, MsgTypeGETRes)
	binary.Write(buf, binary.BigEndian, uint32(len(msg.Value)))
	buf.WriteString(msg.Value)
	return buf.Bytes(), nil
}

func RMUnmarshal(buf []byte) (*GETRes, error) {
	m := GETRes{}
	b := bufferPool.Get().(*bytes.Buffer)
	defer bufferPool.Put(b)

	b.Reset()
	b.Write(buf)
	var msgType int8
	var length uint32
	var value []byte
	binary.Read(b, binary.BigEndian, &msgType)
	binary.Read(b, binary.BigEndian, &length)
	value = make([]byte, length)
	b.Read(value)
	m.Value = string(value)
	return &m, nil
}

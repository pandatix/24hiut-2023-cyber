package cryptageapi

import (
	"encoding/base64"
	"errors"
)

var (
	Key = []byte{0x4e, 0x65, 0x76, 0x33, 0x72, 0x20, 0x47, 0x30, 0x6e, 0x6e,
		0x34, 0x20, 0x47, 0x31, 0x76, 0x65, 0x20, 0x59, 0x6f, 0xc3,
		0xb9, 0x20, 0x55, 0x70, 0x20, 0x3a, 0x70}
)

func CryptageAPIDecrypt(cph []byte) ([]byte, error) {
	out := make([]byte, base64.StdEncoding.DecodedLen(len(cph)))
	cb64n, err := base64.StdEncoding.Decode(out, cph)
	if err != nil {
		return nil, err
	}
	out = out[:cb64n]

	for i := 0; i < len(out); i++ {
		out[i] = out[i] ^ Key[i%len(Key)]
	}
	return divide(out)
}

func divide(b []byte) ([]byte, error) {
	lb := len(b)
	if lb%2 != 0 {
		return nil, errors.New("odd size")
	}

	out := make([]byte, lb/2)
	for i := 0; i < lb/2; i++ {
		out[i] = b[2*i]
	}
	return out, nil
}

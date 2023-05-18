package cryptageapi

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/sha1"
	"encoding/base64"
	"errors"

	"golang.org/x/crypto/pbkdf2"
)

const (
	Itr = 1 << (2<<2 + 2)
	Slt = `5k!#Z6\./ByEs<`
	Kl  = 7 << 3
)

var (
	K, IV []byte
	Pwd   = [...]byte{70, 106, 76, 34, 117, 109, 75, 74, 41, 97, 52, 67, 113, 98}
)

func init() {
	buf := pbkdf2.Key(Pwd[:], []byte(Slt), Itr, Kl, sha1.New)
	K = buf[:32]
	IV = buf[32:48]
}

var (
	ErrInvalidBlockSize   = errors.New("invalid block size")
	ErrCipherContentEmpty = errors.New("cipher content is empty")
)

func CryptageAPIDecrypt(cph []byte) ([]byte, error) {
	out := make([]byte, 4096)
	cb64n, err := base64.StdEncoding.Decode(out, cph)
	if err != nil {
		return nil, err
	}
	out = out[:cb64n]

	if len(out)%16 != 0 {
		return nil, ErrInvalidBlockSize
	}
	block, err := aes.NewCipher(K)
	if err != nil {
		return nil, err
	}
	mode := cipher.NewCBCDecrypter(block, IV)
	mode.CryptBlocks(out, out)

	if len(out) == 0 {
		return nil, ErrCipherContentEmpty
	}
	lch := int(out[len(out)-1])
	if lch > 0 && lch < 16 {
		out = out[:len(out)-int(lch)]
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

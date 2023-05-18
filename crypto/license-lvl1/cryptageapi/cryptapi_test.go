package cryptageapi_test

import (
	"encoding/base64"
	"encoding/json"
	"fmt"
	"testing"
	"time"

	server "github.com/pandatix/24hinfo-2023/l4/challenges/crypto/license-lvl1"
	"github.com/pandatix/24hinfo-2023/l4/challenges/crypto/license-lvl1/cryptageapi"
	"github.com/stretchr/testify/assert"
)

func TestCryptRound(t *testing.T) {
	t.Parallel()

	assert := assert.New(t)

	p := &server.Proprietes{
		ModeApplication:    server.ModeStandard,
		InitDay:            parseTime("2023-04-13T02:00:00Z"),
		NombreSatellites:   5,
		NombreBases:        32,
		NombreUtilisateurs: 12,
		NombreBatteries:    8,
	}
	b, err := json.Marshal(p)
	if err != nil {
		t.Fatal(err)
	}

	out, err := CryptageAPIEncrypt(b)
	if err != nil {
		t.Fatal(err)
	}

	fmt.Printf("%s\n", out)

	out, err = cryptageapi.CryptageAPIDecrypt(out)
	if err != nil {
		t.Fatal(err)
	}

	po := &server.Proprietes{}
	if err := json.Unmarshal(out, po); err != nil {
		t.Fatal(err)
	}

	assert.Equal(p, po)
}

func parseTime(str string) server.ProprietesTime {
	t, err := time.Parse(time.RFC3339, str)
	if err != nil {
		panic(err)
	}
	return server.ProprietesTime(t)
}

// Just avoid to publish it

func CryptageAPIEncrypt(b []byte) ([]byte, error) {
	b = double(b)

	for i := 0; i < len(b); i++ {
		b[i] = b[i] ^ cryptageapi.Key[i%len(cryptageapi.Key)]
	}

	out := make([]byte, base64.StdEncoding.EncodedLen(len(b)))
	base64.StdEncoding.Encode(out, b)

	return out, nil
}

func double(b []byte) []byte {
	lb := len(b)
	out := make([]byte, lb*2)
	for i := 0; i < lb*2; i += 2 {
		out[i] = b[i/2]
		out[i+1] = '\x00'
	}
	return out
}

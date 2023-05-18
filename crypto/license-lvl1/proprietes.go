package server

import (
	"encoding/json"
	"time"
)

const (
	tfmt = "2006-01-02T15:04:05"
)

type Proprietes struct {
	ModeApplication    ModeApplication `json:"ModeApplication"`
	InitDay            ProprietesTime  `json:"InitDay"`
	NombreSatellites   int             `json:"NombreSatellites"`
	NombreBases        int             `json:"NombreBases"`
	NombreUtilisateurs int             `json:"NombreUtilisateurs"`
	NombreBatteries    int             `json:"NombreBatteries"`
}

type ModeApplication int

var _ json.Marshaler = (*ModeApplication)(nil)
var _ json.Unmarshaler = (*ModeApplication)(nil)

const (
	ModeDemo ModeApplication = iota
	ModeLight
	ModeStandard
)

func (ma ModeApplication) MarshalJSON() ([]byte, error) {
	return map[ModeApplication][]byte{
		ModeDemo:     []byte(`"demo"`),
		ModeLight:    []byte(`"light"`),
		ModeStandard: []byte(`"standard"`),
	}[ma], nil
}

func (ma *ModeApplication) UnmarshalJSON(b []byte) error {
	v := map[string]ModeApplication{
		"demo":     ModeDemo,
		"light":    ModeLight,
		"standard": ModeStandard,
	}[string(b[1:len(b)-1])]
	*ma = v
	return nil
}

type ProprietesTime time.Time

var _ json.Marshaler = (*ProprietesTime)(nil)
var _ json.Unmarshaler = (*ProprietesTime)(nil)

func (pt ProprietesTime) MarshalJSON() ([]byte, error) {
	f := time.Time(pt).Format(tfmt)
	return []byte("\"" + f + "\""), nil
}

func (pt *ProprietesTime) UnmarshalJSON(b []byte) error {
	t, err := time.Parse(tfmt, string(b[1:len(b)-1]))
	if err != nil {
		return err
	}
	*pt = ProprietesTime(t)
	return nil
}

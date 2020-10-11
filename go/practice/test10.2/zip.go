package main

import (
	"archive/zip"
	"os"
)

func init() {
	InitFormats(Format{
		Name:"zip",
		Str:"PK\x03\x04",
		Offset:0,
		List:listZip,
		})
	InitFormats(Format{
		Name:"zip",
		Str:"PK\x05\x06",
		Offset:0,
		List:listZip,
	})
}

func listZip(f *os.File) ([]FileHeader, error) {
	var headers []FileHeader
	r, err := zip.OpenReader(f.Name())
	if err != nil {
		return nil, err
	}
	defer r.Close()
	for _, f := range r.File {
		headers = append(headers,
			FileHeader{Name:f.Name,Size:f.UncompressedSize64})
	}
	return headers, nil
}
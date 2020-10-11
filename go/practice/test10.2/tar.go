package main

import (
	"archive/tar"
	"io"
	"os"
)

func init() {
	InitFormats(Format{Name:"tar",
		Str:"ustar\x0000",Offset:257, List:listTar})
}

func listTar(f *os.File) ([]FileHeader, error) {
	var headers []FileHeader
	tr := tar.NewReader(f)
	for {
		hdr, err := tr.Next()
		if err == io.EOF {
			break
		}
		if err != nil {
			return nil, err
		}
		headers = append(headers, FileHeader{
			Name:hdr.Name,
			Size:uint64(hdr.Size),
		})
	}
	return headers, nil
}
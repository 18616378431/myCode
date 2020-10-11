package main

import (
	"bytes"
	"log"
	"reflect"
	"testing"
)

func TestDecoder_Decode(t *testing.T) {
	type Movie struct {
		Title, Subtitle string
		Year int
	}
	data := Movie {
		Title : "qqq",
		Subtitle : "Subtitle",
		Year : 1964,
	}

	b, err := Marshal(data)
	if err != nil {
		t.Fatalf("Marshal failed : %v", err)
	}
	b = bytes.Repeat(b, 2)

	dec := NewDecoder(bytes.NewReader(b))
	var got []Movie
	for dec.More() {
		var movie Movie
		if err := dec.Decode(&movie); err != nil {
			log.Fatal(err)
		}
		got = append(got, movie)
	}
	want := []Movie{data, data}
	if !reflect.DeepEqual(got, want) {
		t.Errorf("got %v, want %v", got, want)
	}
}
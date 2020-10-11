package main

import (
	"fmt"
	"log"
	"reflect"
	"testing"
)

func TestUnmarshal(t *testing.T) {
	type Movie struct {
		Title, Subtitle string
		Year int
		Actors map[string]string
		Oscars []string
		Sequel *string
	}

	strangelove := Movie{
		Title:    "Dr.StrangeLove",
		Subtitle: "How I",
		Year:     1964,
		Actors: map[string]string{
			"Dr.StrangeLove":           "Peter Seller",
			"Grp.Capt.Lionel Mandrake": "Peter Sellers",
		},
		Oscars: []string{
			"Best Actors",
			"Best Adapted",
			"Best Pictures",
		},
	}

	b, err := Marshal(strangelove)
	if err != nil {
		log.Fatal(err)
	}

	var movie Movie
	if err := Unmarshal(b, &movie); err != nil {
		log.Fatal(err)
	}

	if !reflect.DeepEqual(strangelove, movie) {
		log.Fatal("not equal")
	}

	fmt.Println(string(b))
	fmt.Println(movie)


}
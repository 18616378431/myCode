package main

import (
	"reflect"
	"testing"
)

func TestInterface(t *testing.T) {
	type Movie struct {
		Title, Subtitle string
		Year int
		Color bool
		Actors map[string]string
		Oscars []string
		Sequel *string
		F float64
		//V complex128
		S interface{}
	}

	strangelove := Movie{
		Title:    "Dr.StrangeLove",
		Subtitle: "How I",
		Year:     1964,
		Color:    true,
		Actors: map[string]string{
			"Dr.StrangeLove":           "Peter Seller",
			"Grp.Capt.Lionel Mandrake": "Peter Sellers",
		},
		Oscars: []string{
			"Best Actors",
			"Best Adapted",
			"Best Pictures",
		},
		F : 12.2,
		//V : 1 + 2i,
		S : []int{1, 2, 3},
	}

	InterfaceType["[]int"] = reflect.TypeOf(strangelove.S)

	//b, err := Marshal(strangelove)
	//if err != nil {
	//	log.Fatal(err)
	//}
	//
	//var movie Movie
	//if err := Unmarshal(b, &movie); err != nil {
	//	log.Fatal(err)
	//}
	//
	//if !reflect.DeepEqual(strangelove, movie) {
	//	log.Fatal("not equal")
	//}
	//
	//fmt.Println(string(b))
	//fmt.Println(movie)

	// Encode it
	data, err := Marshal(strangelove)
	if err != nil {
		t.Fatalf("Marshal failed: %v", err)
	}

	// Decode it
	var movie Movie
	if err := Unmarshal(data, &movie); err != nil {
		t.Fatalf("Unmarshal failed: %v", err)
	}

	// Check equality.
	if !reflect.DeepEqual(movie, strangelove) {
		t.Fatal("not equal")
	}

}



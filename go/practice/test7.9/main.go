package main

import (
	"fmt"
	"html/template"
	"log"
	"net/http"
	"os"
	"sort"
	"text/tabwriter"
	"time"
)



func main() {

	http.HandleFunc("/", index)
	log.Fatal(http.ListenAndServe(":8888", nil))
}

type Track struct {
	Title string
	Artist string
	Album string
	Year int
	Length time.Duration
}

func click(t string) {
	switch t {
	case "title":
		sort.Stable(custom{tracks,
			func (x, y *Track) bool {
				return x.Title < y.Title
			},
			func (x, y *Track) {
				x.Title, y.Title = y.Title, x.Title
			}})
	case "artist":
		sort.Stable(custom{tracks,
			func(x, y *Track) bool {
				return x.Artist < y.Artist
			},
			func (x, y *Track) {
				x.Artist, y.Artist = y.Artist, x.Artist
			}})
	case "album":
		sort.Stable(custom{tracks,
			func (x, y *Track) bool {
				return x.Album < y.Album
			},
			func (x, y *Track){
				x.Album, y.Album = y.Album, x.Album
			}})
	case "year":
		sort.Stable(custom{tracks,
			func (x, y *Track) bool {
				return x.Year < y.Year
			},
			func (x, y *Track) {
				x.Year, y.Year = y.Year, x.Year
			}})
	case "length":
		sort.Stable(custom{tracks,
			func (x, y *Track) bool {
				return int64(x.Length) < int64(y.Length)
			},
			func (x, y *Track) {
				x.Length, y.Length = y.Length, x.Length
			}})
	}
}

type custom struct {
	t []*Track
	less func(x, y *Track) bool
	swap func(x, y *Track)
}

func (c custom) Len() int {
	return len(c.t)
}

func (c custom) Less(i, j int) bool {
	return c.less(c.t[i], c.t[j])
}

func (c custom) Swap(i, j int) {
	c.swap(c.t[i], c.t[j])
}

func length(s string) time.Duration {
	d, err := time.ParseDuration(s)
	if err != nil {
		panic(s)
	}
	return d
}

var tracks = []*Track{
	{"Go", "Delilah", "From the Roots Up", 2012, length("3m38s")},
	{"Go", "Moby", "Moby", 1992, length("3m37s")},
	{"Go Ahead", "Alicia Keys", "As I Am", 2007, length("4m36s")},
	{"Ready 2 Go", "Martin Solveig", "Smash", 2011, length("4m24s")},
}

func index(w http.ResponseWriter, r *http.Request) {
	switch r.URL.Path {
	case "/title":
		click("title")
		fmt.Println("====title====")
		printTracks(tracks)
	case "/artist":
		click("artist")
		fmt.Println("====artist====")
		printTracks(tracks)
	case "/album":
		click("album")
		fmt.Println("====album====")
		printTracks(tracks)
	case "/year":
		click("year")
		fmt.Println("====year====")
		printTracks(tracks)
	case "/length":
		click("length")
		fmt.Println("====length====")
		printTracks(tracks)
	default:
		fmt.Println("none")
	}

	tmpl := template.Must(template.ParseFiles("index.html"))
	if err := tmpl.Execute(w, &tracks); err != nil {
		log.Println(err)
	}
}

func printTracks(tracks []*Track) {
	const format = "%v\t%v\t%v\t%v\t%v\t\n"
	tw := new(tabwriter.Writer).Init(os.Stdout, 0, 8, 2, ' ', 0)
	fmt.Fprintf(tw, format, "Title", "Artist", "Album", "Year", "Length")
	fmt.Fprintf(tw, format, "-----", "------", "-----", "----", "------")
	for _, t := range tracks {
		fmt.Fprintf(tw, format, t.Title, t.Artist, t.Album, t.Year, t.Length)
	}
	tw.Flush() // calculate column widths and print table
}


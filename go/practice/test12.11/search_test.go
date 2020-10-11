package main

import "testing"

func TestPack(t *testing.T) {
	type Data struct{
		Labels []string `http:"l"`
		MaxResults int	`http:"max"`
		Exact	bool 	`http:"x"`
	}

	tests := []struct{
		data Data
		want string
	} {
		{Data{MaxResults:10}, "?l=&max=10&x=false"},
	}

	for i, tt := range tests {
		if got := Pack(tt.data); got !=tt.want {
			t.Errorf("%d, got %v, want %v", i, got, tt.want)
		}
	}
}
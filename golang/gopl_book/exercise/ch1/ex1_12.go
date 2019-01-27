package main

import (
	"image"
	"image/color"
	"image/gif"
	"io"
	"log"
	"math"
	"math/rand"
	"net/http"
	"strconv"
)

func main() {
	http.HandleFunc("/", lissajousHandler)
	log.Fatal(http.ListenAndServe("localhost:8080", nil))
}

func lissajousHandler(w http.ResponseWriter, r *http.Request) {
	value := r.URL.Query().Get("cycles")
	cycles, err := strconv.Atoi(value)
	if err != nil {
		cycles = 5
	}
	lissajous(w, float64(cycles))
}

var palette = []color.Color{color.Black, color.RGBA{0x00, 0xff, 0x00, 0xff}}

const (
	greenIndex = 1
	res        = 0.001
	size       = 100
	nframes    = 64
	delay      = 8
)

func lissajous(out io.Writer, cycles float64) {
	freq := rand.Float64() * 3
	anim := gif.GIF{LoopCount: nframes}
	phase := 0.0
	for i := 0; i < nframes; i++ {
		rect := image.Rect(0, 0, 2*size+1, 2*size+1)
		img := image.NewPaletted(rect, palette)
		for t := 0.0; t < cycles*2*math.Pi; t += res {
			x := math.Sin(t)
			y := math.Sin(t*freq + phase)
			img.SetColorIndex(size+int(x*size+0.5), size+int(y*size+0.5), greenIndex)
		}
		phase += 0.1
		anim.Delay = append(anim.Delay, delay)
		anim.Image = append(anim.Image, img)
	}
	gif.EncodeAll(out, &anim)
}

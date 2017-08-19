package main

import (
	"bytes"
	"io/ioutil"
	"math/rand"
	"net/http"
	"strconv"
	"text/template"
	"time"

	"github.com/labstack/echo"
)

type Response struct {
	Environment string
	TenantID    string
	UID         string
}

var (
	tmpl *template.Template
)

func init() {
	tmpl = template.Must(template.ParseFiles("public/tag.js.tmpl.org"))
	rand.Seed(time.Now().UnixNano())
}

func main() {
	e := echo.New()
	e.GET("/", index)
	e.GET("/tag", getTag)

	e.Logger.Fatal(e.Start(":1323"))
}

func index(c echo.Context) error {
	data, err := ioutil.ReadFile("public/index.html")
	if err != nil {
		panic(err)
	}
	return c.HTML(http.StatusOK, string(data))
}

func getTag(c echo.Context) error {
	buf := new(bytes.Buffer)
	res := &Response{"edge", "tenant1", strconv.Itoa(rand.Intn(10))}
	if err := tmpl.Execute(buf, res); err != nil {
		panic(err)
	}
	return c.Blob(http.StatusOK, echo.MIMEApplicationJavaScriptCharsetUTF8, buf.Bytes())
}

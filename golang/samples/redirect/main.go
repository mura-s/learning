package main

import (
	"net/http"

	"github.com/labstack/echo"
)

func main() {
	e := echo.New()
	e.File("/", "index.html")

	e.GET("/redirect", func(c echo.Context) error {
		return c.Redirect(http.StatusSeeOther, "http://127.0.0.1:1323/result")
	})
	//e.GET("/result", func(c echo.Context) error {
	//	return c.String(http.StatusOK, "Hello")
	//})
	e.File("/result", "result.html")

	e.Logger.Fatal(e.Start(":1323"))
}

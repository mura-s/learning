package main

import (
	"net/http"

	"github.com/labstack/echo"
)

type User struct {
	Name  string `json:"name"`
	Email string `json:"email"`
}

func main() {
	e := echo.New()

	e.GET("/", getRoot)
	e.POST("/users", postUser)

	e.Logger.Fatal(e.Start(":1323"))
}
func getRoot(c echo.Context) error {
	return c.String(http.StatusOK, "Hello, World!")
}

func postUser(c echo.Context) (err error) {
	u := new(User)
	if err = c.Bind(u); err != nil {
		return
	}
	return c.JSON(http.StatusOK, u)
}

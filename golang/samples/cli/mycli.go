package main

import (
	"os"

	"github.com/codegangsta/cli"
)

var flags []cli.Flag = []cli.Flag{
	cli.StringFlag{
		Name:  "lang, l",
		Value: "en",
		Usage: "language for the greeting",
	},
}

func action(c *cli.Context) {
	if c.String("lang") == "ja" {
		println("こんにちは")
	} else {
		println("Hello")
	}
}

func main() {
	app := cli.NewApp()
	app.Name = "mycli"
	app.Usage = "mycli sample app"
	app.Flags = flags
	app.Action = action

	app.Run(os.Args)
}

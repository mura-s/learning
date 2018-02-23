package main

import (
	"fmt"
	"os"

	"github.com/tealeg/xlsx"
)

func main() {
	excelFileName := "/Users/a14164/Downloads/【○○株式会社 御中】Daily_Report_20180201 .xlsx"
	xlFile, _ := xlsx.OpenFile(excelFileName)
	detailSheet := xlFile.Sheet["全体詳細"]

	for i, row := range detailSheet.Rows {
		for _, cell := range row.Cells {
			text := cell.String()
			fmt.Printf("%s\t", text)
		}
		fmt.Println()

		if i == 100 {
			os.Exit(0)
		}
	}
}

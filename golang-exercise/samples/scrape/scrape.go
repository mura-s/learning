package main

import (
	"fmt"
	"net/url"

	"github.com/PuerkitoBio/goquery"
)

func main() {
	base := "http://golang.org/"
	doc, _ := goquery.NewDocument(base)
	var result []*url.URL
	doc.Find("a").Each(func(_ int, s *goquery.Selection) {
		target, _ := s.Attr("href")
		base, _ := url.Parse(base)
		targets, _ := url.Parse(target)
		result = append(result, base.ResolveReference(targets))
		fmt.Println(result)
	})

}

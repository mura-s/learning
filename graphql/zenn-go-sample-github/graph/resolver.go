package graph

import "github.com/mura-s/learning/graphql/zenn-go-sample-github/graph/services"

// This file will not be regenerated automatically.
//
// It serves as dependency injection for your app, add any dependencies you require here.

type Resolver struct {
	Srv services.Services
	*Loaders
}

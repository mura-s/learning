package services

import (
	"context"

	"github.com/mura-s/learning/graphql/zenn-go-sample-github/graph/model"
	"github.com/volatiletech/sqlboiler/v4/boil"
)

type Services interface {
	UserService
}

type services struct {
	*userService
}

func New(exec boil.ContextExecutor) Services {
	return &services{
		userService: &userService{exec: exec},
	}
}

type UserService interface {
	GetUserByName(ctx context.Context, name string) (*model.User, error)
}

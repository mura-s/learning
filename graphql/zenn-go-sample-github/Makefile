.PHONY: build
build:
	go build ./server.go

.PHONY: exec
exec:
	./server

.PHONY: run
run:
	go run ./server.go

.PHONY: tidy
tidy:
	go mod tidy

.PHONY: setup-db
setup-db:
	./setup.sh

.PHONY: sqlboiler
sqlboiler:
	sqlboiler sqlite3 -c sqlboider.toml

.PHONY: gqlgen
gqlgen:
	gqlgen generate --config ./gqlgen.yml

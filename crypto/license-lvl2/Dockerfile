# Build stage
FROM golang:1.20.3 AS builder

WORKDIR /go/src
COPY go.mod go.sum ./
RUN go mod download

COPY . .
ENV GOOS=linux
ENV GOARCH=amd64
ENV CGO_ENABLED=0
RUN go build -o /go/bin/license-lvl2 cmd/main.go

# Prod stage
FROM scratch
COPY . /
COPY --from=builder /go/bin/license-lvl2 /license-lvl2

EXPOSE 8080
ENTRYPOINT [ "/license-lvl2" ]

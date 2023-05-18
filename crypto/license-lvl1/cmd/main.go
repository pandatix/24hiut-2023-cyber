package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"os"

	"github.com/gin-gonic/gin"
	server "github.com/pandatix/24hinfo-2023/l4/challenges/crypto/license-lvl1"
	"github.com/pandatix/24hinfo-2023/l4/challenges/crypto/license-lvl1/cryptageapi"
	"github.com/pkg/errors"
	"github.com/urfave/cli/v2"
)

func main() {
	app := &cli.App{
		Name:   "License lvl1",
		Usage:  "License server - lvl1",
		Action: run,
		Flags: []cli.Flag{
			&cli.IntFlag{
				Name:    "port",
				Aliases: []string{"p"},
				EnvVars: []string{"PORT"},
				Usage:   "port to serves on",
				Value:   8080,
			},
		},
		Authors: []*cli.Author{
			{
				Name:  "Lucas TESSON - PandatiX",
				Email: "lucastesson@protonmail.com",
			},
		},
	}
	gin.SetMode(gin.ReleaseMode)

	if err := app.Run(os.Args); err != nil {
		log.Fatal(err)
	}
}

func run(ctx *cli.Context) error {
	router := gin.Default()
	router.StaticFS("/static", http.Dir("static"))
	router.StaticFile("/", "static/index.html")

	router.POST("/license", func(ctx *gin.Context) {
		// Extract JSON
		type Body struct {
			Raw string `json:"raw"`
		}
		var body Body
		if err := ctx.BindJSON(&body); err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{
				"error": err.Error(),
			})
			return
		}

		// Decrypt it
		b, err := cryptageapi.CryptageAPIDecrypt([]byte(body.Raw))
		if err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{
				"error": errors.Wrap(err, "invalid license").Error(),
			})
			return
		}
		var prop server.Proprietes
		if err := json.Unmarshal(b, &prop); err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{
				"error": errors.Wrap(err, "invalid license").Error(),
			})
			return
		}

		// Refuse license if not standard, else give flag
		if prop.ModeApplication < server.ModeStandard {
			ctx.JSON(http.StatusForbidden, gin.H{
				"message": "license does not grant access to standard mode.",
			})
			return
		}

		// Return token
		tk, err := os.ReadFile("flag.txt")
		if err != nil {
			ctx.AbortWithError(http.StatusInternalServerError, err)
		}
		ctx.JSON(http.StatusOK, gin.H{
			"flag": string(tk),
		})
	})

	port := ctx.Int("port")
	fmt.Printf("Listening on port %d\n", port)
	return router.Run(fmt.Sprintf(":%d", port))
}

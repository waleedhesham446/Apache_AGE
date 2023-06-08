package main

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"log"

	_ "github.com/lib/pq"
)

type User struct {
	UserID int    `json:"user_id"`
	Name   string `json:"name"`
	Age    int    `json:"age"`
	Phone  string `json:"phone,omitempty"`
}

type Result struct {
	StatusCode int    `json:"status_code"`
	Data       []User `json:"data"`
}

func main() {
	// Establish a connection to the PostgreSQL database
	connStr := "host=your_host user=your_user password=your_password dbname=your_database sslmode=disable"
	db, err := sql.Open("postgres", connStr)
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()

	// Query the user_table
	rows, err := db.Query("SELECT * FROM public.user_table")
	if err != nil {
		log.Fatal(err)
	}
	defer rows.Close()

	// Create a slice to store the users
	users := []User{}

	// Iterate over the rows and populate the users slice
	for rows.Next() {
		var user User
		err := rows.Scan(&user.UserID, &user.Name, &user.Age, &user.Phone)
		if err != nil {
			log.Fatal(err)
		}
		users = append(users, user)
	}
	if err = rows.Err(); err != nil {
		log.Fatal(err)
	}

	// Create the final JSON result
	result := Result{
		StatusCode: 200,
		Data:       users,
	}

	// Convert the result to JSON
	jsonOutput, err := json.Marshal(result)
	if err != nil {
		log.Fatal(err)
	}

	// Print the JSON output
	fmt.Println(string(jsonOutput))
}

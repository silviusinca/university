const mysql = require("mysql");
const express = require("express");
const bodyParser = require("body-parser");
const cors = require("cors")
 
const app = express();
const port = 3000;
 
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }))
app.use(cors());
 
const connection = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "root1234",
    database: "recipes",
    multipleStatements: true
});
 
connection.connect((err) => {
    if(!err) {
        console.log("Connected to the database")
    } else {
        console.log(`Error: ${err}`);
    }
})
 
//recipes routes
 
// get all recipes
app.get('/recipes', (req, res) => {
    connection.query("SELECT * from recipes", (err, rows, fields) => {
        if(!err) {
            res.send(rows);
        } else {
            console.log(err);
        }
    })
})
 
// get recipes with a given ID
app.get('/recipes/:id', (req, res) => {
    connection.query(`SELECT * from recipes where idrecipes=${req.params.id}`, (err, rows) => {
        if(!err) {
            res.send(rows);
        } else {
            console.log(err);
        }
    })
})
 
// add a new recipe
app.post('/recipes', (req, res) => {
    // console.log(req.body)
    const chef = req.body.chef;
    const cookingTime = req.body.cookingTime;
 
    connection.query("INSERT INTO recipes (chef, cookingTime) VALUES (?, ?)", [chef, cookingTime], (err, data) => {
        if(!err) {
            res.send(data);
        } else {
            console.log(err);
        }
    })
})
 
// update
app.put('/recipes/:id', (req, res) => {
    const chef = req.body.chef;
    const cookingTime = req.body.cookingTime;
 
    connection.query(`UPDATE recipes SET chef="${chef}", cookingTime="${cookingTime}" WHERE idrecipes=${req.params.id}`, (err, data) => {
        if(!err) {
            res.send(data);
        } else {
            console.log(err);
        }
    })
})
 
//delete
app.delete('/recipes/:id', (req, res) => {
    connection.query(`DELETE FROM recipes WHERE idrecipes=${req.params.id}`, (err) => {
        if(err) {
            console.log(err);
        } else {
            res.end();
        }
    })
})
 
app.listen(port, () => console.log(`Server started on port ${port}`));
 
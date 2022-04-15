// let http = require('http');
// const dt = require('./module');

// http.createServer((req, res) => {
//     res.write(`Current path is ${req.url}\n`)
//     res.end("Hello world");
// }).listen(8080);

const express = require('express');
const app = express();

app.get('/', (req, res) => {
    res.send('<b>my</b> first express http server');
});

app.get('/welcome', (req, res) => {
    res.send('<b> yeet </b> some some https');
});

app.use((req, res, next) => {
    res.status(404).send("Sorry, that route doesn't exist. Have a nice day :)")
});

app.listen(3000, () => {
    console.log("example app listening on port 3000.");
});

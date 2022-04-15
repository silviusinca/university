const body = document.getElementsByTagName("body")[0];

fetch('https://jsonplaceholder.typicode.com/todos')
.then(res => console.log(res.json()))
.then(data => console.log(data))
.catch(e => console.warn(e));


/*
const timeInMs = 1000;
const h1Node = document.getElementsByTagName("h1")[0];
const divNode = document.getElementsByTagName("div")[0];
const addBtn = document.getElementById("add");
const removeBtn = document.getElementById("remove");
// id = setTimeout(() => {
//     h1Node.innerHTML = `Added after ${timeInMs}ms`;
// }, timeInMs);
// clearTimeout(id);
setTimeout(() => {console.log("this is the first message")}, 5000);
setTimeout(() => {console.log("this is the second message")}, 3000);
setTimeout(() => {console.log("this is the third message")}, 1000);

const id = setInterval(() => {
    h1Node.innerHTML = `Current date: ${new Date()}`;
}, timeInMs);

setTimeout(() => {
    clearInterval(id);
}, 3000);


userInfo = {user:"user", password:"password"};
i=0;
addBtn.addEventListener("click", () => {
    localStorage.setItem(`animal_${i}`, JSON.stringify(userInfo));
    i++;
});

removeBtn.addEventListener("click", () => {
    localStorage.clear();
});

divNode.innerHTML += `Value in localstorage: ${localStorage.getItem('animal_0')}`

// localStorage.clear();
// document.cookie


h1Node.innerHTML = passRegex.test("parola123$");
*/

const passRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#\$%\^&\*])(?=.{8,})/;
const emailRegex = /(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9]))\.){3}(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])/;
const welcome = document.getElementsByTagName("h1")[0];
const errorText = document.getElementsByTagName("p")[0];
const content = document.getElementById("content");
const inputs = document.getElementsByTagName("input");
const button = document.getElementsByTagName("button")[0];

errorText.style.display = "none";

let email = "";
let pass = "";
let isEmailValid = false;
let isPasswordValid = false;

inputs[0].addEventListener("change", (e) => {
    email = e.target.value;
});

inputs[1].addEventListener("change", (e) => {
    pass = e.target.value;
});

if (localStorage.getItem("email")) { // daca e dif de null
    content.style.display = "none";
} else {
    button.disabled = true;
    content.style.display = "block flex";
    if (emailRegex.test(email) && passRegex.test(pass)) {
        button.disabled = false;
    }

}




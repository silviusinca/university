const bodyNode = document.getElementsByTagName("body")[0];
const divNode = document.getElementById("box");

/*
const buttonNode = document.getElementsByTagName("button")[0];
const inputNode = document.getElementsByTagName("input")[0];
const textPar = document.getElementsByTagName("p")[1];
const selectNode = document.getElementsByTagName("select")[0];
const checkbox = document.getElementById("checked");
const formNode = document.getElementsByTagName("form")[0];

const changeBackgroundColor = (color) => {
    bodyNode.style.backgroundColor = color;
}

const calledFunction = () => {
    changeBackgroundColor("salmon");
}

// buttonNode.addEventListener("click", () => changeBackgroundColor("salmon"));
buttonNode.addEventListener("click", calledFunction);
// buttonNode.addEventListener("click", () => {console.log("called")});
buttonNode.addEventListener("click", (e) => {console.log(e.target)});
// buttonNode.removeEventListener("click", calledFunction);

selectNode.addEventListener("change", (e) => changeBackgroundColor(e.target.value));

inputNode.addEventListener("change", (e) => {
    textPar.innerHTML = e.target.value;
    console.log(e.target);
});

inputNode.addEventListener("focus", () => {
    inputNode.style.backgroundColor = "salmon";
});

inputNode.addEventListener("blur", () => {
    inputNode.style.backgroundColor = "white";
});

checkbox.addEventListener("click", (e) => {
    e.preventDefault();
});
*/

document.addEventListener("click", (e) => {
    console.log(e.pageX, e.pageY);
    divNode.style.marginTop = `${e.clientY}px`;
    divNode.style.marginLeft = `${e.clientX}px`;
});

document.addEventListener("keydown", (key) => {
    console.log("key code: ", key.code);
    switch(key.code) {
        case 'KeyW':
            divNode.style.marginTop = `${parseInt(divNode.style.marginTop.slice(0, -2))-10}px`;
            break;
        case 'KeyS':
            divNode.style.marginTop = `${parseInt(divNode.style.marginTop.slice(0, -2))+10}px`;
            break;
    }
});
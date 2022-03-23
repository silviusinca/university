// const paragraph = document.getElementById("par");
// paragraph.classList.add("boldened");

// const p1 = document.getElementsByClassName("cls")[0];
// p1.style.textDecoration = "underline";

// const paragraphs = document.getElementsByClassName("cls");
// const paragraphs = document.getElementsByTagName("p");

// for (let par of paragraphs) {
//     par.style.textDecoration = "underline";
// }

const newDiv = document.createElement("div");
// newDiv.innerHTML = "<h1>hello??</h1>"
newDiv.style.width = "200px";
newDiv.style.height = "200px";

const newPar = document.createElement("p");
newPar.innerHTML = "Hello sunt un nou paragraf";
newPar.style.color = "green";
newPar.style.textDecoration = "underline";

const bodyNode = document.getElementsByTagName("body")[0];
// bodyNode.appendChild(newDiv);

const scriptNode = document.getElementsByTagName("script")[0];

bodyNode.insertBefore(newDiv, scriptNode);

newDiv.appendChild(newPar);
newDiv.removeChild(newPar);

const imageNode = document.getElementsByTagName("img")[0];
imageNode.src="https://imgs.smoothradio.com/images/224840?width=2480&crop=16_9&signature=T4S67eHJflmFzFEGYBYf8BiOWUs=";
imageNode.style.height = "200px";

const getRandomColor = () => {
    const letters = "0123456789ABCDEF";
    let color = "#";
    for (let i = 0; i < 6; i++) {
        color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}

const newButton = document.createElement("button");
newButton.innerHTML = "Schimba culoarea";
newButton.onclick = () => newDiv.style.backgroundColor = getRandomColor();
bodyNode.insertBefore(newButton, scriptNode);

const mainDiv = document.createElement("div");
mainDiv.style.width = "100vw";
mainDiv.style.height = "100vh";
mainDiv.style.display = "flex";
mainDiv.style.justifyContent = "space-around";

const bodyNode = document.getElementsByTagName("body")[0];
bodyNode.appendChild(mainDiv);

const getRandomTopMargin = (element) => {
    const elementHeight = parseInt(element.style.height);
    const x = Math.floor(Math.random() * (window.innerHeight - elementHeight));
    console.log(x);
    return x;
}

const el1 = document.createElement("div");
el1.innerHTML = "primul div";
el1.style.width = "300px";
el1.style.height = "300px";
el1.style.backgroundColor = "lightgrey";
el1.style.position = "relative";
el1.style.top = String(getRandomTopMargin(el1)) + "px";

const el2 = document.createElement("div");
el2.innerHTML = "al doilea div";
el2.style.width = "300px";
el2.style.height = "300px";
el2.style.backgroundColor = "red";
el2.style.position = "relative";
el2.style.top = String(getRandomTopMargin(el2)) + "px";

const el3 = document.createElement("div");
el3.innerHTML = "al 3lea div";
el3.style.width = "300px";
el3.style.height = "300px";
el3.style.backgroundColor = "green";
el3.style.position = "relative";
el3.style.top = String(getRandomTopMargin(el3)) + "px";

mainDiv.appendChild(el1);
mainDiv.appendChild(el2);
mainDiv.appendChild(el3);

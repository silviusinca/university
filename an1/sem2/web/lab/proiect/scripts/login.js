const clockParagraph = document.createElement("p");
const form = document.getElementsByTagName("form")[0];

form.appendChild(clockParagraph);

getRandomColor = () => {
    let color = "#";
    const hexa = "0123456789ABCDEF"
    for (let i = 0; i < 6; i++) {
        const x = Math.floor(Math.random() * 16);                
        color = color.concat(hexa[x]);
    }
    return color;
};

const clockFun = () => {
    let date = new Date();
    clockParagraph.innerHTML = date;    
    clockParagraph.style.color = getRandomColor();
}

clockFun(); // apeleze functia ca sa imi afiseze ceasul imediat dupa reload
setInterval(clockFun, 1000); // setinterval sa imi updateze ceasul la fiecare secunda








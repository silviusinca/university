console.log("test");

const title = document.getElementById("title-main");
/*
    - fisiere separate
    - selectori id, tag, clasa
    - modificare stiluri, html
    - schimbare valoare aleatoare
    - createelement
    - setinterval
    - events
*/
const setRandomFontSize = () => {
    const values = [2, 2.5, 3, 3.5, 4, 5, 6, 7];
    return values[Math.floor(Math.random() * 8)];
}
try {
    title.style.fontSize = `${setRandomFontSize()}em`;
    console.log(title.style.fontSize);
} catch (err) { console.log("not in index"); }




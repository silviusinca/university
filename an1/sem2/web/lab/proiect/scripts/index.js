console.log("test");

const title = document.getElementById("title-main");
/* TERMINATE:
    - fisiere separate
    - selectori id, tag, clasa
    - modificare stiluri, html
    - schimbare valoare aleatoare
    - createelement
    - setinterval
    - events

    DE FACUT:
        - login/logout cu localstorage
        - text/range/number/radio/select
        - validare regex
        
*/
const setRandomFontSize = () => {
    const values = [2, 2.5, 3, 3.5, 4, 5, 6, 7];
    return values[Math.floor(Math.random() * 8)];
}
try {
    title.style.fontSize = `${setRandomFontSize()}em`;
    console.log(title.style.fontSize);
} catch (err) { console.log("not in index"); }




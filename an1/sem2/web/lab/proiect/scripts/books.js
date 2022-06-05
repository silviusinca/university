const grid = document.getElementsByClassName("grid-content")[0];

const bookList = [
`<figure class="imagine">
    <img src="https://images-na.ssl-images-amazon.com/images/I/41QOsSsYHML._SX329_BO1,204,203,200_.jpg" alt="The Daily Stoic" />
</figure>
<div class="grid-text">
    <span class="category">Philosophy</span>
    <div class="book-title">The Daily Stoic</div>
    <div class="book-author">Ryan Holiday</div>
    <p>Sesame snaps jelly-o topping sweet roll shortbread wafer cake. Cupcake cake biscuit apple pie sweet caramels halvah.</p>
</div>`,
`<figure class="imagine">
    <img src="https://images-na.ssl-images-amazon.com/images/I/4145Q3WAneL._SX331_BO1,204,203,200_.jpg" alt="The Art Of War" />
</figure>
<div class="grid-text">
    <span class="category">Philosophy</span>
    <div class="book-title">The Art Of War</div>
    <div class="book-author">Sun Tzu</div>
    <p>Sesame snaps jelly-o topping sweet roll shortbread wafer cake. Cupcake cake biscuit apple pie sweet caramels halvah.</p>
</div>`,
`<figure class="imagine">
    <img src="https://images-na.ssl-images-amazon.com/images/I/41HB0aS4DwL._SX313_BO1,204,203,200_.jpg" alt="The Communist Manifesto" />
</figure>
<div class="grid-text">
    <span class="category">Philosophy</span>
    <div class="book-title">The Communist Manifesto</div>
    <div class="book-author">Karl Marx</div>
    <p>Sesame snaps jelly-o topping sweet roll shortbread wafer cake. Cupcake cake biscuit apple pie sweet caramels halvah.</p>
</div>`
]; 

let i = 0;
document.addEventListener("keydown", (event) => {
    const books = document.querySelectorAll(".book");
    if (event.key.toLowerCase() == 'a' && books.length < 9) {
        const newBook = document.createElement("div");
        newBook.classList.add("book", "grid-item");
        newBook.innerHTML = bookList[i++];
        grid.appendChild(newBook);
    }
    if (books.length == 8) {
        const rand = document.getElementsByClassName("random")[0];
        rand.innerHTML = "There are no more books to add!";
    }
});


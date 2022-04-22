const innerDisplay = document.getElementsByClassName(
    "display-recipes-inner"
)[0];
const updateRecipesBtn = document.getElementById("update-recipes-button");

const addRecipeBtn = document.getElementById("add-recipe-button");
const addChefInput = document.getElementById("add-chef-input");
const addCookingTimeInput = document.getElementById("add-cooking-time-input");

const updateRecipeBtn = document.getElementById("update-recipe-button");
const updateIdInput = document.getElementById("update-id-input");
const updateChefInput = document.getElementById("update-chef-input");
const updateCookingTimeInput = document.getElementById("update-cooking-time-input");

fetch("http://localhost:3000/recipes/")
    .then((res) => res.json())
    .then((data) => {
        console.log(data);
        clearChildren(innerDisplay);
        displayRecipes(data);
    })
    .catch((err) => console.warn(err));

const clearChildren = (node) => {
    node.innerHTML = "";
};

const deleteRecipe = (id) => {
    fetch(`http://localhost:3000/recipes/${id}`, {
        method: "DELETE",
    });
};

const displayRecipes = (recipes) => {
    for (let recipe of recipes) {
        const {
            idrecipes,
            chef,
            cookingTime
        } = recipe;

        const newDiv = document.createElement("div");
        newDiv.style.display = "flex";
        newDiv.style.flexDirection = "column";
        newDiv.style.alignItems = "center";
        newDiv.style.boxShadow = "10px 10px 25px grey";
        newDiv.style.padding = "8px";
        newDiv.innerHTML = `<h4>Id: ${idrecipes}</h4>
          <p><b>Chief:</b> ${chef}</p>
          <p><b>Cooking time:</b> ${cookingTime} minutes</p>
          <button class="red-btn" onClick="deleteRecipe(${idrecipes})">Delete</button>`;

        innerDisplay.appendChild(newDiv);
    }
};

updateRecipesBtn.addEventListener("click", () => {
    fetch("http://localhost:3000/recipes/")
        .then((res) => res.json())
        .then((data) => {
            clearChildren(innerDisplay);
            displayRecipes(data);
        })
        .catch((err) => console.warn(err));
});

addRecipeBtn.addEventListener("click", () => {
    const newChef = addChefInput.value;
    const newCookingTime = addCookingTimeInput.value;
    if (newChef && newCookingTime) {
        const body = {
            chef: newChef,
            cookingTime: newCookingTime
        }
        fetch("http://localhost:3000/recipes/", {
                method: "POST",
                headers: {
                    'Content-Type': 'application/json',
                    'Accept': 'application/json'
                },
                body: JSON.stringify(body)
            })
            .then(res => {
                addChefInput.value = "";
                addCookingTimeInput.value = "";
            })
            .catch(err => console.warn(err))
    }
})

updateRecipeBtn.addEventListener("click", () => {
    const newChef = updateChefInput.value;
    const newCookingTime = updateCookingTimeInput.value;
    const id = updateIdInput.value;
    if (newChef && newCookingTime && id) {
        const body = {
            chef: newChef,
            cookingTime: newCookingTime
        }
        fetch(`http://localhost:3000/recipes/${id}`, {
                method: "PUT",
                headers: {
                    'Content-Type': 'application/json',
                    'Accept': 'application/json'
                },
                body: JSON.stringify(body)
            })
            .then(res => {
                updateChefInput.value = "";
                updateCookingTimeInput.value = "";
                updateIdInput.value = "";
            })
            .catch(err => console.warn(err))
    }
})
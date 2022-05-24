const fs = require("fs");


/* READ JSON FILES */
// const js = require("./students.json");
// console.log(js);

// fs.readFile("./students.json", "utf8", (err, string) => {
//     if (err) {
//         console.log("Failed reading file", err);
//         return;
//     }
//     const obj = JSON.parse(string);
//     console.log(obj);
// });


/* WRITE TO JSON FILES */

obj = {
    students: [
        {
            firstName: "Ram",
            lastName: "Sharam"
        },
        {
            firstName: "RamRam",
            lastName: "SharamSharam"
        }
    ]
}

jsonString = JSON.stringify(obj);

fs.writeFile("./students.json", jsonString, err => {
    if (err) {
        console.log("error writing file", err);
    } else {
        console.log("wrote file");
    }
})

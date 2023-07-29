// Yay more comments, but for variables.

let firstName = "Itchy";
let age = Number.MAX_VALUE;
let isStudent = false; // Lol, definitely true.

console.log("Hello you dumdum " + firstName + "!");
console.log(age + " years old, really?!");
console.log(`${isStudent}, nah dude`); // this is js, not php I swear

document.getElementById("p1").innerHTML = "Hey hey!!!! " + firstName;
document.getElementById("p2").innerHTML = "What if dude, what if you were... " + age; // I'm feelin' dum
document.getElementById("p3").innerHTML = "You are " + (isStudent ? "not ":"") + "a student"; // Woah, these work here!?!
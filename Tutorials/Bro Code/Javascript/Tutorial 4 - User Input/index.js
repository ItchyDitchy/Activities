let psd;

document.getElementById("buttonEi").onclick = function() {
    psd = document.getElementById("psd").value;
    console.log("Thank you! " + psd);
    document.getElementById("lab").innerHTML = "ur pass is \"" + psd + "\""; // ah, opera prompted me to save the password LMAO
}
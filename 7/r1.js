
const fs = require('fs');

let lines = fs.readFileSync("input").toString().replace(/\r/g, "").split("\n");


const containedBy = {};

console.log("parse");
var time = Date.now();

for(let l of lines){
	let l0 = l.split(" contain ");
	if(l0.length < 2){
		console.log("Invalid: " + l);
		continue;
	}
	let target = l0[0].replace(/(\ bags)|(\ bag)/, "").trim();
	let bags0 = l0[1].split(", ");
	for(let b of bags0){
		let name = b.match(/[a-z\ ]+/)[0].replace(/(\ bags)|(\ bag)/, "").trim();
		if(name == "no other")
			continue;
		let count = parseInt(b.match(/[0-9]+/)[0]);
		if(!containedBy[name])
			containedBy[name] = [];
		containedBy[name].push(target);
	}
}

console.log("parse in " + (Date.now() - time) + "ms");
console.log("get");
time = Date.now();

const canContainShinyGold = {};

getBagContainers("shiny gold", canContainShinyGold);

console.log("get in " + (Date.now() - time) + "ms");
console.log(Object.keys(canContainShinyGold).length);


function getBagContainers(bagcolor, cache){
	if(!containedBy[bagcolor])
		return;
	for(let b of containedBy[bagcolor]){
		cache[b] = 1;
		getBagContainers(b, cache);
	}
}



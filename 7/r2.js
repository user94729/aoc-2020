
const fs = require('fs');

let lines = fs.readFileSync("input").toString().replace(/\r/g, "").split("\n");


const contains = {};

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
		if(!contains[target])
			contains[target] = [];
		contains[target].push({name, count});
	}
}

console.log("parse in " + (Date.now() - time) + "ms");
console.log("get");
time = Date.now();

let num = getBagCount("shiny gold");

console.log("get in " + (Date.now() - time) + "ms");
console.log(num);


function getBagCount(bagcolor, mul = 1){
	if(!contains[bagcolor])
		return 0;
	let num = 0;
	for(let b of contains[bagcolor]){
		num += getBagCount(b.name, b.count) + b.count;
	}
	return num * mul;

}


